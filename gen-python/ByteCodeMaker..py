from cv2 import add


class ByteCodeMaker:

    def __init__(self) -> None:
        # self.globalVariables = []
        # self.localVariables = []
        self.jumpStack = []
        self.bytecodePosition = 0
        self.memoryPosition = 0 # position without a token

        self.commandsQueue = []


    def ADD_I(self):
        self.commandsQueue.append(("ADD_I"))

        self.memoryPosition -= 1

        self.bytecodePosition += 1

    def SUB_I(self):
        self.commandsQueue.append(("SUB_I"))

        self.memoryPosition -= 1

        self.bytecodePosition += 1

    def MUL_I(self):
        self.commandsQueue.append(("MUL_I"))

        self.memoryPosition -= 1

        self.bytecodePosition += 1

    
    def DIV_I(self):
        self.commandsQueue.append(("DIV_I"))

        self.memoryPosition -= 1

        self.bytecodePosition += 1

    def MOD_I(self):
        self.commandsQueue.append(("MOD_I"))

        self.memoryPosition -= 1

        self.bytecodePosition += 1

    def ADD_F(self):
        self.commandsQueue.append(("ADD_F"))

        self.memoryPosition -= 1

        self.bytecodePosition += 1

    def SUB_F(self):
        self.commandsQueue.append(("SUB_F"))

        self.memoryPosition -= 1

        self.bytecodePosition += 1

    def MUL_F(self):
        self.commandsQueue.append(("MUL_F"))

        self.memoryPosition -= 1

        self.bytecodePosition += 1

    
    def DIV_F(self):
        self.commandsQueue.append(("DIV_F"))

        self.memoryPosition -= 1

        self.bytecodePosition += 1

    def ADD_L(self):
        self.commandsQueue.append(("ADD_L"))

        self.memoryPosition -= 2

        self.bytecodePosition += 1

    def SUB_L(self):
        self.commandsQueue.append(("SUB_L"))

        self.memoryPosition -= 2

        self.bytecodePosition += 1

    def MUL_L(self):
        self.commandsQueue.append(("MUL_L"))

        self.memoryPosition -= 2

        self.bytecodePosition += 1

    def DIV_L(self):
        self.commandsQueue.append(("DIV_L"))

        self.memoryPosition -= 2

        self.bytecodePosition += 1

    def MOD_L(self):
        self.commandsQueue.append(("MOD_L"))

        self.memoryPosition -= 2

        self.bytecodePosition += 1

    def ADD_D(self):
        self.commandsQueue.append(("ADD_D"))

        self.memoryPosition -= 2

        self.bytecodePosition += 1

    def SUB_D(self):
        self.commandsQueue.append(("SUB_D"))

        self.memoryPosition -= 2

        self.bytecodePosition += 1

    def MUL_D(self):
        self.commandsQueue.append(("MUL_D"))

        self.memoryPosition -= 2

        self.bytecodePosition += 1

    def DIV_D(self):
        self.commandsQueue.append(("DIV_D"))

        self.memoryPosition -= 2

        self.bytecodePosition += 1


    def I2C(self):
        self.commandsQueue.append(("I2C"))

        self.bytecodePosition += 1
    
    
    def I2S(self):
        self.commandsQueue.append(("I2S"))

        self.bytecodePosition += 1

    def I2F(self):
        self.commandsQueue.append(("I2F"))

        self.bytecodePosition += 1

    def I2L(self):
        self.commandsQueue.append(("I2L"))

        self.memoryPosition += 1
        self.bytecodePosition += 1
    
    def I2D(self):
        self.commandsQueue.append(("I2D"))

        self.memoryPosition += 1
        self.bytecodePosition += 1

    def F2I(self):
        self.commandsQueue.append(("F2I"))

        self.bytecodePosition += 1

    def F2L(self):
        self.commandsQueue.append(("F2L"))

        self.memoryPosition += 1
        self.bytecodePosition += 1
    
    def F2D(self):
        self.commandsQueue.append(("F2D"))

        self.memoryPosition += 1
        self.bytecodePosition += 1

    def L2I(self):
        self.commandsQueue.append(("L2I"))

        self.memoryPosition -= 1
        self.bytecodePosition += 1

    def L2F(self):
        self.commandsQueue.append(("L2F"))

        self.memoryPosition -= 1
        self.bytecodePosition += 1
    
    def L2D(self):
        self.commandsQueue.append(("L2D"))

        self.bytecodePosition += 1

    def D2I(self):
        self.commandsQueue.append(("D2I"))

        self.memoryPosition -= 1
        self.bytecodePosition += 1

    def D2F(self):
        self.commandsQueue.append(("D2F"))

        self.memoryPosition -= 1
        self.bytecodePosition += 1
    
    def D2L(self):
        self.commandsQueue.append(("D2L"))

        self.bytecodePosition += 1

    def INC(self, offset: int):
        self.commandsQueue.append(("INC", offset))

        self.bytecodePosition += 1

    def DEC(self, offset: int):
        self.commandsQueue.append(("DEC", offset))  

        self.bytecodePosition += 1   

    def LT(self):
        self.commandsQueue.append(("LT"))  

        self.memoryPosition -= 1
        self.bytecodePosition += 1

    def GT(self):
        self.commandsQueue.append(("GT"))  

        self.memoryPosition -= 1
        self.bytecodePosition += 1

    def LE(self):
        self.commandsQueue.append(("LE"))  

        self.memoryPosition -= 1
        self.bytecodePosition += 1

    def GE(self):
        self.commandsQueue.append(("GE"))  

        self.memoryPosition -= 1
        self.bytecodePosition += 1

    def EQ(self):
        self.commandsQueue.append(("EQ"))  

        self.memoryPosition -= 1
        self.bytecodePosition += 1

    def AND(self):
        self.commandsQueue.append(("AND"))  

        self.memoryPosition -= 1
        self.bytecodePosition += 1    

    def OR(self):
        self.commandsQueue.append(("OR"))  

        self.memoryPosition -= 1
        self.bytecodePosition += 1

    def NEG(self):
        self.commandsQueue.append(("NEG"))  

        self.bytecodePosition += 1


    def JMP(self, offset: int):
        self.commandsQueue.append(("JMP", offset))

        # to fill later offset value
        self.jumpStack.append(self.bytecodePosition)

        self.bytecodePosition += 1

    def JMPT(self, offset: int):
        self.commandsQueue.append(("JMPT", offset))

        # to fill later an offset value
        self.jumpStack.append(self.bytecodePosition)

        self.memoryPosition -= 1
        self.bytecodePosition += 1

    def JMPF(self, offset: int):
        self.commandsQueue.append(("JMPF", offset))

        # to fill later an offset value
        self.jumpStack.append(self.bytecodePosition)

        self.memoryPosition -= 1
        self.bytecodePosition += 1

    def CONST_I(self, value: int):
        self.commandsQueue.append(("CONST_I", value))

        self.memoryPosition += 1
        self.bytecodePosition += 1

    def LOAD(self, offset: int):
        self.commandsQueue.append(("LOAD", offset))

        self.memoryPosition += 1
        self.bytecodePosition += 1


    def GLOAD(self, address: int):
        self.commandsQueue.append(("GLOAD", address))

        self.memoryPosition += 1
        self.bytecodePosition += 1   

    def ALOAD_I(self):
        self.commandsQueue.append(("ALOAD_I"))

        self.memoryPosition -= 1
        self.bytecodePosition += 1

    def STORE(self, offset: int):
        self.commandsQueue.append(("STORE", offset))

        self.memoryPosition -= 1
        self.bytecodePosition += 1
    
    def GSTORE(self, address: int):
        self.commandsQueue.append(("GSTORE", address))

        self.memoryPosition -= 1
        self.bytecodePosition += 1 

    def ASTORE_I(self):
        self.commandsQueue.append(("ASTORE_I"))

        self.memoryPosition -= 3
        self.bytecodePosition += 1

    def PRINT_C(self):
        self.commandsQueue.append(("PRINT_C"))

        self.memoryPosition -= 1
        self.bytecodePosition += 1
    
    def PRINT_I(self):
        self.commandsQueue.append(("PRINT_I"))

        self.memoryPosition -= 1
        self.bytecodePosition += 1

    def PRINT_F(self):
        self.commandsQueue.append(("PRINT_F"))

        self.memoryPosition -= 1
        self.bytecodePosition += 1

    def PRINT_L(self):
        self.commandsQueue.append(("PRINT_L"))

        self.memoryPosition -= 2
        self.bytecodePosition += 1


    def PRINT_D(self):
        self.commandsQueue.append(("PRINT_D"))

        self.memoryPosition -= 2
        self.bytecodePosition += 1

    def POP(self):
        self.commandsQueue.append(("POP"))

        self.memoryPosition -= 1
        self.bytecodePosition += 1

    def POP2(self):
        self.commandsQueue.append(("POP2"))

        self.memoryPosition -= 2
        self.bytecodePosition += 1

    def HALT(self):
        self.commandsQueue.append(("HALT"))

        self.bytecodePosition += 1

    def CALL(self, address: int, arguments: int):
        self.commandsQueue.append(("CALL", address, arguments))

        self.memoryPosition += 3
        self.bytecodePosition += 1

    def RET(self):
        self.commandsQueue.append(("RET"))

        self.memoryPosition -= 3
        self.bytecodePosition += 1

    def NEWARR(self):
        self.commandsQueue.append(("NEWARR"))

        self.bytecodePosition += 1

    def FREE(self):
        self.commandsQueue.append(("FREE"))

        self.memoryPosition -= 1
        self.bytecodePosition += 1