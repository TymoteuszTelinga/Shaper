from OpenGL.GL import * 
import Color
import math
  

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

class Triangle:
    def __init__(self, pos1, pos2, pos3, color = Color.Color(255,255,255,255)):
        self.x1 = pos1[0]
        self.y1 = pos1[1]

        self.x2 = pos2[0]
        self.y2 = pos2[1]
    
        self.x3 = pos3[0]
        self.y3 = pos3[1]  

        self.color = color

    def paint(self):
        glColor4f(self.color.R, self.color.G, self.color.B, self.color.A)
        glBegin(GL_TRIANGLES)
        glVertex2f(self.x1, self.y1)
        glVertex2f(self.x2, self.y2)
        glVertex2f(self.x3, self.y3)
        glEnd()

class Line:
    def __init__(self, pos1, pos2, color = Color.Color(255,255,255,255)):
        self.x1 = pos1[0]
        self.y1 = pos1[1]

        self.x2 = pos2[0]
        self.y2 = pos2[1]
    
        self.color = color
    
    def paint(self):
        glColor4f(self.color.R, self.color.G, self.color.B, self.color.A)
        glBegin(GL_LINES)
        glVertex2f(self.x1, self.y1)
        glVertex2f(self.x2, self.y2)
        glEnd()

class Circle:
    num_seg = 80
    PI = 3.14158

    def __init__(self, pos, size, color = Color.Color(255, 255, 255, 255)):
        self.x = pos[0]
        self.y = pos[1]

        self.width = size[0]
        self.height = size[1]

        self.color = color
    def paint(self):

        glColor4f(self.color.R, self.color.G, self.color.B, self.color.A)
        glBegin(GL_TRIANGLES)

        x1 = self.x + self.width
        y1 = self.y
        for i in range(self.num_seg):
            theta = (2.0 * self.PI * (i+1)) / self.num_seg

            x2 = self.x + self.width * math.cos(theta) 
            y2 = self.y + self.height * math.sin(theta)

            glVertex2f(x1, y1)
            glVertex2f(self.x, self.y)
            glVertex2f(x2, y2)

            x1 = x2
            y1 = y2

        glEnd()
