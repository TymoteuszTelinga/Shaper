from Atoms import Variable

class Scope:
    def __init__(self) -> None:
        self.variables: dict(str, Variable) = {}
        self.upper : Scope = None
    

    # returns variable with given name or None when doesn't exist
    def getVariable(self, name: str) -> Variable:
        if name in self.variables.keys():
            return self.variables[name]
        elif self.upper != None:
            return self.upper.getVariable(name)
        else:
            return None

    # checks if variable was defined earlier in this scope
    def isAvailable(self, name: str) -> bool:
        if name in self.variables.keys():
            return False
        else:
            return True

    # adds new variable to scope
    def addVariable(self, var: Variable) -> None:
        self.variables[var.name] = var
    
