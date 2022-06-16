from Types import Type
from Scope import Scope
from Function import Function
from Atoms import *

class Manager:

    max_recursion: int = 15

    def __init__(self) -> None:
        self.visitor = None

        #scopes
        self.curr_scope: Scope = Scope()
        self.global_scope: Scope = self.curr_scope

        self.return_var = None
        self.curr_function: Function = None

        # functions
        self.user_func : dict(str, Function) = {} 
        self.built_in_func: dict(str, Function) = {}
        self.draw_func: Function = None
        self.setup_func: Function = None

        # for limiting recursion
        self.called_func: int = 0

        self.fillBuitInFunctions()


    def start(self):
        if self.setup_func != None:
            self.curr_function = self.setup_func
            oldScope = self.create_new_scope(False)
            self.visitor.visit(self.setup_func.ctx)

            self.return_var = None
            self.curr_scope = oldScope
        
        if self.draw_func != None:
            self.curr_function = self.draw_func

            self.window.setContext(self, self.visitor, self.draw_func.ctx)
            self.window.show()

    def create_new_scope(self, hasParent) -> Scope:
        new_scope = Scope()
        old_scope = self.curr_scope

        if(hasParent):
            new_scope.upper = old_scope

        self.curr_scope = new_scope

        return old_scope

    def func_exists(self, fun):
        if fun.name == 'draw':
            if self.draw_func == None:
                self.draw_func = fun
                
            else:
                self.visitor.errorstack.append("Function \'draw()\' is redeclared")
            return True
        
        if fun.name == 'setup':
            if self.setup_func == None:
                self.setup_func = fun
            else:
                self.visitor.errorstack.append("Function \'setup()\' is redeclared")
            return True
        
        if fun.name in self.built_in_func.keys():
            self.visitor.errorstack.append(f"Function '{fun.name}' is built-in, can't be redeclared")
            return True

        if fun.name in self.user_func.keys():
            self.visitor.errorstack.append(f"Function '{fun.name}' was declared earlier, can't be redeclared")
            return True

    def addFunction(self, fun: Function):
        if not self.func_exists(fun):
            self.user_func[fun.name] = fun

    def getFunctionAddress(self, name: str) -> int:
        if name == 'draw':
            return self.draw_func.address
        elif name == 'setup':
            return self.setup_func.address

        return self.user_func[name].address

    def findFunction(self, name:str):
        if name == 'draw':
            fun = self.draw_func
            print(fun.address)
            return self.draw_func
        elif name == 'setup':
            fun = self.setup_func
            print(fun.address)
            return self.setup_func
        
        

        return self.user_func[name].return_atom
    

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

            
            if expected.type != Type.ANY and got.type != expected.type:
                return ([i, expected], 4)
                
        return(func, 0)


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
        
        if not self.curr_scope.is_available(name):
            return False
           
        return True
        

    def addVariable(self, var):
        self.curr_scope.addVariable(var)
        

    def fillBuitInFunctions(self):
        temp = Function("print")
        temp.kind = 1
        temp.setParameters([Variable("x", Type.ANY)])

        self.built_in_func[temp.name] = temp


    def setVisitor(self, visitor):
        self.visitor = visitor
 
    def enter_setup(self):
        if self.setup_func != None:
            
            oldScope = self.create_new_scope(False)

            self.curr_function = self.setup_func
            self.return_var = None

            self.visitor.visit(self.setup_func.ctx)
            self.curr_scope = oldScope

    def enter_draw(self):
        if self.draw_func != None:
            oldScope = self.create_new_scope(False)

            self.curr_function = self.draw_func
            self.return_var = None

            self.visitor.visit(self.draw_func.ctx)

            self.curr_scope = oldScope 

    def enter_user_functions(self):
        self.return_var = None
        for func in self.user_func.values():
            self.enter_function(func)


    def enter_function(self, func: Function):
        self.curr_function = func

        #create new scope
        oldScope = self.create_new_scope(False)

        self.curr_scope.fill_by_fun_params(self.curr_function.parameters)

        self.visitor.visit(self.curr_function.ctx)

        if self.return_var == None and self.curr_function.return_atom.type != Type.VOID:
            self.visitor.errorstack.append(f"line {self.curr_function.ctx.start.line} Function {self.curr_function.name} returning non-void value doesn't have 'return' statement")

        self.return_var = None

        self.curr_scope = oldScope 
