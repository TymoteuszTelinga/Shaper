from msilib.schema import Error
from grammar.ShaperVisitor import ShaperVisitor
from grammar.ShaperParser import ShaperParser
from WindowMaker import WindowMaker
import Shapes
import Color
from Types import Type
from Function import Function
from Variable import Variable
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

        if self.currentScope.isDefined(var):
            raise Exception("Variable \'" + name + "\' defined earlier in this scope")

        if ctx.assignmentExpression() != None:
            r_value = self.visit(ctx.assignmentExpression())
            if var == r_value:
                var.val = r_value.val;
        
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
            l_var = self.visit(ctx.unaryExpression())
            r_var = self.visit(ctx.assignmentExpression())

# TODO checking variable types
            if l_var == r_var:
                op = ctx.assignmentOperator().getText()

                if op == '=':
                    l_var.val =  r_var.val 
                elif op == '+=':
                    l_var.val += r_var.val
                elif op == '-=':
                    l_var.val -= r_var.val   
                elif op == '*=':
                    l_var.val *= r_var.val   
                elif op == '/=':
                    l_var.val /= r_var.val 
                elif op == '%=':
                    l_var.val %= r_var.val 

            return l_var
        
        
    def visitLogicalORExpression(self, ctx: ShaperParser.LogicalORExpressionContext) -> Variable:
        if ctx.logicalORExpression() == None:
            return self.visit(ctx.logicalANDExpression())
        else:
            l_var = self.visit(ctx.logicalORExpression())
            r_var = self.visit(ctx.logicalANDExpression())

            temp_var = Variable("temp", Type.BOOL)
            if l_var == Type.BOOL and r_var == Type.BOOL:
                temp_var.val = l_var.val or r_var.val 

            return temp_var

    def visitLogicalANDExpression(self, ctx: ShaperParser.LogicalANDExpressionContext) -> Variable:
        if ctx.logicalANDExpression() == None:
            return self.visit(ctx.equalityExpression())
        else:
            l_var = self.visit(ctx.logicalANDExpression())
            r_var = self.visit(ctx.equalityExpression())

            temp_var = Variable("temp", Type.BOOL)
            if l_var == Type.BOOL and r_var == Type.BOOL:
                temp_var.val = l_var.val and r_var.val 

            return temp_var
    
    def visitEqualityExpression(self, ctx: ShaperParser.EqualityExpressionContext) -> Variable:
        if ctx.equalityExpression() == None:
            return self.visit(ctx.relationalExpression())
        else:
            l_var = self.visit(ctx.equalityExpression())
            r_var = self.visit(ctx.relationalExpression())

            temp_var = Variable("temp", l_var.type)

            if l_var == r_var:
                op = ctx.equalityOperator().getText()
                if op == '==':
                    temp_var.val = l_var.val == r_var.val 
                elif op == '!=':
                    temp_var.val = l_var.val != r_var.val

            return temp_var
    
    def visitRelationalExpression(self, ctx: ShaperParser.RelationalExpressionContext) -> Variable:
        if ctx.relationalExpression() == None:
            return self.visit(ctx.additiveExpression())
        else:
            l_var = self.visit(ctx.relationalExpression())
            r_var = self.visit(ctx.additiveExpression())

            temp_var = Variable("temp", l_var.type)
            
            if l_var == r_var:
                types = [Type.DOUBLE, Type.FLOAT, Type.INT, Type.LONG]
                if l_var.type in types:
                    op = ctx.relationalOperator().getText()
                    if op == '<':
                        temp_var.val = l_var.val < r_var.val 
                    elif op == '>':
                        temp_var.val = l_var.val > r_var.val 
                    elif op == '<=':
                        temp_var.val = l_var.val <= r_var.val
                    elif op == '>=':
                        temp_var.val = l_var.val >= r_var.val 
                else:
                    raise Exception("Type Error: Incorrect types, it should be one of: " + types)

            return temp_var
    
    def visitAdditiveExpression(self, ctx: ShaperParser.AdditiveExpressionContext) -> Variable:
        if ctx.additiveExpression() == None:
            return self.visit(ctx.multiplicativeExpression())
        else:
            l_var = self.visit(ctx.additiveExpression())
            r_var = self.visit(ctx.multiplicativeExpression())

            temp_var = Variable("temp", l_var.type)
            
            if l_var == r_var:
                op = ctx.additiveOperator().getText()
                if op == '+':
                    temp_var.val = l_var.val + r_var.val 
                elif op == '-':
                    temp_var.val = l_var.val - r_var.val 


            return temp_var
       


    def visitMultiplicativeExpression(self, ctx: ShaperParser.MultiplicativeExpressionContext) -> Variable:
        if ctx.multiplicativeExpression() == None:
            return self.visit(ctx.unaryExpression())
        else:
            l_var = self.visit(ctx.multiplicativeExpression())
            r_var = self.visit(ctx.unaryExpression())

            temp_var = Variable("temp", l_var.type)
            
            if l_var == r_var:
                op = ctx.additiveOperator().getText()
                if op == '*':
                    temp_var.val = l_var.val * r_var.val 
                elif op == '/':
                    temp_var.val = l_var.val / r_var.val 
                elif op == '%':
                    temp_var.val = l_var.val % r_var.val

            return temp_var

    def visitUnaryExpression(self, ctx: ShaperParser.UnaryExpressionContext):
        if ctx.unaryOperator() != None and ctx.unaryOperator().getText() == '-':
            var = self.visit(ctx.unaryExpression())
            var.val *= -1
            return var 

        else:
            return self.visit(ctx.postfixExpression())

    def visitPostfixExpression(self, ctx: ShaperParser.PostfixExpressionContext):
        return self.visit(ctx.primaryExpression())

    def visitPrimaryExpression(self, ctx: ShaperParser.PrimaryExpressionContext):
        if ctx.expression() != None:
            return self.visit(ctx.expression())
        elif ctx.constant() != None:
            var = Variable("temp", Type.INT)
            var.val = int(float(ctx.constant().getText()))
            return var
        elif ctx.identifier() != None:
            name = ctx.identifier().getText()
            var = Variable(name, Type.VOID)
            if self.currentScope.isAvailable(var):
               return self.currentScope.getVariable(name)
            else:
                raise Exception("Variables Error: variable isn't defined")



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


    def visitIdentifier(self, ctx: ShaperParser.IdentifierContext):
        return ctx.getText()

    


    
    
