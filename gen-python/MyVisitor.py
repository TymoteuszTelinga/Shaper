from ctypes.wintypes import ATOM
from cv2 import readOpticalFlow

from idna import valid_contextj
from grammar.ShaperVisitor import ShaperVisitor
from grammar.ShaperParser import ShaperParser
from WindowMaker import WindowMaker
import Shapes
import Color
from Types import Type
from Function import Function
from Atoms import Variable, Constant
from Scope import Scope


class MyVisitor(ShaperVisitor):

    def __init__(self) -> None:
        self.window = WindowMaker()
        self.findFunctions = True
        self.funDict = {}
        self.currentScope = Scope() # add start it is global

    def visitProgramm(self, ctx: ShaperParser.ProgrammContext):
        if ctx.externalDeclarationList() != None:
            self.visit(ctx.externalDeclarationList())

        self.findFunctions = False

    def visitExternalDeclarationList(self, ctx: ShaperParser.ExternalDeclarationListContext):
        self.visit(ctx.externalDeclaration())
        # visits other declarations if exists
        if(ctx.externalDeclarationList()):
            self.visit(ctx.externalDeclarationList())

    def visitExternalDeclaration(self, ctx: ShaperParser.ExternalDeclarationContext):
        if self.findFunctions == True: # first tree walking 
            if ctx.functionDefinition() is not None:
                self.visit(ctx.functionDefinition())
        else:
            if ctx.functionDefinition() is not None:
                self.visit(ctx.functionDefinition())
            else:
                self.visit(ctx.declaration())

    def visitFunctionDefinition(self, ctx: ShaperParser.FunctionDefinitionContext):
        if self.findFunctions == True:
            r_type = self.visit(ctx.functionSpecifier())
            name = ctx.identifier().getText()
            f_param = self.visit(ctx.declarator())
            if name not in self.funDict.keys():
                print("success")
                func = Function(name)
                func.setReturnType(r_type)
                func.setParameters(f_param)
                self.funDict[name] = func
            else:
                raise Exception("Ambiguity Error: 2 functions of this same name has been declared") 
        else:
            self.visit(ctx.compoundStatement())

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
            
            par_list.append(var)
            
        return par_list

    def visitParameterDeclaration(self, ctx: ShaperParser.ParameterDeclarationContext):
        name = ctx.identifier().getText()
        type = self.visit(ctx.functionSpecifier())

        var = Variable(name, type)
        return var

    def visitCompoundStatement(self, ctx: ShaperParser.CompoundStatementContext):
        oldScope = self.currentScope
        self.currentScope = Scope()
        self.currentScope.upper = oldScope
        if ctx.instructionList() != None:
            self.visit(ctx.instructionList())
        
        print("Ended scope with variables: " + repr(self.currentScope.variables))
        self.currentScope = oldScope
        print("Current Scope: " + repr(self.currentScope.variables))
    
    def visitInstructionList(self, ctx: ShaperParser.InstructionListContext):
        self.visit(ctx.instruction())

        if ctx.instructionList() != None:
            self.visit(ctx.instructionList())
    
    def visitInstruction(self, ctx: ShaperParser.InstructionContext):
        if ctx.declaration() != None:
            self.visit(ctx.declaration())
        else:
            self.visit(ctx.statement())

    def visitDeclaration(self, ctx: ShaperParser.DeclarationContext):
        if (ctx.structDeclarator() != None):
            return
        else:
            var = self.visit(ctx.initDeclarator())

    def visitInitDeclarator(self, ctx: ShaperParser.InitDeclaratorContext):
        name = ctx.identifier().getText()
        type = self.visit(ctx.declarationSpecifier())
        var = Variable(name, type)

        if not self.currentScope.isAvailable(name):
            raise Exception("Variable \'" + name + "\' defined earlier in this scope")

        if ctx.assignmentExpression() != None:
            r_value = self.visit(ctx.assignmentExpression())
            if var.type == r_value.type:
                var.val = r_value.val;
            else:
                raise Exception(f"Can't use  binary operator \'=\' to type " + repr(var.type) + " and type " + repr(r_value.type))
        
        self.currentScope.addVariable(var)


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
            ret = self.visit(ctx.unaryExpression)
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
            var = self.currentScope.getVariable(name)

            if var == None:
                raise Exception("Variable " + name + "doesn't exist")
            else: 
                return var

        elif ctx.constant() != None:
            return self.visit(ctx.constant())
        
        elif ctx.expression() != None:
            return self.visit(ctx.expression())
        
        elif ctx.functionCall() != None:
            raise Exception("#TODO: functions calling")
        
        raise Exception("(visitPrimaryExpression): It shouldn't be raised")

    def visitStatement(self, ctx: ShaperParser.StatementContext):
        if ctx.paintStatement() != None:
            self.visit(ctx.paintStatement())
        if ctx.compoundStatement() != None:
            self.visit(ctx.compoundStatement())
        if ctx.expression() != None:
            self.visit(ctx.expression())

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

        if type(size) != tuple:
            size = (size,size)

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

        if type(size) != tuple:
            size = (size,size)

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
        exprs = ctx.expression() 
        
        pos_size_tulp = (self.visit(exprs[0]), self.visit(exprs[1]))
        print(pos_size_tulp)
        return pos_size_tulp

    def visitColorStatement(self, ctx: ShaperParser.ColorStatementContext):
        if ctx.constant() != None:
            colorStr = ctx.constant().getText()
            if colorStr == 'BLACK':
                return Color.BLACK
            elif colorStr == 'WHITE':
                return Color.WHITE
            elif colorStr == 'RED':
                return Color.RED
            elif colorStr == 'GREEN':
                return Color.GREEN
            elif colorStr == 'BLUE':
                return Color.BLUE
            else:
                return Color.WHITE
        else:
            return Color.WHITE


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


    


    
    
