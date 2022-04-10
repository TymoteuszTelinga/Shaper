from grammar.ShaperVisitor import ShaperVisitor
from grammar.ShaperParser import ShaperParser
from WindowMaker import WindowMaker
import Shapes
import Color
from Types import Types


class MyVisitor(ShaperVisitor):

    window = WindowMaker()
    
    def visitProgramm(self, ctx: ShaperParser.ProgrammContext):
        for extDec in ctx.externalDeclaration():
            self.visit(extDec)

    def visitExternalDeclaration(self, ctx: ShaperParser.ExternalDeclarationContext):
        if ctx.functionDefinition is not None:
            self.visit(ctx.functionDefinition())

    def visitFunctionDefinition(self, ctx: ShaperParser.FunctionDefinitionContext):
        
        
        if self.visit(ctx.functionSpecifier()) == Types.VOID and self.visit(ctx.identifier())== 'draw' and self.visit(ctx.declarator()) == 0:
           print("In draw")
           self.window.setContext(self, ctx)


    def visitFunctionSpecifier(self, ctx: ShaperParser.FunctionSpecifierContext):
        return self.visitTypeSpecifier(ctx.typeSpecifier())

    def visitTypeSpecifier(self, ctx: ShaperParser.TypeSpecifierContext):
        if ctx.getText() == 'void':
            return Types.VOID
        else:
            return Types.INT

    def visitIdentifier(self, ctx: ShaperParser.IdentifierContext):
        return ctx.getText()

    def visitDeclarator(self, ctx: ShaperParser.DeclaratorContext):
        if ctx.parameterList() == None:
            return 0
        else:
            return 1

    def visitCompoundStatement(self, ctx: ShaperParser.CompoundStatementContext):
        for st in ctx.statement():
            self.visit(st)

    def visitStatement(self, ctx: ShaperParser.StatementContext):
        if ctx.paintStatement() != None:
            self.visit(ctx.paintStatement())

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
        pass

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

    def visitExpression(self, ctx: ShaperParser.ExpressionContext):
        return self.visitChildren(ctx)

    def visitAssignmentExpression(self, ctx: ShaperParser.AssignmentExpressionContext):
        if ctx.unaryExpression() == None:
            return self.visit(ctx.logicalORExpression())
        
    def visitLogicalORExpression(self, ctx: ShaperParser.LogicalORExpressionContext):
        if ctx.logicalORExpression() == None:
            return self.visit(ctx.logicalANDExpression())

    def visitLogicalANDExpression(self, ctx: ShaperParser.LogicalANDExpressionContext):
        if ctx.logicalANDExpression() == None:
            return self.visit(ctx.equalityExpression())
    
    def visitEqualityExpression(self, ctx: ShaperParser.EqualityExpressionContext):
        if ctx.equalityExpression() == None:
            return self.visit(ctx.relationalExpression())
    
    def visitRelationalExpression(self, ctx: ShaperParser.RelationalExpressionContext):
        if ctx.relationalExpression() == None:
            return self.visit(ctx.additiveExpression())
    
    def visitAdditiveExpression(self, ctx: ShaperParser.AdditiveExpressionContext):
        if ctx.additiveOperator() != None:
            l = self.visit(ctx.additiveExpression())
            r = self.visit(ctx.multiplicativeExpression())

            op = ctx.additiveOperator().getText()

            if op =='+' :
                return l+r;
            elif op =='-':
                return l-r;
        else:
            return self.visit(ctx.multiplicativeExpression())
    
    def visitMultiplicativeExpression(self, ctx: ShaperParser.MultiplicativeExpressionContext):
        if ctx.multiplicativeOperator() != None:
            l = self.visit(ctx.multiplicativeExpression())
            r = self.visit(ctx.unaryExpression())

            op = ctx.multiplicativeOperator().getText()

            if op == '*':
                return l * r
            elif op == '/':
                return l / r
            elif op == '%':
                return l % r;

        else:
            return self.visit(ctx.unaryExpression())

    def visitUnaryExpression(self, ctx: ShaperParser.UnaryExpressionContext):
        if ctx.unaryOperator() != None and ctx.unaryOperator().getText() == '-':
            return (-1) * self.visit(ctx.unaryExpression())

        else:
            return self.visit(ctx.postfixExpression())

    def visitPostfixExpression(self, ctx: ShaperParser.PostfixExpressionContext):
        return self.visit(ctx.primaryExpression())

    def visitPrimaryExpression(self, ctx: ShaperParser.PrimaryExpressionContext):
        if ctx.expression() != None:
            return self.visit(ctx.expression())
        elif ctx.constant() != None:
            return int(float(ctx.constant().getText()))

    


    
    
