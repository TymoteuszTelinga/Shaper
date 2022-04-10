from OpenGL import *
from OpenGL.GL import *
from OpenGL.GLU import *
from OpenGL.GLUT import *

import MyVisitor
from grammar.ShaperParser import ShaperParser



class WindowMaker:


    def __init__(self, width=800, height=600):
        self.width = width
        self.height = height
        self.ctx = None
        self.visitor = None
        self.color = 0

    def setBackground(self, color):
        self.color = color

    def setContext(self, visitor: MyVisitor, ctx: ShaperParser.FunctionDefinitionContext):
        self.visitor = visitor
        self.ctx = ctx

    def loop(self):
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
        glLoadIdentity()
        
        glViewport(0, 0, self.width, self.height)
        glOrtho(0, self.width, 0, self.height, 0, 1)


        self.visitor.visit(self.ctx.compoundStatement())

        glutSwapBuffers()

    def show(self):
        glutInit()
        glutInitDisplayMode(GLUT_RGBA)
        glutInitWindowSize(self.width, self.height)
        window = glutCreateWindow("Shaper")
        glutDisplayFunc(self.loop)
        glutMainLoop()