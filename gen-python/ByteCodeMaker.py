class ByteCodeMaker:

    def __init__(self) -> None:


        # containts info about:
        # * commandNumber where jump was initialized
        # * bytecodePosition of place where jump ends
        self.jumpStack = []

        self.functionCallStack = []
        self.bytecodePosition = 0

        self.memoryPosition = 0

        self.framePosition = 0 # start of frame 

        self.commandCounter = 0
        self.commandsQueue = []


    def getIntMemoryAddress(self) -> int:
        temp = self.memoryPosition

        self.memoryPosition += 1

        return temp

    def getLongMemoryAddress(self) -> int:
        temp = self.memoryPosition

        self.memoryPosition += 2

        return temp

    def getLongFrameAddress(self) -> int:
        temp = self.framePosition

        self.framePosition += 2

        return temp

    def getIntFrameAddress(self) -> int:
        temp = self.framePosition

        self.framePosition += 1

        return temp

    def ADD_I(self):
        self.commandsQueue.append(("ADD_I"))

        self.framePosition -= 1

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def SUB_I(self):
        self.commandsQueue.append(("SUB_I"))

        self.framePosition -= 1

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def MUL_I(self):
        self.commandsQueue.append(("MUL_I"))

        self.framePosition -= 1

        self.commandCounter += 1
        self.bytecodePosition += 1

    
    def DIV_I(self):
        self.commandsQueue.append(("DIV_I"))

        self.framePosition -= 1

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def MOD_I(self):
        self.commandsQueue.append(("MOD_I"))

        self.framePosition -= 1

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def ADD_F(self):
        self.commandsQueue.append(("ADD_F"))

        self.framePosition -= 1

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def SUB_F(self):
        self.commandsQueue.append(("SUB_F"))

        self.framePosition -= 1

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def MUL_F(self):
        self.commandsQueue.append(("MUL_F"))

        self.framePosition -= 1

        self.commandCounter += 1 
        self.bytecodePosition += 1

    
    def DIV_F(self):
        self.commandsQueue.append(("DIV_F"))

        self.framePosition -= 1

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def ADD_L(self):
        self.commandsQueue.append(("ADD_L"))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def SUB_L(self):
        self.commandsQueue.append(("SUB_L"))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def MUL_L(self):
        self.commandsQueue.append(("MUL_L"))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def DIV_L(self):
        self.commandsQueue.append(("DIV_L"))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def MOD_L(self):
        self.commandsQueue.append(("MOD_L"))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def ADD_D(self):
        self.commandsQueue.append(("ADD_D"))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def SUB_D(self):
        self.commandsQueue.append(("SUB_D"))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def MUL_D(self):
        self.commandsQueue.append(("MUL_D"))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def DIV_D(self):
        self.commandsQueue.append(("DIV_D"))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1


    def I2C(self):
        self.commandsQueue.append(("I2C"))

        self.commandCounter += 1 
        self.bytecodePosition += 1
    
    
    def I2S(self):
        self.commandsQueue.append(("I2S"))

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def I2F(self):
        self.commandsQueue.append(("I2F"))

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def I2L(self):
        self.commandsQueue.append(("I2L"))

        self.framePosition += 1
        self.commandCounter += 1 
        self.bytecodePosition += 1
    
    def I2D(self):
        self.commandsQueue.append(("I2D"))

        self.framePosition += 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def F2I(self):
        self.commandsQueue.append(("F2I"))

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def F2L(self):
        self.commandsQueue.append(("F2L"))

        self.framePosition += 1
        self.commandCounter += 1 
        self.bytecodePosition += 1
    
    def F2D(self):
        self.commandsQueue.append(("F2D"))

        self.framePosition += 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def L2I(self):
        self.commandsQueue.append(("L2I"))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def L2F(self):
        self.commandsQueue.append(("L2F"))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1
    
    def L2D(self):
        self.commandsQueue.append(("L2D"))

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def D2I(self):
        self.commandsQueue.append(("D2I"))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def D2F(self):
        self.commandsQueue.append(("D2F"))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1
    
    def D2L(self):
        self.commandsQueue.append(("D2L"))

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def INC(self, offset: int):
        self.commandsQueue.append(("INC", offset))

        self.commandCounter += 1 
        self.bytecodePosition += 2

    def DEC(self, offset: int):
        self.commandsQueue.append(("DEC", offset))  

        self.commandCounter += 1 
        self.bytecodePosition += 2

    def LT(self):
        self.commandsQueue.append(("LT"))  

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def GT(self):
        self.commandsQueue.append(("GT"))  

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def LE(self):
        self.commandsQueue.append(("LE"))  

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def GE(self):
        self.commandsQueue.append(("GE"))  

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def EQ(self):
        self.commandsQueue.append(("EQ"))  

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def AND(self):
        self.commandsQueue.append(("AND"))  

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1    

    def OR(self):
        self.commandsQueue.append(("OR"))  

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def NEG(self):
        self.commandsQueue.append(("NEG"))  

        self.commandCounter += 1 
        self.bytecodePosition += 1


    def JMP(self, offset: int):
        self.commandsQueue.append(("JMP", offset))

        self.commandCounter += 1 
        self.bytecodePosition += 2

    def JMPT(self, offset: int):
        self.commandsQueue.append(("JMPT", offset))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 2

    def JMPF(self, offset: int):
        self.commandsQueue.append(("JMPF", offset))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 2

    def CONST_I(self, value: int):
        self.commandsQueue.append(("CONST_I", value))

        self.framePosition += 1
        self.commandCounter += 1 
        self.bytecodePosition += 2

    def LOAD(self, offset: int):
        self.commandsQueue.append(("LOAD", offset))

        self.framePosition += 1
        self.commandCounter += 1 
        self.bytecodePosition += 2


    def GLOAD(self, address: int):
        self.commandsQueue.append(("GLOAD", address))

        self.framePosition += 1
        self.commandCounter += 1 
        self.bytecodePosition += 2   

    def ALOAD_I(self):
        self.commandsQueue.append(("ALOAD_I"))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def STORE(self, offset: int):
        self.commandsQueue.append(("STORE", offset))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 2
    
    def GSTORE(self, address: int):
        self.commandsQueue.append(("GSTORE", address))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 2

    def ASTORE_I(self):
        self.commandsQueue.append(("ASTORE_I"))

        self.framePosition -= 3
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def PRINT_C(self):
        self.commandsQueue.append(("PRINT_C"))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1
    
    def PRINT_I(self):
        self.commandsQueue.append(("PRINT_I"))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def PRINT_F(self):
        self.commandsQueue.append(("PRINT_F"))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def PRINT_L(self):
        self.commandsQueue.append(("PRINT_L"))

        self.framePosition -= 2
        self.commandCounter += 1 
        self.bytecodePosition += 1


    def PRINT_D(self):
        self.commandsQueue.append(("PRINT_D"))

        self.framePosition -= 2
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def POP(self):
        self.commandsQueue.append(("POP"))

        self.framePosition -= 1
        self.commandCounter += 1
        self.bytecodePosition += 1

    def POP2(self):
        self.commandsQueue.append(("POP2"))

        self.framePosition -= 2
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def HALT(self):
        self.commandsQueue.append(("HALT"))

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def CALL(self, address: int, arguments: int):
        self.commandsQueue.append(("CALL", address, arguments))

        # every CALL ends with RET, 
        # so we don't change position in stack
        # self.framePosition += 3

        self.commandCounter += 1 
        self.bytecodePosition += 3

    def RET(self):
        self.commandsQueue.append(("RET"))

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def NEWARR(self):
        self.commandsQueue.append(("NEWARR"))

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def FREE(self):
        self.commandsQueue.append(("FREE"))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def DISPLAY(self):
        self.commandsQueue.append(("DISPLAY"))

        self.commandCounter += 1
        self.bytecodePosition += 1
    
    def CLEAR(self):
        self.commandsQueue.append(("CLEAR"))

        self.commandCounter += 1
        self.bytecodePosition += 1

    def RECT(self):
        self.commandsQueue.append(("RECT"))

        self.framePosition -= 5
        self.commandCounter += 1
        self.bytecodePosition += 1
    
    def ELIPSE(self):
        self.commandsQueue.append(("ELIPSE"))

        self.framePosition -= 5
        self.commandCounter += 1
        self.bytecodePosition += 1

    def LINE(self):
        self.commandsQueue.append(("LINE"))

        self.framePosition -= 5
        self.commandCounter += 1
        self.bytecodePosition += 1
    
    def TRIANGLE(self):
        self.commandsQueue.append(("TRIANGLE"))

        self.framePosition -= 7
        self.commandCounter += 1
        self.bytecodePosition += 1
    
    