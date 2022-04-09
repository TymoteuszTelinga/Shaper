
// Generated from .\Grammar\Shaper.g4 by ANTLR 4.9.3

#pragma once


#include <antlr/antlr4-runtime.h>
#include "ShaperListener.h"


/**
 * This class provides an empty implementation of ShaperListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  ShaperBaseListener : public ShaperListener {
public:

  virtual void enterProgramm(ShaperParser::ProgrammContext * /*ctx*/) override { }
  virtual void exitProgramm(ShaperParser::ProgrammContext * /*ctx*/) override { }

  virtual void enterExternalDeclaration(ShaperParser::ExternalDeclarationContext * /*ctx*/) override { }
  virtual void exitExternalDeclaration(ShaperParser::ExternalDeclarationContext * /*ctx*/) override { }

  virtual void enterFunctionDefinition(ShaperParser::FunctionDefinitionContext * /*ctx*/) override { }
  virtual void exitFunctionDefinition(ShaperParser::FunctionDefinitionContext * /*ctx*/) override { }

  virtual void enterFunctionSpecifier(ShaperParser::FunctionSpecifierContext * /*ctx*/) override { }
  virtual void exitFunctionSpecifier(ShaperParser::FunctionSpecifierContext * /*ctx*/) override { }

  virtual void enterTypeSpecifier(ShaperParser::TypeSpecifierContext * /*ctx*/) override { }
  virtual void exitTypeSpecifier(ShaperParser::TypeSpecifierContext * /*ctx*/) override { }

  virtual void enterDeclarator(ShaperParser::DeclaratorContext * /*ctx*/) override { }
  virtual void exitDeclarator(ShaperParser::DeclaratorContext * /*ctx*/) override { }

  virtual void enterParameterList(ShaperParser::ParameterListContext * /*ctx*/) override { }
  virtual void exitParameterList(ShaperParser::ParameterListContext * /*ctx*/) override { }

  virtual void enterParameterDeclaration(ShaperParser::ParameterDeclarationContext * /*ctx*/) override { }
  virtual void exitParameterDeclaration(ShaperParser::ParameterDeclarationContext * /*ctx*/) override { }

  virtual void enterCompoundStatement(ShaperParser::CompoundStatementContext * /*ctx*/) override { }
  virtual void exitCompoundStatement(ShaperParser::CompoundStatementContext * /*ctx*/) override { }

  virtual void enterDeclaration(ShaperParser::DeclarationContext * /*ctx*/) override { }
  virtual void exitDeclaration(ShaperParser::DeclarationContext * /*ctx*/) override { }

  virtual void enterDeclarationSpecifier(ShaperParser::DeclarationSpecifierContext * /*ctx*/) override { }
  virtual void exitDeclarationSpecifier(ShaperParser::DeclarationSpecifierContext * /*ctx*/) override { }

  virtual void enterDeclarationType(ShaperParser::DeclarationTypeContext * /*ctx*/) override { }
  virtual void exitDeclarationType(ShaperParser::DeclarationTypeContext * /*ctx*/) override { }

  virtual void enterInitDeclarator(ShaperParser::InitDeclaratorContext * /*ctx*/) override { }
  virtual void exitInitDeclarator(ShaperParser::InitDeclaratorContext * /*ctx*/) override { }

  virtual void enterStructDeclarator(ShaperParser::StructDeclaratorContext * /*ctx*/) override { }
  virtual void exitStructDeclarator(ShaperParser::StructDeclaratorContext * /*ctx*/) override { }

  virtual void enterStructDeclarationList(ShaperParser::StructDeclarationListContext * /*ctx*/) override { }
  virtual void exitStructDeclarationList(ShaperParser::StructDeclarationListContext * /*ctx*/) override { }

  virtual void enterExpression(ShaperParser::ExpressionContext * /*ctx*/) override { }
  virtual void exitExpression(ShaperParser::ExpressionContext * /*ctx*/) override { }

  virtual void enterAssignmentExpression(ShaperParser::AssignmentExpressionContext * /*ctx*/) override { }
  virtual void exitAssignmentExpression(ShaperParser::AssignmentExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalORExpression(ShaperParser::LogicalORExpressionContext * /*ctx*/) override { }
  virtual void exitLogicalORExpression(ShaperParser::LogicalORExpressionContext * /*ctx*/) override { }

  virtual void enterLogicalANDExpression(ShaperParser::LogicalANDExpressionContext * /*ctx*/) override { }
  virtual void exitLogicalANDExpression(ShaperParser::LogicalANDExpressionContext * /*ctx*/) override { }

  virtual void enterEqualityExpression(ShaperParser::EqualityExpressionContext * /*ctx*/) override { }
  virtual void exitEqualityExpression(ShaperParser::EqualityExpressionContext * /*ctx*/) override { }

  virtual void enterRelationalExpression(ShaperParser::RelationalExpressionContext * /*ctx*/) override { }
  virtual void exitRelationalExpression(ShaperParser::RelationalExpressionContext * /*ctx*/) override { }

  virtual void enterAdditiveExpression(ShaperParser::AdditiveExpressionContext * /*ctx*/) override { }
  virtual void exitAdditiveExpression(ShaperParser::AdditiveExpressionContext * /*ctx*/) override { }

  virtual void enterMultiplicativeExpression(ShaperParser::MultiplicativeExpressionContext * /*ctx*/) override { }
  virtual void exitMultiplicativeExpression(ShaperParser::MultiplicativeExpressionContext * /*ctx*/) override { }

  virtual void enterUnaryExpression(ShaperParser::UnaryExpressionContext * /*ctx*/) override { }
  virtual void exitUnaryExpression(ShaperParser::UnaryExpressionContext * /*ctx*/) override { }

  virtual void enterPostfixExpression(ShaperParser::PostfixExpressionContext * /*ctx*/) override { }
  virtual void exitPostfixExpression(ShaperParser::PostfixExpressionContext * /*ctx*/) override { }

  virtual void enterPrimaryExpression(ShaperParser::PrimaryExpressionContext * /*ctx*/) override { }
  virtual void exitPrimaryExpression(ShaperParser::PrimaryExpressionContext * /*ctx*/) override { }

  virtual void enterFunctionParameterList(ShaperParser::FunctionParameterListContext * /*ctx*/) override { }
  virtual void exitFunctionParameterList(ShaperParser::FunctionParameterListContext * /*ctx*/) override { }

  virtual void enterAssignmentOperator(ShaperParser::AssignmentOperatorContext * /*ctx*/) override { }
  virtual void exitAssignmentOperator(ShaperParser::AssignmentOperatorContext * /*ctx*/) override { }

  virtual void enterRelationalOperator(ShaperParser::RelationalOperatorContext * /*ctx*/) override { }
  virtual void exitRelationalOperator(ShaperParser::RelationalOperatorContext * /*ctx*/) override { }

  virtual void enterUnaryOperator(ShaperParser::UnaryOperatorContext * /*ctx*/) override { }
  virtual void exitUnaryOperator(ShaperParser::UnaryOperatorContext * /*ctx*/) override { }

  virtual void enterStatement(ShaperParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(ShaperParser::StatementContext * /*ctx*/) override { }

  virtual void enterPaintStatement(ShaperParser::PaintStatementContext * /*ctx*/) override { }
  virtual void exitPaintStatement(ShaperParser::PaintStatementContext * /*ctx*/) override { }

  virtual void enterShapeIndicator(ShaperParser::ShapeIndicatorContext * /*ctx*/) override { }
  virtual void exitShapeIndicator(ShaperParser::ShapeIndicatorContext * /*ctx*/) override { }

  virtual void enterLineParameters(ShaperParser::LineParametersContext * /*ctx*/) override { }
  virtual void exitLineParameters(ShaperParser::LineParametersContext * /*ctx*/) override { }

  virtual void enterTriangleParameters(ShaperParser::TriangleParametersContext * /*ctx*/) override { }
  virtual void exitTriangleParameters(ShaperParser::TriangleParametersContext * /*ctx*/) override { }

  virtual void enterRectangleParameters(ShaperParser::RectangleParametersContext * /*ctx*/) override { }
  virtual void exitRectangleParameters(ShaperParser::RectangleParametersContext * /*ctx*/) override { }

  virtual void enterCircleParameters(ShaperParser::CircleParametersContext * /*ctx*/) override { }
  virtual void exitCircleParameters(ShaperParser::CircleParametersContext * /*ctx*/) override { }

  virtual void enterAtStatement(ShaperParser::AtStatementContext * /*ctx*/) override { }
  virtual void exitAtStatement(ShaperParser::AtStatementContext * /*ctx*/) override { }

  virtual void enterOfStatement(ShaperParser::OfStatementContext * /*ctx*/) override { }
  virtual void exitOfStatement(ShaperParser::OfStatementContext * /*ctx*/) override { }

  virtual void enterFromStatement(ShaperParser::FromStatementContext * /*ctx*/) override { }
  virtual void exitFromStatement(ShaperParser::FromStatementContext * /*ctx*/) override { }

  virtual void enterThroughStatement(ShaperParser::ThroughStatementContext * /*ctx*/) override { }
  virtual void exitThroughStatement(ShaperParser::ThroughStatementContext * /*ctx*/) override { }

  virtual void enterToStatement(ShaperParser::ToStatementContext * /*ctx*/) override { }
  virtual void exitToStatement(ShaperParser::ToStatementContext * /*ctx*/) override { }

  virtual void enterColorStatement(ShaperParser::ColorStatementContext * /*ctx*/) override { }
  virtual void exitColorStatement(ShaperParser::ColorStatementContext * /*ctx*/) override { }

  virtual void enterPosSizeParent(ShaperParser::PosSizeParentContext * /*ctx*/) override { }
  virtual void exitPosSizeParent(ShaperParser::PosSizeParentContext * /*ctx*/) override { }

  virtual void enterSelectionStatement(ShaperParser::SelectionStatementContext * /*ctx*/) override { }
  virtual void exitSelectionStatement(ShaperParser::SelectionStatementContext * /*ctx*/) override { }

  virtual void enterLabeledStatement(ShaperParser::LabeledStatementContext * /*ctx*/) override { }
  virtual void exitLabeledStatement(ShaperParser::LabeledStatementContext * /*ctx*/) override { }

  virtual void enterIterationStatement(ShaperParser::IterationStatementContext * /*ctx*/) override { }
  virtual void exitIterationStatement(ShaperParser::IterationStatementContext * /*ctx*/) override { }

  virtual void enterJumpStatement(ShaperParser::JumpStatementContext * /*ctx*/) override { }
  virtual void exitJumpStatement(ShaperParser::JumpStatementContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

