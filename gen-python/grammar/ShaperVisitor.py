# Generated from Shaper.g4 by ANTLR 4.9.3
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .ShaperParser import ShaperParser
else:
    from ShaperParser import ShaperParser

# This class defines a complete generic visitor for a parse tree produced by ShaperParser.

class ShaperVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by ShaperParser#programm.
    def visitProgramm(self, ctx:ShaperParser.ProgrammContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#externalDeclaration.
    def visitExternalDeclaration(self, ctx:ShaperParser.ExternalDeclarationContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#functionDefinition.
    def visitFunctionDefinition(self, ctx:ShaperParser.FunctionDefinitionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#functionSpecifier.
    def visitFunctionSpecifier(self, ctx:ShaperParser.FunctionSpecifierContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#typeSpecifier.
    def visitTypeSpecifier(self, ctx:ShaperParser.TypeSpecifierContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#declarator.
    def visitDeclarator(self, ctx:ShaperParser.DeclaratorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#parameterList.
    def visitParameterList(self, ctx:ShaperParser.ParameterListContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#parameterDeclaration.
    def visitParameterDeclaration(self, ctx:ShaperParser.ParameterDeclarationContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#compoundStatement.
    def visitCompoundStatement(self, ctx:ShaperParser.CompoundStatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#declaration.
    def visitDeclaration(self, ctx:ShaperParser.DeclarationContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#declarationSpecifier.
    def visitDeclarationSpecifier(self, ctx:ShaperParser.DeclarationSpecifierContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#declarationType.
    def visitDeclarationType(self, ctx:ShaperParser.DeclarationTypeContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#initDeclarator.
    def visitInitDeclarator(self, ctx:ShaperParser.InitDeclaratorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#structDeclarator.
    def visitStructDeclarator(self, ctx:ShaperParser.StructDeclaratorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#structDeclarationList.
    def visitStructDeclarationList(self, ctx:ShaperParser.StructDeclarationListContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#expression.
    def visitExpression(self, ctx:ShaperParser.ExpressionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#assignmentExpression.
    def visitAssignmentExpression(self, ctx:ShaperParser.AssignmentExpressionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#logicalORExpression.
    def visitLogicalORExpression(self, ctx:ShaperParser.LogicalORExpressionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#logicalANDExpression.
    def visitLogicalANDExpression(self, ctx:ShaperParser.LogicalANDExpressionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#equalityExpression.
    def visitEqualityExpression(self, ctx:ShaperParser.EqualityExpressionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#relationalExpression.
    def visitRelationalExpression(self, ctx:ShaperParser.RelationalExpressionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#additiveExpression.
    def visitAdditiveExpression(self, ctx:ShaperParser.AdditiveExpressionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#multiplicativeExpression.
    def visitMultiplicativeExpression(self, ctx:ShaperParser.MultiplicativeExpressionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#unaryExpression.
    def visitUnaryExpression(self, ctx:ShaperParser.UnaryExpressionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#postfixExpression.
    def visitPostfixExpression(self, ctx:ShaperParser.PostfixExpressionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#primaryExpression.
    def visitPrimaryExpression(self, ctx:ShaperParser.PrimaryExpressionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#functionParameterList.
    def visitFunctionParameterList(self, ctx:ShaperParser.FunctionParameterListContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#assignmentOperator.
    def visitAssignmentOperator(self, ctx:ShaperParser.AssignmentOperatorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#relationalOperator.
    def visitRelationalOperator(self, ctx:ShaperParser.RelationalOperatorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#additiveOperator.
    def visitAdditiveOperator(self, ctx:ShaperParser.AdditiveOperatorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#multiplicativeOperator.
    def visitMultiplicativeOperator(self, ctx:ShaperParser.MultiplicativeOperatorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#unaryOperator.
    def visitUnaryOperator(self, ctx:ShaperParser.UnaryOperatorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#statement.
    def visitStatement(self, ctx:ShaperParser.StatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#paintStatement.
    def visitPaintStatement(self, ctx:ShaperParser.PaintStatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#shapeIndicator.
    def visitShapeIndicator(self, ctx:ShaperParser.ShapeIndicatorContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#lineParameters.
    def visitLineParameters(self, ctx:ShaperParser.LineParametersContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#triangleParameters.
    def visitTriangleParameters(self, ctx:ShaperParser.TriangleParametersContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#rectangleParameters.
    def visitRectangleParameters(self, ctx:ShaperParser.RectangleParametersContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#circleParameters.
    def visitCircleParameters(self, ctx:ShaperParser.CircleParametersContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#atStatement.
    def visitAtStatement(self, ctx:ShaperParser.AtStatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#ofStatement.
    def visitOfStatement(self, ctx:ShaperParser.OfStatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#fromStatement.
    def visitFromStatement(self, ctx:ShaperParser.FromStatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#throughStatement.
    def visitThroughStatement(self, ctx:ShaperParser.ThroughStatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#toStatement.
    def visitToStatement(self, ctx:ShaperParser.ToStatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#colorStatement.
    def visitColorStatement(self, ctx:ShaperParser.ColorStatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#posSizeParent.
    def visitPosSizeParent(self, ctx:ShaperParser.PosSizeParentContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#selectionStatement.
    def visitSelectionStatement(self, ctx:ShaperParser.SelectionStatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#labeledStatement.
    def visitLabeledStatement(self, ctx:ShaperParser.LabeledStatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#iterationStatement.
    def visitIterationStatement(self, ctx:ShaperParser.IterationStatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#jumpStatement.
    def visitJumpStatement(self, ctx:ShaperParser.JumpStatementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#identifier.
    def visitIdentifier(self, ctx:ShaperParser.IdentifierContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by ShaperParser#constant.
    def visitConstant(self, ctx:ShaperParser.ConstantContext):
        return self.visitChildren(ctx)



del ShaperParser