
from grammar.ShaperVisitor import ShaperVisitor
from grammar.ShaperParser import ShaperParser
import Shapes
import Color
from Types import Type
from Function import Function
from Atoms import Variable, Constant
from Manager import Manager
from Scope import Scope


class MyVisitor(ShaperVisitor):

    def __init__(self, manager) -> None:
        self.findFunctions = True
        self.globalVars = True
        self.funDict = {}
        self.manager: Manager = manager

    def start(self, tree):
        # restarting state
        self.manager.setVisitor(self)
        self.manager.curr_scope = Scope()
        self.manager.global_scope = self.manager.curr_scope
        self.manager.curr_function = None
        self.manager.return_var = None

        # global variables initializing
        self.visit(tree)

        #running function setup, then draw
        self.manager.start()

    def visitProgramm(self, ctx: ShaperParser.ProgrammContext):   
        #file is not empty
        if ctx.externalDeclarationList() != None: 
            #gather functions
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


    def visitInstructionList(self, ctx: ShaperParser.InstructionListContext):
        self.visit(ctx.instruction())

        if self.manager.return_var != None:
            return

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

        if ctx.assignmentExpression() != None:
            r_value = self.visit(ctx.assignmentExpression())
            var.val = r_value.val;


        self.manager.addVariable(var)



    def visitDeclarationType(self, ctx: ShaperParser.DeclarationTypeContext) -> Type:
        return Type.getType(ctx.getText())
    
    def visitExpression(self, ctx: ShaperParser.ExpressionContext) -> Variable:
        return self.visitChildren(ctx)

    def visitAssignmentExpression(self, ctx: ShaperParser.AssignmentExpressionContext) -> Variable:
        if ctx.unaryExpression() == None:
            return self.visit(ctx.logicalORExpression())
        else:
            l = self.visit(ctx.unaryExpression())
            r = self.visit(ctx.assignmentExpression())
            op = ctx.assignmentOperator().getText()


            if op == '=':
                l.val  =  r.val 
            elif op == '+=':
                l.val += r.val
            elif op == '-=':
                l.val -= r.val  
            elif op == '*=':
                l.val *= r.val  
            elif op == '/=':
                l.val /= r.val 
            elif op == '%=':
                l.val %= r.val 

            return l

        
    def visitLogicalORExpression(self, ctx: ShaperParser.LogicalORExpressionContext) -> Variable:
        if ctx.logicalORExpression() == None:
            return self.visit(ctx.logicalANDExpression())
        else:
            l = self.visit(ctx.logicalORExpression())
            r = self.visit(ctx.logicalANDExpression())
            
            ret = Constant(Type.BOOL, l.val or r.val)

            return ret

    def visitLogicalANDExpression(self, ctx: ShaperParser.LogicalANDExpressionContext) -> Variable:
        if ctx.logicalANDExpression() == None:
            return self.visit(ctx.equalityExpression())
        else:
            l = self.visit(ctx.logicalANDExpression())
            r = self.visit(ctx.equalityExpression())

            ret = Constant(Type.BOOL, l.val and r.val)

            return ret

    def visitEqualityExpression(self, ctx: ShaperParser.EqualityExpressionContext) -> Variable:
        if ctx.equalityExpression() == None:
            return self.visit(ctx.relationalExpression())
        else:
            l = self.visit(ctx.equalityExpression())
            r = self.visit(ctx.relationalExpression())
            op = ctx.equalityOperator().getText()

            if op == '==':
                ret = Constant(Type.BOOL, l.val == r.val)
            elif op == '!=':
                ret = Constant(Type.BOOL, l.val != r.val)

            return ret
    
    def visitRelationalExpression(self, ctx: ShaperParser.RelationalExpressionContext) -> Variable:
        if ctx.relationalExpression() == None:
            return self.visit(ctx.additiveExpression())
        else:
            l = self.visit(ctx.relationalExpression())
            r = self.visit(ctx.additiveExpression())
            op = ctx.relationalOperator().getText()

            if op == '<':
                ret = Constant(Type.BOOL,l.val < r.val)
            elif op == '>':
                ret = Constant(Type.BOOL,l.val > r.val)
            elif op == '<=':
                ret = Constant(Type.BOOL,l.val <= r.val)
            elif op == '>=':
                ret = Constant(Type.BOOL,l.val >= r.val)

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
                ret = Constant(ret_type, l.val + r.val)
            elif op == '/':
                ret = Constant(ret_type, l.val - r.val)


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
                ret = Constant(ret_type, l.val * r.val)
            elif op == '/':
                ret = Constant(ret_type, l.val / r.val)
            elif op == '%':
                ret = Constant(ret_type, l.val % r.val)

            return ret


    def visitUnaryExpression(self, ctx: ShaperParser.UnaryExpressionContext):
        if ctx.postfixExpression() != None:
            return self.visit(ctx.postfixExpression())

        else:
            ret = self.visit(ctx.unaryExpression())
            op = ctx.unaryOperator().getText()

            if  op == '-':
                new_ret = Constant(ret.type, -ret.val)
                return new_ret
            elif op == '!':
                new_ret = Constant(ret.type, not ret.val)
                return new_ret
            elif op == '++':
                ret.val += 1
                return ret
            elif op == '--':
                ret.val -= 1
                return ret

        raise Exception("(visitUnaryExpression): It shouldn't be raised")

    def visitPostfixExpression(self, ctx: ShaperParser.PostfixExpressionContext):
        if ctx.primaryExpression() != None:
            return self.visit(ctx.primaryExpression())

        else:
            ret = self.visit(ctx.postfixExpression())
            
            if ctx.DOT() != None:
                return ret

            elif ctx.PLUSPLUS() != None:
                new_ret = Constant(ret.type, ret.val)
                ret.val += 1
                return new_ret

            elif ctx.MINUSMINUS() != None:
                new_ret = Constant(ret.type, ret.val)
                ret.val -= 1
                return new_ret
        
        raise Exception("(visitPostfixExpression): It shouldn't be raised")

    def visitPrimaryExpression(self, ctx: ShaperParser.PrimaryExpressionContext):
        if ctx.identifier() != None: 
            name = self.visit(ctx.identifier())
            var = self.manager.getVariable(name)

            return var

        elif ctx.constant() != None:
            return self.visit(ctx.constant())
        
        elif ctx.expression() != None:
            return self.visit(ctx.expression())
        
        elif ctx.functionCall() != None:
            return self.visit(ctx.functionCall())
        
        raise Exception("(visitPrimaryExpression): It shouldn't be raised")

    def visitFunctionCall(self, ctx: ShaperParser.FunctionCallContext):
        name = self.visit(ctx.identifier())
        params = []
        if ctx.functionParameterList() != None:
            params = self.visit(ctx.functionParameterList())
        
        return self.manager.enterFunction(name, params)

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

        if ctx.compoundStatement() != None:
            oldScope =  self.manager.createNewScope(True)

            self.visit(ctx.compoundStatement())

            self.manager.curr_scope = oldScope

        if ctx.expression() != None:
            self.visit(ctx.expression())

        if ctx.jumpStatement() != None:
            self.visit(ctx.jumpStatement())

    def visitPaintStatement(self, ctx: ShaperParser.PaintStatementContext):
        self.visit(ctx.shapeIndicator())

    def visitShapeIndicator(self, ctx: ShaperParser.ShapeIndicatorContext):
        self.visitChildren(ctx)

    def visitLineParameters(self, ctx: ShaperParser.LineParametersContext):
        pos1 = self.visit(ctx.fromStatement())
        pos2 = self.visit(ctx.toStatement())

        if(ctx.colorStatement() != None):
            color = self.visit(ctx.colorStatement())  
            line = Shapes.Line(pos1, pos2, color)
        else:
            line = Shapes.Line(pos1, pos2, color)

        line.paint()
    
    def visitTriangleParameters(self, ctx: ShaperParser.TriangleParametersContext):
        pos1 = self.visit(ctx.fromStatement())
        pos2 = self.visit(ctx.throughStatement())
        pos3 = self.visit(ctx.toStatement())

        if(ctx.colorStatement() != None):
            color = self.visit(ctx.colorStatement())  
            trg = Shapes.Triangle(pos1, pos2, pos3, color)
        else:
            trg = Shapes.Triangle(pos1, pos2, pos3)
        
        trg.paint()

    def visitRectangleParameters(self, ctx: ShaperParser.RectangleParametersContext):
        pos = self.visit(ctx.atStatement())
        size = self.visit(ctx.ofStatement())

        if(ctx.colorStatement() != None):
            color = self.visit(ctx.colorStatement())  
            rect = Shapes.Rectangle(pos, size, color)
        else:
            rect = Shapes.Rectangle(pos, size)
        
        rect.paint() 

    def visitCircleParameters(self, ctx: ShaperParser.CircleParametersContext): 
        pos = self.visit(ctx.atStatement())
        size = self.visit(ctx.ofStatement())

        if(ctx.colorStatement() != None):
            color = self.visit(ctx.colorStatement())  
            cir = Shapes.Circle(pos, size, color)
        else:
            cir = Shapes.Circle(pos, size)
        
        cir.paint() 

    def visitAtStatement(self, ctx: ShaperParser.AtStatementContext):
        return self.visitChildren(ctx)

    def visitOfStatement(self, ctx: ShaperParser.OfStatementContext):
        return self.visitChildren(ctx)

    def visitFromStatement(self, ctx: ShaperParser.FromStatementContext):
        return self.visitChildren(ctx)

    def visitThroughStatement(self, ctx: ShaperParser.ThroughStatementContext):
        return self.visitChildren(ctx)

    def visitToStatement(self, ctx: ShaperParser.ToStatementContext):
        return self.visitChildren(ctx)

    def visitColorStatement(self, ctx: ShaperParser.ColorStatementContext):
        if ctx.constant != None:
            const = self.visit(ctx.constant())

            return const
        else:
            name = self.visit(ctx.identifier())
            var = self.manager.getVariable(name)
            
            return var

    def visitPosSizeParent(self, ctx: ShaperParser.PosSizeParentContext):        
        if ctx.right != None:

            pos_size_tulp = (self.visit(ctx.left), self.visit(ctx.right))

        else:
            var = self.visit(ctx.left)
            pos_size_tulp = (var, var)
        
        return pos_size_tulp

        
    def visitJumpStatement(self, ctx: ShaperParser.JumpStatementContext):
        if ctx.expression() != None:
            self.manager.return_var = self.visit(ctx.expression())
        else:   
            self.manager.return_var = Constant(Type.VOID, None)

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