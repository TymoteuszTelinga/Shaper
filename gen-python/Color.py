class Color:
    def __init__(self,R: int,G: int,B: int,A: int):
        self.R = R / 255.0
        self.G = G / 255.0
        self.B = B / 255.0
        self.A = A / 255.0

BLACK = Color(0, 0, 0, 255)
WHITE = Color(255, 255, 255, 255)
RED = Color(255, 0, 0, 255)
GREEN = Color(0, 255, 0, 255)
BLUE = Color(0, 0, 255, 255)