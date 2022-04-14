from Types import Type

class Variable:
    def __init__(self, v_name : str, v_type: Type) -> None : 
        self.name : str = v_name
        self.type : Type = v_type
        self.val = None

    def __repr__(self) -> str:
        return repr(self.type) + " " + self.name

    def __eq__(self, other) -> bool:
        if self.type == other.type:
            return True
        else:
            raise Exception("Type Error: Expected" + repr(self.type) + ", got" + repr(other.type))

    def __eq__(self, type) -> bool:
        if self.type == type:
            return True
        else:
            raise Exception("Type Error: Expected " + repr(type) + ", got " + repr(self.type))
