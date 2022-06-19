from common.Atoms import *
from common.Types import Type

class Function:
    def __init__(self, f_name : str) -> None:
        self.name : str = f_name 
        self.return_atom: Constant = Constant(Type.VOID, None)
        self.parameters = []
        self.kind = 0 # 0 - user 1 - built in
        self.ctx = None
        self.address = 0

    def setReturnVar(self, type: Type) -> None:
        self.return_atom = Constant(type, None)
    
    def setParameters(self, par_list) -> None:
        self.parameters = par_list

    def __repr__(self) -> str:
        return repr(self.return_atom) + " " +  self.name + ": " + str(self.parameters)