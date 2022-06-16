from Types import Type

class Variable:
    def __init__(self, v_name : str, v_type: Type) -> None : 
        self.name : str = v_name
        self.type : Type = v_type
        self.val = None
        self.isGlobal = False
        self.address = 0

        # only for array
        self.is_root = False
        self.array_var = None

    def __repr__(self) -> str:
        return repr(self.type) + " " + self.name

class Constant:
    def __init__ (self, v_type: Type , v_val) -> None:
        self.type : Type = v_type
        self.val = v_val
        self.address = 0


    def __repr__(self) -> str:
        return repr(self.type) + "(" + repr(self.val) + ")"
