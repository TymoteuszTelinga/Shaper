from ast import Expression
from grammar.ShaperVisitor import ShaperVisitor
from grammar.ShaperParser import ShaperParser
import Shapes
import Color
from Types import Type
from Function import Function
from Atoms import Variable, Constant
from Manager import Manager


class MyVisitor(ShaperVisitor):

    def __init__(self) -> None:
        self.findFunctions = True
        self.globalVars = True
        self.funDict = {}
        self.manager = Manager(self)

    def visitProgramm(self, ctx: ShaperParser.ProgrammContext):
        if ctx.externalDeclarationList() != None:
            self.visit(ctx.externalDeclarationList())
        
        self.findFunctions = False

        self.visit(ctx.externalDeclarationList())

        self.manager.start()

    def visitExternalDeclarationList(self, ctx: ShaperParser.ExternalDeclarationListContext):
        self.visit(ctx.externalDeclaration())
        # visits other declarations if exists
        if(ctx.externalDeclarationList()):
            self.visit(ctx.externalDeclarationList())

    def visitExternalDeclaration(self, ctx: ShaperParser.ExternalDeclarationContext):
        if self.findFunctions: # first tree walking 
            if ctx.functionDefinition() != None:
                self.visit(ctx.functionDefinition())
        else:
            if ctx.functionDefinition() == None:
                self.visit(ctx.declaration())
            # else:
            #     self.visit(ctx.functionDefinition())

    def visitFunctionDefinition(self, ctx: ShaperParser.FunctionDefinitionContext):
        if self.findFunctions:
            r_type = self.visit(ctx.functionSpecifier())
            name = ctx.identifier().getText()
            f_param = self.visit(ctx.declarator())
            func = Function(name)
            func.setReturnType(r_type)
            func.setParameters(f_param)
            func.ctx = ctx
            self.manager.addFunction(func)
        else:
            return self.visit(ctx.compoundStatement())

    def visitFunctionSpecifier(self, ctx: ShaperParser.FunctionSpecifierContext):
        return self.visit(ctx.typeSpecifier())

    def visitTypeSpecifier(self, ctx: ShaperParser.TypeSpecifierContext):
        return Type.getType(ctx.getText())

    def visitDeclarator(self, ctx: ShaperParser.DeclaratorContext):
        if ctx.parameterList() == None:
            return []
        else:
            return self.visit(ctx.parameterList())

    def visitParameterList(self, ctx: ShaperParser.ParameterListContext):
        var = self.visit(ctx.parameterDeclaration())

        if ctx.parameterList() == None:
            par_list = [var]
        else:
            par_list = self.visit(ctx.parameterList())
            for param in par_list:
                if var.name == param.name:
                    raise Exception("Ambiguity Error: Two or more parameters of this same name in one function")
            
            par_list.insert(0,var)
            
        return par_list

    def visitParameterDeclaration(self, ctx: ShaperParser.ParameterDeclarationContext):
        name = ctx.identifier().getText()
        type = self.visit(ctx.functionSpecifier())

        var = Variable(name, type)
        return var

    def visitCompoundStatement(self, ctx: ShaperParser.CompoundStatementContext):
        if ctx.instructionList() != None:
            return self.visit(ctx.instructionList())
        else:
            return None
    
    def visitInstructionList(self, ctx: ShaperParser.InstructionListContext):
        ret_val = self.visit(ctx.instruction())

        if ret_val != None:
            return ret_val

        if ctx.instructionList() != None:
            ret_val = self.visit(ctx.instructionList())
        
        return ret_val
    
    def visitInstruction(self, ctx: ShaperParser.InstructionContext):
        if ctx.declaration() != None:
            self.visit(ctx.declaration())
            return None
        else:
            return self.visit(ctx.statement())

    def visitDeclaration(self, ctx: ShaperParser.DeclarationContext):
        if (ctx.structDeclarator() != None):
            return
        else:
            var = self.visit(ctx.initDeclarator())

    def visitInitDeclarator(self, ctx: ShaperParser.InitDeclaratorContext):
        name = ctx.identifier().getText()
        type = self.visit(ctx.declarationSpecifier())
        var = Variable(name, type)

        if not self.manager.isVariableAvailable(name):
            raise Exception("Variable \'" + name + "\' defined earlier in this scope")

        if ctx.assignmentExpression() != None:
            r_value = self.visit(ctx.assignmentExpression())
            if var.type == r_value.type:
                var.val = r_value.val;
            else:
                raise Exception(f"Can't use  binary operator \'=\' to type " + repr(var.type) + " and type " + repr(r_value.type))

        self.manager.addVariable(var)


    def visitDeclarationSpecifier(self, ctx: ShaperParser.DeclarationSpecifierContext) -> Type:
        return self.visit(ctx.declarationType())

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

            if(type(l) is Constant):
                raise Exception("Can't assign value to a non-variable atom")

            if l.type != r.type :
                raise Exception(f"Can't use  binary operator \'{op}\' to type " + repr(l.type) + " and type " + repr(r.type))

            if op == '=':
                l.val  =  r.val 
            elif op == '+=':
                if l.type not in [Type.FLOAT, Type.INT]:
                    raise Exception(f"Can't use  assign operator \'{op}\' to type " + repr(l.type))
                else: 
                    l.val += r.val
            elif op == '-=':
                if l.type not in [Type.FLOAT, Type.INT]:
                    raise Exception(f"Can't use  assign operator \'{op}\' to type " + repr(l.type))
                else: 
                    l.val -= r.val  
            elif op == '*=':
                if l.type not in [Type.FLOAT, Type.INT]:
                    raise Exception(f"Can't use  assign operator \'{op}\' to type " + repr(l.type))
                else: 
                    l.val *= r.val  
            elif op == '/=':
                if l.type not in [Type.FLOAT, Type.INT]:
                    raise Exception(f"Can't use  assign operator \'{op}\' to type " + repr(l.type))
                else: 
                    l.val /= r.val 
            elif op == '%=':
                if l.type not in [Type.INT]:
                    raise Exception(f"Can't use  assign operator \'{op}\' to type " + repr(l.type))
                else: 
                    l.val %= r.val 

            return l
        
        raise Exception("(visitAssignmentExpression): It shouldn't be raised")
        
    def visitLogicalORExpression(self, ctx: ShaperParser.LogicalORExpressionContext) -> Variable:
        if ctx.logicalORExpression() == None:
            return self.visit(ctx.logicalANDExpression())
        else:
            l = self.visit(ctx.logicalORExpression())
            r = self.visit(ctx.logicalANDExpression())
            
            if l.type not in [Type.BOOL]:
                raise Exception(f"Can't use  binary operator \'|\' to type " + repr(l.type))
            
            if r.type not in [Type.BOOL]:
                raise Exception(f"Can't use  binary operator \'|\' to type " + repr(r.type))

            ret = Constant(Type.BOOL, l.val or r.val)

            return ret

        raise Exception("(visitLogicalORExpression): It shouldn't be raised")

    def visitLogicalANDExpression(self, ctx: ShaperParser.LogicalANDExpressionContext) -> Variable:
        if ctx.logicalANDExpression() == None:
            return self.visit(ctx.equalityExpression())
        else:
            l = self.visit(ctx.logicalANDExpression())
            r = self.visit(ctx.equalityExpression())
            
            if l.type not in [Type.BOOL]:
                raise Exception(f"Can't use  binary operator \'&\' to type " + repr(l.type))
            
            if r.type not in [Type.BOOL]:
                raise Exception(f"Can't use  binary operator \'&\' to type " + repr(r.type))

            ret = Constant(Type.BOOL, l.val and r.val)

            return ret

        raise Exception("(visitLogicalANDExpression): It shouldn't be raised")
    
    def visitEqualityExpression(self, ctx: ShaperParser.EqualityExpressionContext) -> Variable:
        if ctx.equalityExpression() == None:
            return self.visit(ctx.relationalExpression())
        else:
            l = self.visit(ctx.equalityExpression())
            r = self.visit(ctx.relationalExpression())
            op = ctx.equalityOperator().getText()

            if l.type not in [Type.INT, Type.FLOAT, Type.BOOL, Type.COLOR]:
                raise Exception(f"Can't use  binary operator \'{op}\' to type " + repr(l.type))
            
            if r.type not in [Type.INT, Type.FLOAT, Type.BOOL, Type.COLOR]:
                raise Exception(f"Can't use  binary operator \'{op}\' to type " + repr(r.type))

            if l.type != r.type and (Type.BOOL in [l.type, r.type] or Type.Color in [l.type, r.type]):
                raise Exception(f"Can't use  binary operator \'{op}\' to type " + repr(l.type) + " and type " + repr(r.type))
            
            if op == '==':
                ret = Constant(Type.BOOL, l.val == r.val)
            elif op == '!=':
                ret = Constant(Type.BOOL, l.val != r.val)

            return ret
        
        raise Exception("(visitEqualityExpression): It shouldn't be raised")
    
    def visitRelationalExpression(self, ctx: ShaperParser.RelationalExpressionContext) -> Variable:
        if ctx.relationalExpression() == None:
            return self.visit(ctx.additiveExpression())
        else:
            l = self.visit(ctx.relationalExpression())
            r = self.visit(ctx.additiveExpression())
            op = ctx.relationalOperator().getText()

            if l.type not in [Type.INT, Type.FLOAT]:
                raise Exception(f"Can't use  binary operator \'{op}\' to type " + repr(l.type))
            
            if r.type not in [Type.INT, Type.FLOAT]:
                raise Exception(f"Can't use  binary operator \'{op}\' to type " + repr(r.type))

            if op == '<':
                ret = Constant(Type.BOOL,l.val < r.val)
            elif op == '>':
                ret = Constant(Type.BOOL,l.val > r.val)
            elif op == '<=':
                ret = Constant(Type.BOOL,l.val <= r.val)
            elif op == '>=':
                ret = Constant(Type.BOOL,l.val >= r.val)

            return ret

        raise Exception("(visitRelationalExpression): It shouldn't be raised")
    
    def visitAdditiveExpression(self, ctx: ShaperParser.AdditiveExpressionContext) -> Variable:
        if ctx.additiveExpression() == None:
            return self.visit(ctx.multiplicativeExpression())
        else:
            l = self.visit(ctx.additiveExpression())
            r = self.visit(ctx.multiplicativeExpression())
            op = ctx.additiveOperator().getText()

            if l.type not in [Type.INT, Type.FLOAT]:
                raise Exception(f"Can't use  binary operator \'{op}\' to type " + repr(l.type))
            
            if r.type not in [Type.INT, Type.FLOAT]:
                raise Exception(f"Can't use  binary operator \'{op}\' to type " + repr(r.type))
            
            ret_type = Type.INT    
            if r.type == Type.FLOAT or l.type == Type.FLOAT:
                ret_type = Type.FLOAT
            
            if op == '+':
                ret = Constant(ret_type, l.val + r.val)
            elif op == '/':
                ret = Constant(ret_type, l.val - r.val)


            return ret

        raise Exception("(visitAdditiveExpression): It shouldn't be raised")
       


    def visitMultiplicativeExpression(self, ctx: ShaperParser.MultiplicativeExpressionContext) -> Variable:
        if ctx.multiplicativeExpression() == None:
            return self.visit(ctx.unaryExpression())
        else:

            l = self.visit(ctx.multiplicativeExpression())
            r = self.visit(ctx.unaryExpression())
            op = ctx.multiplicativeOperator().getText()
            
            if l.type not in [Type.INT, Type.FLOAT]:
                raise Exception(f"Can't use  multiplicative operator \'{op}\' to type " + repr(l.type))
            
            if r.type not in [Type.INT, Type.FLOAT]:
                raise Exception(f"Can't use  binary operator \'{op}\' to type " + repr(r.type))

            ret_type = Type.INT    
            if r.type == Type.FLOAT or l.type == Type.FLOAT:
                ret_type = Type.FLOAT
            
            if op == '*':
                ret = Constant(ret_type, l.val * r.val)
            elif op == '/':
                ret = Constant(ret_type, l.val / r.val)
            elif op == '%':
                if ret_type != Type.INT:
                    raise Exception(f"Can't use  binary operator \'{op}\' to type \'float\'" )
                else:
                    ret = Constant(ret_type, l.val % r.val)

            return ret

        raise Exception("(visitMultiplicativeExpression): It shouldn't be raised")

    def visitUnaryExpression(self, ctx: ShaperParser.UnaryExpressionContext):
        if ctx.postfixExpression() != None:
            return self.visit(ctx.postfixExpression())

        else:
            ret = self.visit(ctx.unaryExpression())
            op = ctx.unaryOperator().getText()

            if  op == '-':
                if ret.type not in [Type.INT, Type.FLOAT]:
                    raise Exception("Can't use unary operator \'-\' to type " + repr(ret.type))
                else:
                    new_ret = Constant(ret.type, -ret.val)
                    return new_ret
            elif op == '!':
                if ret.type not in [Type.BOOL]:
                    raise Exception("Can't use unary operator \'!\' to type " + repr(ret.type))
                else:
                    new_ret = Constant(ret.type, not ret.val)
                    return new_ret
            elif op == '++':
                if type(ret) == Constant:
                    raise Exception("Can't use operator \'++\' to a non-variable atom")
                elif ret.type not in [Type.INT, Type.FLOAT]:
                    raise Exception("Can't use operator \'++\' to type " + repr(ret.type))
                else:
                    ret.val += 1
                    return ret
            elif op == '--':
                if type(ret) == Constant:
                    raise Exception("Can't use operator \'--\' to a non-variable atom")
                elif ret.type not in [Type.INT, Type.FLOAT]:
                    raise Exception("Can't use operator \'--\' to type " + repr(ret.type))
                else:
                    ret.val -= 1
                    return ret

        raise Exception("(visitUnaryExpression): It shouldn't be raised")

    def visitPostfixExpression(self, ctx: ShaperParser.PostfixExpressionContext):
        if ctx.primaryExpression() != None:
            return self.visit(ctx.primaryExpression())

        else:
            ret = self.visit(ctx.postfixExpression())

            if type(ret) == Constant:
                if ctx.DOT() != None:
                     raise Exception("Can't use operator \'.\' to a non-variable atom")
                elif ctx.PLUSPLUS() != None:
                     raise Exception("Can't use operator \'++\' to a non-variable atom")
                elif ctx.MINUSMINUS() != None:
                     raise Exception("Can't use operator \'--\' to a non-variable atom")
            
            if ctx.DOT() != None:
                if ret.type in [Type.BOOL, Type.INT, Type.FLOAT, Type.VOID]:
                    raise Exception("Can't use operator \'.\' to type " + repr(ret.type))
                else:
                    return ret

            elif ctx.PLUSPLUS() != None:
                if ret.type not in [Type.INT, Type.FLOAT]:
                    raise Exception("Can't use operator \'++\' to type " + repr(ret.type))
                else:
                    new_ret = Constant(ret.type, ret.val)
                    ret.val += 1
                    return new_ret
            elif ctx.MINUSMINUS() != None:
                if ret.type not in [Type.INT, Type.FLOAT]:
                    raise Exception("Can't use operator \'--\' to type " + repr(ret.type))
                else:
                    new_ret = Constant(ret.type, ret.val)
                    ret.val -= 1
                    return new_ret
        
        raise Exception("(visitPostfixExpression): It shouldn't be raised")

    def visitPrimaryExpression(self, ctx: ShaperParser.PrimaryExpressionContext):
        if ctx.identifier() != None: 
            name = self.visit(ctx.identifier())
            var = self.manager.getVariable(name)

            if var == None:
                raise Exception("Variable " + name + " doesn't exist")
            else: 
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
            return None

        if ctx.compoundStatement() != None:
            oldScope =  self.manager.createNewScope(True)

            ret_val = self.visit(ctx.compoundStatement())

            print("Ended scope with variables: " + repr(self.manager.curr_scope.variables))
            self.manager.curr_scope = oldScope
            print("Current Scope: " + repr(self.manager.curr_scope.variables))

            return ret_val

        if ctx.expression() != None:
            self.visit(ctx.expression())
            return None

        if ctx.jumpStatement() != None:
            return self.visit(ctx.jumpStatement())

    def visitPaintStatement(self, ctx: ShaperParser.PaintStatementContext):
        self.visit(ctx.shapeIndicator())

    def visitShapeIndicator(self, ctx: ShaperParser.ShapeIndicatorContext):
        self.visitChildren(ctx)

    def visitLineParameters(self, ctx: ShaperParser.LineParametersContext):
        print("Line:")

        pos1 = self.visit(ctx.fromStatement())
        pos2 = self.visit(ctx.toStatement())

        if(ctx.colorStatement() != None):
            color = self.visit(ctx.colorStatement())  
            line = Shapes.Line(pos1, pos2, color)
        else:
            line = Shapes.Line(pos1, pos2, color)

        line.paint()
        print("===\n")
    
    def visitTriangleParameters(self, ctx: ShaperParser.TriangleParametersContext):
        print("Triangle:")
        
        pos1 = self.visit(ctx.fromStatement())
        pos2 = self.visit(ctx.throughStatement())
        pos3 = self.visit(ctx.toStatement())

        if(ctx.colorStatement() != None):
            color = self.visit(ctx.colorStatement())  
            trg = Shapes.Triangle(pos1, pos2, pos3, color)
        else:
            trg = Shapes.Triangle(pos1, pos2, pos3)
        
        trg.paint()
        print("===\n")

    def visitRectangleParameters(self, ctx: ShaperParser.RectangleParametersContext):
        print("Rectangle:")
        
        pos = self.visit(ctx.atStatement())
        size = self.visit(ctx.ofStatement())

        if(ctx.colorStatement() != None):
            color = self.visit(ctx.colorStatement())  
            rect = Shapes.Rectangle(pos, size, color)
        else:
            rect = Shapes.Rectangle(pos, size)
        
        rect.paint() 
        print("===\n")

    def visitCircleParameters(self, ctx: ShaperParser.CircleParametersContext):
        print("Circle:")
        
        pos = self.visit(ctx.atStatement())
        size = self.visit(ctx.ofStatement())

        if(ctx.colorStatement() != None):
            color = self.visit(ctx.colorStatement())  
            cir = Shapes.Circle(pos, size, color)
        else:
            cir = Shapes.Circle(pos, size)
        
        cir.paint() 
        print("===\n")

    def visitAtStatement(self, ctx: ShaperParser.AtStatementContext):
        print("pos:")
        return self.visitChildren(ctx)

    def visitFromStatement(self, ctx: ShaperParser.FromStatementContext):
        print("pos1:")
        return self.visitChildren(ctx)

    def visitThroughStatement(self, ctx: ShaperParser.ThroughStatementContext):
        print("pos2:")
        return self.visitChildren(ctx)

    def visitToStatement(self, ctx: ShaperParser.ToStatementContext):
        print("pos3:")
        return self.visitChildren(ctx)

    def visitOfStatement(self, ctx: ShaperParser.OfStatementContext):
        print("size:")
        return self.visitChildren(ctx)

    def visitPosSizeParent(self, ctx: ShaperParser.PosSizeParentContext):        
        if ctx.right != None:

            pos_size_tulp = (self.visit(ctx.left), self.visit(ctx.right))

        else:
            var = self.visit(ctx.left)
            pos_size_tulp = (var, var)
        
        if pos_size_tulp[0].type not in [Type.INT, Type.FLOAT]:
            raise Exception("Incorrect type, expected 'int' or 'float', got " + repr(pos_size_tulp[0].type))

        if pos_size_tulp[1].type not in [Type.INT, Type.FLOAT]:
            raise Exception("Incorrect type, expected 'int' or 'float', got " + repr(pos_size_tulp[0].type))

        print(pos_size_tulp)
        return pos_size_tulp

    def visitColorStatement(self, ctx: ShaperParser.ColorStatementContext):
        if ctx.constant != None:
            const = self.visit(ctx.constant())

            if const.type != Type.COLOR:
                raise Exception("Incorrect type, expected 'color', got " + repr(const.type))

            return const
        else:
            name = self.visit(ctx.identifier())
            var = self.manager.getVariable(name)

            if var == None:
                raise Exception("Variable " + name + " doesn't exist")
            elif var.type != Type.COLOR: 
                raise Exception("Incorrect type, expected 'color', got " + repr(var.type))
            
            return var
        
    def visitJumpStatement(self, ctx: ShaperParser.JumpStatementContext):
        if ctx.expression() != None:
            return self.visit(ctx.expression())
        return None

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