# Generated from Shaper.g4 by ANTLR 4.9.3
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .ShaperParser import ShaperParser
else:
    from ShaperParser import ShaperParser

# This class defines a complete listener for a parse tree produced by ShaperParser.
class ShaperListener(ParseTreeListener):

    # Enter a parse tree produced by ShaperParser#programm.
    def enterProgramm(self, ctx:ShaperParser.ProgrammContext):
        pass

    # Exit a parse tree produced by ShaperParser#programm.
    def exitProgramm(self, ctx:ShaperParser.ProgrammContext):
        pass


    # Enter a parse tree produced by ShaperParser#externalDeclarationList.
    def enterExternalDeclarationList(self, ctx:ShaperParser.ExternalDeclarationListContext):
        pass

    # Exit a parse tree produced by ShaperParser#externalDeclarationList.
    def exitExternalDeclarationList(self, ctx:ShaperParser.ExternalDeclarationListContext):
        pass


    # Enter a parse tree produced by ShaperParser#externalDeclaration.
    def enterExternalDeclaration(self, ctx:ShaperParser.ExternalDeclarationContext):
        pass

    # Exit a parse tree produced by ShaperParser#externalDeclaration.
    def exitExternalDeclaration(self, ctx:ShaperParser.ExternalDeclarationContext):
        pass


    # Enter a parse tree produced by ShaperParser#functionDefinition.
    def enterFunctionDefinition(self, ctx:ShaperParser.FunctionDefinitionContext):
        pass

    # Exit a parse tree produced by ShaperParser#functionDefinition.
    def exitFunctionDefinition(self, ctx:ShaperParser.FunctionDefinitionContext):
        pass


    # Enter a parse tree produced by ShaperParser#typeSpecifier.
    def enterTypeSpecifier(self, ctx:ShaperParser.TypeSpecifierContext):
        pass

    # Exit a parse tree produced by ShaperParser#typeSpecifier.
    def exitTypeSpecifier(self, ctx:ShaperParser.TypeSpecifierContext):
        pass


    # Enter a parse tree produced by ShaperParser#declarator.
    def enterDeclarator(self, ctx:ShaperParser.DeclaratorContext):
        pass

    # Exit a parse tree produced by ShaperParser#declarator.
    def exitDeclarator(self, ctx:ShaperParser.DeclaratorContext):
        pass


    # Enter a parse tree produced by ShaperParser#parameterList.
    def enterParameterList(self, ctx:ShaperParser.ParameterListContext):
        pass

    # Exit a parse tree produced by ShaperParser#parameterList.
    def exitParameterList(self, ctx:ShaperParser.ParameterListContext):
        pass


    # Enter a parse tree produced by ShaperParser#parameterDeclaration.
    def enterParameterDeclaration(self, ctx:ShaperParser.ParameterDeclarationContext):
        pass

    # Exit a parse tree produced by ShaperParser#parameterDeclaration.
    def exitParameterDeclaration(self, ctx:ShaperParser.ParameterDeclarationContext):
        pass


    # Enter a parse tree produced by ShaperParser#compoundStatement.
    def enterCompoundStatement(self, ctx:ShaperParser.CompoundStatementContext):
        pass

    # Exit a parse tree produced by ShaperParser#compoundStatement.
    def exitCompoundStatement(self, ctx:ShaperParser.CompoundStatementContext):
        pass


    # Enter a parse tree produced by ShaperParser#instructionList.
    def enterInstructionList(self, ctx:ShaperParser.InstructionListContext):
        pass

    # Exit a parse tree produced by ShaperParser#instructionList.
    def exitInstructionList(self, ctx:ShaperParser.InstructionListContext):
        pass


    # Enter a parse tree produced by ShaperParser#instruction.
    def enterInstruction(self, ctx:ShaperParser.InstructionContext):
        pass

    # Exit a parse tree produced by ShaperParser#instruction.
    def exitInstruction(self, ctx:ShaperParser.InstructionContext):
        pass


    # Enter a parse tree produced by ShaperParser#declaration.
    def enterDeclaration(self, ctx:ShaperParser.DeclarationContext):
        pass

    # Exit a parse tree produced by ShaperParser#declaration.
    def exitDeclaration(self, ctx:ShaperParser.DeclarationContext):
        pass


    # Enter a parse tree produced by ShaperParser#initDeclarator.
    def enterInitDeclarator(self, ctx:ShaperParser.InitDeclaratorContext):
        pass

    # Exit a parse tree produced by ShaperParser#initDeclarator.
    def exitInitDeclarator(self, ctx:ShaperParser.InitDeclaratorContext):
        pass


    # Enter a parse tree produced by ShaperParser#declarationType.
    def enterDeclarationType(self, ctx:ShaperParser.DeclarationTypeContext):
        pass

    # Exit a parse tree produced by ShaperParser#declarationType.
    def exitDeclarationType(self, ctx:ShaperParser.DeclarationTypeContext):
        pass


    # Enter a parse tree produced by ShaperParser#structDeclarator.
    def enterStructDeclarator(self, ctx:ShaperParser.StructDeclaratorContext):
        pass

    # Exit a parse tree produced by ShaperParser#structDeclarator.
    def exitStructDeclarator(self, ctx:ShaperParser.StructDeclaratorContext):
        pass


    # Enter a parse tree produced by ShaperParser#structDeclarationList.
    def enterStructDeclarationList(self, ctx:ShaperParser.StructDeclarationListContext):
        pass

    # Exit a parse tree produced by ShaperParser#structDeclarationList.
    def exitStructDeclarationList(self, ctx:ShaperParser.StructDeclarationListContext):
        pass


    # Enter a parse tree produced by ShaperParser#expression.
    def enterExpression(self, ctx:ShaperParser.ExpressionContext):
        pass

    # Exit a parse tree produced by ShaperParser#expression.
    def exitExpression(self, ctx:ShaperParser.ExpressionContext):
        pass


    # Enter a parse tree produced by ShaperParser#assignmentExpression.
    def enterAssignmentExpression(self, ctx:ShaperParser.AssignmentExpressionContext):
        pass

    # Exit a parse tree produced by ShaperParser#assignmentExpression.
    def exitAssignmentExpression(self, ctx:ShaperParser.AssignmentExpressionContext):
        pass


    # Enter a parse tree produced by ShaperParser#logicalORExpression.
    def enterLogicalORExpression(self, ctx:ShaperParser.LogicalORExpressionContext):
        pass

    # Exit a parse tree produced by ShaperParser#logicalORExpression.
    def exitLogicalORExpression(self, ctx:ShaperParser.LogicalORExpressionContext):
        pass


    # Enter a parse tree produced by ShaperParser#logicalANDExpression.
    def enterLogicalANDExpression(self, ctx:ShaperParser.LogicalANDExpressionContext):
        pass

    # Exit a parse tree produced by ShaperParser#logicalANDExpression.
    def exitLogicalANDExpression(self, ctx:ShaperParser.LogicalANDExpressionContext):
        pass


    # Enter a parse tree produced by ShaperParser#equalityExpression.
    def enterEqualityExpression(self, ctx:ShaperParser.EqualityExpressionContext):
        pass

    # Exit a parse tree produced by ShaperParser#equalityExpression.
    def exitEqualityExpression(self, ctx:ShaperParser.EqualityExpressionContext):
        pass


    # Enter a parse tree produced by ShaperParser#relationalExpression.
    def enterRelationalExpression(self, ctx:ShaperParser.RelationalExpressionContext):
        pass

    # Exit a parse tree produced by ShaperParser#relationalExpression.
    def exitRelationalExpression(self, ctx:ShaperParser.RelationalExpressionContext):
        pass


    # Enter a parse tree produced by ShaperParser#additiveExpression.
    def enterAdditiveExpression(self, ctx:ShaperParser.AdditiveExpressionContext):
        pass

    # Exit a parse tree produced by ShaperParser#additiveExpression.
    def exitAdditiveExpression(self, ctx:ShaperParser.AdditiveExpressionContext):
        pass


    # Enter a parse tree produced by ShaperParser#multiplicativeExpression.
    def enterMultiplicativeExpression(self, ctx:ShaperParser.MultiplicativeExpressionContext):
        pass

    # Exit a parse tree produced by ShaperParser#multiplicativeExpression.
    def exitMultiplicativeExpression(self, ctx:ShaperParser.MultiplicativeExpressionContext):
        pass


    # Enter a parse tree produced by ShaperParser#unaryExpression.
    def enterUnaryExpression(self, ctx:ShaperParser.UnaryExpressionContext):
        pass

    # Exit a parse tree produced by ShaperParser#unaryExpression.
    def exitUnaryExpression(self, ctx:ShaperParser.UnaryExpressionContext):
        pass


    # Enter a parse tree produced by ShaperParser#postfixExpression.
    def enterPostfixExpression(self, ctx:ShaperParser.PostfixExpressionContext):
        pass

    # Exit a parse tree produced by ShaperParser#postfixExpression.
    def exitPostfixExpression(self, ctx:ShaperParser.PostfixExpressionContext):
        pass


    # Enter a parse tree produced by ShaperParser#primaryExpression.
    def enterPrimaryExpression(self, ctx:ShaperParser.PrimaryExpressionContext):
        pass

    # Exit a parse tree produced by ShaperParser#primaryExpression.
    def exitPrimaryExpression(self, ctx:ShaperParser.PrimaryExpressionContext):
        pass


    # Enter a parse tree produced by ShaperParser#functionCall.
    def enterFunctionCall(self, ctx:ShaperParser.FunctionCallContext):
        pass

    # Exit a parse tree produced by ShaperParser#functionCall.
    def exitFunctionCall(self, ctx:ShaperParser.FunctionCallContext):
        pass


    # Enter a parse tree produced by ShaperParser#functionParameterList.
    def enterFunctionParameterList(self, ctx:ShaperParser.FunctionParameterListContext):
        pass

    # Exit a parse tree produced by ShaperParser#functionParameterList.
    def exitFunctionParameterList(self, ctx:ShaperParser.FunctionParameterListContext):
        pass


    # Enter a parse tree produced by ShaperParser#assignmentOperator.
    def enterAssignmentOperator(self, ctx:ShaperParser.AssignmentOperatorContext):
        pass

    # Exit a parse tree produced by ShaperParser#assignmentOperator.
    def exitAssignmentOperator(self, ctx:ShaperParser.AssignmentOperatorContext):
        pass


    # Enter a parse tree produced by ShaperParser#equalityOperator.
    def enterEqualityOperator(self, ctx:ShaperParser.EqualityOperatorContext):
        pass

    # Exit a parse tree produced by ShaperParser#equalityOperator.
    def exitEqualityOperator(self, ctx:ShaperParser.EqualityOperatorContext):
        pass


    # Enter a parse tree produced by ShaperParser#relationalOperator.
    def enterRelationalOperator(self, ctx:ShaperParser.RelationalOperatorContext):
        pass

    # Exit a parse tree produced by ShaperParser#relationalOperator.
    def exitRelationalOperator(self, ctx:ShaperParser.RelationalOperatorContext):
        pass


    # Enter a parse tree produced by ShaperParser#additiveOperator.
    def enterAdditiveOperator(self, ctx:ShaperParser.AdditiveOperatorContext):
        pass

    # Exit a parse tree produced by ShaperParser#additiveOperator.
    def exitAdditiveOperator(self, ctx:ShaperParser.AdditiveOperatorContext):
        pass


    # Enter a parse tree produced by ShaperParser#multiplicativeOperator.
    def enterMultiplicativeOperator(self, ctx:ShaperParser.MultiplicativeOperatorContext):
        pass

    # Exit a parse tree produced by ShaperParser#multiplicativeOperator.
    def exitMultiplicativeOperator(self, ctx:ShaperParser.MultiplicativeOperatorContext):
        pass


    # Enter a parse tree produced by ShaperParser#unaryOperator.
    def enterUnaryOperator(self, ctx:ShaperParser.UnaryOperatorContext):
        pass

    # Exit a parse tree produced by ShaperParser#unaryOperator.
    def exitUnaryOperator(self, ctx:ShaperParser.UnaryOperatorContext):
        pass


    # Enter a parse tree produced by ShaperParser#statement.
    def enterStatement(self, ctx:ShaperParser.StatementContext):
        pass

    # Exit a parse tree produced by ShaperParser#statement.
    def exitStatement(self, ctx:ShaperParser.StatementContext):
        pass


    # Enter a parse tree produced by ShaperParser#paintStatement.
    def enterPaintStatement(self, ctx:ShaperParser.PaintStatementContext):
        pass

    # Exit a parse tree produced by ShaperParser#paintStatement.
    def exitPaintStatement(self, ctx:ShaperParser.PaintStatementContext):
        pass


    # Enter a parse tree produced by ShaperParser#shapeIndicator.
    def enterShapeIndicator(self, ctx:ShaperParser.ShapeIndicatorContext):
        pass

    # Exit a parse tree produced by ShaperParser#shapeIndicator.
    def exitShapeIndicator(self, ctx:ShaperParser.ShapeIndicatorContext):
        pass


    # Enter a parse tree produced by ShaperParser#lineParameters.
    def enterLineParameters(self, ctx:ShaperParser.LineParametersContext):
        pass

    # Exit a parse tree produced by ShaperParser#lineParameters.
    def exitLineParameters(self, ctx:ShaperParser.LineParametersContext):
        pass


    # Enter a parse tree produced by ShaperParser#triangleParameters.
    def enterTriangleParameters(self, ctx:ShaperParser.TriangleParametersContext):
        pass

    # Exit a parse tree produced by ShaperParser#triangleParameters.
    def exitTriangleParameters(self, ctx:ShaperParser.TriangleParametersContext):
        pass


    # Enter a parse tree produced by ShaperParser#rectangleParameters.
    def enterRectangleParameters(self, ctx:ShaperParser.RectangleParametersContext):
        pass

    # Exit a parse tree produced by ShaperParser#rectangleParameters.
    def exitRectangleParameters(self, ctx:ShaperParser.RectangleParametersContext):
        pass


    # Enter a parse tree produced by ShaperParser#circleParameters.
    def enterCircleParameters(self, ctx:ShaperParser.CircleParametersContext):
        pass

    # Exit a parse tree produced by ShaperParser#circleParameters.
    def exitCircleParameters(self, ctx:ShaperParser.CircleParametersContext):
        pass


    # Enter a parse tree produced by ShaperParser#atStatement.
    def enterAtStatement(self, ctx:ShaperParser.AtStatementContext):
        pass

    # Exit a parse tree produced by ShaperParser#atStatement.
    def exitAtStatement(self, ctx:ShaperParser.AtStatementContext):
        pass


    # Enter a parse tree produced by ShaperParser#ofStatement.
    def enterOfStatement(self, ctx:ShaperParser.OfStatementContext):
        pass

    # Exit a parse tree produced by ShaperParser#ofStatement.
    def exitOfStatement(self, ctx:ShaperParser.OfStatementContext):
        pass


    # Enter a parse tree produced by ShaperParser#fromStatement.
    def enterFromStatement(self, ctx:ShaperParser.FromStatementContext):
        pass

    # Exit a parse tree produced by ShaperParser#fromStatement.
    def exitFromStatement(self, ctx:ShaperParser.FromStatementContext):
        pass


    # Enter a parse tree produced by ShaperParser#throughStatement.
    def enterThroughStatement(self, ctx:ShaperParser.ThroughStatementContext):
        pass

    # Exit a parse tree produced by ShaperParser#throughStatement.
    def exitThroughStatement(self, ctx:ShaperParser.ThroughStatementContext):
        pass


    # Enter a parse tree produced by ShaperParser#toStatement.
    def enterToStatement(self, ctx:ShaperParser.ToStatementContext):
        pass

    # Exit a parse tree produced by ShaperParser#toStatement.
    def exitToStatement(self, ctx:ShaperParser.ToStatementContext):
        pass


    # Enter a parse tree produced by ShaperParser#colorStatement.
    def enterColorStatement(self, ctx:ShaperParser.ColorStatementContext):
        pass

    # Exit a parse tree produced by ShaperParser#colorStatement.
    def exitColorStatement(self, ctx:ShaperParser.ColorStatementContext):
        pass


    # Enter a parse tree produced by ShaperParser#posSizeParent.
    def enterPosSizeParent(self, ctx:ShaperParser.PosSizeParentContext):
        pass

    # Exit a parse tree produced by ShaperParser#posSizeParent.
    def exitPosSizeParent(self, ctx:ShaperParser.PosSizeParentContext):
        pass


    # Enter a parse tree produced by ShaperParser#selectionStatement.
    def enterSelectionStatement(self, ctx:ShaperParser.SelectionStatementContext):
        pass

    # Exit a parse tree produced by ShaperParser#selectionStatement.
    def exitSelectionStatement(self, ctx:ShaperParser.SelectionStatementContext):
        pass


    # Enter a parse tree produced by ShaperParser#labeledStatement.
    def enterLabeledStatement(self, ctx:ShaperParser.LabeledStatementContext):
        pass

    # Exit a parse tree produced by ShaperParser#labeledStatement.
    def exitLabeledStatement(self, ctx:ShaperParser.LabeledStatementContext):
        pass


    # Enter a parse tree produced by ShaperParser#iterationStatement.
    def enterIterationStatement(self, ctx:ShaperParser.IterationStatementContext):
        pass

    # Exit a parse tree produced by ShaperParser#iterationStatement.
    def exitIterationStatement(self, ctx:ShaperParser.IterationStatementContext):
        pass


    # Enter a parse tree produced by ShaperParser#jumpStatement.
    def enterJumpStatement(self, ctx:ShaperParser.JumpStatementContext):
        pass

    # Exit a parse tree produced by ShaperParser#jumpStatement.
    def exitJumpStatement(self, ctx:ShaperParser.JumpStatementContext):
        pass


    # Enter a parse tree produced by ShaperParser#identifier.
    def enterIdentifier(self, ctx:ShaperParser.IdentifierContext):
        pass

    # Exit a parse tree produced by ShaperParser#identifier.
    def exitIdentifier(self, ctx:ShaperParser.IdentifierContext):
        pass


    # Enter a parse tree produced by ShaperParser#constant.
    def enterConstant(self, ctx:ShaperParser.ConstantContext):
        pass

    # Exit a parse tree produced by ShaperParser#constant.
    def exitConstant(self, ctx:ShaperParser.ConstantContext):
        pass



del ShaperParser