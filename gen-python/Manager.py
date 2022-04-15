from Scope import Scope
from Function import Function
from WindowMaker import WindowMaker

class Manager:


    def __init__(self, visitor) -> None:
        self.visitor = visitor
        self.window = WindowMaker()
        self.curr_scope = Scope()
        self.global_scope = self.curr_scope
        self.user_func : dict(str, Function) = {} 
        self.built_in_func: dict(str, Function) = {}
        self.draw_func = None
        self.setup_func = None

    def addFunction(self, fun: Function):
        if fun.name == 'draw':
            if self.draw_func == None:
                self.draw_func = fun
                return
            else:
                raise Exception("Function \'draw()\' is redeclared")
        
        if fun.name == 'setup':
            if self.setup_func == None:
                self.setup_func= fun
                return
            else:
                raise Exception("Function \'setup()\' is redeclared")
        
        if fun.name in self.built_in_func.keys():
            raise Exception(f"Function '{fun.name}' is built-in, can't be redeclared")

        if fun.name in self.user_func.keys():
            raise Exception(f"Function '{fun.name}' was declared earlier, can't be redeclared")

        self.user_func[fun.name] = fun

    def createNewScope(self, hasParent) -> Scope:
        new_scope = Scope()
        old_scope = self.curr_scope

        if(hasParent):
            new_scope.upper = old_scope

        self.curr_scope = new_scope

        return old_scope

    def start(self):
        if self.setup_func != None:
            self.visitor.visit(self.setup_func.ctx.compoundStatement())
        
        if self.draw_func != None:
            self.window.setContext(self, self.visitor, self.draw_func.ctx)
            self.window.show()
    
    def getVariable(self, name: str):
        var = self.curr_scope.getVariable(name) 

        if var != None:
            return var
        else:
            return self.global_scope.getVariable(name)

    def isVariableAvailable(self, name):
        if name in ['draw', 'setup'] or name in self.built_in_func.keys() or name in self.user_func.keys():
            raise Exception("Can't create variable with the same name as declared function")
        
        if not self.curr_scope.isAvailable(name):
            return False
           
        return True
        

    def addVariable(self, var):
        self.curr_scope.addVariable(var)
        

    def fillBuitInFunctions():
        print("#TODO fill built in functions")


        