
// Generated from .\Grammar\Shaper.g4 by ANTLR 4.9.3

#pragma once


#include <antlr/antlr4-runtime.h>
#include "ShaperParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ShaperParser.
 */
class  ShaperVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ShaperParser.
   */
    virtual antlrcpp::Any visitProgramm(ShaperParser::ProgrammContext *context) = 0;

    virtual antlrcpp::Any visitExternalDeclaration(ShaperParser::ExternalDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDefinition(ShaperParser::FunctionDefinitionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionSpecifier(ShaperParser::FunctionSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitTypeSpecifier(ShaperParser::TypeSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitDeclarator(ShaperParser::DeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitParameterList(ShaperParser::ParameterListContext *context) = 0;

    virtual antlrcpp::Any visitParameterDeclaration(ShaperParser::ParameterDeclarationContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(ShaperParser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitDeclaration(ShaperParser::DeclarationContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationSpecifier(ShaperParser::DeclarationSpecifierContext *context) = 0;

    virtual antlrcpp::Any visitDeclarationType(ShaperParser::DeclarationTypeContext *context) = 0;

    virtual antlrcpp::Any visitInitDeclarator(ShaperParser::InitDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclarator(ShaperParser::StructDeclaratorContext *context) = 0;

    virtual antlrcpp::Any visitStructDeclarationList(ShaperParser::StructDeclarationListContext *context) = 0;

    virtual antlrcpp::Any visitExpression(ShaperParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentExpression(ShaperParser::AssignmentExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalORExpression(ShaperParser::LogicalORExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalANDExpression(ShaperParser::LogicalANDExpressionContext *context) = 0;

    virtual antlrcpp::Any visitEqualityExpression(ShaperParser::EqualityExpressionContext *context) = 0;

    virtual antlrcpp::Any visitRelationalExpression(ShaperParser::RelationalExpressionContext *context) = 0;

    virtual antlrcpp::Any visitAdditiveExpression(ShaperParser::AdditiveExpressionContext *context) = 0;

    virtual antlrcpp::Any visitMultiplicativeExpression(ShaperParser::MultiplicativeExpressionContext *context) = 0;

    virtual antlrcpp::Any visitUnaryExpression(ShaperParser::UnaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPostfixExpression(ShaperParser::PostfixExpressionContext *context) = 0;

    virtual antlrcpp::Any visitPrimaryExpression(ShaperParser::PrimaryExpressionContext *context) = 0;

    virtual antlrcpp::Any visitFunctionParameterList(ShaperParser::FunctionParameterListContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentOperator(ShaperParser::AssignmentOperatorContext *context) = 0;

    virtual antlrcpp::Any visitRelationalOperator(ShaperParser::RelationalOperatorContext *context) = 0;

    virtual antlrcpp::Any visitUnaryOperator(ShaperParser::UnaryOperatorContext *context) = 0;

    virtual antlrcpp::Any visitStatement(ShaperParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitPaintStatement(ShaperParser::PaintStatementContext *context) = 0;

    virtual antlrcpp::Any visitShapeIndicator(ShaperParser::ShapeIndicatorContext *context) = 0;

    virtual antlrcpp::Any visitLineParameters(ShaperParser::LineParametersContext *context) = 0;

    virtual antlrcpp::Any visitTriangleParameters(ShaperParser::TriangleParametersContext *context) = 0;

    virtual antlrcpp::Any visitRectangleParameters(ShaperParser::RectangleParametersContext *context) = 0;

    virtual antlrcpp::Any visitCircleParameters(ShaperParser::CircleParametersContext *context) = 0;

    virtual antlrcpp::Any visitAtStatement(ShaperParser::AtStatementContext *context) = 0;

    virtual antlrcpp::Any visitOfStatement(ShaperParser::OfStatementContext *context) = 0;

    virtual antlrcpp::Any visitFromStatement(ShaperParser::FromStatementContext *context) = 0;

    virtual antlrcpp::Any visitThroughStatement(ShaperParser::ThroughStatementContext *context) = 0;

    virtual antlrcpp::Any visitToStatement(ShaperParser::ToStatementContext *context) = 0;

    virtual antlrcpp::Any visitColorStatement(ShaperParser::ColorStatementContext *context) = 0;

    virtual antlrcpp::Any visitPosSizeParent(ShaperParser::PosSizeParentContext *context) = 0;

    virtual antlrcpp::Any visitSelectionStatement(ShaperParser::SelectionStatementContext *context) = 0;

    virtual antlrcpp::Any visitLabeledStatement(ShaperParser::LabeledStatementContext *context) = 0;

    virtual antlrcpp::Any visitIterationStatement(ShaperParser::IterationStatementContext *context) = 0;

    virtual antlrcpp::Any visitJumpStatement(ShaperParser::JumpStatementContext *context) = 0;


};

