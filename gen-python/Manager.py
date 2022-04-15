from pstats import FunctionProfile
from pyclbr import Function
from Scope import Scope
from Function import Function

class Manager:
    built_in_functions = {}
    draw_funct = Function

    def __init__(self) -> None:
        self.curr_scope : Scope = Scope()
        self.user_funct : set(Function) = {} 
        