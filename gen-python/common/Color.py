class Color:
    def __init__(self, R: int, G: int, B: int, A: int):
        self.R = R / 255.0
        self.G = G / 255.0
        self.B = B / 255.0
        self.A = A / 255.0

    def __eq__(self, other) -> bool:
        if self.R == other.R and self.G == other.G and self.B == other.B:
            return True
        else:
            return False

    def __ne__(self, other) -> bool:
        return not self == other
    
    def __str__(self):
        ret = f"R:{int(self.R*255)} G:{int(self.G*255)} B:{int(self.B*255)} A:{int(self.A*255)}" 
        return ret

    def __int__(self) -> None:
        ret = int(self.R * 255)
        ret *= 256
        ret += int(self.G * 255)
        ret *= 256
        ret += int(self.B * 255)
        ret *= 256
        ret += int(self.A * 255)
        return ret
        

    @staticmethod
    def getColor(colorStr: str):
        if colorStr == 'BLACK':
            return BLACK
        elif colorStr == 'WHITE':
            return WHITE
        elif colorStr == 'RED':
            return RED
        elif colorStr == 'GREEN':
            return GREEN
        elif colorStr == 'BLUE':
            return BLUE
        elif colorStr == 'YELLOW':
            return YELLOW
        else:
            return WHITE
        


BLACK = Color(0, 0, 0, 255)
WHITE = Color(255, 255, 255, 255)
RED = Color(255, 0, 0, 255)
GREEN = Color(0, 255, 0, 255)
BLUE = Color(0, 0, 255, 255)
YELLOW = Color(255, 255, 0, 255)