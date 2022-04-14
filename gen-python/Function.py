from Types import Type

class Function:
    def __init__(self, f_name : str) -> None:
        self.name : str = f_name 
        self.return_type : Type = Type.VOID
        self.parameters = []

    def setReturnType(self, type : Type) -> None:
        self.return_type = type
    
    def setParameters(self, par_list) -> None:
        self.parameters = par_list

    def __repr__(self) -> str:
        return repr(self.return_type) + " " +  self.name + ": " + str(self.parameters)