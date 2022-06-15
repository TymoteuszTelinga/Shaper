import types
from Types import Type
from Scope import Scope
from Function import Function
from WindowMaker import WindowMaker
from Atoms import *

class Manager:

    max_recursion: int = 15

    def __init__(self) -> None:
        self.visitor = None
        self.window: WindowMaker = WindowMaker()

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
            oldScope = self.createNewScope(False)
            self.visitor.visit(self.setup_func.ctx)

            self.return_var = None
            self.curr_scope = oldScope
        
        if self.draw_func != None:
            self.curr_function = self.draw_func

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

    def enterFunction(self, name: str, params: list, ctx):
        
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
            expected = self.curr_function.parameters[i]
            var = Variable(expected.name, got.type)
            var.val = got.val

            self.addVariable(var)
    
        if not self.addToHeap():
            if self.curr_function.kind == 0:
                raise Exception(f"line {self.curr_function.ctx.start.line} Function {self.curr_function.name} exceeded maximum recursion depth: {self.max_recursion}") 
            else:
                raise Exception(f"line {ctx.start.line} Function {self.curr_function.name} exceeded maximum recursion depth: {self.max_recursion}") 
        
        if self.curr_function.kind == 0:
           self.visitor.visit(self.curr_function.ctx)
        else:
            var = self.getVariable("x");
            if var.type == Type.INT:
                print(int(var.val))
            elif var.type == Type.FLOAT:
                print(float(var.val))
            else:
                print(var.val)


        self.deleteFromHeap()

        temp = self.return_var

        if temp == None and self.curr_function.return_atom.type != Type.VOID:
            raise Exception(f"line {self.curr_function.ctx.start.line} Function {self.curr_function.name} returning non-void value doesn't have 'return' statement") 

        if temp == None:
            
            temp = Constant(Type.VOID, None)

        self.return_var = None

        self.curr_scope = oldScope
        self.curr_function = oldFunction
        
        temp = self.return_var
            
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
        

    def fillBuitInFunctions(self):
        temp = Function("print")
        temp.kind = 1
        temp.setParameters([Variable("x", Type.ANY)])

        self.built_in_func[temp.name] = temp


    def setVisitor(self, visitor):
        self.visitor = visitor

    def addToHeap(self):
        self.called_func +=1

        if self.called_func > self.max_recursion:
            return False
        
        return True

    def deleteFromHeap(self):
        self.called_func -=1
 
        