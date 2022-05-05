from OpenGL import *
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

from grammar.ShaperParser import ShaperParser


class WindowMaker:


    def __init__(self, width=800, height=600):
        self.width = width
        self.height = height
        self.ctx = None
        self.manager = None
        self.visitor = None
        self.color = 0

        self.isCorrect = True

    def setBackground(self, color):
        self.color = color

    def setContext(self, manager, visitor, ctx: ShaperParser.CompoundStatementContext):
        self.manager = manager
        self.visitor = visitor
        self.ctx = ctx

    def loop(self):
        if self.isCorrect:
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
            glLoadIdentity()
            
            glViewport(0, 0, self.width, self.height)
            glOrtho(0, self.width, 0, self.height, 0, 1)


            oldScope = self.manager.createNewScope(False)

            try:
                self.visitor.visit(self.ctx)
            except Exception as e:
                print("Error: ", e) 
                self.isCorrect = False

            self.manager.curr_scope = oldScope

            glutSwapBuffers()

    def show(self):
        glutInit()
        glutInitDisplayMode(GLUT_RGBA)
        glutInitWindowSize(self.width, self.height)
        window = glutCreateWindow("Shaper")
        glutDisplayFunc(self.loop)
        glutMainLoop()