from Types import Type
from Scope import Scope
from Function import Function
from WindowMaker import WindowMaker
from Atoms import *

class Manager:


    def __init__(self) -> None:
        self.visitor = None
        self.window: WindowMaker = WindowMaker()

        #variables
        self.curr_scope: Scope = Scope()
        self.global_scope: Scope = self.curr_scope
        self.return_var = None

        # functions
        self.curr_function: function = None
        self.user_func : dict(str, Function) = {} 
        self.built_in_func: dict(str, Function) = {}
        self.draw_func: function = None
        self.setup_func: function = None

    def start(self):
        if self.setup_func != None:
            oldScope = self.createNewScope(False)
            self.visitor.visit(self.setup_func.ctx)
            self.curr_scope = oldScope
        
        if self.draw_func != None:
            self.window.setContext(self, self.visitor, self.draw_func.ctx)
            self.window.show()

    def createNewScope(self, hasParent) -> Scope:
        new_scope = Scope()
        old_scope = self.curr_scope

        if(hasParent):
            new_scope.upper = old_scope

        self.curr_scope = new_scope

        return old_scope

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

    def functionExists(self,name:str, params:list):
        #check if function with this name exists
        if name in self.user_func.keys():
            func = self.user_func[name]
        elif name in self.built_in_func.keys():
            func = self.built_in_func[name]
        elif name in ['setup', 'draw']:
            return (None, 1)
        else:
            return (None, 2)
            
        if len(params) != len(func.parameters):
            return (func, 3)

        # add function's call parameters to new scope
        for i in range(len(params)):
            got = params[i]
            expected = func.parameters[i]

            if got.type != expected.type:
                return ([i, expected], 4)
                
        return(func, 0)

    def enterFunction(self, name: str, params: list):
        oldFunction = self.curr_function

        if name in self.user_func.keys():
            self.curr_function = self.user_func[name]
        elif name in self.built_in_func.keys():
            self.curr_function = self.built_in_func[name]

        #create new scope
        oldScope = self.createNewScope(False)

        # add function's call parameters to new scope
        for i in range(len(params)):
            got = params[i]
            var = Variable(got.name, got.type)
            var.val = got.val

            self.addVariable(var)
        
        
        self.visitor.visit(self.curr_function.ctx)
        self.curr_scope = oldScope
        self.curr_function = oldFunction

        temp = self.return_var
        self.return_var = None

        if temp == None:
            
            temp = Constant(Type.VOID, None)
        
        return temp
            
            
    
    def getVariable(self, name: str):
        var = self.curr_scope.getVariable(name) 

        if var != None:
            return var
        else:
            return self.global_scope.getVariable(name)

    # checks if variable can be created in current scope
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

    def setVisitor(self, visitor):
        self.visitor = visitor


        