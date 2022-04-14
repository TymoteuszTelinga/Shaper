from Variable import Variable

class Scope:
    def __init__(self) -> None:
        self.variables: dict(str, Variable) = {}
        self.upper : Scope = None
    
    def isAvailable(self, var: Variable) -> bool:
        if var.name in self.variables.keys():
            return True
        elif self.upper != None:
            return self.upper.isAvailable(var)
        else:
            return False

    def getVariable(self, name: str) -> Variable:
        if name in self.variables.keys():
            return self.variables[name]
        elif self.upper != None:
            return self.upper.getVariable(name)
        else:
            return None

    def isDefined(self, var: Variable) -> bool:
        if var.name in self.variables.keys():
            return True
        else:
            return False

    def addVariable(self, var: Variable) -> None:
        self.variables[var.name] = var
    
