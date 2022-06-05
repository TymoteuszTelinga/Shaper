from distutils.archive_util import make_archive
import imp
from multiprocessing.dummy import Manager
from grammar.ShaperVisitor import ShaperVisitor
from grammar.ShaperParser import ShaperParser

from Atoms import *
from Manager import Manager
from ByteCodeMaker import ByteCodeMaker

from Scope import Scope
from Types import Type

import Color


class ByteCodeVisitor(ShaperVisitor):

    def __init__(self, manager: Manager) -> None:
        self.manager = manager
        self.maker = ByteCodeMaker()

        self.manager.curr_scope = Scope()
        self.manager.global_scope = self.manager.curr_scope

    
    def generateCode(self, tree):
        
        self.isGlobal = True
        # get global variables
        self.visit(tree)
        self.isGlobal = False

        # enter 'setup'
        if self.manager.setup_func != None:
            self.maker.functionCallStack.append(('setup', self.maker.bytecodePosition))
            self.maker.CALL(-1, 0)
        
        if self.manager.draw_func != None:
            self.maker.functionCallStack.append(('draw', self.maker.bytecodePosition))
            self.maker.CALL(-1, 0)
            self.maker.JMP(-1)
        
        self.maker.HALT()

        if self.manager.setup_func != None:
            oldScope = self.manager.createNewScope(False)
            oldFP = self.maker.framePosition
            self.maker.framePosition = 1

            self.manager.setup_func.address = self.maker.bytecodePosition
            self.visit(self.manager.setup_func.ctx)

            self.maker.framePosition = oldFP
            self.manager.curr_scope = oldScope

        if self.manager.draw_func != None:
            print(type(self.manager.draw_func))
            oldScope = self.manager.createNewScope(False)
            oldFP = self.maker.framePosition
            self.maker.framePosition = 1

            self.manager.draw_func.address = self.maker.bytecodePosition
            self.visit(self.manager.draw_func.ctx)
            self.maker.framePosition = oldFP
            self.manager.curr_scope = oldScope

        for func in self.manager.user_func.values():
            oldScope = self.manager.createNewScope(False)
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

            self.maker.framePosition = oldFP
            self.manager.curr_scope = oldScope

        self.fillFunctionsPosition()

    def fillFunctionsPosition(self):
        for functionCall in self.maker.functionCallStack:
            funcAddress = self.manager.getFunctionAddress(functionCall[0])

            comm = self.maker.commandsQueue[functionCall[1]]
            comm = (comm[0], funcAddress, comm[2])

            self.maker.commandsQueue[functionCall[1]] = comm


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
            self.visit(ctx.initDeclarator())

    def visitCompoundStatement(self, ctx: ShaperParser.CompoundStatementContext):
        if ctx.instructionList() != None:
            self.visit(ctx.instructionList())
            
        self.maker.CONST_I(0)
        self.maker.RET()


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
        name = ctx.identifier().getText()
        type = self.visit(ctx.declarationType())
        var = Variable(name, type)



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
            var.isGlobal = True
        

        if ctx.assignmentExpression() != None:
            self.visit(ctx.assignmentExpression())
            if self.isGlobal:
                self.maker.GSTORE(var.address)
            else:
                self.maker.STORE(var.address)
            


        self.manager.addVariable(var)

    def visitExpression(self, ctx: ShaperParser.ExpressionContext) -> Variable:
        return self.visitChildren(ctx)

    def visitAssignmentExpression(self, ctx: ShaperParser.AssignmentExpressionContext):
        if ctx.scopeIdentifier() == None:
           return self.visit(ctx.logicalORExpression())

        else:
            l = self.visit(ctx.scopeIdentifier())
            op = ctx.assignmentOperator().getText()
            
        
            if op == '=':
                self.visit(ctx.assignmentExpression())
                if l.isGlobal:
                    self.maker.GSTORE(l.address)
                else:
                    self.maker.STORE(l.address)

            elif op == '+=':
                if l.isGlobal:
                    self.maker.GLOAD(l.address) #save left to stack
                    self.visit(ctx.assignmentExpression()) # save right value
                    self.maker.ADD_I() # add 
                    self.maker.GSTORE(l.address)
                else:
                    self.maker.LOAD(l.address)
                    self.visit(ctx.assignmentExpression()) # save right value
                    self.maker.ADD_I()
                    self.maker.STORE(l.address)

            elif op == '-=':
                if l.isGlobal:
                    self.maker.GLOAD(l.address) #save left to stack
                    self.visit(ctx.assignmentExpression()) # save right value
                    self.maker.SUB_I() 
                    self.maker.GSTORE(l.address)
                else:
                    self.maker.LOAD(l.address)
                    self.visit(ctx.assignmentExpression()) # save right value
                    self.maker.SUB_I()
                    self.maker.STORE(l.address)

            elif op == '*=':
                if l.isGlobal:
                    self.maker.GLOAD(l.address) #save left to stack
                    self.visit(ctx.assignmentExpression()) # save right value
                    self.maker.MUL_I() 
                    self.maker.GSTORE(l.address)
                else:
                    self.maker.LOAD(l.address)
                    self.visit(ctx.assignmentExpression()) # save right value
                    self.maker.MUL_I()
                    self.maker.STORE(l.address) 
            elif op == '/=':
                if l.isGlobal:
                    self.maker.GLOAD(l.address) #save left to stack
                    self.visit(ctx.assignmentExpression()) # save right value
                    self.maker.DIV_I() 
                    self.maker.GSTORE(l.address)
                else:
                    self.maker.LOAD(l.address)
                    self.visit(ctx.assignmentExpression()) # save right value
                    self.maker.DIV_I()
                    self.maker.STORE(l.address)
            elif op == '%=':
                if l.isGlobal:
                    self.maker.GLOAD(l.address) #save left to stack
                    self.visit(ctx.assignmentExpression()) # save right value
                    self.maker.MOD_I() 
                    self.maker.GSTORE(l.address)
                else:
                    self.maker.LOAD(l.address)
                    self.visit(ctx.assignmentExpression()) # save right value
                    self.maker.MOD_I()
                    self.maker.STORE(l.address)
            
            return l


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
            l = self.visit(ctx.equalityExpression())
            r = self.visit(ctx.relationalExpression())
            op = ctx.equalityOperator().getText()

            self.maker.EQ()

            if op == '==':
                ret = Constant(Type.BOOL, None)

            elif op == '!=':
                self.maker.NEG()    
                ret = Constant(Type.BOOL, None)

            return ret


    def visitRelationalExpression(self, ctx: ShaperParser.RelationalExpressionContext) -> Variable:
        if ctx.relationalExpression() == None:
            return self.visit(ctx.additiveExpression())
        else:
            l = self.visit(ctx.relationalExpression())
            r = self.visit(ctx.additiveExpression())
            op = ctx.relationalOperator().getText()

            if op == '<':
                self.maker.LT()
                ret = Constant(Type.BOOL, None)
            elif op == '>':
                self.maker.GT()
                # self.maker.LT()
                # self.maker.NEG()
                ret = Constant(Type.BOOL, None)
            elif op == '<=':
                self.maker.LE()
                ret = Constant(Type.BOOL, None)
            elif op == '>=':
                self.maker.GE()
                # self.maker.LE()
                # self.maker.NEG()
                ret = Constant(Type.BOOL, None)

            return ret

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
            
            if op == '+':
                self.maker.ADD_I()
                ret = Constant(ret_type, None)
            elif op == '-':
                self.maker.SUB_I()
                ret = Constant(ret_type, None)

            return ret

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
            
            if op == '*':
                self.maker.MUL_I()
                ret = Constant(ret_type, None)
            elif op == '/':
                ret = Constant(ret_type, None)
            elif op == '%':
                ret = Constant(ret_type, None)

            return ret

    def visitUnaryExpression(self, ctx: ShaperParser.UnaryExpressionContext):
        if ctx.postfixExpression() != None:
            return self.visit(ctx.postfixExpression())

        else:
            ret = self.visit(ctx.unaryExpression())
            op = ctx.unaryOperator().getText()

            if op == '-':
                self.maker.CONST_I(-1)
                self.maker.MUL_I()

                new_ret = Constant(ret.type, None)

                return new_ret
            elif op == '!':
                self.maker.NEG()

                new_ret = Constant(ret.type, None)
                return new_ret    


            if type(ret) == Variable:  
                if op == '++':
                    if ret.isGlobal:
                        self.maker.CONST_I(1)
                        self.maker.ADD_I()
                        self.maker.GSTORE(ret.address)
                        self.maker.GLOAD(ret.address)

                        return ret
                    else:
                        # self.maker.INC(ret.address)

                        self.maker.CONST_I(1)
                        self.maker.ADD_I()
                        self.maker.STORE(ret.address)
                        self.maker.LOAD(ret.address)

                        return ret
                elif op == '--':
                    if ret.isGlobal:
                        self.maker.CONST_I(1)
                        self.maker.SUB_I()
                        self.maker.GSTORE(ret.address)
                        self.maker.GLOAD(ret.address)

                        return ret
                    else:
                        # self.maker.DEC(ret.address)

                        self.maker.CONST_I(1)
                        self.maker.ADD_I()
                        self.maker.STORE(ret.address)
                        self.maker.LOAD(ret.address)

                        return ret
            else: 
                if op == '++':
                        self.maker.CONST_I(1)
                        self.maker.ADD_I()

                        new_ret = Constant(ret.type, None)
                        return new_ret    
                elif op == '--':
                        self.maker.CONST_I(1)
                        self.maker.SUB_I()
                        new_ret = Constant(ret.type, None)
                        return new_ret    

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
        if ctx.scopeIdentifier() != None: 
            var = self.visit(ctx.scopeIdentifier())
            
            if var.isGlobal:
                self.maker.GLOAD(var.address)
            else: 
                self.maker.LOAD(var.address)

            return var

        elif ctx.constant() != None:
            const = self.visit(ctx.constant())
            self.maker.CONST_I(int(const.val))
            return const
        
        elif ctx.expression() != None:
            return self.visit(ctx.expression())
        
        elif ctx.functionCall() != None:
            return self.visit(ctx.functionCall())

    def visitFunctionCall(self, ctx: ShaperParser.FunctionCallContext):
        name = self.visit(ctx.identifier())
        params = []
        if ctx.functionParameterList() != None:
            params = self.visit(ctx.functionParameterList())

        self.maker.functionCallStack.append((name, self.maker.bytecodePosition))
        self.maker.CALL(-1, len(params))
        
        return self.manager.findFunction(name)
        
    def visitFunctionParameterList(self, ctx: ShaperParser.FunctionParameterListContext):

        if ctx.functionParameterList() != None:
            params = self.visit(ctx.functionParameterList())
            params.insert(0,self.visit(ctx.expression()))
            return params
        else:
            return [self.visit(ctx.expression())]


    def visitStatement(self, ctx: ShaperParser.StatementContext):
        if ctx.paintStatement() != None:
            self.visit(ctx.paintStatement())

        elif ctx.compoundStatement() != None:
            oldScope =  self.manager.createNewScope(True)
            oldFP = self.maker.framePosition
            self.visit(ctx.compoundStatement())
            self.maker.framePosition = oldFP
            self.manager.curr_scope = oldScope


        elif ctx.expression() != None:
            self.visit(ctx.expression())

        elif ctx.jumpStatement() != None:
            self.visit(ctx.jumpStatement())

        elif ctx.iterationStatement() != None:
            self.visit(ctx.iterationStatement())

        elif ctx.selectionStatement() != None:
            self.visitSelectionStatement(ctx.selectionStatement())


    def visitJumpStatement(self, ctx: ShaperParser.JumpStatementContext):
        if ctx.expression() != None:
            self.visit(ctx.expression())
        else:
            self.maker.CONST_I(0)

        self.maker.RET()


    # def visitSelectionStatement(self, ctx: ShaperParser.SelectionStatementContext):
    #     oldScope  =  self.manager.createNewScope(True)

    #     expressions = ctx.expression()
    #     compounds = ctx.compoundStatement()


    #     for i in range(len(expressions)):
    #         if self.visit(expressions[i]).val == True:
    #             self.visit(compounds[i])
    #             self.manager.curr_scope = oldScope
    #             return;
            

    #     if len(compounds) > len(expressions):
    #         self.visit(compounds[-1])
    #         self.manager.curr_scope = oldScope

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
            const = Constant(Type.COLOR, Color.Color.getColor(ctx.getText()))
        
        return const