from Types import Type

class Variable:
    def __init__(self, v_name, v_type) -> None : 
        self.name : str = v_name
        self.type : Type = v_type
        self.val  = None

    def __repr__(self) -> str:
        return repr(self.type) + " " + self.name
