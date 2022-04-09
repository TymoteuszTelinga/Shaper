
// Generated from .\Grammar\Shaper.g4 by ANTLR 4.9.3

#pragma once


#include <antlr/antlr4-runtime.h>
#include "ShaperParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by ShaperParser.
 */
class  ShaperListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgramm(ShaperParser::ProgrammContext *ctx) = 0;
  virtual void exitProgramm(ShaperParser::ProgrammContext *ctx) = 0;

  virtual void enterExternalDeclaration(ShaperParser::ExternalDeclarationContext *ctx) = 0;
  virtual void exitExternalDeclaration(ShaperParser::ExternalDeclarationContext *ctx) = 0;

  virtual void enterFunctionDefinition(ShaperParser::FunctionDefinitionContext *ctx) = 0;
  virtual void exitFunctionDefinition(ShaperParser::FunctionDefinitionContext *ctx) = 0;

  virtual void enterFunctionSpecifier(ShaperParser::FunctionSpecifierContext *ctx) = 0;
  virtual void exitFunctionSpecifier(ShaperParser::FunctionSpecifierContext *ctx) = 0;

  virtual void enterTypeSpecifier(ShaperParser::TypeSpecifierContext *ctx) = 0;
  virtual void exitTypeSpecifier(ShaperParser::TypeSpecifierContext *ctx) = 0;

  virtual void enterDeclarator(ShaperParser::DeclaratorContext *ctx) = 0;
  virtual void exitDeclarator(ShaperParser::DeclaratorContext *ctx) = 0;

  virtual void enterParameterList(ShaperParser::ParameterListContext *ctx) = 0;
  virtual void exitParameterList(ShaperParser::ParameterListContext *ctx) = 0;

  virtual void enterParameterDeclaration(ShaperParser::ParameterDeclarationContext *ctx) = 0;
  virtual void exitParameterDeclaration(ShaperParser::ParameterDeclarationContext *ctx) = 0;

  virtual void enterCompoundStatement(ShaperParser::CompoundStatementContext *ctx) = 0;
  virtual void exitCompoundStatement(ShaperParser::CompoundStatementContext *ctx) = 0;

  virtual void enterDeclaration(ShaperParser::DeclarationContext *ctx) = 0;
  virtual void exitDeclaration(ShaperParser::DeclarationContext *ctx) = 0;

  virtual void enterDeclarationSpecifier(ShaperParser::DeclarationSpecifierContext *ctx) = 0;
  virtual void exitDeclarationSpecifier(ShaperParser::DeclarationSpecifierContext *ctx) = 0;

  virtual void enterDeclarationType(ShaperParser::DeclarationTypeContext *ctx) = 0;
  virtual void exitDeclarationType(ShaperParser::DeclarationTypeContext *ctx) = 0;

  virtual void enterInitDeclarator(ShaperParser::InitDeclaratorContext *ctx) = 0;
  virtual void exitInitDeclarator(ShaperParser::InitDeclaratorContext *ctx) = 0;

  virtual void enterStructDeclarator(ShaperParser::StructDeclaratorContext *ctx) = 0;
  virtual void exitStructDeclarator(ShaperParser::StructDeclaratorContext *ctx) = 0;

  virtual void enterStructDeclarationList(ShaperParser::StructDeclarationListContext *ctx) = 0;
  virtual void exitStructDeclarationList(ShaperParser::StructDeclarationListContext *ctx) = 0;

  virtual void enterExpression(ShaperParser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(ShaperParser::ExpressionContext *ctx) = 0;

  virtual void enterAssignmentExpression(ShaperParser::AssignmentExpressionContext *ctx) = 0;
  virtual void exitAssignmentExpression(ShaperParser::AssignmentExpressionContext *ctx) = 0;

  virtual void enterLogicalORExpression(ShaperParser::LogicalORExpressionContext *ctx) = 0;
  virtual void exitLogicalORExpression(ShaperParser::LogicalORExpressionContext *ctx) = 0;

  virtual void enterLogicalANDExpression(ShaperParser::LogicalANDExpressionContext *ctx) = 0;
  virtual void exitLogicalANDExpression(ShaperParser::LogicalANDExpressionContext *ctx) = 0;

  virtual void enterEqualityExpression(ShaperParser::EqualityExpressionContext *ctx) = 0;
  virtual void exitEqualityExpression(ShaperParser::EqualityExpressionContext *ctx) = 0;

  virtual void enterRelationalExpression(ShaperParser::RelationalExpressionContext *ctx) = 0;
  virtual void exitRelationalExpression(ShaperParser::RelationalExpressionContext *ctx) = 0;

  virtual void enterAdditiveExpression(ShaperParser::AdditiveExpressionContext *ctx) = 0;
  virtual void exitAdditiveExpression(ShaperParser::AdditiveExpressionContext *ctx) = 0;

  virtual void enterMultiplicativeExpression(ShaperParser::MultiplicativeExpressionContext *ctx) = 0;
  virtual void exitMultiplicativeExpression(ShaperParser::MultiplicativeExpressionContext *ctx) = 0;

  virtual void enterUnaryExpression(ShaperParser::UnaryExpressionContext *ctx) = 0;
  virtual void exitUnaryExpression(ShaperParser::UnaryExpressionContext *ctx) = 0;

  virtual void enterPostfixExpression(ShaperParser::PostfixExpressionContext *ctx) = 0;
  virtual void exitPostfixExpression(ShaperParser::PostfixExpressionContext *ctx) = 0;

  virtual void enterPrimaryExpression(ShaperParser::PrimaryExpressionContext *ctx) = 0;
  virtual void exitPrimaryExpression(ShaperParser::PrimaryExpressionContext *ctx) = 0;

  virtual void enterFunctionParameterList(ShaperParser::FunctionParameterListContext *ctx) = 0;
  virtual void exitFunctionParameterList(ShaperParser::FunctionParameterListContext *ctx) = 0;

  virtual void enterAssignmentOperator(ShaperParser::AssignmentOperatorContext *ctx) = 0;
  virtual void exitAssignmentOperator(ShaperParser::AssignmentOperatorContext *ctx) = 0;

  virtual void enterRelationalOperator(ShaperParser::RelationalOperatorContext *ctx) = 0;
  virtual void exitRelationalOperator(ShaperParser::RelationalOperatorContext *ctx) = 0;

  virtual void enterUnaryOperator(ShaperParser::UnaryOperatorContext *ctx) = 0;
  virtual void exitUnaryOperator(ShaperParser::UnaryOperatorContext *ctx) = 0;

  virtual void enterStatement(ShaperParser::StatementContext *ctx) = 0;
  virtual void exitStatement(ShaperParser::StatementContext *ctx) = 0;

  virtual void enterPaintStatement(ShaperParser::PaintStatementContext *ctx) = 0;
  virtual void exitPaintStatement(ShaperParser::PaintStatementContext *ctx) = 0;

  virtual void enterShapeIndicator(ShaperParser::ShapeIndicatorContext *ctx) = 0;
  virtual void exitShapeIndicator(ShaperParser::ShapeIndicatorContext *ctx) = 0;

  virtual void enterLineParameters(ShaperParser::LineParametersContext *ctx) = 0;
  virtual void exitLineParameters(ShaperParser::LineParametersContext *ctx) = 0;

  virtual void enterTriangleParameters(ShaperParser::TriangleParametersContext *ctx) = 0;
  virtual void exitTriangleParameters(ShaperParser::TriangleParametersContext *ctx) = 0;

  virtual void enterRectangleParameters(ShaperParser::RectangleParametersContext *ctx) = 0;
  virtual void exitRectangleParameters(ShaperParser::RectangleParametersContext *ctx) = 0;

  virtual void enterCircleParameters(ShaperParser::CircleParametersContext *ctx) = 0;
  virtual void exitCircleParameters(ShaperParser::CircleParametersContext *ctx) = 0;

  virtual void enterAtStatement(ShaperParser::AtStatementContext *ctx) = 0;
  virtual void exitAtStatement(ShaperParser::AtStatementContext *ctx) = 0;

  virtual void enterOfStatement(ShaperParser::OfStatementContext *ctx) = 0;
  virtual void exitOfStatement(ShaperParser::OfStatementContext *ctx) = 0;

  virtual void enterFromStatement(ShaperParser::FromStatementContext *ctx) = 0;
  virtual void exitFromStatement(ShaperParser::FromStatementContext *ctx) = 0;

  virtual void enterThroughStatement(ShaperParser::ThroughStatementContext *ctx) = 0;
  virtual void exitThroughStatement(ShaperParser::ThroughStatementContext *ctx) = 0;

  virtual void enterToStatement(ShaperParser::ToStatementContext *ctx) = 0;
  virtual void exitToStatement(ShaperParser::ToStatementContext *ctx) = 0;

  virtual void enterColorStatement(ShaperParser::ColorStatementContext *ctx) = 0;
  virtual void exitColorStatement(ShaperParser::ColorStatementContext *ctx) = 0;

  virtual void enterPosSizeParent(ShaperParser::PosSizeParentContext *ctx) = 0;
  virtual void exitPosSizeParent(ShaperParser::PosSizeParentContext *ctx) = 0;

  virtual void enterSelectionStatement(ShaperParser::SelectionStatementContext *ctx) = 0;
  virtual void exitSelectionStatement(ShaperParser::SelectionStatementContext *ctx) = 0;

  virtual void enterLabeledStatement(ShaperParser::LabeledStatementContext *ctx) = 0;
  virtual void exitLabeledStatement(ShaperParser::LabeledStatementContext *ctx) = 0;

  virtual void enterIterationStatement(ShaperParser::IterationStatementContext *ctx) = 0;
  virtual void exitIterationStatement(ShaperParser::IterationStatementContext *ctx) = 0;

  virtual void enterJumpStatement(ShaperParser::JumpStatementContext *ctx) = 0;
  virtual void exitJumpStatement(ShaperParser::JumpStatementContext *ctx) = 0;


};

