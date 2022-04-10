from OpenGL.GL import * 
import Color
  

class Rectangle:

    def __init__(self, pos, size, color = Color.Color(255,255,255,255)):
        self.x = pos[0]
        self.y = pos[1]

        self.width = size[0]
        self.height = size[1]

        self.color = color

    def paint(self):
        glColor4f(self.color.R, self.color.G, self.color.B, self.color.A)
        glBegin(GL_QUADS)
        glVertex2f(self.x, self.y)
        glVertex2f(self.x, self.y + self.height)
        glVertex2f(self.x +self.width, self.y + self.height)
        glVertex2f(self.x +self.width, self.y)
        glEnd()
