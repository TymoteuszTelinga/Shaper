from Commands import Command

'''
Class below creates, a set of commands
and holds points which should be later filled
with appriopriate values
'''
class ByteCodeMaker:

    def __init__(self) -> None:


        # contains info about:
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

        #self.framePosition += 2

        return temp

    def getIntFrameAddress(self) -> int:
        temp = self.framePosition

        #self.framePosition += 1

        return temp

    def ADD_I(self):
        self.commandsQueue.append( (Command.ADD_I ))

        self.framePosition -= 1

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def SUB_I(self):
        self.commandsQueue.append( (Command.SUB_I ))

        self.framePosition -= 1

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def MUL_I(self):
        self.commandsQueue.append( (Command.MUL_I ))

        self.framePosition -= 1

        self.commandCounter += 1
        self.bytecodePosition += 1

    
    def DIV_I(self):
        self.commandsQueue.append( (Command.DIV_I ))

        self.framePosition -= 1

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def MOD_I(self):
        self.commandsQueue.append( (Command.MOD_I ))

        self.framePosition -= 1

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def ADD_F(self):
        self.commandsQueue.append( (Command.ADD_F ))

        self.framePosition -= 1

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def SUB_F(self):
        self.commandsQueue.append( (Command.SUB_F ))

        self.framePosition -= 1

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def MUL_F(self):
        self.commandsQueue.append( (Command.MUL_F ))

        self.framePosition -= 1

        self.commandCounter += 1 
        self.bytecodePosition += 1

    
    def DIV_F(self):
        self.commandsQueue.append( (Command.DIV_F ))

        self.framePosition -= 1

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def ADD_L(self):
        self.commandsQueue.append( (Command.ADD_L ))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def SUB_L(self):
        self.commandsQueue.append( (Command.SUB_L ))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def MUL_L(self):
        self.commandsQueue.append( (Command.MUL_L ))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def DIV_L(self):
        self.commandsQueue.append( (Command.DIV_L ))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def MOD_L(self):
        self.commandsQueue.append( (Command.MOD_L ))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def ADD_D(self):
        self.commandsQueue.append( (Command.ADD_D ))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def SUB_D(self):
        self.commandsQueue.append( (Command.SUB_D ))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def MUL_D(self):
        self.commandsQueue.append( (Command.MUL_D ))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def DIV_D(self):
        self.commandsQueue.append( (Command.DIV_D ))

        self.framePosition -= 2

        self.commandCounter += 1 
        self.bytecodePosition += 1


    def I2C(self):
        self.commandsQueue.append( (Command.I2C ))

        self.commandCounter += 1 
        self.bytecodePosition += 1
    
    
    def I2S(self):
        self.commandsQueue.append( (Command.I2S ))

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def I2F(self):
        self.commandsQueue.append( (Command.I2F ))

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def I2L(self):
        self.commandsQueue.append( (Command.I2L ))

        self.framePosition += 1
        self.commandCounter += 1 
        self.bytecodePosition += 1
    
    def I2D(self):
        self.commandsQueue.append( (Command.I2D ))

        self.framePosition += 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def F2I(self):
        self.commandsQueue.append( (Command.F2I ))

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def F2L(self):
        self.commandsQueue.append( (Command.F2L ))

        self.framePosition += 1
        self.commandCounter += 1 
        self.bytecodePosition += 1
    
    def F2D(self):
        self.commandsQueue.append( (Command.F2D ))

        self.framePosition += 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def L2I(self):
        self.commandsQueue.append( (Command.L2I ))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def L2F(self):
        self.commandsQueue.append( (Command.L2F ))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1
    
    def L2D(self):
        self.commandsQueue.append( (Command.L2D ))

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def D2I(self):
        self.commandsQueue.append( (Command.D2I ))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def D2F(self):
        self.commandsQueue.append( (Command.D2F ))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1
    
    def D2L(self):
        self.commandsQueue.append( (Command.D2L ))

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def INC(self, offset: int):
        self.commandsQueue.append( (Command.INC , offset))

        self.commandCounter += 1 
        self.bytecodePosition += 2

    def DEC(self, offset: int):
        self.commandsQueue.append( (Command.DEC , offset))  

        self.commandCounter += 1 
        self.bytecodePosition += 2

    def LT(self):
        self.commandsQueue.append( (Command.LT ))  

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def GT(self):
        self.commandsQueue.append( (Command.GT ))  

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def LE(self):
        self.commandsQueue.append( (Command.LE ))  

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def GE(self):
        self.commandsQueue.append( (Command.GE ))  

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def EQ(self):
        self.commandsQueue.append( (Command.EQ ))  

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def AND(self):
        self.commandsQueue.append( (Command.AND ))  

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1    

    def OR(self):
        self.commandsQueue.append( (Command.OR ))  

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def NEG(self):
        self.commandsQueue.append( (Command.NEG ))  

        self.commandCounter += 1 
        self.bytecodePosition += 1


    def JMP(self, offset: int):
        self.commandsQueue.append( (Command.JMP , offset))

        self.commandCounter += 1 
        self.bytecodePosition += 2

    def JMPT(self, offset: int):
        self.commandsQueue.append( (Command.JMPT , offset))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 2

    def JMPF(self, offset: int):
        self.commandsQueue.append( (Command.JMPF , offset))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 2

    def CONST_I(self, value: int):
        self.commandsQueue.append( (Command.CONST_I , value))

        self.framePosition += 1
        self.commandCounter += 1 
        self.bytecodePosition += 2

    def LOAD(self, offset: int):
        self.commandsQueue.append( (Command.LOAD , offset))

        self.framePosition += 1
        self.commandCounter += 1 
        self.bytecodePosition += 2


    def GLOAD(self, address: int):
        self.commandsQueue.append( (Command.GLOAD , address))

        self.framePosition += 1
        self.commandCounter += 1 
        self.bytecodePosition += 2   

    def ALOAD_I(self):
        self.commandsQueue.append( (Command.ALOAD_I ))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def LOAD_CH(self, channel: int):
        self.commandsQueue.append((Command.LOAD_CH, channel))

        self.framePosition += 0
        self.commandCounter += 1
        self.bytecodePosition += 2

    def STORE(self, offset: int):
        self.commandsQueue.append( (Command.STORE , offset))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 2
    
    def GSTORE(self, address: int):
        self.commandsQueue.append( (Command.GSTORE , address))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 2

    def ASTORE_I(self):
        self.commandsQueue.append( (Command.ASTORE_I ))

        self.framePosition -= 3
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def STORE_CH(self, channel: int):
        self.commandsQueue.append((Command.STORE_CH, channel))

        self.framePosition -= 1
        self.commandCounter += 1
        self.bytecodePosition += 2

    def PRINT_C(self):
        self.commandsQueue.append( (Command.PRINT_C ))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1
    
    def PRINT_I(self):
        self.commandsQueue.append( (Command.PRINT_I ))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def PRINT_F(self):
        self.commandsQueue.append( (Command.PRINT_F ))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def PRINT_L(self):
        self.commandsQueue.append( (Command.PRINT_L ))

        self.framePosition -= 2
        self.commandCounter += 1 
        self.bytecodePosition += 1


    def PRINT_D(self):
        self.commandsQueue.append( (Command.PRINT_D ))

        self.framePosition -= 2
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def POP(self):
        self.commandsQueue.append( (Command.POP ))

        self.framePosition -= 1
        self.commandCounter += 1
        self.bytecodePosition += 1

    def POP2(self):
        self.commandsQueue.append( (Command.POP2 ))

        self.framePosition -= 2
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def HALT(self):
        self.commandsQueue.append( (Command.HALT ))

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def CALL(self, address: int, arguments: int):
        self.commandsQueue.append( (Command.CALL , address, arguments))

        # every CALL ends with RET, 
        # so we don't change position in stack
        # self.framePosition += 3

        self.commandCounter += 1 
        self.bytecodePosition += 3

    def RET(self):
        self.commandsQueue.append( (Command.RET ))

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def NEWARR(self):
        self.commandsQueue.append( (Command.NEWARR ))

        self.commandCounter += 1 
        self.bytecodePosition += 1

    def FREE(self):
        self.commandsQueue.append( (Command.FREE ))

        self.framePosition -= 1
        self.commandCounter += 1 
        self.bytecodePosition += 1

    def DISPLAY(self):
        self.commandsQueue.append( (Command.DISPLAY ))

        self.commandCounter += 1
        self.bytecodePosition += 1
    
    def CLEAR(self):
        self.commandsQueue.append( (Command.CLEAR ))

        self.commandCounter += 1
        self.bytecodePosition += 1

    def RECT(self):
        self.commandsQueue.append( (Command.RECT ))

        self.framePosition -= 5
        self.commandCounter += 1
        self.bytecodePosition += 1
    
    def ELIPSE(self):
        self.commandsQueue.append( (Command.ELIPSE ))

        self.framePosition -= 5
        self.commandCounter += 1
        self.bytecodePosition += 1

    def LINE(self):
        self.commandsQueue.append( (Command.LINE ))

        self.framePosition -= 5
        self.commandCounter += 1
        self.bytecodePosition += 1
    
    def TRIANGLE(self):
        self.commandsQueue.append( (Command.TRIANGLE ))

        self.framePosition -= 7
        self.commandCounter += 1
        self.bytecodePosition += 1
    
    