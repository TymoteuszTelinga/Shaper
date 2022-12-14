from grammar.ShaperVisitor import ShaperVisitor
from grammar.ShaperParser import ShaperParser

from common.Atoms import *
from Manager import Manager
from bytecode.ByteCodeMaker import ByteCodeMaker

from common.Scope import Scope
from common.Types import Type

from common.Color import Color

from Converter import Converter


class ByteCodeVisitor(ShaperVisitor):

    def __init__(self, manager: Manager) -> None:
        self.manager = manager
        self.maker = ByteCodeMaker()
        self.converter = Converter(self.maker)

        self.manager.curr_scope = Scope()
        self.manager.global_scope = self.manager.curr_scope


    
    def generateCode(self, tree):
        
        self.isGlobal = True
        # get global variables
        self.visit(tree)
        self.isGlobal = False

        # enter 'setup'
        if self.manager.setup_func != None:
            self.maker.functionCallStack.append(('setup', self.maker.commandCounter))
            self.maker.CALL(-1, 0)
            self.maker.POP()
        
        #enter 'draw'
        if self.manager.draw_func != None:
            self.maker.CLEAR() # clear window
            self.maker.functionCallStack.append(('draw', self.maker.commandCounter))
            self.maker.CALL(-1, 0) # here we call endless function
            self.maker.POP()   # delete `draw` return from stack 
            self.maker.DISPLAY() # refresh widnow
            self.maker.JMP(-8) # jump to `clear` command
        
        self.maker.HALT() # ends programm

        self.lookSetupFunc()  # generate `setup` body
        self.lookDrawFunc() # generate `draw` body
        self.lookUserDefinedFunc() # generate user functions' bodies

        self.fillFunctionsPosition() # fill function's calls destinations
        self.fillJumpsPosition() # fill jumps (loops and if) destinations

    def lookSetupFunc(self):
        if self.manager.setup_func != None:
            oldScope = self.manager.create_new_scope(False)
            oldFP = self.maker.framePosition
            self.maker.framePosition = 1

            self.manager.setup_func.address = self.maker.bytecodePosition
            self.visit(self.manager.setup_func.ctx)

            self.freeMemory(self.manager.clearScope(oldScope))
            self.maker.framePosition = oldFP

            self.maker.CONST_I(0)
            self.maker.RET()

    def lookDrawFunc(self):
        if self.manager.draw_func != None:
            oldScope = self.manager.create_new_scope(False)
            oldFP = self.maker.framePosition
            self.maker.framePosition = 1

            self.manager.draw_func.address = self.maker.bytecodePosition
            self.visit(self.manager.draw_func.ctx)
            self.freeMemory(self.manager.clearScope(oldScope))  
            self.maker.framePosition = oldFP

            self.maker.CONST_I(0)
            self.maker.RET()

    def lookUserDefinedFunc(self):
        for func in self.manager.user_func.values():
            oldScope = self.manager.create_new_scope(False)
            oldFP = self.maker.framePosition
            self.maker.framePosition = 1

            par_count = len(func.parameters)
            for i in range(par_count):
                param = func.parameters[i]
                var = Variable(param.name, param.type)
                var.address = -par_count + i - 2
                self.manager.addVariable(var)


            func.address = self.maker.bytecodePosition

            self.visit(func.ctx)

            self.freeMemory(self.manager.clearScope(oldScope))
            self.maker.framePosition = oldFP

            self.maker.CONST_I(0)
            self.maker.RET()

    def fillFunctionsPosition(self):
        for functionCall in self.maker.functionCallStack:
            funcAddress = self.manager.getFunctionAddress(functionCall[0])
            
            comm = self.maker.commandsQueue[functionCall[1]]
            comm = (comm[0], funcAddress, comm[2])

            self.maker.commandsQueue[functionCall[1]] = comm
    
    def fillJumpsPosition(self):
        for jump in self.maker.jumpStack:
            comm = self.maker.commandsQueue[jump[0]]
            comm = (comm[0], jump[1])

            self.maker.commandsQueue[jump[0]] = comm

    def redundant_pop(self, var):
        if var.type == Type.LONG or var.type == Type.DOUBLE:
            self.maker.POP2()
        else:
            self.maker.POP()

        var.type = Type.VOID

    
    def freeMemory(self, to_free):
        for var in to_free:
            if var.is_root:
                if var.isGlobal:
                    self.maker.GLOAD(var.address)
                else:
                    self.maker.LOAD(var.address)
                self.maker.FREE()

        for var in to_free:
            if var.address > 0:
                if var.type in [Type.LONG, Type.DOUBLE]:
                    self.maker.POP2()
                else:
                    self.maker.POP()
        


    def convert_single(self, atom):
        if atom.type == Type.FLOAT:
            self.maker.I2F()
        elif atom.type == Type.CHAR:
            self.maker.I2C()
        elif atom.type == Type.SHORT:
            self.maker.I2S()
        elif atom.type == Type.LONG:
            self.maker.I2L()
        elif atom.type == Type.DOUBLE:
            self.maker.I2D()



    def visitProgramm(self, ctx: ShaperParser.ProgrammContext):   
        #file is not empty
        if ctx.externalDeclarationList() != None: 
            #gather global variables
            self.visit(ctx.externalDeclarationList()) 

    def visitExternalDeclarationList(self, ctx: ShaperParser.ExternalDeclarationListContext):
        self.visit(ctx.externalDeclaration())
        # visits other declarations if exists
        if(ctx.externalDeclarationList()):
            self.visit(ctx.externalDeclarationList())

    def visitExternalDeclaration(self, ctx: ShaperParser.ExternalDeclarationContext):
        if ctx.declaration() != None:
            self.visit(ctx.declaration())

    def visitDeclaration(self, ctx: ShaperParser.DeclarationContext):
        if (ctx.initDeclarator() != None): 
            return self.visit(ctx.initDeclarator())

    def visitCompoundStatement(self, ctx: ShaperParser.CompoundStatementContext):
        if ctx.instructionList() != None:
            self.visit(ctx.instructionList())
        


    def visitInstructionList(self, ctx: ShaperParser.InstructionListContext):
        self.visit(ctx.instruction())

        if ctx.instructionList() != None:
            self.visit(ctx.instructionList())
    
    def visitInstruction(self, ctx: ShaperParser.InstructionContext):
        if ctx.declaration() != None:
            self.visit(ctx.declaration())
        else:
            self.visit(ctx.statement())

    def visitInitDeclarator(self, ctx: ShaperParser.InitDeclaratorContext):

        if not self.isGlobal:
                self.maker.CONST_I(0)

        name = ctx.identifier().getText() # gets variable name 
        types = self.visit(ctx.declarationType()) # end type (types if array is one of them)

        var = Variable(name, types[0]) 

        # if array set array item 
        if var.type == Type.ARRAY:
            var.is_root = True # for freeing table memory
            var.array_var = Constant(types[1], None)


        if self.isGlobal:
            if type == Type.LONG or type == Type.DOUBLE:
                var.address = self.maker.getLongMemoryAddress()
            else:
                var.address = self.maker.getIntMemoryAddress()
            var.isGlobal = True
        
        else:
            if type == Type.LONG or type == Type.DOUBLE:
                var.address = self.maker.getLongFrameAddress()
            else:
                var.address = self.maker.getIntFrameAddress()



            if var.type == Type.ARRAY:
                var.address -= 2
            else:
                var.address -= 1

            var.isGlobal = False
        

        if ctx.assignmentExpression() != None:

            right = self.visit(ctx.assignmentExpression())
            
            self.converter.ConvVarToType(right, var.type)


            if self.isGlobal:
                self.maker.GSTORE(var.address)
            else:
                self.maker.STORE(var.address)


        if var.type == Type.ARRAY:
            self.maker.NEWARR() # creates table in global memory

            if self.isGlobal:
                self.maker.GSTORE(var.address)
            else:
                self.maker.STORE(var.address)


        
        self.manager.addVariable(var)
        return var

    def visitDeclarationType(self, ctx: ShaperParser.DeclarationTypeContext) -> Type:
        type_list = []

        if ctx.expression() == None:
            type_list.append(self.visit(ctx.atomicType()))

             
        else: 
            type_list.append(Type.ARRAY)

            # it writes size of array on top of stack
            self.visit(ctx.expression())
              
             
            ret = self.visit(ctx.atomicType())

            type_list.append(ret)

        return type_list

    def visitExpression(self, ctx: ShaperParser.ExpressionContext) -> Variable:
        ret = self.visitChildren(ctx)
        
        # self.redundant_pop(ret)

        return ret

    def visitAssignmentExpression(self, ctx: ShaperParser.AssignmentExpressionContext):
        if ctx.scopeIdentifier() == None:
            ret = self.visit(ctx.logicalORExpression())
            return ret

        else:

            l = self.visit(ctx.scopeIdentifier())
            op = ctx.assignmentOperator().getText()

            if ctx.arrayIndex() != None:

                if op == '=':
                    if l.isGlobal:
                        self.maker.GLOAD(l.address)
                    else:
                        self.maker.LOAD(l.address)

                    self.visit(ctx.arrayIndex())
                    
                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr
                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr index

                    r = self.visit(ctx.assignmentExpression())
                    self.converter.ConvVarToType(r, l.array_var.type)           


                    self.maker.ASTORE_I()

                elif op == '+=':
                    if l.isGlobal:
                        self.maker.GLOAD(l.address)     # addr
                    

                    else:
                        self.maker.LOAD(l.address)     # addr

                    self.visit(ctx.arrayIndex()) # addr index
                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr
                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr index

                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr index addr
                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr index addr index

                    self.maker.ALOAD_I() # addr index addr index val1

                    r = self.visit(ctx.assignmentExpression()) # addr index addr index val1 val2
                    self.converter.ConvVarToType(r, l.array_var.type)

                    if l.array_var.type == Type.FLOAT:
                        self.maker.ADD_F() # addr index addr index val
                    else:
                        self.maker.ADD_I()
                        

                    self.maker.ASTORE_I() # addr index _

                elif op == '-=':
                    if l.isGlobal:
                        self.maker.GLOAD(l.address)     # addr

                    else:
                        self.maker.LOAD(l.address)     # addr

                    self.visit(ctx.arrayIndex()) # addr index

                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr
                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr index

                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr index addr
                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr index addr index

                    self.maker.ALOAD_I() # addr index val1
                    r = self.visit(ctx.assignmentExpression()) # addr index val1 val2
                    self.converter.ConvVarToType(r, l.array_var.type)

                    if l.array_var.type == Type.FLOAT:
                        self.maker.SUB_F() # addr index addr index val
                    else:
                        self.maker.SUB_F()

                    self.maker.ASTORE_I() # _

                elif op == '*=':
                    if l.isGlobal:
                        self.maker.GLOAD(l.address)     # addr

                    else:
                        self.maker.LOAD(l.address)     # addr

                    self.visit(ctx.arrayIndex()) # addr index

                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr
                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr index

                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr index addr
                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr index addr index

                    self.maker.ALOAD_I() # addr index val1
                    r = self.visit(ctx.assignmentExpression()) # addr index val1 val2
                    self.converter.ConvVarToType(r, l.array_var.type)

                    if l.array_var.type == Type.FLOAT:
                        self.maker.MUL_L() # addr index addr index val
                    else:
                        self.maker.MUL_I()

                    self.maker.ASTORE_I() # _

                elif op == '/=':
                    if l.isGlobal:
                        self.maker.GLOAD(l.address)     # addr

                    else:
                        self.maker.LOAD(l.address)     # addr

                    self.visit(ctx.arrayIndex()) # addr index

                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr
                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr index

                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr index addr
                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr index addr index

                    self.maker.ALOAD_I() # addr index val1
                    r = self.visit(ctx.assignmentExpression()) # addr index val1 val2

                    self.converter.ConvVarToType(r, l.array_var.type)

                    if l.array_var.type == Type.FLOAT:
                        self.maker.DIV_F() # addr index addr index val
                    else:
                        self.maker.DIV_I()

                    self.maker.ASTORE_I() # _

                elif op == '%=':
                    if l.isGlobal:
                        self.maker.GLOAD(l.address)     # addr

                    else:
                        self.maker.LOAD(l.address)     # addr

                    self.visit(ctx.arrayIndex()) # addr index

                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr
                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr index

                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr index addr
                    self.maker.LOAD(self.maker.framePosition-2) # addr index addr index addr index

                    self.maker.ALOAD_I() # addr index val1
                    r = self.visit(ctx.assignmentExpression()) # addr index val1 val2
                    self.converter.ConvVarToType(r, l.array_var.type)

                    if l.array_var.type == Type.INT:
                        self.maker.MOD_I() # addr index addr index val


                    self.maker.ASTORE_I() # _


            elif ctx.channelIndex() != None:
                channel = self.visit(ctx.channelIndex())

                if op == '=':
                    r = self.visit(ctx.assignmentExpression())
                    self.converter.ConvVarToType(r, Type.INT)
                    if l.isGlobal:
                        self.maker.GLOAD(l.address)
                        self.maker.STORE_CH(channel)
                        self.maker.GSTORE(l.address)
                    else:
                        self.maker.LOAD(l.address)
                        self.maker.STORE_CH(channel)
                        self.maker.STORE(l.address)

                elif op == '+=':
                    r = self.visit(ctx.assignmentExpression())
                    self.converter.ConvVarToType(r, Type.INT)
                    if l.isGlobal:
                        self.maker.GLOAD(l.address)
                        self.maker.LOAD_CH(channel)
                        self.maker.ADD_I()

                        self.maker.GLOAD(l.address)
                        self.maker.STORE_CH(channel)
                        self.maker.GSTORE(l.address)
                    else:
                        self.maker.LOAD(l.address) 
                        self.maker.LOAD_CH(channel)
                        self.maker.ADD_I()

                        self.maker.LOAD(l.address)
                        self.maker.STORE_CH(channel)
                        self.maker.STORE(l.address)

                elif op == '-=':
                    if l.isGlobal:
                        self.maker.GLOAD(l.address)
                        self.maker.LOAD_CH(channel)
                        r = self.visit(ctx.assignmentExpression())
                        self.converter.ConvVarToType(r, Type.INT)
                        self.maker.SUB_I()

                        self.maker.GLOAD(l.address)
                        self.maker.STORE_CH(channel)
                        self.maker.GSTORE(l.address)
                    else:
                        self.maker.LOAD(l.address) 
                        self.maker.LOAD_CH(channel)
                        r = self.visit(ctx.assignmentExpression())
                        self.converter.ConvVarToType(r, Type.INT)
                        self.maker.SUB_I()

                        self.maker.LOAD(l.address)
                        self.maker.STORE_CH(channel)
                        self.maker.STORE(l.address)

                elif op == '*=':
                    if l.isGlobal:
                        self.maker.GLOAD(l.address)
                        self.maker.LOAD_CH(channel)
                        r = self.visit(ctx.assignmentExpression())
                        self.converter.ConvVarToType(r, Type.INT)
                        self.maker.MUL_I()

                        self.maker.GLOAD(l.address)
                        self.maker.STORE_CH(channel)
                        self.maker.GSTORE(l.address)
                    else:
                        self.maker.LOAD(l.address) 
                        self.maker.LOAD_CH(channel)
                        r = self.visit(ctx.assignmentExpression())
                        self.converter.ConvVarToType(r, Type.INT)
                        self.maker.MUL_I()

                        self.maker.LOAD(l.address)
                        self.maker.STORE_CH(channel)
                        self.maker.STORE(l.address)

                elif op == '/=':
                    if l.isGlobal:
                        self.maker.GLOAD(l.address)
                        self.maker.LOAD_CH(channel)
                        r = self.visit(ctx.assignmentExpression())
                        self.converter.ConvVarToType(r, Type.INT)
                        self.maker.DIV_I()

                        self.maker.GLOAD(l.address)
                        self.maker.STORE_CH(channel)
                        self.maker.GSTORE(l.address)
                    else:
                        self.maker.LOAD(l.address) 
                        self.maker.LOAD_CH(channel)
                        r = self.visit(ctx.assignmentExpression())
                        self.converter.ConvVarToType(r, Type.INT)
                        self.maker.DIV_I()

                        self.maker.LOAD(l.address)
                        self.maker.STORE_CH(channel)
                        self.maker.STORE(l.address)
                elif op == '%=':
                    if l.isGlobal:
                        self.maker.GLOAD(l.address)
                        self.maker.LOAD_CH(channel)
                        r = self.visit(ctx.assignmentExpression())
                        self.converter.ConvVarToType(r, Type.INT)
                        self.maker.MOD_I()

                        self.maker.GLOAD(l.address)
                        self.maker.STORE_CH(channel)
                        self.maker.GSTORE(l.address)
                    else:
                        self.maker.LOAD(l.address) 
                        self.maker.LOAD_CH(channel)
                        r = self.visit(ctx.assignmentExpression())
                        self.converter.ConvVarToType(r, Type.INT)
                        self.maker.MOD_I()

                        self.maker.LOAD(l.address)
                        self.maker.STORE_CH(channel)
                        self.maker.STORE(l.address)

            else:
                if op == '=':
                    r = self.visit(ctx.assignmentExpression())
                    if l.isGlobal:
                        self.maker.GSTORE(l.address)
                    else:
                        self.maker.STORE(l.address)

                elif op == '+=':
                    if l.isGlobal:
                        self.maker.GLOAD(l.address) #save left to stack
                        r = self.visit(ctx.assignmentExpression()) # save right value
                        self.converter.ConvVarToType(r, l.type)

                        if l.type == Type.FLOAT:
                            self.maker.ADD_F()
                        else:
                            self.maker.ADD_I()
                        
                        self.maker.GSTORE(l.address)
                    else:
                        self.maker.LOAD(l.address)
                        r = self.visit(ctx.assignmentExpression()) # save right value
                        self.converter.ConvVarToType(r, l.type)

                        if l.type == Type.FLOAT:
                            self.maker.ADD_F()
                        else:
                            self.maker.ADD_I()
                        self.maker.STORE(l.address)

                elif op == '-=':
                    if l.isGlobal:
                        self.maker.GLOAD(l.address) #save left to stack
                        r = self.visit(ctx.assignmentExpression()) # save right value
                        self.converter.ConvVarToType(r, l.type)

                        if l.type == Type.FLOAT:
                            self.maker.SUB_F()
                        else:
                            self.maker.SUB_I()

                        self.maker.GSTORE(l.address)
                    else:
                        self.maker.LOAD(l.address)
                        r = self.visit(ctx.assignmentExpression()) # save right value
                        self.converter.ConvVarToType(r, l.type)

                        if l.type == Type.FLOAT:
                            self.maker.SUB_F()
                        else:
                            self.maker.SUB_I()
                            
                        self.maker.STORE(l.address)

                elif op == '*=':
                    if l.isGlobal:
                        self.maker.GLOAD(l.address) #save left to stack
                        r = self.visit(ctx.assignmentExpression()) # save right value
                        self.converter.ConvVarToType(r, l.type)

                        if l.type == Type.FLOAT:
                            self.maker.MUL_F()
                        else:
                            self.maker.MUL_I()
                            
                        self.maker.GSTORE(l.address)
                    else:
                        self.maker.LOAD(l.address)
                        r = self.visit(ctx.assignmentExpression()) # save right value
                        self.converter.ConvVarToType(r, l.type)

                        if l.type == Type.FLOAT:
                            self.maker.MUL_F()
                        else:
                            self.maker.MUL_I()
                            
                        self.maker.STORE(l.address) 
                elif op == '/=':
                    if l.isGlobal:
                        self.maker.GLOAD(l.address) #save left to stack
                        r = self.visit(ctx.assignmentExpression()) # save right value
                        self.converter.ConvVarToType(r, l.type)

                        if l.type == Type.FLOAT:
                            self.maker.DIV_F()
                        else:
                            self.maker.DIV_I()
                            
                        self.maker.GSTORE(l.address)
                    else:
                        self.maker.LOAD(l.address)
                        r = self.visit(ctx.assignmentExpression()) # save right value
                        self.converter.ConvVarToType(r, l.type)

                        if l.type == Type.FLOAT:
                            self.maker.DIV_F()
                        else:
                            self.maker.DIV_I()
                            
                        self.maker.STORE(l.address)
                elif op == '%=':
                    if l.isGlobal:
                        self.maker.GLOAD(l.address) #save left to stack
                        r = self.visit(ctx.assignmentExpression()) # save right value
                        self.converter.ConvVarToType(r, l.type)

                        if l.type == Type.INT:
                            self.maker.MOD_I()

                            
                        self.maker.GSTORE(l.address)
                    else:
                        self.maker.LOAD(l.address)
                        r = self.visit(ctx.assignmentExpression()) # save right value
                        self.converter.ConvVarToType(r, l.type)

                        if l.type == Type.INT:
                            self.maker.MOD_I()

                        self.maker.STORE(l.address)


            if ctx.arrayIndex() != None:
                self.maker.ALOAD_I()
                return Constant(l.array_var.type, None)


            if l.isGlobal:
                self.maker.GLOAD(l.address)
            else:
                self.maker.LOAD(l.address)
            
            return Constant(l.type, None)


    def visitLogicalORExpression(self, ctx: ShaperParser.LogicalORExpressionContext) -> Variable:
        if ctx.logicalORExpression() == None:
            return self.visit(ctx.logicalANDExpression())
        else:
            l = self.visit(ctx.logicalORExpression())
            r = self.visit(ctx.logicalANDExpression())
            
            self.maker.OR()

            ret = Constant(Type.BOOL, None)

            return ret
            

    def visitLogicalANDExpression(self, ctx: ShaperParser.LogicalANDExpressionContext) -> Variable:
        if ctx.logicalANDExpression() == None:
            return self.visit(ctx.equalityExpression())
        else:
            l = self.visit(ctx.logicalANDExpression())
            r = self.visit(ctx.equalityExpression())

            self.maker.AND()

            ret = Constant(Type.BOOL, None)

            return ret

    def visitEqualityExpression(self, ctx: ShaperParser.EqualityExpressionContext) -> Variable:
        if ctx.equalityExpression() == None:
            return self.visit(ctx.relationalExpression())
        else:
            l = self.visit(ctx.equalityExpression()) # left
            r = self.visit(ctx.relationalExpression()) # right
            op = ctx.equalityOperator().getText()

            self.converter.ConvToBetter(l, r)

            self.maker.EQ()

          #  if op == '==':
                
            if op == '!=':
                self.maker.NEG()    

            return Constant(Type.BOOL,None)


    def visitRelationalExpression(self, ctx: ShaperParser.RelationalExpressionContext) -> Variable:
        if ctx.relationalExpression() == None:
            return self.visit(ctx.additiveExpression())
        else:
            l = self.visit(ctx.relationalExpression()) # left
            r = self.visit(ctx.additiveExpression()) ## right
            op = ctx.relationalOperator().getText()

            self.converter.ConvToBetter(l, r)

            if op == '<':
                self.maker.LT()
            elif op == '>':
                self.maker.GT()
                # self.maker.LE()
                # self.maker.NEG()
            elif op == '<=':
                self.maker.LE()

            elif op == '>=':
                self.maker.GE()
                # self.maker.LT()
                # self.maker.NEG()


            return Constant(Type.BOOL, None)

    def visitAdditiveExpression(self, ctx: ShaperParser.AdditiveExpressionContext) -> Variable:
        if ctx.additiveExpression() == None:
            return self.visit(ctx.multiplicativeExpression())
        else:
            l = self.visit(ctx.additiveExpression())
            r = self.visit(ctx.multiplicativeExpression())
            op = ctx.additiveOperator().getText()

            
            ret_type = Type.INT    
            if r.type == Type.FLOAT or l.type == Type.FLOAT:
                ret_type = Type.FLOAT
            
            self.converter.ConvToBetter(l, r)

            if op == '+':
                if ret_type == Type.FLOAT:
                    self.maker.ADD_F()
                else:
                    self.maker.ADD_I()
            elif op == '-':
                if ret_type == Type.FLOAT:
                    self.maker.SUB_F()
                else:
                    self.maker.SUB_I()


            return Constant(ret_type, None)

    def visitMultiplicativeExpression(self, ctx: ShaperParser.MultiplicativeExpressionContext) -> Variable:
        if ctx.multiplicativeExpression() == None:
            return self.visit(ctx.unaryExpression())
        else:

            l = self.visit(ctx.multiplicativeExpression())
            r = self.visit(ctx.unaryExpression())
            op = ctx.multiplicativeOperator().getText()
            

            ret_type = Type.INT    
            if r.type == Type.FLOAT or l.type == Type.FLOAT:
                ret_type = Type.FLOAT
            
            self.converter.ConvToBetter(l, r)

            if op == '*':
                if ret_type == Type.FLOAT:
                    self.maker.MUL_F()
                else:
                    self.maker.MUL_I()
            elif op == '/':
                if ret_type == Type.FLOAT:
                    self.maker.DIV_F()
                else:
                    self.maker.DIV_I()
            elif op == '%':
                self.maker.MOD_I()


            return Constant(ret_type, None)

    def visitUnaryExpression(self, ctx: ShaperParser.UnaryExpressionContext):
        if ctx.postfixExpression() != None:
            return self.visit(ctx.postfixExpression())

        else:
            ret = self.visit(ctx.unaryExpression())
            op = ctx.unaryOperator().getText()

            if op == '-':
                self.maker.CONST_I(-1)

                if ret.type == Type.INT:
                    self.maker.MUL_I()
                elif ret.type == Type.FLOAT:
                    self.converter.ConvVarToType(Constant(Type.INT, None), Type.FLOAT)
                    self.maker.MUL_F();

                return Constant(ret.type, None)
            elif op == '!':
                self.maker.NEG()
                return Constant(ret.type, None)  


            if type(ret) == Variable:  
                if op == '++':
                    if ret.isGlobal:
                        self.maker.CONST_I(1)
                        self.maker.ADD_I()
                        self.maker.GSTORE(ret.address)
                        self.maker.GLOAD(ret.address)
                    else:
                        # self.maker.INC(ret.address)

                        self.maker.CONST_I(1)
                        self.maker.ADD_I()
                        self.maker.STORE(ret.address)
                        self.maker.LOAD(ret.address)
                elif op == '--':
                    if ret.isGlobal:
                        self.maker.CONST_I(1)
                        self.maker.SUB_I()
                        self.maker.GSTORE(ret.address)
                        self.maker.GLOAD(ret.address)
                    else:
                        # self.maker.DEC(ret.address)
                        self.maker.CONST_I(1)
                        self.maker.SUB_I()
                        self.maker.STORE(ret.address)
                        self.maker.LOAD(ret.address)

                return ret
            else: 
                if op == '++':
                        self.maker.CONST_I(1)
                        self.maker.ADD_I()  
                elif op == '--':
                        self.maker.CONST_I(1)
                        self.maker.SUB_I()
                        
                        
                return  Constant(ret.type, None)

    def visitPostfixExpression(self, ctx: ShaperParser.PostfixExpressionContext):
        if ctx.primaryExpression() != None:
            return self.visit(ctx.primaryExpression())

        else:
            ret = self.visit(ctx.postfixExpression())
            
            if type(ret) == Variable:
                if ctx.PLUSPLUS() != None:
                    if ret.isGlobal:
                        self.maker.GLOAD(ret.address)

                        self.maker.CONST_I(1)
                        self.maker.ADD_I()
                        self.maker.GSTORE(ret.address)

                    else:
                        self.maker.INC(ret.address)

                        # self.maker.LOAD(ret.address)
                        # self.maker.CONST_I(1)
                        # self.maker.ADD_I()
                        # self.maker.STORE(ret.address)

                elif ctx.MINUSMINUS() != None:
                    if ret.isGlobal:
                        self.maker.GLOAD(ret.address) 

                        self.maker.CONST_I(1)
                        self.maker.SUB_I()
                        self.maker.GSTORE(ret.address)
                    else:
                        self.maker.DEC(ret.address)

                        # self.maker.LOAD(ret.address)
                        # self.maker.CONST_I(1)
                        # self.maker.SUB_I()
                        # self.maker.STORE(ret.address)
            else:
                if ctx.PLUSPLUS() != None:
                    self.maker.CONST_I(1)
                    self.maker.ADD_I()

                elif ctx.MINUSMINUS() != None:

                    self.maker.CONST_I(1)
                    self.maker.SUB_I()

            new_ret = Constant(ret.type, None)

            return new_ret

    def visitPrimaryExpression(self, ctx: ShaperParser.PrimaryExpressionContext):
        if ctx.constant() != None:
            const = self.visit(ctx.constant())
            
            if const.type == Type.COLOR:
                self.maker.CONST_I(int(const.val))
            else:
                self.maker.CONST_I(const.val)



            return const

        elif ctx.channelIndex() != None:
            var = self.visit(ctx.scopeIdentifier())

            if var.isGlobal:
                self.maker.GLOAD(var.address)
            else: 
                self.maker.LOAD(var.address)

            channel = self.visit(ctx.channelIndex())

            self.maker.LOAD_CH(channel)

            return Constant(Type.INT, None)

        elif ctx.arrayIndex() != None:
            var = self.visit(ctx.scopeIdentifier())

            if var.isGlobal:
                self.maker.GLOAD(var.address)
            else: 
                self.maker.LOAD(var.address)

            self.visit(ctx.arrayIndex())

            self.maker.ALOAD_I()

            return var.array_var

        elif ctx.scopeIdentifier() != None: 
            var = self.visit(ctx.scopeIdentifier())
            
            if var.isGlobal:
                self.maker.GLOAD(var.address)
            else: 
                self.maker.LOAD(var.address)

            return var

        
        elif ctx.expression() != None:
            return self.visit(ctx.expression())
        
        elif ctx.functionCall() != None:
            return self.visit(ctx.functionCall())

    def visitFunctionCall(self, ctx: ShaperParser.FunctionCallContext):
        name = self.visit(ctx.identifier())
        params = []
        if ctx.functionParameterList() != None:
            params = self.visit(ctx.functionParameterList())

        if name == "print":
            if params[0].type == Type.FLOAT:
                self.maker.PRINT_F()
            else:
                self.maker.PRINT_I()
            self.maker.CONST_I(0)
            return Constant(Type.VOID, None)
        elif name == "rand":
            self.maker.RANDOM()

            return Constant(Type.INT, None)
        else:
            ret = self.manager.findFunction(name)

            self.maker.functionCallStack.append((name, self.maker.commandCounter))
            self.maker.CALL(-1, len(params))

            return ret
        
    def visitFunctionParameterList(self, ctx: ShaperParser.FunctionParameterListContext):

        if ctx.functionParameterList() != None:
            params = [self.visit(ctx.expression())]
            params += self.visit(ctx.functionParameterList())
            return params
        else:
            return [self.visit(ctx.expression())]


    def visitStatement(self, ctx: ShaperParser.StatementContext):
        if ctx.paintStatement() != None:
            self.visit(ctx.paintStatement())

        elif ctx.compoundStatement() != None:
            oldScope =  self.manager.create_new_scope(True)
            oldFP = self.maker.framePosition
            self.visit(ctx.compoundStatement())


            self.freeMemory(self.manager.clearScope(oldScope))
            self.maker.framePosition = oldFP
        

        elif ctx.expression() != None:
            self.redundant_pop(self.visit(ctx.expression()))

        elif ctx.jumpStatement() != None:
            self.visit(ctx.jumpStatement())

        elif ctx.iterationStatement() != None:
            self.visit(ctx.iterationStatement())

        elif ctx.selectionStatement() != None:
            self.visitSelectionStatement(ctx.selectionStatement())

    def visitPaintStatement(self, ctx: ShaperParser.PaintStatementContext):
        self.visit(ctx.shapeIndicator())

    def visitShapeIndicator(self, ctx: ShaperParser.ShapeIndicatorContext):
        self.visitChildren(ctx)

    def visitLineParameters(self, ctx: ShaperParser.LineParametersContext):
        self.visit(ctx.fromStatement())
        self.visit(ctx.toStatement())

        if(ctx.colorStatement() != None):
            self.visit(ctx.colorStatement())  
        else:
            self.maker.CONST_I(int(Color.WHITE))

        self.maker.LINE()
    
    def visitTriangleParameters(self, ctx: ShaperParser.TriangleParametersContext):
        self.visit(ctx.fromStatement())
        self.visit(ctx.throughStatement())
        self.visit(ctx.toStatement())

        if(ctx.colorStatement() != None):
            self.visit(ctx.colorStatement())  
        else:
            self.maker.CONST_I(int(Color.WHITE))
        
        self.maker.TRIANGLE()

    def visitRectangleParameters(self, ctx: ShaperParser.RectangleParametersContext):
        self.visit(ctx.atStatement())
        self.visit(ctx.ofStatement())

        if(ctx.colorStatement() != None):
            self.visit(ctx.colorStatement())  
        else:
            self.maker.CONST_I(int(Color.WHITE))
        
        self.maker.RECT()

    def visitCircleParameters(self, ctx: ShaperParser.CircleParametersContext): 
        self.visit(ctx.atStatement())
        self.visit(ctx.ofStatement())

        if(ctx.colorStatement() != None):
            self.visit(ctx.colorStatement())  
        else:
            self.maker.CONST_I(int(Color.WHITE))
        
        self.maker.ELIPSE()

    def visitAtStatement(self, ctx: ShaperParser.AtStatementContext):
        self.visitChildren(ctx) 
    
    def visitOfStatement(self, ctx: ShaperParser.OfStatementContext):
        self.visitChildren(ctx)

    def visitFromStatement(self, ctx: ShaperParser.FromStatementContext):
        self.visitChildren(ctx)

    def visitThroughStatement(self, ctx: ShaperParser.ThroughStatementContext):
        self.visitChildren(ctx)

    def visitToStatement(self, ctx: ShaperParser.ToStatementContext):
        self.visitChildren(ctx)

    def visitColorStatement(self, ctx: ShaperParser.ColorStatementContext):
        self.visit(ctx.expression())


    def visitPosSizeParent(self, ctx: ShaperParser.PosSizeParentContext):        
        if ctx.right != None:

            l = self.visit(ctx.left)

            if l.type == Type.FLOAT:
                self.converter.ConvVarToType(l, Type.INT)

            r = self.visit(ctx.right)
            if r.type == Type.FLOAT:
                self.converter.ConvVarToType(r, Type.INT)

        else:
            l = self.visit(ctx.left)

            if l.type == Type.FLOAT:
                self.converter.ConvVarToType(l, Type.INT)

            self.maker.LOAD(self.maker.framePosition-1)





    def visitJumpStatement(self, ctx: ShaperParser.JumpStatementContext):
        if ctx.expression() != None:
            self.visit(ctx.expression())
        else:
            self.maker.CONST_I(0)

        self.maker.RET()

    def visitSelectionStatement(self, ctx: ShaperParser.SelectionStatementContext):
        expressions = ctx.expression()
        compounds = ctx.compoundStatement()

        com_len = len(compounds)
        exp_len = len(expressions)

        # list of points where jumps to end starts (commandPosition nad bytePosition)
        end_jump = []

        # list of tuples of points where jumps to next fragment of if-else
        # clause starts (commandPosition nad bytePosition)
        frag_jump = []

        # the first one is the 'if'
        # the next ones are 'elif'
        for i in range(exp_len):

            # add to jump stack information about jump when to later fill 
            # by it appriopriate command in commandQueue
            #
            # it takes place in second lap and next ones
            if i > 0:
                jmp_start = frag_jump.pop()
                self.maker.jumpStack.append((jmp_start[0], 
                                             self.maker.bytecodePosition - jmp_start[1] - 2))

            # get condition value
            self.visit(expressions[i])

            # add this place as a start point
            frag_jump.append((self.maker.commandCounter, self.maker.bytecodePosition))

            # if false jump to 'elif'/'else'/end of clause
            self.maker.JMPF(-1)

            # make scope for visiting context
            oldScope  =  self.manager.create_new_scope(True)
            oldFP = self.maker.framePosition

            # visit context
            self.visit(compounds[i])

            #restore scope and fp
            self.freeMemory(self.manager.clearScope(oldScope))
            self.maker.framePosition = oldFP


            if com_len > exp_len or i <= exp_len - 2:
                #save this as a source of jump
                end_jump.append((self.maker.commandCounter, self.maker.bytecodePosition))

                #make jump to end of clause
                self.maker.JMP(-1)


            # check next fragment of clause

            
        # here is checked 'else' fragment, firstly we 
        # save this place as a destination 
        # for jump from last section 
        # it takes place whenever 'else' exists
        # or not
        jmp_start = frag_jump.pop()
        self.maker.jumpStack.append((jmp_start[0], 
                                    self.maker.bytecodePosition - jmp_start[1] - 2))

        # if 'true' 'else' exists
        if len(compounds) > len(expressions):
            # make new scope
            oldScope  =  self.manager.create_new_scope(True)
            oldFP = self.maker.framePosition

            # visit context
            self.visit(compounds[-1])

            # restore scope
            self.freeMemory(self.manager.clearScope(oldScope))
            self.maker.framePosition = oldFP

            # end of if-clause
        
        # in this place we must full jumpStack with information
        # to jump here if context of one body from if was visited
        # the last one won't be entered, because jump from there is unnecesary
        while len(end_jump):
            jmp_end = end_jump.pop()
            self.maker.jumpStack.append((jmp_end[0], 
                                         self.maker.bytecodePosition - jmp_end[1] - 2))
        
    def visitIterationStatement(self, ctx: ShaperParser.IterationStatementContext):
        if ctx.whileLoopStatement() != None:
            self.visit(ctx.whileLoopStatement())

        elif ctx.forLoopStatement() != None:
            self.visit(ctx.forLoopStatement())

    def visitWhileLoopStatement(self, ctx: ShaperParser.WhileLoopStatementContext):

        # make new scope
        oldScope  =  self.manager.create_new_scope(True)
        oldFP = self.maker.framePosition

        # get destination to condition jump
        cond_address = self.maker.bytecodePosition

        # check condition
        self.visit(ctx.expression())


        # make jump to end if condition is False:
        end_jump = (self.maker.commandCounter, self.maker.bytecodePosition)

        self.maker.JMPF(-1)


        # visit context
        self.visit(ctx.compoundStatement())

        # restore scope

        curr_address = self.maker.bytecodePosition

        # make jump to start of while
        self.maker.JMP(cond_address - curr_address - 2)

        # add out of while jump to stack 
        self.maker.jumpStack.append((end_jump[0], 
                                     self.maker.bytecodePosition - end_jump[1] - 2))

        self.freeMemory(self.manager.clearScope(oldScope))
        self.maker.framePosition = oldFP


    def visitForLoopStatement(self, ctx: ShaperParser.ForLoopStatementContext):
        # make new scope
        oldScope  =  self.manager.create_new_scope(True)
        oldFP = self.maker.framePosition
        
        #visit init Expression/Declaration
        if ctx.initExpr != None:
            self.redundant_pop(self.visit(ctx.initExpr))
        elif ctx.initDec != None:
            self.visit(ctx.initDec)
        

        # save address to this place for condition jump
        cond_address = self.maker.bytecodePosition


        # check condition
        if ctx.condition != None:
            self.visit(ctx.condition)
        else:
            self.maker.CONST_I(1)

        # make jump to end if condition is False:
        end_jump = (self.maker.commandCounter, self.maker.bytecodePosition)

        self.maker.JMPF(-1)


        # visit 'for' body
        self.visit(ctx.compoundStatement())

        # visit loop Expression
        if ctx.loopExpr != None:
            self.redundant_pop(self.visit(ctx.loopExpr))


        curr_address = self.maker.bytecodePosition
        # make jump to condition
        self.maker.JMP(cond_address - curr_address - 2)

        # add out of for jump to stack 
        self.maker.jumpStack.append((end_jump[0], 
                                     self.maker.bytecodePosition - end_jump[1] - 2))


        # restore scope
        self.freeMemory(self.manager.clearScope(oldScope))
        self.maker.framePosition = oldFP



    def visitScopeIdentifier(self, ctx: ShaperParser.ScopeIdentifierContext):
        name = self.visit(ctx.identifier())
        if ctx.globalScope() != None:
            var = self.manager.global_scope.getVariable(name)
        else: 
            var = self.manager.getVariable(name)
            
        return var

    def visitIdentifier(self, ctx: ShaperParser.IdentifierContext) -> str:
        return ctx.getText()

    def visitConstant(self, ctx: ShaperParser.ConstantContext) -> Constant:
        const = None
        if ctx.integer != None:
            const = Constant(Type.INT, int(ctx.getText()))
            
        elif ctx.floating != None:
            const = Constant(Type.FLOAT, float(ctx.getText()))
        elif ctx.logical != None:
            if ctx.getText() == 'true':
                const = Constant(Type.BOOL, True)
            else:
                const = Constant(Type.BOOL, False)
        elif ctx.color != None:
            const = Constant(Type.COLOR, Color.getColor(ctx.getText()))
        
        return const

    def visitChannelIndex(self, ctx: ShaperParser.ChannelIndexContext):
        channel = ctx.getText()

        if channel == 'R':
            return 3
        elif channel == 'G':
            return 2
        elif channel == 'B':
            return 1
        else:
            return 0

    def visitArrayIndex(self, ctx: ShaperParser.ArrayIndexContext):
        gotVar = self.visit(ctx.expression())
        return gotVar

    
    def visitAtomicType(self, ctx: ShaperParser.AtomicTypeContext):
        return Type.getType(ctx.getText())