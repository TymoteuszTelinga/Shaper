from bytecode.ByteCodeMaker import ByteCodeMaker

from common.Types import Type
from common.Atoms import Constant

class Converter:

    def __init__(self, maker: ByteCodeMaker):
        self.maker = maker

    def ConvVarToType(self, var: Constant, type: Type):
        if var.type != type:
            if type == Type.INT:
                self.ConvToInt(var)
            elif type == Type.FLOAT:
                self.ConvToFloat(var)
            elif type == Type.LONG:
                self.ConvToLong(var)
            elif type == Type.DOUBLE:
                self.ConvToDouble(var)

    def ConvToInt(self, var: Constant):
        if var.type == Type.DOUBLE:
            self.maker.D2I()
        elif var.type == Type.LONG:
            self.maker.L2I()
        elif var.type == Type.FLOAT:
            self.maker.F2I()

        var.type = Type.INT

    def ConvToFloat(self, var: Constant):
        if var.type == Type.INT:
            self.maker.I2F()
        elif var.type == Type.LONG:
            self.maker.L2F()
        elif var.type == Type.DOUBLE:
            self.maker.D2F()

        var.type = Type.FLOAT
    
    def ConvToLong(self, var: Constant):
        if var.type == Type.INT:
            self.maker.I2L()
        elif var.type == Type.FLOAT:
            self.maker.F2L()
        elif var.type == Type.DOUBLE:
            self.maker.D2L()

        var.type = Type.LONG

    def ConvToDouble(self, var: Constant):
        if var.type == Type.INT:
            self.maker.I2D()
        elif var.type == Type.FLOAT:
            self.maker.F2D()
        elif var.type == Type.LONG:
            self.maker.L2D()

        var.type = Type.DOUBLE

    def ConvToBetter(self, left_var: Constant, right_var: Constant):
        max_type = self.GetBestType(left_var, right_var)

        if max_type in [Type.LONG, Type.DOUBLE]:
            self.Conv2ToLong(left_var, right_var, max_type)
        else:
            self.Conv2ToInt(left_var, right_var, max_type)



    def GetBestType(self, left_var: Constant, right_var: Constant) -> Type:
        max_type = Type(max(left_var.type.value, right_var.type.value))
        
        if max_type == Type.LONG and Type.FLOAT in [left_var.type, right_var.type]:
            max_type = Type.DOUBLE
        
        return max_type
    
    def Conv2ToLong(self, left_var: Constant, right_var: Constant, to_type: Type):
        pass

    def Conv2ToInt(self, left_var: Constant, right_var: Constant, to_type: Type):
        if left_var.type != to_type and left_var.type in [Type.INT, Type.FLOAT]:
            self.maker.LOAD(self.maker.framePosition - 2)
            self.ConvVarToType(left_var, to_type)
            self.maker.STORE(self.maker.framePosition - 3)
        
        if right_var.type != to_type and right_var.type in [Type.INT, Type.FLOAT]:
            
            self.ConvVarToType(right_var, to_type)
            

    def ConvLLToInt(self, left_var: Constant, right_var: Constant, to_type: Type):
        if left_var.type != to_type:
            self.maker.LOAD(self.maker.framePosition - 4)
            self.maker.LOAD(self.maker.framePosition - 4)

            


