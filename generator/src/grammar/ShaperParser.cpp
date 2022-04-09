
// Generated from .\Grammar\Shaper.g4 by ANTLR 4.9.3


#include "ShaperListener.h"
#include "ShaperVisitor.h"

#include "ShaperParser.h"


using namespace antlrcpp;
using namespace antlr4;

ShaperParser::ShaperParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ShaperParser::~ShaperParser() {
  delete _interpreter;
}

std::string ShaperParser::getGrammarFileName() const {
  return "Shaper.g4";
}

const std::vector<std::string>& ShaperParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ShaperParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgrammContext ------------------------------------------------------------------

ShaperParser::ProgrammContext::ProgrammContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ShaperParser::ExternalDeclarationContext *> ShaperParser::ProgrammContext::externalDeclaration() {
  return getRuleContexts<ShaperParser::ExternalDeclarationContext>();
}

ShaperParser::ExternalDeclarationContext* ShaperParser::ProgrammContext::externalDeclaration(size_t i) {
  return getRuleContext<ShaperParser::ExternalDeclarationContext>(i);
}


size_t ShaperParser::ProgrammContext::getRuleIndex() const {
  return ShaperParser::RuleProgramm;
}

void ShaperParser::ProgrammContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgramm(this);
}

void ShaperParser::ProgrammContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgramm(this);
}


antlrcpp::Any ShaperParser::ProgrammContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitProgramm(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::ProgrammContext* ShaperParser::programm() {
  ProgrammContext *_localctx = _tracker.createInstance<ProgrammContext>(_ctx, getState());
  enterRule(_localctx, 0, ShaperParser::RuleProgramm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(99);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ShaperParser::VOID)
      | (1ULL << ShaperParser::BOOL)
      | (1ULL << ShaperParser::INT)
      | (1ULL << ShaperParser::LONG)
      | (1ULL << ShaperParser::CHAR)
      | (1ULL << ShaperParser::FLOAT)
      | (1ULL << ShaperParser::DOUBLE)
      | (1ULL << ShaperParser::COLOR)
      | (1ULL << ShaperParser::STRUCT)
      | (1ULL << ShaperParser::ARRAY)
      | (1ULL << ShaperParser::LIST)
      | (1ULL << ShaperParser::CONST))) != 0)) {
      setState(96);
      externalDeclaration();
      setState(101);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExternalDeclarationContext ------------------------------------------------------------------

ShaperParser::ExternalDeclarationContext::ExternalDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::FunctionDefinitionContext* ShaperParser::ExternalDeclarationContext::functionDefinition() {
  return getRuleContext<ShaperParser::FunctionDefinitionContext>(0);
}

ShaperParser::DeclarationContext* ShaperParser::ExternalDeclarationContext::declaration() {
  return getRuleContext<ShaperParser::DeclarationContext>(0);
}

tree::TerminalNode* ShaperParser::ExternalDeclarationContext::SEMICOLON() {
  return getToken(ShaperParser::SEMICOLON, 0);
}


size_t ShaperParser::ExternalDeclarationContext::getRuleIndex() const {
  return ShaperParser::RuleExternalDeclaration;
}

void ShaperParser::ExternalDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExternalDeclaration(this);
}

void ShaperParser::ExternalDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExternalDeclaration(this);
}


antlrcpp::Any ShaperParser::ExternalDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitExternalDeclaration(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::ExternalDeclarationContext* ShaperParser::externalDeclaration() {
  ExternalDeclarationContext *_localctx = _tracker.createInstance<ExternalDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 2, ShaperParser::RuleExternalDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(106);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(102);
      functionDefinition();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(103);
      declaration();
      setState(104);
      match(ShaperParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDefinitionContext ------------------------------------------------------------------

ShaperParser::FunctionDefinitionContext::FunctionDefinitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::FunctionSpecifierContext* ShaperParser::FunctionDefinitionContext::functionSpecifier() {
  return getRuleContext<ShaperParser::FunctionSpecifierContext>(0);
}

tree::TerminalNode* ShaperParser::FunctionDefinitionContext::Identifier() {
  return getToken(ShaperParser::Identifier, 0);
}

ShaperParser::DeclaratorContext* ShaperParser::FunctionDefinitionContext::declarator() {
  return getRuleContext<ShaperParser::DeclaratorContext>(0);
}

ShaperParser::CompoundStatementContext* ShaperParser::FunctionDefinitionContext::compoundStatement() {
  return getRuleContext<ShaperParser::CompoundStatementContext>(0);
}


size_t ShaperParser::FunctionDefinitionContext::getRuleIndex() const {
  return ShaperParser::RuleFunctionDefinition;
}

void ShaperParser::FunctionDefinitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDefinition(this);
}

void ShaperParser::FunctionDefinitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDefinition(this);
}


antlrcpp::Any ShaperParser::FunctionDefinitionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitFunctionDefinition(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::FunctionDefinitionContext* ShaperParser::functionDefinition() {
  FunctionDefinitionContext *_localctx = _tracker.createInstance<FunctionDefinitionContext>(_ctx, getState());
  enterRule(_localctx, 4, ShaperParser::RuleFunctionDefinition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    functionSpecifier();
    setState(109);
    match(ShaperParser::Identifier);
    setState(110);
    declarator();
    setState(111);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionSpecifierContext ------------------------------------------------------------------

ShaperParser::FunctionSpecifierContext::FunctionSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::TypeSpecifierContext* ShaperParser::FunctionSpecifierContext::typeSpecifier() {
  return getRuleContext<ShaperParser::TypeSpecifierContext>(0);
}

tree::TerminalNode* ShaperParser::FunctionSpecifierContext::CONST() {
  return getToken(ShaperParser::CONST, 0);
}


size_t ShaperParser::FunctionSpecifierContext::getRuleIndex() const {
  return ShaperParser::RuleFunctionSpecifier;
}

void ShaperParser::FunctionSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionSpecifier(this);
}

void ShaperParser::FunctionSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionSpecifier(this);
}


antlrcpp::Any ShaperParser::FunctionSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitFunctionSpecifier(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::FunctionSpecifierContext* ShaperParser::functionSpecifier() {
  FunctionSpecifierContext *_localctx = _tracker.createInstance<FunctionSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 6, ShaperParser::RuleFunctionSpecifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(116);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ShaperParser::VOID:
      case ShaperParser::BOOL:
      case ShaperParser::INT:
      case ShaperParser::LONG:
      case ShaperParser::CHAR:
      case ShaperParser::FLOAT:
      case ShaperParser::DOUBLE:
      case ShaperParser::COLOR:
      case ShaperParser::STRUCT:
      case ShaperParser::ARRAY:
      case ShaperParser::LIST: {
        enterOuterAlt(_localctx, 1);
        setState(113);
        typeSpecifier();
        break;
      }

      case ShaperParser::CONST: {
        enterOuterAlt(_localctx, 2);
        setState(114);
        match(ShaperParser::CONST);
        setState(115);
        typeSpecifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSpecifierContext ------------------------------------------------------------------

ShaperParser::TypeSpecifierContext::TypeSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::TypeSpecifierContext::VOID() {
  return getToken(ShaperParser::VOID, 0);
}

tree::TerminalNode* ShaperParser::TypeSpecifierContext::BOOL() {
  return getToken(ShaperParser::BOOL, 0);
}

tree::TerminalNode* ShaperParser::TypeSpecifierContext::INT() {
  return getToken(ShaperParser::INT, 0);
}

tree::TerminalNode* ShaperParser::TypeSpecifierContext::LONG() {
  return getToken(ShaperParser::LONG, 0);
}

tree::TerminalNode* ShaperParser::TypeSpecifierContext::CHAR() {
  return getToken(ShaperParser::CHAR, 0);
}

tree::TerminalNode* ShaperParser::TypeSpecifierContext::FLOAT() {
  return getToken(ShaperParser::FLOAT, 0);
}

tree::TerminalNode* ShaperParser::TypeSpecifierContext::DOUBLE() {
  return getToken(ShaperParser::DOUBLE, 0);
}

tree::TerminalNode* ShaperParser::TypeSpecifierContext::COLOR() {
  return getToken(ShaperParser::COLOR, 0);
}

tree::TerminalNode* ShaperParser::TypeSpecifierContext::STRUCT() {
  return getToken(ShaperParser::STRUCT, 0);
}

tree::TerminalNode* ShaperParser::TypeSpecifierContext::Identifier() {
  return getToken(ShaperParser::Identifier, 0);
}

tree::TerminalNode* ShaperParser::TypeSpecifierContext::ARRAY() {
  return getToken(ShaperParser::ARRAY, 0);
}

ShaperParser::FunctionSpecifierContext* ShaperParser::TypeSpecifierContext::functionSpecifier() {
  return getRuleContext<ShaperParser::FunctionSpecifierContext>(0);
}

tree::TerminalNode* ShaperParser::TypeSpecifierContext::LIST() {
  return getToken(ShaperParser::LIST, 0);
}


size_t ShaperParser::TypeSpecifierContext::getRuleIndex() const {
  return ShaperParser::RuleTypeSpecifier;
}

void ShaperParser::TypeSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeSpecifier(this);
}

void ShaperParser::TypeSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeSpecifier(this);
}


antlrcpp::Any ShaperParser::TypeSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitTypeSpecifier(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::TypeSpecifierContext* ShaperParser::typeSpecifier() {
  TypeSpecifierContext *_localctx = _tracker.createInstance<TypeSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 8, ShaperParser::RuleTypeSpecifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(132);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ShaperParser::VOID: {
        enterOuterAlt(_localctx, 1);
        setState(118);
        match(ShaperParser::VOID);
        break;
      }

      case ShaperParser::BOOL: {
        enterOuterAlt(_localctx, 2);
        setState(119);
        match(ShaperParser::BOOL);
        break;
      }

      case ShaperParser::INT: {
        enterOuterAlt(_localctx, 3);
        setState(120);
        match(ShaperParser::INT);
        break;
      }

      case ShaperParser::LONG: {
        enterOuterAlt(_localctx, 4);
        setState(121);
        match(ShaperParser::LONG);
        break;
      }

      case ShaperParser::CHAR: {
        enterOuterAlt(_localctx, 5);
        setState(122);
        match(ShaperParser::CHAR);
        break;
      }

      case ShaperParser::FLOAT: {
        enterOuterAlt(_localctx, 6);
        setState(123);
        match(ShaperParser::FLOAT);
        break;
      }

      case ShaperParser::DOUBLE: {
        enterOuterAlt(_localctx, 7);
        setState(124);
        match(ShaperParser::DOUBLE);
        break;
      }

      case ShaperParser::COLOR: {
        enterOuterAlt(_localctx, 8);
        setState(125);
        match(ShaperParser::COLOR);
        break;
      }

      case ShaperParser::STRUCT: {
        enterOuterAlt(_localctx, 9);
        setState(126);
        match(ShaperParser::STRUCT);
        setState(127);
        match(ShaperParser::Identifier);
        break;
      }

      case ShaperParser::ARRAY: {
        enterOuterAlt(_localctx, 10);
        setState(128);
        match(ShaperParser::ARRAY);
        setState(129);
        functionSpecifier();
        break;
      }

      case ShaperParser::LIST: {
        enterOuterAlt(_localctx, 11);
        setState(130);
        match(ShaperParser::LIST);
        setState(131);
        functionSpecifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclaratorContext ------------------------------------------------------------------

ShaperParser::DeclaratorContext::DeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::DeclaratorContext::LEFTPAREN() {
  return getToken(ShaperParser::LEFTPAREN, 0);
}

tree::TerminalNode* ShaperParser::DeclaratorContext::RIGHTPAREN() {
  return getToken(ShaperParser::RIGHTPAREN, 0);
}

ShaperParser::ParameterListContext* ShaperParser::DeclaratorContext::parameterList() {
  return getRuleContext<ShaperParser::ParameterListContext>(0);
}


size_t ShaperParser::DeclaratorContext::getRuleIndex() const {
  return ShaperParser::RuleDeclarator;
}

void ShaperParser::DeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarator(this);
}

void ShaperParser::DeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarator(this);
}


antlrcpp::Any ShaperParser::DeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::DeclaratorContext* ShaperParser::declarator() {
  DeclaratorContext *_localctx = _tracker.createInstance<DeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 10, ShaperParser::RuleDeclarator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(140);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(134);
      match(ShaperParser::LEFTPAREN);
      setState(135);
      match(ShaperParser::RIGHTPAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(136);
      match(ShaperParser::LEFTPAREN);
      setState(137);
      parameterList(0);
      setState(138);
      match(ShaperParser::RIGHTPAREN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterListContext ------------------------------------------------------------------

ShaperParser::ParameterListContext::ParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::ParameterDeclarationContext* ShaperParser::ParameterListContext::parameterDeclaration() {
  return getRuleContext<ShaperParser::ParameterDeclarationContext>(0);
}

ShaperParser::ParameterListContext* ShaperParser::ParameterListContext::parameterList() {
  return getRuleContext<ShaperParser::ParameterListContext>(0);
}

tree::TerminalNode* ShaperParser::ParameterListContext::COMMA() {
  return getToken(ShaperParser::COMMA, 0);
}


size_t ShaperParser::ParameterListContext::getRuleIndex() const {
  return ShaperParser::RuleParameterList;
}

void ShaperParser::ParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterList(this);
}

void ShaperParser::ParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterList(this);
}


antlrcpp::Any ShaperParser::ParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitParameterList(this);
  else
    return visitor->visitChildren(this);
}


ShaperParser::ParameterListContext* ShaperParser::parameterList() {
   return parameterList(0);
}

ShaperParser::ParameterListContext* ShaperParser::parameterList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ShaperParser::ParameterListContext *_localctx = _tracker.createInstance<ParameterListContext>(_ctx, parentState);
  ShaperParser::ParameterListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, ShaperParser::RuleParameterList, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(143);
    parameterDeclaration();
    _ctx->stop = _input->LT(-1);
    setState(150);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ParameterListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleParameterList);
        setState(145);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(146);
        match(ShaperParser::COMMA);
        setState(147);
        parameterDeclaration(); 
      }
      setState(152);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ParameterDeclarationContext ------------------------------------------------------------------

ShaperParser::ParameterDeclarationContext::ParameterDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::FunctionSpecifierContext* ShaperParser::ParameterDeclarationContext::functionSpecifier() {
  return getRuleContext<ShaperParser::FunctionSpecifierContext>(0);
}

tree::TerminalNode* ShaperParser::ParameterDeclarationContext::Identifier() {
  return getToken(ShaperParser::Identifier, 0);
}


size_t ShaperParser::ParameterDeclarationContext::getRuleIndex() const {
  return ShaperParser::RuleParameterDeclaration;
}

void ShaperParser::ParameterDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterDeclaration(this);
}

void ShaperParser::ParameterDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterDeclaration(this);
}


antlrcpp::Any ShaperParser::ParameterDeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitParameterDeclaration(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::ParameterDeclarationContext* ShaperParser::parameterDeclaration() {
  ParameterDeclarationContext *_localctx = _tracker.createInstance<ParameterDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 14, ShaperParser::RuleParameterDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(153);
    functionSpecifier();
    setState(154);
    match(ShaperParser::Identifier);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStatementContext ------------------------------------------------------------------

ShaperParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::CompoundStatementContext::LEFTBRACKET() {
  return getToken(ShaperParser::LEFTBRACKET, 0);
}

tree::TerminalNode* ShaperParser::CompoundStatementContext::RIGHTBRACKET() {
  return getToken(ShaperParser::RIGHTBRACKET, 0);
}

std::vector<ShaperParser::StatementContext *> ShaperParser::CompoundStatementContext::statement() {
  return getRuleContexts<ShaperParser::StatementContext>();
}

ShaperParser::StatementContext* ShaperParser::CompoundStatementContext::statement(size_t i) {
  return getRuleContext<ShaperParser::StatementContext>(i);
}

std::vector<ShaperParser::DeclarationContext *> ShaperParser::CompoundStatementContext::declaration() {
  return getRuleContexts<ShaperParser::DeclarationContext>();
}

ShaperParser::DeclarationContext* ShaperParser::CompoundStatementContext::declaration(size_t i) {
  return getRuleContext<ShaperParser::DeclarationContext>(i);
}

std::vector<tree::TerminalNode *> ShaperParser::CompoundStatementContext::SEMICOLON() {
  return getTokens(ShaperParser::SEMICOLON);
}

tree::TerminalNode* ShaperParser::CompoundStatementContext::SEMICOLON(size_t i) {
  return getToken(ShaperParser::SEMICOLON, i);
}


size_t ShaperParser::CompoundStatementContext::getRuleIndex() const {
  return ShaperParser::RuleCompoundStatement;
}

void ShaperParser::CompoundStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompoundStatement(this);
}

void ShaperParser::CompoundStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompoundStatement(this);
}


antlrcpp::Any ShaperParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::CompoundStatementContext* ShaperParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 16, ShaperParser::RuleCompoundStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(ShaperParser::LEFTBRACKET);
    setState(163);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ShaperParser::PAINT)
      | (1ULL << ShaperParser::LEFTPAREN)
      | (1ULL << ShaperParser::LEFTBRACKET)
      | (1ULL << ShaperParser::BOOL)
      | (1ULL << ShaperParser::INT)
      | (1ULL << ShaperParser::LONG)
      | (1ULL << ShaperParser::CHAR)
      | (1ULL << ShaperParser::FLOAT)
      | (1ULL << ShaperParser::DOUBLE)
      | (1ULL << ShaperParser::COLOR)
      | (1ULL << ShaperParser::STRUCT)
      | (1ULL << ShaperParser::ARRAY)
      | (1ULL << ShaperParser::LIST)
      | (1ULL << ShaperParser::CONST)
      | (1ULL << ShaperParser::MINUS)
      | (1ULL << ShaperParser::PLUSPLUS)
      | (1ULL << ShaperParser::MINUSMINUS)
      | (1ULL << ShaperParser::EXCLAMATION)
      | (1ULL << ShaperParser::IF)
      | (1ULL << ShaperParser::SWITCH)
      | (1ULL << ShaperParser::CASE)
      | (1ULL << ShaperParser::DEFAULT)
      | (1ULL << ShaperParser::WHILE)
      | (1ULL << ShaperParser::FOR)
      | (1ULL << ShaperParser::CONTINUE)
      | (1ULL << ShaperParser::BREAK))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (ShaperParser::RETURN - 64))
      | (1ULL << (ShaperParser::Constant - 64))
      | (1ULL << (ShaperParser::Identifier - 64)))) != 0)) {
      setState(161);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case ShaperParser::BOOL:
        case ShaperParser::INT:
        case ShaperParser::LONG:
        case ShaperParser::CHAR:
        case ShaperParser::FLOAT:
        case ShaperParser::DOUBLE:
        case ShaperParser::COLOR:
        case ShaperParser::STRUCT:
        case ShaperParser::ARRAY:
        case ShaperParser::LIST:
        case ShaperParser::CONST: {
          setState(157);
          declaration();
          setState(158);
          match(ShaperParser::SEMICOLON);
          break;
        }

        case ShaperParser::PAINT:
        case ShaperParser::LEFTPAREN:
        case ShaperParser::LEFTBRACKET:
        case ShaperParser::MINUS:
        case ShaperParser::PLUSPLUS:
        case ShaperParser::MINUSMINUS:
        case ShaperParser::EXCLAMATION:
        case ShaperParser::IF:
        case ShaperParser::SWITCH:
        case ShaperParser::CASE:
        case ShaperParser::DEFAULT:
        case ShaperParser::WHILE:
        case ShaperParser::FOR:
        case ShaperParser::CONTINUE:
        case ShaperParser::BREAK:
        case ShaperParser::RETURN:
        case ShaperParser::Constant:
        case ShaperParser::Identifier: {
          setState(160);
          statement();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(165);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(166);
    match(ShaperParser::RIGHTBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

ShaperParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::DeclarationSpecifierContext* ShaperParser::DeclarationContext::declarationSpecifier() {
  return getRuleContext<ShaperParser::DeclarationSpecifierContext>(0);
}

ShaperParser::InitDeclaratorContext* ShaperParser::DeclarationContext::initDeclarator() {
  return getRuleContext<ShaperParser::InitDeclaratorContext>(0);
}

ShaperParser::StructDeclaratorContext* ShaperParser::DeclarationContext::structDeclarator() {
  return getRuleContext<ShaperParser::StructDeclaratorContext>(0);
}


size_t ShaperParser::DeclarationContext::getRuleIndex() const {
  return ShaperParser::RuleDeclaration;
}

void ShaperParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void ShaperParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}


antlrcpp::Any ShaperParser::DeclarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitDeclaration(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::DeclarationContext* ShaperParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 18, ShaperParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(172);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(168);
      declarationSpecifier();
      setState(169);
      initDeclarator();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(171);
      structDeclarator();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationSpecifierContext ------------------------------------------------------------------

ShaperParser::DeclarationSpecifierContext::DeclarationSpecifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::DeclarationTypeContext* ShaperParser::DeclarationSpecifierContext::declarationType() {
  return getRuleContext<ShaperParser::DeclarationTypeContext>(0);
}

tree::TerminalNode* ShaperParser::DeclarationSpecifierContext::CONST() {
  return getToken(ShaperParser::CONST, 0);
}


size_t ShaperParser::DeclarationSpecifierContext::getRuleIndex() const {
  return ShaperParser::RuleDeclarationSpecifier;
}

void ShaperParser::DeclarationSpecifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationSpecifier(this);
}

void ShaperParser::DeclarationSpecifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationSpecifier(this);
}


antlrcpp::Any ShaperParser::DeclarationSpecifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitDeclarationSpecifier(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::DeclarationSpecifierContext* ShaperParser::declarationSpecifier() {
  DeclarationSpecifierContext *_localctx = _tracker.createInstance<DeclarationSpecifierContext>(_ctx, getState());
  enterRule(_localctx, 20, ShaperParser::RuleDeclarationSpecifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(177);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ShaperParser::BOOL:
      case ShaperParser::INT:
      case ShaperParser::LONG:
      case ShaperParser::CHAR:
      case ShaperParser::FLOAT:
      case ShaperParser::DOUBLE:
      case ShaperParser::COLOR:
      case ShaperParser::STRUCT:
      case ShaperParser::ARRAY:
      case ShaperParser::LIST: {
        enterOuterAlt(_localctx, 1);
        setState(174);
        declarationType();
        break;
      }

      case ShaperParser::CONST: {
        enterOuterAlt(_localctx, 2);
        setState(175);
        match(ShaperParser::CONST);
        setState(176);
        declarationType();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationTypeContext ------------------------------------------------------------------

ShaperParser::DeclarationTypeContext::DeclarationTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::DeclarationTypeContext::BOOL() {
  return getToken(ShaperParser::BOOL, 0);
}

tree::TerminalNode* ShaperParser::DeclarationTypeContext::INT() {
  return getToken(ShaperParser::INT, 0);
}

tree::TerminalNode* ShaperParser::DeclarationTypeContext::LONG() {
  return getToken(ShaperParser::LONG, 0);
}

tree::TerminalNode* ShaperParser::DeclarationTypeContext::CHAR() {
  return getToken(ShaperParser::CHAR, 0);
}

tree::TerminalNode* ShaperParser::DeclarationTypeContext::FLOAT() {
  return getToken(ShaperParser::FLOAT, 0);
}

tree::TerminalNode* ShaperParser::DeclarationTypeContext::DOUBLE() {
  return getToken(ShaperParser::DOUBLE, 0);
}

tree::TerminalNode* ShaperParser::DeclarationTypeContext::COLOR() {
  return getToken(ShaperParser::COLOR, 0);
}

tree::TerminalNode* ShaperParser::DeclarationTypeContext::STRUCT() {
  return getToken(ShaperParser::STRUCT, 0);
}

tree::TerminalNode* ShaperParser::DeclarationTypeContext::Identifier() {
  return getToken(ShaperParser::Identifier, 0);
}

tree::TerminalNode* ShaperParser::DeclarationTypeContext::ARRAY() {
  return getToken(ShaperParser::ARRAY, 0);
}

tree::TerminalNode* ShaperParser::DeclarationTypeContext::LEFTPAREN() {
  return getToken(ShaperParser::LEFTPAREN, 0);
}

tree::TerminalNode* ShaperParser::DeclarationTypeContext::RIGHTPAREN() {
  return getToken(ShaperParser::RIGHTPAREN, 0);
}

ShaperParser::DeclarationSpecifierContext* ShaperParser::DeclarationTypeContext::declarationSpecifier() {
  return getRuleContext<ShaperParser::DeclarationSpecifierContext>(0);
}

tree::TerminalNode* ShaperParser::DeclarationTypeContext::Constant() {
  return getToken(ShaperParser::Constant, 0);
}

tree::TerminalNode* ShaperParser::DeclarationTypeContext::LIST() {
  return getToken(ShaperParser::LIST, 0);
}


size_t ShaperParser::DeclarationTypeContext::getRuleIndex() const {
  return ShaperParser::RuleDeclarationType;
}

void ShaperParser::DeclarationTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclarationType(this);
}

void ShaperParser::DeclarationTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclarationType(this);
}


antlrcpp::Any ShaperParser::DeclarationTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitDeclarationType(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::DeclarationTypeContext* ShaperParser::declarationType() {
  DeclarationTypeContext *_localctx = _tracker.createInstance<DeclarationTypeContext>(_ctx, getState());
  enterRule(_localctx, 22, ShaperParser::RuleDeclarationType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(197);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ShaperParser::BOOL: {
        enterOuterAlt(_localctx, 1);
        setState(179);
        match(ShaperParser::BOOL);
        break;
      }

      case ShaperParser::INT: {
        enterOuterAlt(_localctx, 2);
        setState(180);
        match(ShaperParser::INT);
        break;
      }

      case ShaperParser::LONG: {
        enterOuterAlt(_localctx, 3);
        setState(181);
        match(ShaperParser::LONG);
        break;
      }

      case ShaperParser::CHAR: {
        enterOuterAlt(_localctx, 4);
        setState(182);
        match(ShaperParser::CHAR);
        break;
      }

      case ShaperParser::FLOAT: {
        enterOuterAlt(_localctx, 5);
        setState(183);
        match(ShaperParser::FLOAT);
        break;
      }

      case ShaperParser::DOUBLE: {
        enterOuterAlt(_localctx, 6);
        setState(184);
        match(ShaperParser::DOUBLE);
        break;
      }

      case ShaperParser::COLOR: {
        enterOuterAlt(_localctx, 7);
        setState(185);
        match(ShaperParser::COLOR);
        break;
      }

      case ShaperParser::STRUCT: {
        enterOuterAlt(_localctx, 8);
        setState(186);
        match(ShaperParser::STRUCT);
        setState(187);
        match(ShaperParser::Identifier);
        break;
      }

      case ShaperParser::ARRAY: {
        enterOuterAlt(_localctx, 9);
        setState(188);
        match(ShaperParser::ARRAY);
        setState(189);
        match(ShaperParser::LEFTPAREN);
        setState(191);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ShaperParser::Constant

        || _la == ShaperParser::Identifier) {
          setState(190);
          _la = _input->LA(1);
          if (!(_la == ShaperParser::Constant

          || _la == ShaperParser::Identifier)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
        }
        setState(193);
        match(ShaperParser::RIGHTPAREN);
        setState(194);
        declarationSpecifier();
        break;
      }

      case ShaperParser::LIST: {
        enterOuterAlt(_localctx, 10);
        setState(195);
        match(ShaperParser::LIST);
        setState(196);
        declarationSpecifier();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InitDeclaratorContext ------------------------------------------------------------------

ShaperParser::InitDeclaratorContext::InitDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::InitDeclaratorContext::Identifier() {
  return getToken(ShaperParser::Identifier, 0);
}

ShaperParser::AssignmentOperatorContext* ShaperParser::InitDeclaratorContext::assignmentOperator() {
  return getRuleContext<ShaperParser::AssignmentOperatorContext>(0);
}

ShaperParser::AssignmentExpressionContext* ShaperParser::InitDeclaratorContext::assignmentExpression() {
  return getRuleContext<ShaperParser::AssignmentExpressionContext>(0);
}


size_t ShaperParser::InitDeclaratorContext::getRuleIndex() const {
  return ShaperParser::RuleInitDeclarator;
}

void ShaperParser::InitDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInitDeclarator(this);
}

void ShaperParser::InitDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInitDeclarator(this);
}


antlrcpp::Any ShaperParser::InitDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitInitDeclarator(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::InitDeclaratorContext* ShaperParser::initDeclarator() {
  InitDeclaratorContext *_localctx = _tracker.createInstance<InitDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 24, ShaperParser::RuleInitDeclarator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    match(ShaperParser::Identifier);
    setState(203);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ShaperParser::ASSIGN)
      | (1ULL << ShaperParser::PLUSASSIGN)
      | (1ULL << ShaperParser::MINUSASSIGN)
      | (1ULL << ShaperParser::MULTIPLYASSIGN)
      | (1ULL << ShaperParser::DIVIDEASSIGN)
      | (1ULL << ShaperParser::MODULOASSIGN))) != 0)) {
      setState(200);
      assignmentOperator();
      setState(201);
      assignmentExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclaratorContext ------------------------------------------------------------------

ShaperParser::StructDeclaratorContext::StructDeclaratorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::StructDeclaratorContext::STRUCT() {
  return getToken(ShaperParser::STRUCT, 0);
}

tree::TerminalNode* ShaperParser::StructDeclaratorContext::Identifier() {
  return getToken(ShaperParser::Identifier, 0);
}

tree::TerminalNode* ShaperParser::StructDeclaratorContext::LEFTBRACKET() {
  return getToken(ShaperParser::LEFTBRACKET, 0);
}

ShaperParser::StructDeclarationListContext* ShaperParser::StructDeclaratorContext::structDeclarationList() {
  return getRuleContext<ShaperParser::StructDeclarationListContext>(0);
}

tree::TerminalNode* ShaperParser::StructDeclaratorContext::RIGHTBRACKET() {
  return getToken(ShaperParser::RIGHTBRACKET, 0);
}


size_t ShaperParser::StructDeclaratorContext::getRuleIndex() const {
  return ShaperParser::RuleStructDeclarator;
}

void ShaperParser::StructDeclaratorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclarator(this);
}

void ShaperParser::StructDeclaratorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclarator(this);
}


antlrcpp::Any ShaperParser::StructDeclaratorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitStructDeclarator(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::StructDeclaratorContext* ShaperParser::structDeclarator() {
  StructDeclaratorContext *_localctx = _tracker.createInstance<StructDeclaratorContext>(_ctx, getState());
  enterRule(_localctx, 26, ShaperParser::RuleStructDeclarator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(205);
    match(ShaperParser::STRUCT);
    setState(206);
    match(ShaperParser::Identifier);
    setState(207);
    match(ShaperParser::LEFTBRACKET);
    setState(208);
    structDeclarationList(0);
    setState(209);
    match(ShaperParser::RIGHTBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclarationListContext ------------------------------------------------------------------

ShaperParser::StructDeclarationListContext::StructDeclarationListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::DeclarationContext* ShaperParser::StructDeclarationListContext::declaration() {
  return getRuleContext<ShaperParser::DeclarationContext>(0);
}

tree::TerminalNode* ShaperParser::StructDeclarationListContext::SEMICOLON() {
  return getToken(ShaperParser::SEMICOLON, 0);
}

ShaperParser::StructDeclarationListContext* ShaperParser::StructDeclarationListContext::structDeclarationList() {
  return getRuleContext<ShaperParser::StructDeclarationListContext>(0);
}


size_t ShaperParser::StructDeclarationListContext::getRuleIndex() const {
  return ShaperParser::RuleStructDeclarationList;
}

void ShaperParser::StructDeclarationListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclarationList(this);
}

void ShaperParser::StructDeclarationListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclarationList(this);
}


antlrcpp::Any ShaperParser::StructDeclarationListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitStructDeclarationList(this);
  else
    return visitor->visitChildren(this);
}


ShaperParser::StructDeclarationListContext* ShaperParser::structDeclarationList() {
   return structDeclarationList(0);
}

ShaperParser::StructDeclarationListContext* ShaperParser::structDeclarationList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ShaperParser::StructDeclarationListContext *_localctx = _tracker.createInstance<StructDeclarationListContext>(_ctx, parentState);
  ShaperParser::StructDeclarationListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 28;
  enterRecursionRule(_localctx, 28, ShaperParser::RuleStructDeclarationList, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(212);
    declaration();
    setState(213);
    match(ShaperParser::SEMICOLON);
    _ctx->stop = _input->LT(-1);
    setState(221);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StructDeclarationListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleStructDeclarationList);
        setState(215);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(216);
        declaration();
        setState(217);
        match(ShaperParser::SEMICOLON); 
      }
      setState(223);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

ShaperParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::AssignmentExpressionContext* ShaperParser::ExpressionContext::assignmentExpression() {
  return getRuleContext<ShaperParser::AssignmentExpressionContext>(0);
}


size_t ShaperParser::ExpressionContext::getRuleIndex() const {
  return ShaperParser::RuleExpression;
}

void ShaperParser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void ShaperParser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}


antlrcpp::Any ShaperParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::ExpressionContext* ShaperParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 30, ShaperParser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(224);
    assignmentExpression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentExpressionContext ------------------------------------------------------------------

ShaperParser::AssignmentExpressionContext::AssignmentExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::LogicalORExpressionContext* ShaperParser::AssignmentExpressionContext::logicalORExpression() {
  return getRuleContext<ShaperParser::LogicalORExpressionContext>(0);
}

ShaperParser::UnaryExpressionContext* ShaperParser::AssignmentExpressionContext::unaryExpression() {
  return getRuleContext<ShaperParser::UnaryExpressionContext>(0);
}

ShaperParser::AssignmentOperatorContext* ShaperParser::AssignmentExpressionContext::assignmentOperator() {
  return getRuleContext<ShaperParser::AssignmentOperatorContext>(0);
}

ShaperParser::AssignmentExpressionContext* ShaperParser::AssignmentExpressionContext::assignmentExpression() {
  return getRuleContext<ShaperParser::AssignmentExpressionContext>(0);
}


size_t ShaperParser::AssignmentExpressionContext::getRuleIndex() const {
  return ShaperParser::RuleAssignmentExpression;
}

void ShaperParser::AssignmentExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentExpression(this);
}

void ShaperParser::AssignmentExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentExpression(this);
}


antlrcpp::Any ShaperParser::AssignmentExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitAssignmentExpression(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::AssignmentExpressionContext* ShaperParser::assignmentExpression() {
  AssignmentExpressionContext *_localctx = _tracker.createInstance<AssignmentExpressionContext>(_ctx, getState());
  enterRule(_localctx, 32, ShaperParser::RuleAssignmentExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(231);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(226);
      logicalORExpression(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(227);
      unaryExpression();
      setState(228);
      assignmentOperator();
      setState(229);
      assignmentExpression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LogicalORExpressionContext ------------------------------------------------------------------

ShaperParser::LogicalORExpressionContext::LogicalORExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::LogicalANDExpressionContext* ShaperParser::LogicalORExpressionContext::logicalANDExpression() {
  return getRuleContext<ShaperParser::LogicalANDExpressionContext>(0);
}

ShaperParser::LogicalORExpressionContext* ShaperParser::LogicalORExpressionContext::logicalORExpression() {
  return getRuleContext<ShaperParser::LogicalORExpressionContext>(0);
}

tree::TerminalNode* ShaperParser::LogicalORExpressionContext::OR() {
  return getToken(ShaperParser::OR, 0);
}


size_t ShaperParser::LogicalORExpressionContext::getRuleIndex() const {
  return ShaperParser::RuleLogicalORExpression;
}

void ShaperParser::LogicalORExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalORExpression(this);
}

void ShaperParser::LogicalORExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalORExpression(this);
}


antlrcpp::Any ShaperParser::LogicalORExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitLogicalORExpression(this);
  else
    return visitor->visitChildren(this);
}


ShaperParser::LogicalORExpressionContext* ShaperParser::logicalORExpression() {
   return logicalORExpression(0);
}

ShaperParser::LogicalORExpressionContext* ShaperParser::logicalORExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ShaperParser::LogicalORExpressionContext *_localctx = _tracker.createInstance<LogicalORExpressionContext>(_ctx, parentState);
  ShaperParser::LogicalORExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 34;
  enterRecursionRule(_localctx, 34, ShaperParser::RuleLogicalORExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(234);
    logicalANDExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(241);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalORExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalORExpression);
        setState(236);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(237);
        match(ShaperParser::OR);
        setState(238);
        logicalANDExpression(0); 
      }
      setState(243);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- LogicalANDExpressionContext ------------------------------------------------------------------

ShaperParser::LogicalANDExpressionContext::LogicalANDExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::EqualityExpressionContext* ShaperParser::LogicalANDExpressionContext::equalityExpression() {
  return getRuleContext<ShaperParser::EqualityExpressionContext>(0);
}

ShaperParser::LogicalANDExpressionContext* ShaperParser::LogicalANDExpressionContext::logicalANDExpression() {
  return getRuleContext<ShaperParser::LogicalANDExpressionContext>(0);
}

tree::TerminalNode* ShaperParser::LogicalANDExpressionContext::AND() {
  return getToken(ShaperParser::AND, 0);
}


size_t ShaperParser::LogicalANDExpressionContext::getRuleIndex() const {
  return ShaperParser::RuleLogicalANDExpression;
}

void ShaperParser::LogicalANDExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalANDExpression(this);
}

void ShaperParser::LogicalANDExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalANDExpression(this);
}


antlrcpp::Any ShaperParser::LogicalANDExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitLogicalANDExpression(this);
  else
    return visitor->visitChildren(this);
}


ShaperParser::LogicalANDExpressionContext* ShaperParser::logicalANDExpression() {
   return logicalANDExpression(0);
}

ShaperParser::LogicalANDExpressionContext* ShaperParser::logicalANDExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ShaperParser::LogicalANDExpressionContext *_localctx = _tracker.createInstance<LogicalANDExpressionContext>(_ctx, parentState);
  ShaperParser::LogicalANDExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, ShaperParser::RuleLogicalANDExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(245);
    equalityExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(252);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<LogicalANDExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleLogicalANDExpression);
        setState(247);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(248);
        match(ShaperParser::AND);
        setState(249);
        equalityExpression(0); 
      }
      setState(254);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- EqualityExpressionContext ------------------------------------------------------------------

ShaperParser::EqualityExpressionContext::EqualityExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::RelationalExpressionContext* ShaperParser::EqualityExpressionContext::relationalExpression() {
  return getRuleContext<ShaperParser::RelationalExpressionContext>(0);
}

ShaperParser::EqualityExpressionContext* ShaperParser::EqualityExpressionContext::equalityExpression() {
  return getRuleContext<ShaperParser::EqualityExpressionContext>(0);
}

tree::TerminalNode* ShaperParser::EqualityExpressionContext::EQUAL() {
  return getToken(ShaperParser::EQUAL, 0);
}

tree::TerminalNode* ShaperParser::EqualityExpressionContext::NOTEQUAL() {
  return getToken(ShaperParser::NOTEQUAL, 0);
}


size_t ShaperParser::EqualityExpressionContext::getRuleIndex() const {
  return ShaperParser::RuleEqualityExpression;
}

void ShaperParser::EqualityExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEqualityExpression(this);
}

void ShaperParser::EqualityExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEqualityExpression(this);
}


antlrcpp::Any ShaperParser::EqualityExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitEqualityExpression(this);
  else
    return visitor->visitChildren(this);
}


ShaperParser::EqualityExpressionContext* ShaperParser::equalityExpression() {
   return equalityExpression(0);
}

ShaperParser::EqualityExpressionContext* ShaperParser::equalityExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ShaperParser::EqualityExpressionContext *_localctx = _tracker.createInstance<EqualityExpressionContext>(_ctx, parentState);
  ShaperParser::EqualityExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, ShaperParser::RuleEqualityExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(256);
    relationalExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(266);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(264);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(258);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(259);
          match(ShaperParser::EQUAL);
          setState(260);
          relationalExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<EqualityExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleEqualityExpression);
          setState(261);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(262);
          match(ShaperParser::NOTEQUAL);
          setState(263);
          relationalExpression(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(268);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- RelationalExpressionContext ------------------------------------------------------------------

ShaperParser::RelationalExpressionContext::RelationalExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::AdditiveExpressionContext* ShaperParser::RelationalExpressionContext::additiveExpression() {
  return getRuleContext<ShaperParser::AdditiveExpressionContext>(0);
}

ShaperParser::RelationalExpressionContext* ShaperParser::RelationalExpressionContext::relationalExpression() {
  return getRuleContext<ShaperParser::RelationalExpressionContext>(0);
}

ShaperParser::RelationalOperatorContext* ShaperParser::RelationalExpressionContext::relationalOperator() {
  return getRuleContext<ShaperParser::RelationalOperatorContext>(0);
}


size_t ShaperParser::RelationalExpressionContext::getRuleIndex() const {
  return ShaperParser::RuleRelationalExpression;
}

void ShaperParser::RelationalExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalExpression(this);
}

void ShaperParser::RelationalExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalExpression(this);
}


antlrcpp::Any ShaperParser::RelationalExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitRelationalExpression(this);
  else
    return visitor->visitChildren(this);
}


ShaperParser::RelationalExpressionContext* ShaperParser::relationalExpression() {
   return relationalExpression(0);
}

ShaperParser::RelationalExpressionContext* ShaperParser::relationalExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ShaperParser::RelationalExpressionContext *_localctx = _tracker.createInstance<RelationalExpressionContext>(_ctx, parentState);
  ShaperParser::RelationalExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 40;
  enterRecursionRule(_localctx, 40, ShaperParser::RuleRelationalExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(270);
    additiveExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(278);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<RelationalExpressionContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleRelationalExpression);
        setState(272);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(273);
        relationalOperator();
        setState(274);
        additiveExpression(0); 
      }
      setState(280);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AdditiveExpressionContext ------------------------------------------------------------------

ShaperParser::AdditiveExpressionContext::AdditiveExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::MultiplicativeExpressionContext* ShaperParser::AdditiveExpressionContext::multiplicativeExpression() {
  return getRuleContext<ShaperParser::MultiplicativeExpressionContext>(0);
}

ShaperParser::AdditiveExpressionContext* ShaperParser::AdditiveExpressionContext::additiveExpression() {
  return getRuleContext<ShaperParser::AdditiveExpressionContext>(0);
}

tree::TerminalNode* ShaperParser::AdditiveExpressionContext::PLUS() {
  return getToken(ShaperParser::PLUS, 0);
}

tree::TerminalNode* ShaperParser::AdditiveExpressionContext::MINUS() {
  return getToken(ShaperParser::MINUS, 0);
}


size_t ShaperParser::AdditiveExpressionContext::getRuleIndex() const {
  return ShaperParser::RuleAdditiveExpression;
}

void ShaperParser::AdditiveExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAdditiveExpression(this);
}

void ShaperParser::AdditiveExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAdditiveExpression(this);
}


antlrcpp::Any ShaperParser::AdditiveExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitAdditiveExpression(this);
  else
    return visitor->visitChildren(this);
}


ShaperParser::AdditiveExpressionContext* ShaperParser::additiveExpression() {
   return additiveExpression(0);
}

ShaperParser::AdditiveExpressionContext* ShaperParser::additiveExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ShaperParser::AdditiveExpressionContext *_localctx = _tracker.createInstance<AdditiveExpressionContext>(_ctx, parentState);
  ShaperParser::AdditiveExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 42;
  enterRecursionRule(_localctx, 42, ShaperParser::RuleAdditiveExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(282);
    multiplicativeExpression(0);
    _ctx->stop = _input->LT(-1);
    setState(292);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(290);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(284);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(285);
          match(ShaperParser::PLUS);
          setState(286);
          multiplicativeExpression(0);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<AdditiveExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleAdditiveExpression);
          setState(287);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(288);
          match(ShaperParser::MINUS);
          setState(289);
          multiplicativeExpression(0);
          break;
        }

        default:
          break;
        } 
      }
      setState(294);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MultiplicativeExpressionContext ------------------------------------------------------------------

ShaperParser::MultiplicativeExpressionContext::MultiplicativeExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::UnaryExpressionContext* ShaperParser::MultiplicativeExpressionContext::unaryExpression() {
  return getRuleContext<ShaperParser::UnaryExpressionContext>(0);
}

ShaperParser::MultiplicativeExpressionContext* ShaperParser::MultiplicativeExpressionContext::multiplicativeExpression() {
  return getRuleContext<ShaperParser::MultiplicativeExpressionContext>(0);
}

tree::TerminalNode* ShaperParser::MultiplicativeExpressionContext::MULTIPLY() {
  return getToken(ShaperParser::MULTIPLY, 0);
}

tree::TerminalNode* ShaperParser::MultiplicativeExpressionContext::DIVIDE() {
  return getToken(ShaperParser::DIVIDE, 0);
}

tree::TerminalNode* ShaperParser::MultiplicativeExpressionContext::MODULO() {
  return getToken(ShaperParser::MODULO, 0);
}


size_t ShaperParser::MultiplicativeExpressionContext::getRuleIndex() const {
  return ShaperParser::RuleMultiplicativeExpression;
}

void ShaperParser::MultiplicativeExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMultiplicativeExpression(this);
}

void ShaperParser::MultiplicativeExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMultiplicativeExpression(this);
}


antlrcpp::Any ShaperParser::MultiplicativeExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitMultiplicativeExpression(this);
  else
    return visitor->visitChildren(this);
}


ShaperParser::MultiplicativeExpressionContext* ShaperParser::multiplicativeExpression() {
   return multiplicativeExpression(0);
}

ShaperParser::MultiplicativeExpressionContext* ShaperParser::multiplicativeExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ShaperParser::MultiplicativeExpressionContext *_localctx = _tracker.createInstance<MultiplicativeExpressionContext>(_ctx, parentState);
  ShaperParser::MultiplicativeExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 44;
  enterRecursionRule(_localctx, 44, ShaperParser::RuleMultiplicativeExpression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(296);
    unaryExpression();
    _ctx->stop = _input->LT(-1);
    setState(309);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(307);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(298);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(299);
          match(ShaperParser::MULTIPLY);
          setState(300);
          unaryExpression();
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(301);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(302);
          match(ShaperParser::DIVIDE);
          setState(303);
          unaryExpression();
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<MultiplicativeExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleMultiplicativeExpression);
          setState(304);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(305);
          match(ShaperParser::MODULO);
          setState(306);
          unaryExpression();
          break;
        }

        default:
          break;
        } 
      }
      setState(311);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnaryExpressionContext ------------------------------------------------------------------

ShaperParser::UnaryExpressionContext::UnaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::PostfixExpressionContext* ShaperParser::UnaryExpressionContext::postfixExpression() {
  return getRuleContext<ShaperParser::PostfixExpressionContext>(0);
}

ShaperParser::UnaryOperatorContext* ShaperParser::UnaryExpressionContext::unaryOperator() {
  return getRuleContext<ShaperParser::UnaryOperatorContext>(0);
}

ShaperParser::UnaryExpressionContext* ShaperParser::UnaryExpressionContext::unaryExpression() {
  return getRuleContext<ShaperParser::UnaryExpressionContext>(0);
}


size_t ShaperParser::UnaryExpressionContext::getRuleIndex() const {
  return ShaperParser::RuleUnaryExpression;
}

void ShaperParser::UnaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryExpression(this);
}

void ShaperParser::UnaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryExpression(this);
}


antlrcpp::Any ShaperParser::UnaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitUnaryExpression(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::UnaryExpressionContext* ShaperParser::unaryExpression() {
  UnaryExpressionContext *_localctx = _tracker.createInstance<UnaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 46, ShaperParser::RuleUnaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(316);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ShaperParser::LEFTPAREN:
      case ShaperParser::Constant:
      case ShaperParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(312);
        postfixExpression(0);
        break;
      }

      case ShaperParser::MINUS:
      case ShaperParser::PLUSPLUS:
      case ShaperParser::MINUSMINUS:
      case ShaperParser::EXCLAMATION: {
        enterOuterAlt(_localctx, 2);
        setState(313);
        unaryOperator();
        setState(314);
        unaryExpression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PostfixExpressionContext ------------------------------------------------------------------

ShaperParser::PostfixExpressionContext::PostfixExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::PrimaryExpressionContext* ShaperParser::PostfixExpressionContext::primaryExpression() {
  return getRuleContext<ShaperParser::PrimaryExpressionContext>(0);
}

ShaperParser::PostfixExpressionContext* ShaperParser::PostfixExpressionContext::postfixExpression() {
  return getRuleContext<ShaperParser::PostfixExpressionContext>(0);
}

tree::TerminalNode* ShaperParser::PostfixExpressionContext::DOT() {
  return getToken(ShaperParser::DOT, 0);
}

tree::TerminalNode* ShaperParser::PostfixExpressionContext::Identifier() {
  return getToken(ShaperParser::Identifier, 0);
}

tree::TerminalNode* ShaperParser::PostfixExpressionContext::PLUSPLUS() {
  return getToken(ShaperParser::PLUSPLUS, 0);
}

tree::TerminalNode* ShaperParser::PostfixExpressionContext::MINUSMINUS() {
  return getToken(ShaperParser::MINUSMINUS, 0);
}

tree::TerminalNode* ShaperParser::PostfixExpressionContext::LEFTPAREN() {
  return getToken(ShaperParser::LEFTPAREN, 0);
}

tree::TerminalNode* ShaperParser::PostfixExpressionContext::RIGHTPAREN() {
  return getToken(ShaperParser::RIGHTPAREN, 0);
}

ShaperParser::FunctionParameterListContext* ShaperParser::PostfixExpressionContext::functionParameterList() {
  return getRuleContext<ShaperParser::FunctionParameterListContext>(0);
}


size_t ShaperParser::PostfixExpressionContext::getRuleIndex() const {
  return ShaperParser::RulePostfixExpression;
}

void ShaperParser::PostfixExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPostfixExpression(this);
}

void ShaperParser::PostfixExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPostfixExpression(this);
}


antlrcpp::Any ShaperParser::PostfixExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitPostfixExpression(this);
  else
    return visitor->visitChildren(this);
}


ShaperParser::PostfixExpressionContext* ShaperParser::postfixExpression() {
   return postfixExpression(0);
}

ShaperParser::PostfixExpressionContext* ShaperParser::postfixExpression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ShaperParser::PostfixExpressionContext *_localctx = _tracker.createInstance<PostfixExpressionContext>(_ctx, parentState);
  ShaperParser::PostfixExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 48;
  enterRecursionRule(_localctx, 48, ShaperParser::RulePostfixExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(319);
    primaryExpression();
    _ctx->stop = _input->LT(-1);
    setState(336);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(334);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(321);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(322);
          match(ShaperParser::DOT);
          setState(323);
          match(ShaperParser::Identifier);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(324);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(325);
          match(ShaperParser::PLUSPLUS);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(326);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(327);
          match(ShaperParser::MINUSMINUS);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<PostfixExpressionContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RulePostfixExpression);
          setState(328);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(329);
          match(ShaperParser::LEFTPAREN);
          setState(331);
          _errHandler->sync(this);

          _la = _input->LA(1);
          if (((((_la - 12) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 12)) & ((1ULL << (ShaperParser::LEFTPAREN - 12))
            | (1ULL << (ShaperParser::MINUS - 12))
            | (1ULL << (ShaperParser::PLUSPLUS - 12))
            | (1ULL << (ShaperParser::MINUSMINUS - 12))
            | (1ULL << (ShaperParser::EXCLAMATION - 12))
            | (1ULL << (ShaperParser::Constant - 12))
            | (1ULL << (ShaperParser::Identifier - 12)))) != 0)) {
            setState(330);
            functionParameterList(0);
          }
          setState(333);
          match(ShaperParser::RIGHTPAREN);
          break;
        }

        default:
          break;
        } 
      }
      setState(338);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimaryExpressionContext ------------------------------------------------------------------

ShaperParser::PrimaryExpressionContext::PrimaryExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::PrimaryExpressionContext::Identifier() {
  return getToken(ShaperParser::Identifier, 0);
}

tree::TerminalNode* ShaperParser::PrimaryExpressionContext::Constant() {
  return getToken(ShaperParser::Constant, 0);
}

tree::TerminalNode* ShaperParser::PrimaryExpressionContext::LEFTPAREN() {
  return getToken(ShaperParser::LEFTPAREN, 0);
}

ShaperParser::ExpressionContext* ShaperParser::PrimaryExpressionContext::expression() {
  return getRuleContext<ShaperParser::ExpressionContext>(0);
}

tree::TerminalNode* ShaperParser::PrimaryExpressionContext::RIGHTPAREN() {
  return getToken(ShaperParser::RIGHTPAREN, 0);
}


size_t ShaperParser::PrimaryExpressionContext::getRuleIndex() const {
  return ShaperParser::RulePrimaryExpression;
}

void ShaperParser::PrimaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpression(this);
}

void ShaperParser::PrimaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpression(this);
}


antlrcpp::Any ShaperParser::PrimaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitPrimaryExpression(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::PrimaryExpressionContext* ShaperParser::primaryExpression() {
  PrimaryExpressionContext *_localctx = _tracker.createInstance<PrimaryExpressionContext>(_ctx, getState());
  enterRule(_localctx, 50, ShaperParser::RulePrimaryExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(345);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ShaperParser::Identifier: {
        enterOuterAlt(_localctx, 1);
        setState(339);
        match(ShaperParser::Identifier);
        break;
      }

      case ShaperParser::Constant: {
        enterOuterAlt(_localctx, 2);
        setState(340);
        match(ShaperParser::Constant);
        break;
      }

      case ShaperParser::LEFTPAREN: {
        enterOuterAlt(_localctx, 3);
        setState(341);
        match(ShaperParser::LEFTPAREN);
        setState(342);
        expression();
        setState(343);
        match(ShaperParser::RIGHTPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionParameterListContext ------------------------------------------------------------------

ShaperParser::FunctionParameterListContext::FunctionParameterListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::ExpressionContext* ShaperParser::FunctionParameterListContext::expression() {
  return getRuleContext<ShaperParser::ExpressionContext>(0);
}

ShaperParser::FunctionParameterListContext* ShaperParser::FunctionParameterListContext::functionParameterList() {
  return getRuleContext<ShaperParser::FunctionParameterListContext>(0);
}

tree::TerminalNode* ShaperParser::FunctionParameterListContext::COMMA() {
  return getToken(ShaperParser::COMMA, 0);
}


size_t ShaperParser::FunctionParameterListContext::getRuleIndex() const {
  return ShaperParser::RuleFunctionParameterList;
}

void ShaperParser::FunctionParameterListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionParameterList(this);
}

void ShaperParser::FunctionParameterListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionParameterList(this);
}


antlrcpp::Any ShaperParser::FunctionParameterListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitFunctionParameterList(this);
  else
    return visitor->visitChildren(this);
}


ShaperParser::FunctionParameterListContext* ShaperParser::functionParameterList() {
   return functionParameterList(0);
}

ShaperParser::FunctionParameterListContext* ShaperParser::functionParameterList(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  ShaperParser::FunctionParameterListContext *_localctx = _tracker.createInstance<FunctionParameterListContext>(_ctx, parentState);
  ShaperParser::FunctionParameterListContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 52;
  enterRecursionRule(_localctx, 52, ShaperParser::RuleFunctionParameterList, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(348);
    expression();
    _ctx->stop = _input->LT(-1);
    setState(355);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<FunctionParameterListContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RuleFunctionParameterList);
        setState(350);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(351);
        match(ShaperParser::COMMA);
        setState(352);
        expression(); 
      }
      setState(357);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AssignmentOperatorContext ------------------------------------------------------------------

ShaperParser::AssignmentOperatorContext::AssignmentOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::AssignmentOperatorContext::ASSIGN() {
  return getToken(ShaperParser::ASSIGN, 0);
}

tree::TerminalNode* ShaperParser::AssignmentOperatorContext::PLUSASSIGN() {
  return getToken(ShaperParser::PLUSASSIGN, 0);
}

tree::TerminalNode* ShaperParser::AssignmentOperatorContext::MINUSASSIGN() {
  return getToken(ShaperParser::MINUSASSIGN, 0);
}

tree::TerminalNode* ShaperParser::AssignmentOperatorContext::MULTIPLYASSIGN() {
  return getToken(ShaperParser::MULTIPLYASSIGN, 0);
}

tree::TerminalNode* ShaperParser::AssignmentOperatorContext::DIVIDEASSIGN() {
  return getToken(ShaperParser::DIVIDEASSIGN, 0);
}

tree::TerminalNode* ShaperParser::AssignmentOperatorContext::MODULOASSIGN() {
  return getToken(ShaperParser::MODULOASSIGN, 0);
}


size_t ShaperParser::AssignmentOperatorContext::getRuleIndex() const {
  return ShaperParser::RuleAssignmentOperator;
}

void ShaperParser::AssignmentOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignmentOperator(this);
}

void ShaperParser::AssignmentOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignmentOperator(this);
}


antlrcpp::Any ShaperParser::AssignmentOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitAssignmentOperator(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::AssignmentOperatorContext* ShaperParser::assignmentOperator() {
  AssignmentOperatorContext *_localctx = _tracker.createInstance<AssignmentOperatorContext>(_ctx, getState());
  enterRule(_localctx, 54, ShaperParser::RuleAssignmentOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(358);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ShaperParser::ASSIGN)
      | (1ULL << ShaperParser::PLUSASSIGN)
      | (1ULL << ShaperParser::MINUSASSIGN)
      | (1ULL << ShaperParser::MULTIPLYASSIGN)
      | (1ULL << ShaperParser::DIVIDEASSIGN)
      | (1ULL << ShaperParser::MODULOASSIGN))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelationalOperatorContext ------------------------------------------------------------------

ShaperParser::RelationalOperatorContext::RelationalOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::RelationalOperatorContext::LESS() {
  return getToken(ShaperParser::LESS, 0);
}

tree::TerminalNode* ShaperParser::RelationalOperatorContext::MOREE() {
  return getToken(ShaperParser::MOREE, 0);
}

tree::TerminalNode* ShaperParser::RelationalOperatorContext::LESSEQUAL() {
  return getToken(ShaperParser::LESSEQUAL, 0);
}

tree::TerminalNode* ShaperParser::RelationalOperatorContext::MOREEQUAL() {
  return getToken(ShaperParser::MOREEQUAL, 0);
}


size_t ShaperParser::RelationalOperatorContext::getRuleIndex() const {
  return ShaperParser::RuleRelationalOperator;
}

void ShaperParser::RelationalOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationalOperator(this);
}

void ShaperParser::RelationalOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationalOperator(this);
}


antlrcpp::Any ShaperParser::RelationalOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitRelationalOperator(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::RelationalOperatorContext* ShaperParser::relationalOperator() {
  RelationalOperatorContext *_localctx = _tracker.createInstance<RelationalOperatorContext>(_ctx, getState());
  enterRule(_localctx, 56, ShaperParser::RuleRelationalOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(360);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ShaperParser::LESS)
      | (1ULL << ShaperParser::MOREE)
      | (1ULL << ShaperParser::LESSEQUAL)
      | (1ULL << ShaperParser::MOREEQUAL))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOperatorContext ------------------------------------------------------------------

ShaperParser::UnaryOperatorContext::UnaryOperatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::UnaryOperatorContext::MINUS() {
  return getToken(ShaperParser::MINUS, 0);
}

tree::TerminalNode* ShaperParser::UnaryOperatorContext::EXCLAMATION() {
  return getToken(ShaperParser::EXCLAMATION, 0);
}

tree::TerminalNode* ShaperParser::UnaryOperatorContext::PLUSPLUS() {
  return getToken(ShaperParser::PLUSPLUS, 0);
}

tree::TerminalNode* ShaperParser::UnaryOperatorContext::MINUSMINUS() {
  return getToken(ShaperParser::MINUSMINUS, 0);
}


size_t ShaperParser::UnaryOperatorContext::getRuleIndex() const {
  return ShaperParser::RuleUnaryOperator;
}

void ShaperParser::UnaryOperatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOperator(this);
}

void ShaperParser::UnaryOperatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOperator(this);
}


antlrcpp::Any ShaperParser::UnaryOperatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitUnaryOperator(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::UnaryOperatorContext* ShaperParser::unaryOperator() {
  UnaryOperatorContext *_localctx = _tracker.createInstance<UnaryOperatorContext>(_ctx, getState());
  enterRule(_localctx, 58, ShaperParser::RuleUnaryOperator);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(362);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ShaperParser::MINUS)
      | (1ULL << ShaperParser::PLUSPLUS)
      | (1ULL << ShaperParser::MINUSMINUS)
      | (1ULL << ShaperParser::EXCLAMATION))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ShaperParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::CompoundStatementContext* ShaperParser::StatementContext::compoundStatement() {
  return getRuleContext<ShaperParser::CompoundStatementContext>(0);
}

ShaperParser::ExpressionContext* ShaperParser::StatementContext::expression() {
  return getRuleContext<ShaperParser::ExpressionContext>(0);
}

tree::TerminalNode* ShaperParser::StatementContext::SEMICOLON() {
  return getToken(ShaperParser::SEMICOLON, 0);
}

ShaperParser::PaintStatementContext* ShaperParser::StatementContext::paintStatement() {
  return getRuleContext<ShaperParser::PaintStatementContext>(0);
}

ShaperParser::SelectionStatementContext* ShaperParser::StatementContext::selectionStatement() {
  return getRuleContext<ShaperParser::SelectionStatementContext>(0);
}

ShaperParser::LabeledStatementContext* ShaperParser::StatementContext::labeledStatement() {
  return getRuleContext<ShaperParser::LabeledStatementContext>(0);
}

ShaperParser::IterationStatementContext* ShaperParser::StatementContext::iterationStatement() {
  return getRuleContext<ShaperParser::IterationStatementContext>(0);
}

ShaperParser::JumpStatementContext* ShaperParser::StatementContext::jumpStatement() {
  return getRuleContext<ShaperParser::JumpStatementContext>(0);
}


size_t ShaperParser::StatementContext::getRuleIndex() const {
  return ShaperParser::RuleStatement;
}

void ShaperParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void ShaperParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}


antlrcpp::Any ShaperParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::StatementContext* ShaperParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 60, ShaperParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(375);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ShaperParser::LEFTBRACKET: {
        enterOuterAlt(_localctx, 1);
        setState(364);
        compoundStatement();
        break;
      }

      case ShaperParser::LEFTPAREN:
      case ShaperParser::MINUS:
      case ShaperParser::PLUSPLUS:
      case ShaperParser::MINUSMINUS:
      case ShaperParser::EXCLAMATION:
      case ShaperParser::Constant:
      case ShaperParser::Identifier: {
        enterOuterAlt(_localctx, 2);
        setState(365);
        expression();
        setState(366);
        match(ShaperParser::SEMICOLON);
        break;
      }

      case ShaperParser::PAINT: {
        enterOuterAlt(_localctx, 3);
        setState(368);
        paintStatement();
        setState(369);
        match(ShaperParser::SEMICOLON);
        break;
      }

      case ShaperParser::IF:
      case ShaperParser::SWITCH: {
        enterOuterAlt(_localctx, 4);
        setState(371);
        selectionStatement();
        break;
      }

      case ShaperParser::CASE:
      case ShaperParser::DEFAULT: {
        enterOuterAlt(_localctx, 5);
        setState(372);
        labeledStatement();
        break;
      }

      case ShaperParser::WHILE:
      case ShaperParser::FOR: {
        enterOuterAlt(_localctx, 6);
        setState(373);
        iterationStatement();
        break;
      }

      case ShaperParser::CONTINUE:
      case ShaperParser::BREAK:
      case ShaperParser::RETURN: {
        enterOuterAlt(_localctx, 7);
        setState(374);
        jumpStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PaintStatementContext ------------------------------------------------------------------

ShaperParser::PaintStatementContext::PaintStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::PaintStatementContext::PAINT() {
  return getToken(ShaperParser::PAINT, 0);
}

ShaperParser::ShapeIndicatorContext* ShaperParser::PaintStatementContext::shapeIndicator() {
  return getRuleContext<ShaperParser::ShapeIndicatorContext>(0);
}


size_t ShaperParser::PaintStatementContext::getRuleIndex() const {
  return ShaperParser::RulePaintStatement;
}

void ShaperParser::PaintStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPaintStatement(this);
}

void ShaperParser::PaintStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPaintStatement(this);
}


antlrcpp::Any ShaperParser::PaintStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitPaintStatement(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::PaintStatementContext* ShaperParser::paintStatement() {
  PaintStatementContext *_localctx = _tracker.createInstance<PaintStatementContext>(_ctx, getState());
  enterRule(_localctx, 62, ShaperParser::RulePaintStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(377);
    match(ShaperParser::PAINT);
    setState(378);
    shapeIndicator();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShapeIndicatorContext ------------------------------------------------------------------

ShaperParser::ShapeIndicatorContext::ShapeIndicatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::ShapeIndicatorContext::LINE() {
  return getToken(ShaperParser::LINE, 0);
}

ShaperParser::LineParametersContext* ShaperParser::ShapeIndicatorContext::lineParameters() {
  return getRuleContext<ShaperParser::LineParametersContext>(0);
}

tree::TerminalNode* ShaperParser::ShapeIndicatorContext::TRIANGLE() {
  return getToken(ShaperParser::TRIANGLE, 0);
}

ShaperParser::TriangleParametersContext* ShaperParser::ShapeIndicatorContext::triangleParameters() {
  return getRuleContext<ShaperParser::TriangleParametersContext>(0);
}

tree::TerminalNode* ShaperParser::ShapeIndicatorContext::RECTANGLE() {
  return getToken(ShaperParser::RECTANGLE, 0);
}

ShaperParser::RectangleParametersContext* ShaperParser::ShapeIndicatorContext::rectangleParameters() {
  return getRuleContext<ShaperParser::RectangleParametersContext>(0);
}

tree::TerminalNode* ShaperParser::ShapeIndicatorContext::CIRCLE() {
  return getToken(ShaperParser::CIRCLE, 0);
}

ShaperParser::CircleParametersContext* ShaperParser::ShapeIndicatorContext::circleParameters() {
  return getRuleContext<ShaperParser::CircleParametersContext>(0);
}


size_t ShaperParser::ShapeIndicatorContext::getRuleIndex() const {
  return ShaperParser::RuleShapeIndicator;
}

void ShaperParser::ShapeIndicatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShapeIndicator(this);
}

void ShaperParser::ShapeIndicatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShapeIndicator(this);
}


antlrcpp::Any ShaperParser::ShapeIndicatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitShapeIndicator(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::ShapeIndicatorContext* ShaperParser::shapeIndicator() {
  ShapeIndicatorContext *_localctx = _tracker.createInstance<ShapeIndicatorContext>(_ctx, getState());
  enterRule(_localctx, 64, ShaperParser::RuleShapeIndicator);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(388);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ShaperParser::LINE: {
        enterOuterAlt(_localctx, 1);
        setState(380);
        match(ShaperParser::LINE);
        setState(381);
        lineParameters();
        break;
      }

      case ShaperParser::TRIANGLE: {
        enterOuterAlt(_localctx, 2);
        setState(382);
        match(ShaperParser::TRIANGLE);
        setState(383);
        triangleParameters();
        break;
      }

      case ShaperParser::RECTANGLE: {
        enterOuterAlt(_localctx, 3);
        setState(384);
        match(ShaperParser::RECTANGLE);
        setState(385);
        rectangleParameters();
        break;
      }

      case ShaperParser::CIRCLE: {
        enterOuterAlt(_localctx, 4);
        setState(386);
        match(ShaperParser::CIRCLE);
        setState(387);
        circleParameters();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LineParametersContext ------------------------------------------------------------------

ShaperParser::LineParametersContext::LineParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::FromStatementContext* ShaperParser::LineParametersContext::fromStatement() {
  return getRuleContext<ShaperParser::FromStatementContext>(0);
}

ShaperParser::ToStatementContext* ShaperParser::LineParametersContext::toStatement() {
  return getRuleContext<ShaperParser::ToStatementContext>(0);
}

ShaperParser::ColorStatementContext* ShaperParser::LineParametersContext::colorStatement() {
  return getRuleContext<ShaperParser::ColorStatementContext>(0);
}


size_t ShaperParser::LineParametersContext::getRuleIndex() const {
  return ShaperParser::RuleLineParameters;
}

void ShaperParser::LineParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLineParameters(this);
}

void ShaperParser::LineParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLineParameters(this);
}


antlrcpp::Any ShaperParser::LineParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitLineParameters(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::LineParametersContext* ShaperParser::lineParameters() {
  LineParametersContext *_localctx = _tracker.createInstance<LineParametersContext>(_ctx, getState());
  enterRule(_localctx, 66, ShaperParser::RuleLineParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(390);
    fromStatement();
    setState(391);
    toStatement();
    setState(393);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ShaperParser::WITH) {
      setState(392);
      colorStatement();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TriangleParametersContext ------------------------------------------------------------------

ShaperParser::TriangleParametersContext::TriangleParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::FromStatementContext* ShaperParser::TriangleParametersContext::fromStatement() {
  return getRuleContext<ShaperParser::FromStatementContext>(0);
}

ShaperParser::ThroughStatementContext* ShaperParser::TriangleParametersContext::throughStatement() {
  return getRuleContext<ShaperParser::ThroughStatementContext>(0);
}

ShaperParser::ToStatementContext* ShaperParser::TriangleParametersContext::toStatement() {
  return getRuleContext<ShaperParser::ToStatementContext>(0);
}

ShaperParser::ColorStatementContext* ShaperParser::TriangleParametersContext::colorStatement() {
  return getRuleContext<ShaperParser::ColorStatementContext>(0);
}


size_t ShaperParser::TriangleParametersContext::getRuleIndex() const {
  return ShaperParser::RuleTriangleParameters;
}

void ShaperParser::TriangleParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTriangleParameters(this);
}

void ShaperParser::TriangleParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTriangleParameters(this);
}


antlrcpp::Any ShaperParser::TriangleParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitTriangleParameters(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::TriangleParametersContext* ShaperParser::triangleParameters() {
  TriangleParametersContext *_localctx = _tracker.createInstance<TriangleParametersContext>(_ctx, getState());
  enterRule(_localctx, 68, ShaperParser::RuleTriangleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    fromStatement();
    setState(396);
    throughStatement();
    setState(397);
    toStatement();
    setState(399);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ShaperParser::WITH) {
      setState(398);
      colorStatement();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RectangleParametersContext ------------------------------------------------------------------

ShaperParser::RectangleParametersContext::RectangleParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::AtStatementContext* ShaperParser::RectangleParametersContext::atStatement() {
  return getRuleContext<ShaperParser::AtStatementContext>(0);
}

ShaperParser::OfStatementContext* ShaperParser::RectangleParametersContext::ofStatement() {
  return getRuleContext<ShaperParser::OfStatementContext>(0);
}

ShaperParser::ColorStatementContext* ShaperParser::RectangleParametersContext::colorStatement() {
  return getRuleContext<ShaperParser::ColorStatementContext>(0);
}


size_t ShaperParser::RectangleParametersContext::getRuleIndex() const {
  return ShaperParser::RuleRectangleParameters;
}

void ShaperParser::RectangleParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRectangleParameters(this);
}

void ShaperParser::RectangleParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRectangleParameters(this);
}


antlrcpp::Any ShaperParser::RectangleParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitRectangleParameters(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::RectangleParametersContext* ShaperParser::rectangleParameters() {
  RectangleParametersContext *_localctx = _tracker.createInstance<RectangleParametersContext>(_ctx, getState());
  enterRule(_localctx, 70, ShaperParser::RuleRectangleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    atStatement();
    setState(402);
    ofStatement();
    setState(404);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ShaperParser::WITH) {
      setState(403);
      colorStatement();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CircleParametersContext ------------------------------------------------------------------

ShaperParser::CircleParametersContext::CircleParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ShaperParser::AtStatementContext* ShaperParser::CircleParametersContext::atStatement() {
  return getRuleContext<ShaperParser::AtStatementContext>(0);
}

ShaperParser::OfStatementContext* ShaperParser::CircleParametersContext::ofStatement() {
  return getRuleContext<ShaperParser::OfStatementContext>(0);
}

ShaperParser::ColorStatementContext* ShaperParser::CircleParametersContext::colorStatement() {
  return getRuleContext<ShaperParser::ColorStatementContext>(0);
}


size_t ShaperParser::CircleParametersContext::getRuleIndex() const {
  return ShaperParser::RuleCircleParameters;
}

void ShaperParser::CircleParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCircleParameters(this);
}

void ShaperParser::CircleParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCircleParameters(this);
}


antlrcpp::Any ShaperParser::CircleParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitCircleParameters(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::CircleParametersContext* ShaperParser::circleParameters() {
  CircleParametersContext *_localctx = _tracker.createInstance<CircleParametersContext>(_ctx, getState());
  enterRule(_localctx, 72, ShaperParser::RuleCircleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(406);
    atStatement();
    setState(407);
    ofStatement();
    setState(409);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ShaperParser::WITH) {
      setState(408);
      colorStatement();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtStatementContext ------------------------------------------------------------------

ShaperParser::AtStatementContext::AtStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::AtStatementContext::AT() {
  return getToken(ShaperParser::AT, 0);
}

ShaperParser::PosSizeParentContext* ShaperParser::AtStatementContext::posSizeParent() {
  return getRuleContext<ShaperParser::PosSizeParentContext>(0);
}


size_t ShaperParser::AtStatementContext::getRuleIndex() const {
  return ShaperParser::RuleAtStatement;
}

void ShaperParser::AtStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtStatement(this);
}

void ShaperParser::AtStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtStatement(this);
}


antlrcpp::Any ShaperParser::AtStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitAtStatement(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::AtStatementContext* ShaperParser::atStatement() {
  AtStatementContext *_localctx = _tracker.createInstance<AtStatementContext>(_ctx, getState());
  enterRule(_localctx, 74, ShaperParser::RuleAtStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(411);
    match(ShaperParser::AT);
    setState(412);
    posSizeParent();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OfStatementContext ------------------------------------------------------------------

ShaperParser::OfStatementContext::OfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::OfStatementContext::OF() {
  return getToken(ShaperParser::OF, 0);
}

ShaperParser::PosSizeParentContext* ShaperParser::OfStatementContext::posSizeParent() {
  return getRuleContext<ShaperParser::PosSizeParentContext>(0);
}

ShaperParser::ExpressionContext* ShaperParser::OfStatementContext::expression() {
  return getRuleContext<ShaperParser::ExpressionContext>(0);
}


size_t ShaperParser::OfStatementContext::getRuleIndex() const {
  return ShaperParser::RuleOfStatement;
}

void ShaperParser::OfStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOfStatement(this);
}

void ShaperParser::OfStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOfStatement(this);
}


antlrcpp::Any ShaperParser::OfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitOfStatement(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::OfStatementContext* ShaperParser::ofStatement() {
  OfStatementContext *_localctx = _tracker.createInstance<OfStatementContext>(_ctx, getState());
  enterRule(_localctx, 76, ShaperParser::RuleOfStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(418);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(414);
      match(ShaperParser::OF);
      setState(415);
      posSizeParent();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(416);
      match(ShaperParser::OF);
      setState(417);
      expression();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FromStatementContext ------------------------------------------------------------------

ShaperParser::FromStatementContext::FromStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::FromStatementContext::FROM() {
  return getToken(ShaperParser::FROM, 0);
}

ShaperParser::PosSizeParentContext* ShaperParser::FromStatementContext::posSizeParent() {
  return getRuleContext<ShaperParser::PosSizeParentContext>(0);
}


size_t ShaperParser::FromStatementContext::getRuleIndex() const {
  return ShaperParser::RuleFromStatement;
}

void ShaperParser::FromStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFromStatement(this);
}

void ShaperParser::FromStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFromStatement(this);
}


antlrcpp::Any ShaperParser::FromStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitFromStatement(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::FromStatementContext* ShaperParser::fromStatement() {
  FromStatementContext *_localctx = _tracker.createInstance<FromStatementContext>(_ctx, getState());
  enterRule(_localctx, 78, ShaperParser::RuleFromStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(420);
    match(ShaperParser::FROM);
    setState(421);
    posSizeParent();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThroughStatementContext ------------------------------------------------------------------

ShaperParser::ThroughStatementContext::ThroughStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::ThroughStatementContext::THROUGH() {
  return getToken(ShaperParser::THROUGH, 0);
}

ShaperParser::PosSizeParentContext* ShaperParser::ThroughStatementContext::posSizeParent() {
  return getRuleContext<ShaperParser::PosSizeParentContext>(0);
}


size_t ShaperParser::ThroughStatementContext::getRuleIndex() const {
  return ShaperParser::RuleThroughStatement;
}

void ShaperParser::ThroughStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThroughStatement(this);
}

void ShaperParser::ThroughStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThroughStatement(this);
}


antlrcpp::Any ShaperParser::ThroughStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitThroughStatement(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::ThroughStatementContext* ShaperParser::throughStatement() {
  ThroughStatementContext *_localctx = _tracker.createInstance<ThroughStatementContext>(_ctx, getState());
  enterRule(_localctx, 80, ShaperParser::RuleThroughStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(423);
    match(ShaperParser::THROUGH);
    setState(424);
    posSizeParent();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ToStatementContext ------------------------------------------------------------------

ShaperParser::ToStatementContext::ToStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::ToStatementContext::TO() {
  return getToken(ShaperParser::TO, 0);
}

ShaperParser::PosSizeParentContext* ShaperParser::ToStatementContext::posSizeParent() {
  return getRuleContext<ShaperParser::PosSizeParentContext>(0);
}


size_t ShaperParser::ToStatementContext::getRuleIndex() const {
  return ShaperParser::RuleToStatement;
}

void ShaperParser::ToStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterToStatement(this);
}

void ShaperParser::ToStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitToStatement(this);
}


antlrcpp::Any ShaperParser::ToStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitToStatement(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::ToStatementContext* ShaperParser::toStatement() {
  ToStatementContext *_localctx = _tracker.createInstance<ToStatementContext>(_ctx, getState());
  enterRule(_localctx, 82, ShaperParser::RuleToStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(426);
    match(ShaperParser::TO);
    setState(427);
    posSizeParent();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ColorStatementContext ------------------------------------------------------------------

ShaperParser::ColorStatementContext::ColorStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::ColorStatementContext::WITH() {
  return getToken(ShaperParser::WITH, 0);
}

tree::TerminalNode* ShaperParser::ColorStatementContext::Identifier() {
  return getToken(ShaperParser::Identifier, 0);
}

tree::TerminalNode* ShaperParser::ColorStatementContext::Constant() {
  return getToken(ShaperParser::Constant, 0);
}


size_t ShaperParser::ColorStatementContext::getRuleIndex() const {
  return ShaperParser::RuleColorStatement;
}

void ShaperParser::ColorStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColorStatement(this);
}

void ShaperParser::ColorStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColorStatement(this);
}


antlrcpp::Any ShaperParser::ColorStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitColorStatement(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::ColorStatementContext* ShaperParser::colorStatement() {
  ColorStatementContext *_localctx = _tracker.createInstance<ColorStatementContext>(_ctx, getState());
  enterRule(_localctx, 84, ShaperParser::RuleColorStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(429);
    match(ShaperParser::WITH);
    setState(430);
    _la = _input->LA(1);
    if (!(_la == ShaperParser::Constant

    || _la == ShaperParser::Identifier)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PosSizeParentContext ------------------------------------------------------------------

ShaperParser::PosSizeParentContext::PosSizeParentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::PosSizeParentContext::LEFTPAREN() {
  return getToken(ShaperParser::LEFTPAREN, 0);
}

std::vector<ShaperParser::ExpressionContext *> ShaperParser::PosSizeParentContext::expression() {
  return getRuleContexts<ShaperParser::ExpressionContext>();
}

ShaperParser::ExpressionContext* ShaperParser::PosSizeParentContext::expression(size_t i) {
  return getRuleContext<ShaperParser::ExpressionContext>(i);
}

tree::TerminalNode* ShaperParser::PosSizeParentContext::COMMA() {
  return getToken(ShaperParser::COMMA, 0);
}

tree::TerminalNode* ShaperParser::PosSizeParentContext::RIGHTPAREN() {
  return getToken(ShaperParser::RIGHTPAREN, 0);
}


size_t ShaperParser::PosSizeParentContext::getRuleIndex() const {
  return ShaperParser::RulePosSizeParent;
}

void ShaperParser::PosSizeParentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPosSizeParent(this);
}

void ShaperParser::PosSizeParentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPosSizeParent(this);
}


antlrcpp::Any ShaperParser::PosSizeParentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitPosSizeParent(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::PosSizeParentContext* ShaperParser::posSizeParent() {
  PosSizeParentContext *_localctx = _tracker.createInstance<PosSizeParentContext>(_ctx, getState());
  enterRule(_localctx, 86, ShaperParser::RulePosSizeParent);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(432);
    match(ShaperParser::LEFTPAREN);
    setState(433);
    expression();
    setState(434);
    match(ShaperParser::COMMA);
    setState(435);
    expression();
    setState(436);
    match(ShaperParser::RIGHTPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SelectionStatementContext ------------------------------------------------------------------

ShaperParser::SelectionStatementContext::SelectionStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::SelectionStatementContext::IF() {
  return getToken(ShaperParser::IF, 0);
}

std::vector<tree::TerminalNode *> ShaperParser::SelectionStatementContext::LEFTPAREN() {
  return getTokens(ShaperParser::LEFTPAREN);
}

tree::TerminalNode* ShaperParser::SelectionStatementContext::LEFTPAREN(size_t i) {
  return getToken(ShaperParser::LEFTPAREN, i);
}

std::vector<ShaperParser::ExpressionContext *> ShaperParser::SelectionStatementContext::expression() {
  return getRuleContexts<ShaperParser::ExpressionContext>();
}

ShaperParser::ExpressionContext* ShaperParser::SelectionStatementContext::expression(size_t i) {
  return getRuleContext<ShaperParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> ShaperParser::SelectionStatementContext::RIGHTPAREN() {
  return getTokens(ShaperParser::RIGHTPAREN);
}

tree::TerminalNode* ShaperParser::SelectionStatementContext::RIGHTPAREN(size_t i) {
  return getToken(ShaperParser::RIGHTPAREN, i);
}

std::vector<ShaperParser::CompoundStatementContext *> ShaperParser::SelectionStatementContext::compoundStatement() {
  return getRuleContexts<ShaperParser::CompoundStatementContext>();
}

ShaperParser::CompoundStatementContext* ShaperParser::SelectionStatementContext::compoundStatement(size_t i) {
  return getRuleContext<ShaperParser::CompoundStatementContext>(i);
}

std::vector<tree::TerminalNode *> ShaperParser::SelectionStatementContext::ELIF() {
  return getTokens(ShaperParser::ELIF);
}

tree::TerminalNode* ShaperParser::SelectionStatementContext::ELIF(size_t i) {
  return getToken(ShaperParser::ELIF, i);
}

tree::TerminalNode* ShaperParser::SelectionStatementContext::ELSE() {
  return getToken(ShaperParser::ELSE, 0);
}

tree::TerminalNode* ShaperParser::SelectionStatementContext::SWITCH() {
  return getToken(ShaperParser::SWITCH, 0);
}

tree::TerminalNode* ShaperParser::SelectionStatementContext::LEFTBRACKET() {
  return getToken(ShaperParser::LEFTBRACKET, 0);
}

tree::TerminalNode* ShaperParser::SelectionStatementContext::RIGHTBRACKET() {
  return getToken(ShaperParser::RIGHTBRACKET, 0);
}

std::vector<ShaperParser::LabeledStatementContext *> ShaperParser::SelectionStatementContext::labeledStatement() {
  return getRuleContexts<ShaperParser::LabeledStatementContext>();
}

ShaperParser::LabeledStatementContext* ShaperParser::SelectionStatementContext::labeledStatement(size_t i) {
  return getRuleContext<ShaperParser::LabeledStatementContext>(i);
}


size_t ShaperParser::SelectionStatementContext::getRuleIndex() const {
  return ShaperParser::RuleSelectionStatement;
}

void ShaperParser::SelectionStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectionStatement(this);
}

void ShaperParser::SelectionStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectionStatement(this);
}


antlrcpp::Any ShaperParser::SelectionStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitSelectionStatement(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::SelectionStatementContext* ShaperParser::selectionStatement() {
  SelectionStatementContext *_localctx = _tracker.createInstance<SelectionStatementContext>(_ctx, getState());
  enterRule(_localctx, 88, ShaperParser::RuleSelectionStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(470);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ShaperParser::IF: {
        enterOuterAlt(_localctx, 1);
        setState(438);
        match(ShaperParser::IF);
        setState(439);
        match(ShaperParser::LEFTPAREN);
        setState(440);
        expression();
        setState(441);
        match(ShaperParser::RIGHTPAREN);
        setState(442);
        compoundStatement();
        setState(450);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == ShaperParser::ELIF) {
          setState(443);
          match(ShaperParser::ELIF);
          setState(444);
          match(ShaperParser::LEFTPAREN);
          setState(445);
          expression();
          setState(446);
          match(ShaperParser::RIGHTPAREN);
          setState(452);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(455);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == ShaperParser::ELSE) {
          setState(453);
          match(ShaperParser::ELSE);
          setState(454);
          compoundStatement();
        }
        break;
      }

      case ShaperParser::SWITCH: {
        enterOuterAlt(_localctx, 2);
        setState(457);
        match(ShaperParser::SWITCH);
        setState(458);
        match(ShaperParser::LEFTPAREN);
        setState(459);
        expression();
        setState(460);
        match(ShaperParser::RIGHTPAREN);
        setState(461);
        match(ShaperParser::LEFTBRACKET);
        setState(465);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == ShaperParser::CASE

        || _la == ShaperParser::DEFAULT) {
          setState(462);
          labeledStatement();
          setState(467);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(468);
        match(ShaperParser::RIGHTBRACKET);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LabeledStatementContext ------------------------------------------------------------------

ShaperParser::LabeledStatementContext::LabeledStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::LabeledStatementContext::CASE() {
  return getToken(ShaperParser::CASE, 0);
}

ShaperParser::LogicalORExpressionContext* ShaperParser::LabeledStatementContext::logicalORExpression() {
  return getRuleContext<ShaperParser::LogicalORExpressionContext>(0);
}

tree::TerminalNode* ShaperParser::LabeledStatementContext::COLON() {
  return getToken(ShaperParser::COLON, 0);
}

ShaperParser::ExpressionContext* ShaperParser::LabeledStatementContext::expression() {
  return getRuleContext<ShaperParser::ExpressionContext>(0);
}

tree::TerminalNode* ShaperParser::LabeledStatementContext::DEFAULT() {
  return getToken(ShaperParser::DEFAULT, 0);
}


size_t ShaperParser::LabeledStatementContext::getRuleIndex() const {
  return ShaperParser::RuleLabeledStatement;
}

void ShaperParser::LabeledStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabeledStatement(this);
}

void ShaperParser::LabeledStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabeledStatement(this);
}


antlrcpp::Any ShaperParser::LabeledStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitLabeledStatement(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::LabeledStatementContext* ShaperParser::labeledStatement() {
  LabeledStatementContext *_localctx = _tracker.createInstance<LabeledStatementContext>(_ctx, getState());
  enterRule(_localctx, 90, ShaperParser::RuleLabeledStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(480);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ShaperParser::CASE: {
        enterOuterAlt(_localctx, 1);
        setState(472);
        match(ShaperParser::CASE);
        setState(473);
        logicalORExpression(0);
        setState(474);
        match(ShaperParser::COLON);
        setState(475);
        expression();
        break;
      }

      case ShaperParser::DEFAULT: {
        enterOuterAlt(_localctx, 2);
        setState(477);
        match(ShaperParser::DEFAULT);
        setState(478);
        match(ShaperParser::COLON);
        setState(479);
        expression();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IterationStatementContext ------------------------------------------------------------------

ShaperParser::IterationStatementContext::IterationStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::IterationStatementContext::WHILE() {
  return getToken(ShaperParser::WHILE, 0);
}

tree::TerminalNode* ShaperParser::IterationStatementContext::LEFTPAREN() {
  return getToken(ShaperParser::LEFTPAREN, 0);
}

std::vector<ShaperParser::ExpressionContext *> ShaperParser::IterationStatementContext::expression() {
  return getRuleContexts<ShaperParser::ExpressionContext>();
}

ShaperParser::ExpressionContext* ShaperParser::IterationStatementContext::expression(size_t i) {
  return getRuleContext<ShaperParser::ExpressionContext>(i);
}

tree::TerminalNode* ShaperParser::IterationStatementContext::RIGHTPAREN() {
  return getToken(ShaperParser::RIGHTPAREN, 0);
}

ShaperParser::CompoundStatementContext* ShaperParser::IterationStatementContext::compoundStatement() {
  return getRuleContext<ShaperParser::CompoundStatementContext>(0);
}

tree::TerminalNode* ShaperParser::IterationStatementContext::FOR() {
  return getToken(ShaperParser::FOR, 0);
}

std::vector<tree::TerminalNode *> ShaperParser::IterationStatementContext::SEMICOLON() {
  return getTokens(ShaperParser::SEMICOLON);
}

tree::TerminalNode* ShaperParser::IterationStatementContext::SEMICOLON(size_t i) {
  return getToken(ShaperParser::SEMICOLON, i);
}

std::vector<ShaperParser::DeclarationContext *> ShaperParser::IterationStatementContext::declaration() {
  return getRuleContexts<ShaperParser::DeclarationContext>();
}

ShaperParser::DeclarationContext* ShaperParser::IterationStatementContext::declaration(size_t i) {
  return getRuleContext<ShaperParser::DeclarationContext>(i);
}


size_t ShaperParser::IterationStatementContext::getRuleIndex() const {
  return ShaperParser::RuleIterationStatement;
}

void ShaperParser::IterationStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIterationStatement(this);
}

void ShaperParser::IterationStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIterationStatement(this);
}


antlrcpp::Any ShaperParser::IterationStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitIterationStatement(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::IterationStatementContext* ShaperParser::iterationStatement() {
  IterationStatementContext *_localctx = _tracker.createInstance<IterationStatementContext>(_ctx, getState());
  enterRule(_localctx, 92, ShaperParser::RuleIterationStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(506);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ShaperParser::WHILE: {
        enterOuterAlt(_localctx, 1);
        setState(482);
        match(ShaperParser::WHILE);
        setState(483);
        match(ShaperParser::LEFTPAREN);
        setState(484);
        expression();
        setState(485);
        match(ShaperParser::RIGHTPAREN);
        setState(486);
        compoundStatement();
        break;
      }

      case ShaperParser::FOR: {
        enterOuterAlt(_localctx, 2);
        setState(488);
        match(ShaperParser::FOR);
        setState(489);
        match(ShaperParser::LEFTPAREN);
        setState(492);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case ShaperParser::LEFTPAREN:
          case ShaperParser::MINUS:
          case ShaperParser::PLUSPLUS:
          case ShaperParser::MINUSMINUS:
          case ShaperParser::EXCLAMATION:
          case ShaperParser::Constant:
          case ShaperParser::Identifier: {
            setState(490);
            expression();
            break;
          }

          case ShaperParser::BOOL:
          case ShaperParser::INT:
          case ShaperParser::LONG:
          case ShaperParser::CHAR:
          case ShaperParser::FLOAT:
          case ShaperParser::DOUBLE:
          case ShaperParser::COLOR:
          case ShaperParser::STRUCT:
          case ShaperParser::ARRAY:
          case ShaperParser::LIST:
          case ShaperParser::CONST: {
            setState(491);
            declaration();
            break;
          }

          case ShaperParser::SEMICOLON: {
            break;
          }

        default:
          break;
        }
        setState(494);
        match(ShaperParser::SEMICOLON);
        setState(497);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case ShaperParser::LEFTPAREN:
          case ShaperParser::MINUS:
          case ShaperParser::PLUSPLUS:
          case ShaperParser::MINUSMINUS:
          case ShaperParser::EXCLAMATION:
          case ShaperParser::Constant:
          case ShaperParser::Identifier: {
            setState(495);
            expression();
            break;
          }

          case ShaperParser::BOOL:
          case ShaperParser::INT:
          case ShaperParser::LONG:
          case ShaperParser::CHAR:
          case ShaperParser::FLOAT:
          case ShaperParser::DOUBLE:
          case ShaperParser::COLOR:
          case ShaperParser::STRUCT:
          case ShaperParser::ARRAY:
          case ShaperParser::LIST:
          case ShaperParser::CONST: {
            setState(496);
            declaration();
            break;
          }

          case ShaperParser::SEMICOLON: {
            break;
          }

        default:
          break;
        }
        setState(499);
        match(ShaperParser::SEMICOLON);
        setState(502);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case ShaperParser::LEFTPAREN:
          case ShaperParser::MINUS:
          case ShaperParser::PLUSPLUS:
          case ShaperParser::MINUSMINUS:
          case ShaperParser::EXCLAMATION:
          case ShaperParser::Constant:
          case ShaperParser::Identifier: {
            setState(500);
            expression();
            break;
          }

          case ShaperParser::BOOL:
          case ShaperParser::INT:
          case ShaperParser::LONG:
          case ShaperParser::CHAR:
          case ShaperParser::FLOAT:
          case ShaperParser::DOUBLE:
          case ShaperParser::COLOR:
          case ShaperParser::STRUCT:
          case ShaperParser::ARRAY:
          case ShaperParser::LIST:
          case ShaperParser::CONST: {
            setState(501);
            declaration();
            break;
          }

          case ShaperParser::RIGHTPAREN: {
            break;
          }

        default:
          break;
        }
        setState(504);
        match(ShaperParser::RIGHTPAREN);
        setState(505);
        compoundStatement();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- JumpStatementContext ------------------------------------------------------------------

ShaperParser::JumpStatementContext::JumpStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ShaperParser::JumpStatementContext::CONTINUE() {
  return getToken(ShaperParser::CONTINUE, 0);
}

tree::TerminalNode* ShaperParser::JumpStatementContext::SEMICOLON() {
  return getToken(ShaperParser::SEMICOLON, 0);
}

tree::TerminalNode* ShaperParser::JumpStatementContext::BREAK() {
  return getToken(ShaperParser::BREAK, 0);
}

tree::TerminalNode* ShaperParser::JumpStatementContext::RETURN() {
  return getToken(ShaperParser::RETURN, 0);
}

ShaperParser::ExpressionContext* ShaperParser::JumpStatementContext::expression() {
  return getRuleContext<ShaperParser::ExpressionContext>(0);
}


size_t ShaperParser::JumpStatementContext::getRuleIndex() const {
  return ShaperParser::RuleJumpStatement;
}

void ShaperParser::JumpStatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJumpStatement(this);
}

void ShaperParser::JumpStatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<ShaperListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJumpStatement(this);
}


antlrcpp::Any ShaperParser::JumpStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ShaperVisitor*>(visitor))
    return parserVisitor->visitJumpStatement(this);
  else
    return visitor->visitChildren(this);
}

ShaperParser::JumpStatementContext* ShaperParser::jumpStatement() {
  JumpStatementContext *_localctx = _tracker.createInstance<JumpStatementContext>(_ctx, getState());
  enterRule(_localctx, 94, ShaperParser::RuleJumpStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(517);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ShaperParser::CONTINUE: {
        enterOuterAlt(_localctx, 1);
        setState(508);
        match(ShaperParser::CONTINUE);
        setState(509);
        match(ShaperParser::SEMICOLON);
        break;
      }

      case ShaperParser::BREAK: {
        enterOuterAlt(_localctx, 2);
        setState(510);
        match(ShaperParser::BREAK);
        setState(511);
        match(ShaperParser::SEMICOLON);
        break;
      }

      case ShaperParser::RETURN: {
        enterOuterAlt(_localctx, 3);
        setState(512);
        match(ShaperParser::RETURN);
        setState(514);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (((((_la - 12) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 12)) & ((1ULL << (ShaperParser::LEFTPAREN - 12))
          | (1ULL << (ShaperParser::MINUS - 12))
          | (1ULL << (ShaperParser::PLUSPLUS - 12))
          | (1ULL << (ShaperParser::MINUSMINUS - 12))
          | (1ULL << (ShaperParser::EXCLAMATION - 12))
          | (1ULL << (ShaperParser::Constant - 12))
          | (1ULL << (ShaperParser::Identifier - 12)))) != 0)) {
          setState(513);
          expression();
        }
        setState(516);
        match(ShaperParser::SEMICOLON);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool ShaperParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return parameterListSempred(antlrcpp::downCast<ParameterListContext *>(context), predicateIndex);
    case 14: return structDeclarationListSempred(antlrcpp::downCast<StructDeclarationListContext *>(context), predicateIndex);
    case 17: return logicalORExpressionSempred(antlrcpp::downCast<LogicalORExpressionContext *>(context), predicateIndex);
    case 18: return logicalANDExpressionSempred(antlrcpp::downCast<LogicalANDExpressionContext *>(context), predicateIndex);
    case 19: return equalityExpressionSempred(antlrcpp::downCast<EqualityExpressionContext *>(context), predicateIndex);
    case 20: return relationalExpressionSempred(antlrcpp::downCast<RelationalExpressionContext *>(context), predicateIndex);
    case 21: return additiveExpressionSempred(antlrcpp::downCast<AdditiveExpressionContext *>(context), predicateIndex);
    case 22: return multiplicativeExpressionSempred(antlrcpp::downCast<MultiplicativeExpressionContext *>(context), predicateIndex);
    case 24: return postfixExpressionSempred(antlrcpp::downCast<PostfixExpressionContext *>(context), predicateIndex);
    case 26: return functionParameterListSempred(antlrcpp::downCast<FunctionParameterListContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool ShaperParser::parameterListSempred(ParameterListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool ShaperParser::structDeclarationListSempred(StructDeclarationListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool ShaperParser::logicalORExpressionSempred(LogicalORExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 2: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool ShaperParser::logicalANDExpressionSempred(LogicalANDExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool ShaperParser::equalityExpressionSempred(EqualityExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 2);
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool ShaperParser::relationalExpressionSempred(RelationalExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool ShaperParser::additiveExpressionSempred(AdditiveExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 2);
    case 8: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool ShaperParser::multiplicativeExpressionSempred(MultiplicativeExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 9: return precpred(_ctx, 3);
    case 10: return precpred(_ctx, 2);
    case 11: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool ShaperParser::postfixExpressionSempred(PostfixExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 12: return precpred(_ctx, 4);
    case 13: return precpred(_ctx, 3);
    case 14: return precpred(_ctx, 2);
    case 15: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool ShaperParser::functionParameterListSempred(FunctionParameterListContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 16: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> ShaperParser::_decisionToDFA;
atn::PredictionContextCache ShaperParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ShaperParser::_atn;
std::vector<uint16_t> ShaperParser::_serializedATN;

std::vector<std::string> ShaperParser::_ruleNames = {
  "programm", "externalDeclaration", "functionDefinition", "functionSpecifier", 
  "typeSpecifier", "declarator", "parameterList", "parameterDeclaration", 
  "compoundStatement", "declaration", "declarationSpecifier", "declarationType", 
  "initDeclarator", "structDeclarator", "structDeclarationList", "expression", 
  "assignmentExpression", "logicalORExpression", "logicalANDExpression", 
  "equalityExpression", "relationalExpression", "additiveExpression", "multiplicativeExpression", 
  "unaryExpression", "postfixExpression", "primaryExpression", "functionParameterList", 
  "assignmentOperator", "relationalOperator", "unaryOperator", "statement", 
  "paintStatement", "shapeIndicator", "lineParameters", "triangleParameters", 
  "rectangleParameters", "circleParameters", "atStatement", "ofStatement", 
  "fromStatement", "throughStatement", "toStatement", "colorStatement", 
  "posSizeParent", "selectionStatement", "labeledStatement", "iterationStatement", 
  "jumpStatement"
};

std::vector<std::string> ShaperParser::_literalNames = {
  "", "'paint'", "'line'", "'triangle'", "'rectangle'", "'circle'", "'at'", 
  "'of'", "'from'", "'through'", "'to'", "'with'", "'('", "')'", "'{'", 
  "'}'", "','", "';'", "':'", "'void'", "'bool'", "'int'", "'long'", "'char'", 
  "'float'", "'double'", "'color'", "'struct'", "'array'", "'list'", "'const'", 
  "'|'", "'&'", "'=='", "'!='", "'+'", "'-'", "'*'", "'/'", "'%'", "'.'", 
  "'++'", "'--'", "'='", "'+='", "'-='", "'*='", "'/='", "'%='", "'<'", 
  "'>'", "'<='", "'>='", "'!'", "'if'", "'elif'", "'else'", "'switch'", 
  "'case'", "'default'", "'while'", "'for'", "'continue'", "'break'", "'return'"
};

std::vector<std::string> ShaperParser::_symbolicNames = {
  "", "PAINT", "LINE", "TRIANGLE", "RECTANGLE", "CIRCLE", "AT", "OF", "FROM", 
  "THROUGH", "TO", "WITH", "LEFTPAREN", "RIGHTPAREN", "LEFTBRACKET", "RIGHTBRACKET", 
  "COMMA", "SEMICOLON", "COLON", "VOID", "BOOL", "INT", "LONG", "CHAR", 
  "FLOAT", "DOUBLE", "COLOR", "STRUCT", "ARRAY", "LIST", "CONST", "OR", 
  "AND", "EQUAL", "NOTEQUAL", "PLUS", "MINUS", "MULTIPLY", "DIVIDE", "MODULO", 
  "DOT", "PLUSPLUS", "MINUSMINUS", "ASSIGN", "PLUSASSIGN", "MINUSASSIGN", 
  "MULTIPLYASSIGN", "DIVIDEASSIGN", "MODULOASSIGN", "LESS", "MOREE", "LESSEQUAL", 
  "MOREEQUAL", "EXCLAMATION", "IF", "ELIF", "ELSE", "SWITCH", "CASE", "DEFAULT", 
  "WHILE", "FOR", "CONTINUE", "BREAK", "RETURN", "Constant", "Identifier", 
  "WS", "WhiteSpace"
};

dfa::Vocabulary ShaperParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ShaperParser::_tokenNames;

ShaperParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x46, 0x20a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x3, 0x2, 
       0x7, 0x2, 0x64, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x67, 0xb, 0x2, 0x3, 
       0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x6d, 0xa, 0x3, 0x3, 
       0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 
       0x3, 0x5, 0x5, 0x5, 0x77, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
       0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
       0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x87, 0xa, 
       0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
       0x5, 0x7, 0x8f, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x97, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 
       0x9a, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 
       0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xa4, 0xa, 0xa, 0xc, 0xa, 
       0xe, 0xa, 0xa7, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xb, 0x3, 0xb, 
       0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xaf, 0xa, 0xb, 0x3, 0xc, 0x3, 0xc, 
       0x3, 0xc, 0x5, 0xc, 0xb4, 0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 
       0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x3, 
       0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xc2, 0xa, 0xd, 0x3, 0xd, 0x3, 
       0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xc8, 0xa, 0xd, 0x3, 0xe, 0x3, 
       0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xce, 0xa, 0xe, 0x3, 0xf, 0x3, 
       0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 
       0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 
       0x7, 0x10, 0xde, 0xa, 0x10, 0xc, 0x10, 0xe, 0x10, 0xe1, 0xb, 0x10, 
       0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 
       0x3, 0x12, 0x5, 0x12, 0xea, 0xa, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
       0x13, 0x3, 0x13, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0xf2, 0xa, 0x13, 
       0xc, 0x13, 0xe, 0x13, 0xf5, 0xb, 0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 
       0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x7, 0x14, 0xfd, 0xa, 0x14, 
       0xc, 0x14, 0xe, 0x14, 0x100, 0xb, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 
       0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 
       0x15, 0x7, 0x15, 0x10b, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0x10e, 0xb, 
       0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x3, 0x16, 0x7, 0x16, 0x117, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 
       0x11a, 0xb, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 
       0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x7, 0x17, 0x125, 
       0xa, 0x17, 0xc, 0x17, 0xe, 0x17, 0x128, 0xb, 0x17, 0x3, 0x18, 0x3, 
       0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 
       0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0x136, 
       0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0x139, 0xb, 0x18, 0x3, 0x19, 0x3, 
       0x19, 0x3, 0x19, 0x3, 0x19, 0x5, 0x19, 0x13f, 0xa, 0x19, 0x3, 0x1a, 
       0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
       0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
       0x5, 0x1a, 0x14e, 0xa, 0x1a, 0x3, 0x1a, 0x7, 0x1a, 0x151, 0xa, 0x1a, 
       0xc, 0x1a, 0xe, 0x1a, 0x154, 0xb, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
       0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x5, 0x1b, 0x15c, 0xa, 0x1b, 
       0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
       0x7, 0x1c, 0x164, 0xa, 0x1c, 0xc, 0x1c, 0xe, 0x1c, 0x167, 0xb, 0x1c, 
       0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 
       0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 
       0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 
       0x17a, 0xa, 0x20, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 
       0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x3, 
       0x22, 0x5, 0x22, 0x187, 0xa, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x23, 
       0x5, 0x23, 0x18c, 0xa, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
       0x24, 0x5, 0x24, 0x192, 0xa, 0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 
       0x5, 0x25, 0x197, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x5, 
       0x26, 0x19c, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 
       0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 0x28, 0x1a5, 0xa, 0x28, 0x3, 
       0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
       0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
       0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
       0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 
       0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 0x1c3, 0xa, 0x2e, 
       0xc, 0x2e, 0xe, 0x2e, 0x1c6, 0xb, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 
       0x2e, 0x1ca, 0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
       0x3, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 0x1d2, 0xa, 0x2e, 0xc, 0x2e, 0xe, 
       0x2e, 0x1d5, 0xb, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x1d9, 0xa, 
       0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
       0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x5, 0x2f, 0x1e3, 0xa, 0x2f, 0x3, 0x30, 
       0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 
       0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x1ef, 0xa, 0x30, 0x3, 
       0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x1f4, 0xa, 0x30, 0x3, 0x30, 
       0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x1f9, 0xa, 0x30, 0x3, 0x30, 0x3, 
       0x30, 0x5, 0x30, 0x1fd, 0xa, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
       0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x205, 0xa, 0x31, 0x3, 
       0x31, 0x5, 0x31, 0x208, 0xa, 0x31, 0x3, 0x31, 0x2, 0xc, 0xe, 0x1e, 
       0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x32, 0x36, 0x32, 0x2, 0x4, 0x6, 
       0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
       0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 
       0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 
       0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 
       0x2, 0x6, 0x3, 0x2, 0x43, 0x44, 0x3, 0x2, 0x2d, 0x32, 0x3, 0x2, 0x33, 
       0x36, 0x5, 0x2, 0x26, 0x26, 0x2b, 0x2c, 0x37, 0x37, 0x2, 0x229, 0x2, 
       0x65, 0x3, 0x2, 0x2, 0x2, 0x4, 0x6c, 0x3, 0x2, 0x2, 0x2, 0x6, 0x6e, 
       0x3, 0x2, 0x2, 0x2, 0x8, 0x76, 0x3, 0x2, 0x2, 0x2, 0xa, 0x86, 0x3, 
       0x2, 0x2, 0x2, 0xc, 0x8e, 0x3, 0x2, 0x2, 0x2, 0xe, 0x90, 0x3, 0x2, 
       0x2, 0x2, 0x10, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x12, 0x9e, 0x3, 0x2, 0x2, 
       0x2, 0x14, 0xae, 0x3, 0x2, 0x2, 0x2, 0x16, 0xb3, 0x3, 0x2, 0x2, 0x2, 
       0x18, 0xc7, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x1c, 
       0xcf, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xd5, 0x3, 0x2, 0x2, 0x2, 0x20, 0xe2, 
       0x3, 0x2, 0x2, 0x2, 0x22, 0xe9, 0x3, 0x2, 0x2, 0x2, 0x24, 0xeb, 0x3, 
       0x2, 0x2, 0x2, 0x26, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x28, 0x101, 0x3, 
       0x2, 0x2, 0x2, 0x2a, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x11b, 0x3, 
       0x2, 0x2, 0x2, 0x2e, 0x129, 0x3, 0x2, 0x2, 0x2, 0x30, 0x13e, 0x3, 
       0x2, 0x2, 0x2, 0x32, 0x140, 0x3, 0x2, 0x2, 0x2, 0x34, 0x15b, 0x3, 
       0x2, 0x2, 0x2, 0x36, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x38, 0x168, 0x3, 
       0x2, 0x2, 0x2, 0x3a, 0x16a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x16c, 0x3, 
       0x2, 0x2, 0x2, 0x3e, 0x179, 0x3, 0x2, 0x2, 0x2, 0x40, 0x17b, 0x3, 
       0x2, 0x2, 0x2, 0x42, 0x186, 0x3, 0x2, 0x2, 0x2, 0x44, 0x188, 0x3, 
       0x2, 0x2, 0x2, 0x46, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x48, 0x193, 0x3, 
       0x2, 0x2, 0x2, 0x4a, 0x198, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x19d, 0x3, 
       0x2, 0x2, 0x2, 0x4e, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x50, 0x1a6, 0x3, 
       0x2, 0x2, 0x2, 0x52, 0x1a9, 0x3, 0x2, 0x2, 0x2, 0x54, 0x1ac, 0x3, 
       0x2, 0x2, 0x2, 0x56, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x58, 0x1b2, 0x3, 
       0x2, 0x2, 0x2, 0x5a, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x1e2, 0x3, 
       0x2, 0x2, 0x2, 0x5e, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x60, 0x207, 0x3, 
       0x2, 0x2, 0x2, 0x62, 0x64, 0x5, 0x4, 0x3, 0x2, 0x63, 0x62, 0x3, 0x2, 
       0x2, 0x2, 0x64, 0x67, 0x3, 0x2, 0x2, 0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 
       0x2, 0x65, 0x66, 0x3, 0x2, 0x2, 0x2, 0x66, 0x3, 0x3, 0x2, 0x2, 0x2, 
       0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6d, 0x5, 0x6, 0x4, 0x2, 0x69, 
       0x6a, 0x5, 0x14, 0xb, 0x2, 0x6a, 0x6b, 0x7, 0x13, 0x2, 0x2, 0x6b, 
       0x6d, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x69, 
       0x3, 0x2, 0x2, 0x2, 0x6d, 0x5, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6f, 0x5, 
       0x8, 0x5, 0x2, 0x6f, 0x70, 0x7, 0x44, 0x2, 0x2, 0x70, 0x71, 0x5, 
       0xc, 0x7, 0x2, 0x71, 0x72, 0x5, 0x12, 0xa, 0x2, 0x72, 0x7, 0x3, 0x2, 
       0x2, 0x2, 0x73, 0x77, 0x5, 0xa, 0x6, 0x2, 0x74, 0x75, 0x7, 0x20, 
       0x2, 0x2, 0x75, 0x77, 0x5, 0xa, 0x6, 0x2, 0x76, 0x73, 0x3, 0x2, 0x2, 
       0x2, 0x76, 0x74, 0x3, 0x2, 0x2, 0x2, 0x77, 0x9, 0x3, 0x2, 0x2, 0x2, 
       0x78, 0x87, 0x7, 0x15, 0x2, 0x2, 0x79, 0x87, 0x7, 0x16, 0x2, 0x2, 
       0x7a, 0x87, 0x7, 0x17, 0x2, 0x2, 0x7b, 0x87, 0x7, 0x18, 0x2, 0x2, 
       0x7c, 0x87, 0x7, 0x19, 0x2, 0x2, 0x7d, 0x87, 0x7, 0x1a, 0x2, 0x2, 
       0x7e, 0x87, 0x7, 0x1b, 0x2, 0x2, 0x7f, 0x87, 0x7, 0x1c, 0x2, 0x2, 
       0x80, 0x81, 0x7, 0x1d, 0x2, 0x2, 0x81, 0x87, 0x7, 0x44, 0x2, 0x2, 
       0x82, 0x83, 0x7, 0x1e, 0x2, 0x2, 0x83, 0x87, 0x5, 0x8, 0x5, 0x2, 
       0x84, 0x85, 0x7, 0x1f, 0x2, 0x2, 0x85, 0x87, 0x5, 0x8, 0x5, 0x2, 
       0x86, 0x78, 0x3, 0x2, 0x2, 0x2, 0x86, 0x79, 0x3, 0x2, 0x2, 0x2, 0x86, 
       0x7a, 0x3, 0x2, 0x2, 0x2, 0x86, 0x7b, 0x3, 0x2, 0x2, 0x2, 0x86, 0x7c, 
       0x3, 0x2, 0x2, 0x2, 0x86, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x86, 0x7e, 0x3, 
       0x2, 0x2, 0x2, 0x86, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x86, 0x80, 0x3, 0x2, 
       0x2, 0x2, 0x86, 0x82, 0x3, 0x2, 0x2, 0x2, 0x86, 0x84, 0x3, 0x2, 0x2, 
       0x2, 0x87, 0xb, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x7, 0xe, 0x2, 0x2, 
       0x89, 0x8f, 0x7, 0xf, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0xe, 0x2, 0x2, 0x8b, 
       0x8c, 0x5, 0xe, 0x8, 0x2, 0x8c, 0x8d, 0x7, 0xf, 0x2, 0x2, 0x8d, 0x8f, 
       0x3, 0x2, 0x2, 0x2, 0x8e, 0x88, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8a, 0x3, 
       0x2, 0x2, 0x2, 0x8f, 0xd, 0x3, 0x2, 0x2, 0x2, 0x90, 0x91, 0x8, 0x8, 
       0x1, 0x2, 0x91, 0x92, 0x5, 0x10, 0x9, 0x2, 0x92, 0x98, 0x3, 0x2, 
       0x2, 0x2, 0x93, 0x94, 0xc, 0x3, 0x2, 0x2, 0x94, 0x95, 0x7, 0x12, 
       0x2, 0x2, 0x95, 0x97, 0x5, 0x10, 0x9, 0x2, 0x96, 0x93, 0x3, 0x2, 
       0x2, 0x2, 0x97, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x98, 0x96, 0x3, 0x2, 0x2, 
       0x2, 0x98, 0x99, 0x3, 0x2, 0x2, 0x2, 0x99, 0xf, 0x3, 0x2, 0x2, 0x2, 
       0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x5, 0x8, 0x5, 0x2, 0x9c, 
       0x9d, 0x7, 0x44, 0x2, 0x2, 0x9d, 0x11, 0x3, 0x2, 0x2, 0x2, 0x9e, 
       0xa5, 0x7, 0x10, 0x2, 0x2, 0x9f, 0xa0, 0x5, 0x14, 0xb, 0x2, 0xa0, 
       0xa1, 0x7, 0x13, 0x2, 0x2, 0xa1, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa2, 
       0xa4, 0x5, 0x3e, 0x20, 0x2, 0xa3, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa3, 
       0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa3, 
       0x3, 0x2, 0x2, 0x2, 0xa5, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa8, 0x3, 
       0x2, 0x2, 0x2, 0xa7, 0xa5, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x11, 
       0x2, 0x2, 0xa9, 0x13, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x5, 0x16, 
       0xc, 0x2, 0xab, 0xac, 0x5, 0x1a, 0xe, 0x2, 0xac, 0xaf, 0x3, 0x2, 
       0x2, 0x2, 0xad, 0xaf, 0x5, 0x1c, 0xf, 0x2, 0xae, 0xaa, 0x3, 0x2, 
       0x2, 0x2, 0xae, 0xad, 0x3, 0x2, 0x2, 0x2, 0xaf, 0x15, 0x3, 0x2, 0x2, 
       0x2, 0xb0, 0xb4, 0x5, 0x18, 0xd, 0x2, 0xb1, 0xb2, 0x7, 0x20, 0x2, 
       0x2, 0xb2, 0xb4, 0x5, 0x18, 0xd, 0x2, 0xb3, 0xb0, 0x3, 0x2, 0x2, 
       0x2, 0xb3, 0xb1, 0x3, 0x2, 0x2, 0x2, 0xb4, 0x17, 0x3, 0x2, 0x2, 0x2, 
       0xb5, 0xc8, 0x7, 0x16, 0x2, 0x2, 0xb6, 0xc8, 0x7, 0x17, 0x2, 0x2, 
       0xb7, 0xc8, 0x7, 0x18, 0x2, 0x2, 0xb8, 0xc8, 0x7, 0x19, 0x2, 0x2, 
       0xb9, 0xc8, 0x7, 0x1a, 0x2, 0x2, 0xba, 0xc8, 0x7, 0x1b, 0x2, 0x2, 
       0xbb, 0xc8, 0x7, 0x1c, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0x1d, 0x2, 0x2, 
       0xbd, 0xc8, 0x7, 0x44, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x1e, 0x2, 0x2, 
       0xbf, 0xc1, 0x7, 0xe, 0x2, 0x2, 0xc0, 0xc2, 0x9, 0x2, 0x2, 0x2, 0xc1, 
       0xc0, 0x3, 0x2, 0x2, 0x2, 0xc1, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc3, 
       0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0xf, 0x2, 0x2, 0xc4, 0xc8, 0x5, 
       0x16, 0xc, 0x2, 0xc5, 0xc6, 0x7, 0x1f, 0x2, 0x2, 0xc6, 0xc8, 0x5, 
       0x16, 0xc, 0x2, 0xc7, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xb6, 0x3, 
       0x2, 0x2, 0x2, 0xc7, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xb8, 0x3, 0x2, 
       0x2, 0x2, 0xc7, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xba, 0x3, 0x2, 0x2, 
       0x2, 0xc7, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xbc, 0x3, 0x2, 0x2, 0x2, 
       0xc7, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc8, 
       0x19, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xcd, 0x7, 0x44, 0x2, 0x2, 0xca, 
       0xcb, 0x5, 0x38, 0x1d, 0x2, 0xcb, 0xcc, 0x5, 0x22, 0x12, 0x2, 0xcc, 
       0xce, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xce, 
       0x3, 0x2, 0x2, 0x2, 0xce, 0x1b, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd0, 0x7, 
       0x1d, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x44, 0x2, 0x2, 0xd1, 0xd2, 0x7, 
       0x10, 0x2, 0x2, 0xd2, 0xd3, 0x5, 0x1e, 0x10, 0x2, 0xd3, 0xd4, 0x7, 
       0x11, 0x2, 0x2, 0xd4, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd6, 0x8, 
       0x10, 0x1, 0x2, 0xd6, 0xd7, 0x5, 0x14, 0xb, 0x2, 0xd7, 0xd8, 0x7, 
       0x13, 0x2, 0x2, 0xd8, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xda, 0xc, 
       0x3, 0x2, 0x2, 0xda, 0xdb, 0x5, 0x14, 0xb, 0x2, 0xdb, 0xdc, 0x7, 
       0x13, 0x2, 0x2, 0xdc, 0xde, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xd9, 0x3, 
       0x2, 0x2, 0x2, 0xde, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xdf, 0xdd, 0x3, 0x2, 
       0x2, 0x2, 0xdf, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe0, 0x1f, 0x3, 0x2, 0x2, 
       0x2, 0xe1, 0xdf, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe3, 0x5, 0x22, 0x12, 
       0x2, 0xe3, 0x21, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xea, 0x5, 0x24, 0x13, 
       0x2, 0xe5, 0xe6, 0x5, 0x30, 0x19, 0x2, 0xe6, 0xe7, 0x5, 0x38, 0x1d, 
       0x2, 0xe7, 0xe8, 0x5, 0x22, 0x12, 0x2, 0xe8, 0xea, 0x3, 0x2, 0x2, 
       0x2, 0xe9, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe5, 0x3, 0x2, 0x2, 0x2, 
       0xea, 0x23, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x8, 0x13, 0x1, 0x2, 
       0xec, 0xed, 0x5, 0x26, 0x14, 0x2, 0xed, 0xf3, 0x3, 0x2, 0x2, 0x2, 
       0xee, 0xef, 0xc, 0x3, 0x2, 0x2, 0xef, 0xf0, 0x7, 0x21, 0x2, 0x2, 
       0xf0, 0xf2, 0x5, 0x26, 0x14, 0x2, 0xf1, 0xee, 0x3, 0x2, 0x2, 0x2, 
       0xf2, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf3, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xf3, 
       0xf4, 0x3, 0x2, 0x2, 0x2, 0xf4, 0x25, 0x3, 0x2, 0x2, 0x2, 0xf5, 0xf3, 
       0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x8, 0x14, 0x1, 0x2, 0xf7, 0xf8, 
       0x5, 0x28, 0x15, 0x2, 0xf8, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 
       0xc, 0x3, 0x2, 0x2, 0xfa, 0xfb, 0x7, 0x22, 0x2, 0x2, 0xfb, 0xfd, 
       0x5, 0x28, 0x15, 0x2, 0xfc, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xfd, 0x100, 
       0x3, 0x2, 0x2, 0x2, 0xfe, 0xfc, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x3, 
       0x2, 0x2, 0x2, 0xff, 0x27, 0x3, 0x2, 0x2, 0x2, 0x100, 0xfe, 0x3, 
       0x2, 0x2, 0x2, 0x101, 0x102, 0x8, 0x15, 0x1, 0x2, 0x102, 0x103, 0x5, 
       0x2a, 0x16, 0x2, 0x103, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 
       0xc, 0x4, 0x2, 0x2, 0x105, 0x106, 0x7, 0x23, 0x2, 0x2, 0x106, 0x10b, 
       0x5, 0x2a, 0x16, 0x2, 0x107, 0x108, 0xc, 0x3, 0x2, 0x2, 0x108, 0x109, 
       0x7, 0x24, 0x2, 0x2, 0x109, 0x10b, 0x5, 0x2a, 0x16, 0x2, 0x10a, 0x104, 
       0x3, 0x2, 0x2, 0x2, 0x10a, 0x107, 0x3, 0x2, 0x2, 0x2, 0x10b, 0x10e, 
       0x3, 0x2, 0x2, 0x2, 0x10c, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10c, 0x10d, 
       0x3, 0x2, 0x2, 0x2, 0x10d, 0x29, 0x3, 0x2, 0x2, 0x2, 0x10e, 0x10c, 
       0x3, 0x2, 0x2, 0x2, 0x10f, 0x110, 0x8, 0x16, 0x1, 0x2, 0x110, 0x111, 
       0x5, 0x2c, 0x17, 0x2, 0x111, 0x118, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 
       0xc, 0x3, 0x2, 0x2, 0x113, 0x114, 0x5, 0x3a, 0x1e, 0x2, 0x114, 0x115, 
       0x5, 0x2c, 0x17, 0x2, 0x115, 0x117, 0x3, 0x2, 0x2, 0x2, 0x116, 0x112, 
       0x3, 0x2, 0x2, 0x2, 0x117, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x118, 0x116, 
       0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x3, 0x2, 0x2, 0x2, 0x119, 0x2b, 
       0x3, 0x2, 0x2, 0x2, 0x11a, 0x118, 0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 
       0x8, 0x17, 0x1, 0x2, 0x11c, 0x11d, 0x5, 0x2e, 0x18, 0x2, 0x11d, 0x126, 
       0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 0xc, 0x4, 0x2, 0x2, 0x11f, 0x120, 
       0x7, 0x25, 0x2, 0x2, 0x120, 0x125, 0x5, 0x2e, 0x18, 0x2, 0x121, 0x122, 
       0xc, 0x3, 0x2, 0x2, 0x122, 0x123, 0x7, 0x26, 0x2, 0x2, 0x123, 0x125, 
       0x5, 0x2e, 0x18, 0x2, 0x124, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x124, 0x121, 
       0x3, 0x2, 0x2, 0x2, 0x125, 0x128, 0x3, 0x2, 0x2, 0x2, 0x126, 0x124, 
       0x3, 0x2, 0x2, 0x2, 0x126, 0x127, 0x3, 0x2, 0x2, 0x2, 0x127, 0x2d, 
       0x3, 0x2, 0x2, 0x2, 0x128, 0x126, 0x3, 0x2, 0x2, 0x2, 0x129, 0x12a, 
       0x8, 0x18, 0x1, 0x2, 0x12a, 0x12b, 0x5, 0x30, 0x19, 0x2, 0x12b, 0x137, 
       0x3, 0x2, 0x2, 0x2, 0x12c, 0x12d, 0xc, 0x5, 0x2, 0x2, 0x12d, 0x12e, 
       0x7, 0x27, 0x2, 0x2, 0x12e, 0x136, 0x5, 0x30, 0x19, 0x2, 0x12f, 0x130, 
       0xc, 0x4, 0x2, 0x2, 0x130, 0x131, 0x7, 0x28, 0x2, 0x2, 0x131, 0x136, 
       0x5, 0x30, 0x19, 0x2, 0x132, 0x133, 0xc, 0x3, 0x2, 0x2, 0x133, 0x134, 
       0x7, 0x29, 0x2, 0x2, 0x134, 0x136, 0x5, 0x30, 0x19, 0x2, 0x135, 0x12c, 
       0x3, 0x2, 0x2, 0x2, 0x135, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x135, 0x132, 
       0x3, 0x2, 0x2, 0x2, 0x136, 0x139, 0x3, 0x2, 0x2, 0x2, 0x137, 0x135, 
       0x3, 0x2, 0x2, 0x2, 0x137, 0x138, 0x3, 0x2, 0x2, 0x2, 0x138, 0x2f, 
       0x3, 0x2, 0x2, 0x2, 0x139, 0x137, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x13f, 
       0x5, 0x32, 0x1a, 0x2, 0x13b, 0x13c, 0x5, 0x3c, 0x1f, 0x2, 0x13c, 
       0x13d, 0x5, 0x30, 0x19, 0x2, 0x13d, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x13e, 
       0x13a, 0x3, 0x2, 0x2, 0x2, 0x13e, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13f, 
       0x31, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 0x8, 0x1a, 0x1, 0x2, 0x141, 
       0x142, 0x5, 0x34, 0x1b, 0x2, 0x142, 0x152, 0x3, 0x2, 0x2, 0x2, 0x143, 
       0x144, 0xc, 0x6, 0x2, 0x2, 0x144, 0x145, 0x7, 0x2a, 0x2, 0x2, 0x145, 
       0x151, 0x7, 0x44, 0x2, 0x2, 0x146, 0x147, 0xc, 0x5, 0x2, 0x2, 0x147, 
       0x151, 0x7, 0x2b, 0x2, 0x2, 0x148, 0x149, 0xc, 0x4, 0x2, 0x2, 0x149, 
       0x151, 0x7, 0x2c, 0x2, 0x2, 0x14a, 0x14b, 0xc, 0x3, 0x2, 0x2, 0x14b, 
       0x14d, 0x7, 0xe, 0x2, 0x2, 0x14c, 0x14e, 0x5, 0x36, 0x1c, 0x2, 0x14d, 
       0x14c, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x14e, 
       0x14f, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x151, 0x7, 0xf, 0x2, 0x2, 0x150, 
       0x143, 0x3, 0x2, 0x2, 0x2, 0x150, 0x146, 0x3, 0x2, 0x2, 0x2, 0x150, 
       0x148, 0x3, 0x2, 0x2, 0x2, 0x150, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x151, 
       0x154, 0x3, 0x2, 0x2, 0x2, 0x152, 0x150, 0x3, 0x2, 0x2, 0x2, 0x152, 
       0x153, 0x3, 0x2, 0x2, 0x2, 0x153, 0x33, 0x3, 0x2, 0x2, 0x2, 0x154, 
       0x152, 0x3, 0x2, 0x2, 0x2, 0x155, 0x15c, 0x7, 0x44, 0x2, 0x2, 0x156, 
       0x15c, 0x7, 0x43, 0x2, 0x2, 0x157, 0x158, 0x7, 0xe, 0x2, 0x2, 0x158, 
       0x159, 0x5, 0x20, 0x11, 0x2, 0x159, 0x15a, 0x7, 0xf, 0x2, 0x2, 0x15a, 
       0x15c, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x155, 0x3, 0x2, 0x2, 0x2, 0x15b, 
       0x156, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x157, 0x3, 0x2, 0x2, 0x2, 0x15c, 
       0x35, 0x3, 0x2, 0x2, 0x2, 0x15d, 0x15e, 0x8, 0x1c, 0x1, 0x2, 0x15e, 
       0x15f, 0x5, 0x20, 0x11, 0x2, 0x15f, 0x165, 0x3, 0x2, 0x2, 0x2, 0x160, 
       0x161, 0xc, 0x3, 0x2, 0x2, 0x161, 0x162, 0x7, 0x12, 0x2, 0x2, 0x162, 
       0x164, 0x5, 0x20, 0x11, 0x2, 0x163, 0x160, 0x3, 0x2, 0x2, 0x2, 0x164, 
       0x167, 0x3, 0x2, 0x2, 0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 0x2, 0x165, 
       0x166, 0x3, 0x2, 0x2, 0x2, 0x166, 0x37, 0x3, 0x2, 0x2, 0x2, 0x167, 
       0x165, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x9, 0x3, 0x2, 0x2, 0x169, 
       0x39, 0x3, 0x2, 0x2, 0x2, 0x16a, 0x16b, 0x9, 0x4, 0x2, 0x2, 0x16b, 
       0x3b, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16d, 0x9, 0x5, 0x2, 0x2, 0x16d, 
       0x3d, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x17a, 0x5, 0x12, 0xa, 0x2, 0x16f, 
       0x170, 0x5, 0x20, 0x11, 0x2, 0x170, 0x171, 0x7, 0x13, 0x2, 0x2, 0x171, 
       0x17a, 0x3, 0x2, 0x2, 0x2, 0x172, 0x173, 0x5, 0x40, 0x21, 0x2, 0x173, 
       0x174, 0x7, 0x13, 0x2, 0x2, 0x174, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x175, 
       0x17a, 0x5, 0x5a, 0x2e, 0x2, 0x176, 0x17a, 0x5, 0x5c, 0x2f, 0x2, 
       0x177, 0x17a, 0x5, 0x5e, 0x30, 0x2, 0x178, 0x17a, 0x5, 0x60, 0x31, 
       0x2, 0x179, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x179, 0x16f, 0x3, 0x2, 0x2, 
       0x2, 0x179, 0x172, 0x3, 0x2, 0x2, 0x2, 0x179, 0x175, 0x3, 0x2, 0x2, 
       0x2, 0x179, 0x176, 0x3, 0x2, 0x2, 0x2, 0x179, 0x177, 0x3, 0x2, 0x2, 
       0x2, 0x179, 0x178, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x3f, 0x3, 0x2, 0x2, 
       0x2, 0x17b, 0x17c, 0x7, 0x3, 0x2, 0x2, 0x17c, 0x17d, 0x5, 0x42, 0x22, 
       0x2, 0x17d, 0x41, 0x3, 0x2, 0x2, 0x2, 0x17e, 0x17f, 0x7, 0x4, 0x2, 
       0x2, 0x17f, 0x187, 0x5, 0x44, 0x23, 0x2, 0x180, 0x181, 0x7, 0x5, 
       0x2, 0x2, 0x181, 0x187, 0x5, 0x46, 0x24, 0x2, 0x182, 0x183, 0x7, 
       0x6, 0x2, 0x2, 0x183, 0x187, 0x5, 0x48, 0x25, 0x2, 0x184, 0x185, 
       0x7, 0x7, 0x2, 0x2, 0x185, 0x187, 0x5, 0x4a, 0x26, 0x2, 0x186, 0x17e, 
       0x3, 0x2, 0x2, 0x2, 0x186, 0x180, 0x3, 0x2, 0x2, 0x2, 0x186, 0x182, 
       0x3, 0x2, 0x2, 0x2, 0x186, 0x184, 0x3, 0x2, 0x2, 0x2, 0x187, 0x43, 
       0x3, 0x2, 0x2, 0x2, 0x188, 0x189, 0x5, 0x50, 0x29, 0x2, 0x189, 0x18b, 
       0x5, 0x54, 0x2b, 0x2, 0x18a, 0x18c, 0x5, 0x56, 0x2c, 0x2, 0x18b, 
       0x18a, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18c, 0x3, 0x2, 0x2, 0x2, 0x18c, 
       0x45, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 0x5, 0x50, 0x29, 0x2, 0x18e, 
       0x18f, 0x5, 0x52, 0x2a, 0x2, 0x18f, 0x191, 0x5, 0x54, 0x2b, 0x2, 
       0x190, 0x192, 0x5, 0x56, 0x2c, 0x2, 0x191, 0x190, 0x3, 0x2, 0x2, 
       0x2, 0x191, 0x192, 0x3, 0x2, 0x2, 0x2, 0x192, 0x47, 0x3, 0x2, 0x2, 
       0x2, 0x193, 0x194, 0x5, 0x4c, 0x27, 0x2, 0x194, 0x196, 0x5, 0x4e, 
       0x28, 0x2, 0x195, 0x197, 0x5, 0x56, 0x2c, 0x2, 0x196, 0x195, 0x3, 
       0x2, 0x2, 0x2, 0x196, 0x197, 0x3, 0x2, 0x2, 0x2, 0x197, 0x49, 0x3, 
       0x2, 0x2, 0x2, 0x198, 0x199, 0x5, 0x4c, 0x27, 0x2, 0x199, 0x19b, 
       0x5, 0x4e, 0x28, 0x2, 0x19a, 0x19c, 0x5, 0x56, 0x2c, 0x2, 0x19b, 
       0x19a, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x3, 0x2, 0x2, 0x2, 0x19c, 
       0x4b, 0x3, 0x2, 0x2, 0x2, 0x19d, 0x19e, 0x7, 0x8, 0x2, 0x2, 0x19e, 
       0x19f, 0x5, 0x58, 0x2d, 0x2, 0x19f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1a0, 
       0x1a1, 0x7, 0x9, 0x2, 0x2, 0x1a1, 0x1a5, 0x5, 0x58, 0x2d, 0x2, 0x1a2, 
       0x1a3, 0x7, 0x9, 0x2, 0x2, 0x1a3, 0x1a5, 0x5, 0x20, 0x11, 0x2, 0x1a4, 
       0x1a0, 0x3, 0x2, 0x2, 0x2, 0x1a4, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a5, 
       0x4f, 0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a7, 0x7, 0xa, 0x2, 0x2, 0x1a7, 
       0x1a8, 0x5, 0x58, 0x2d, 0x2, 0x1a8, 0x51, 0x3, 0x2, 0x2, 0x2, 0x1a9, 
       0x1aa, 0x7, 0xb, 0x2, 0x2, 0x1aa, 0x1ab, 0x5, 0x58, 0x2d, 0x2, 0x1ab, 
       0x53, 0x3, 0x2, 0x2, 0x2, 0x1ac, 0x1ad, 0x7, 0xc, 0x2, 0x2, 0x1ad, 
       0x1ae, 0x5, 0x58, 0x2d, 0x2, 0x1ae, 0x55, 0x3, 0x2, 0x2, 0x2, 0x1af, 
       0x1b0, 0x7, 0xd, 0x2, 0x2, 0x1b0, 0x1b1, 0x9, 0x2, 0x2, 0x2, 0x1b1, 
       0x57, 0x3, 0x2, 0x2, 0x2, 0x1b2, 0x1b3, 0x7, 0xe, 0x2, 0x2, 0x1b3, 
       0x1b4, 0x5, 0x20, 0x11, 0x2, 0x1b4, 0x1b5, 0x7, 0x12, 0x2, 0x2, 0x1b5, 
       0x1b6, 0x5, 0x20, 0x11, 0x2, 0x1b6, 0x1b7, 0x7, 0xf, 0x2, 0x2, 0x1b7, 
       0x59, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b9, 0x7, 0x38, 0x2, 0x2, 0x1b9, 
       0x1ba, 0x7, 0xe, 0x2, 0x2, 0x1ba, 0x1bb, 0x5, 0x20, 0x11, 0x2, 0x1bb, 
       0x1bc, 0x7, 0xf, 0x2, 0x2, 0x1bc, 0x1c4, 0x5, 0x12, 0xa, 0x2, 0x1bd, 
       0x1be, 0x7, 0x39, 0x2, 0x2, 0x1be, 0x1bf, 0x7, 0xe, 0x2, 0x2, 0x1bf, 
       0x1c0, 0x5, 0x20, 0x11, 0x2, 0x1c0, 0x1c1, 0x7, 0xf, 0x2, 0x2, 0x1c1, 
       0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1c3, 
       0x1c6, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x1c4, 
       0x1c5, 0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1c6, 
       0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0x7, 0x3a, 0x2, 0x2, 0x1c8, 
       0x1ca, 0x5, 0x12, 0xa, 0x2, 0x1c9, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x1c9, 
       0x1ca, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1cb, 
       0x1cc, 0x7, 0x3b, 0x2, 0x2, 0x1cc, 0x1cd, 0x7, 0xe, 0x2, 0x2, 0x1cd, 
       0x1ce, 0x5, 0x20, 0x11, 0x2, 0x1ce, 0x1cf, 0x7, 0xf, 0x2, 0x2, 0x1cf, 
       0x1d3, 0x7, 0x10, 0x2, 0x2, 0x1d0, 0x1d2, 0x5, 0x5c, 0x2f, 0x2, 0x1d1, 
       0x1d0, 0x3, 0x2, 0x2, 0x2, 0x1d2, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d3, 
       0x1d1, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d4, 
       0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1d3, 0x3, 0x2, 0x2, 0x2, 0x1d6, 
       0x1d7, 0x7, 0x11, 0x2, 0x2, 0x1d7, 0x1d9, 0x3, 0x2, 0x2, 0x2, 0x1d8, 
       0x1b8, 0x3, 0x2, 0x2, 0x2, 0x1d8, 0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1d9, 
       0x5b, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1db, 0x7, 0x3c, 0x2, 0x2, 0x1db, 
       0x1dc, 0x5, 0x24, 0x13, 0x2, 0x1dc, 0x1dd, 0x7, 0x14, 0x2, 0x2, 0x1dd, 
       0x1de, 0x5, 0x20, 0x11, 0x2, 0x1de, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1df, 
       0x1e0, 0x7, 0x3d, 0x2, 0x2, 0x1e0, 0x1e1, 0x7, 0x14, 0x2, 0x2, 0x1e1, 
       0x1e3, 0x5, 0x20, 0x11, 0x2, 0x1e2, 0x1da, 0x3, 0x2, 0x2, 0x2, 0x1e2, 
       0x1df, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x1e4, 
       0x1e5, 0x7, 0x3e, 0x2, 0x2, 0x1e5, 0x1e6, 0x7, 0xe, 0x2, 0x2, 0x1e6, 
       0x1e7, 0x5, 0x20, 0x11, 0x2, 0x1e7, 0x1e8, 0x7, 0xf, 0x2, 0x2, 0x1e8, 
       0x1e9, 0x5, 0x12, 0xa, 0x2, 0x1e9, 0x1fd, 0x3, 0x2, 0x2, 0x2, 0x1ea, 
       0x1eb, 0x7, 0x3f, 0x2, 0x2, 0x1eb, 0x1ee, 0x7, 0xe, 0x2, 0x2, 0x1ec, 
       0x1ef, 0x5, 0x20, 0x11, 0x2, 0x1ed, 0x1ef, 0x5, 0x14, 0xb, 0x2, 0x1ee, 
       0x1ec, 0x3, 0x2, 0x2, 0x2, 0x1ee, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ee, 
       0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1ef, 0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f0, 
       0x1f3, 0x7, 0x13, 0x2, 0x2, 0x1f1, 0x1f4, 0x5, 0x20, 0x11, 0x2, 0x1f2, 
       0x1f4, 0x5, 0x14, 0xb, 0x2, 0x1f3, 0x1f1, 0x3, 0x2, 0x2, 0x2, 0x1f3, 
       0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f3, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f4, 
       0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f5, 0x1f8, 0x7, 0x13, 0x2, 0x2, 0x1f6, 
       0x1f9, 0x5, 0x20, 0x11, 0x2, 0x1f7, 0x1f9, 0x5, 0x14, 0xb, 0x2, 0x1f8, 
       0x1f6, 0x3, 0x2, 0x2, 0x2, 0x1f8, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x1f8, 
       0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1f9, 0x1fa, 0x3, 0x2, 0x2, 0x2, 0x1fa, 
       0x1fb, 0x7, 0xf, 0x2, 0x2, 0x1fb, 0x1fd, 0x5, 0x12, 0xa, 0x2, 0x1fc, 
       0x1e4, 0x3, 0x2, 0x2, 0x2, 0x1fc, 0x1ea, 0x3, 0x2, 0x2, 0x2, 0x1fd, 
       0x5f, 0x3, 0x2, 0x2, 0x2, 0x1fe, 0x1ff, 0x7, 0x40, 0x2, 0x2, 0x1ff, 
       0x208, 0x7, 0x13, 0x2, 0x2, 0x200, 0x201, 0x7, 0x41, 0x2, 0x2, 0x201, 
       0x208, 0x7, 0x13, 0x2, 0x2, 0x202, 0x204, 0x7, 0x42, 0x2, 0x2, 0x203, 
       0x205, 0x5, 0x20, 0x11, 0x2, 0x204, 0x203, 0x3, 0x2, 0x2, 0x2, 0x204, 
       0x205, 0x3, 0x2, 0x2, 0x2, 0x205, 0x206, 0x3, 0x2, 0x2, 0x2, 0x206, 
       0x208, 0x7, 0x13, 0x2, 0x2, 0x207, 0x1fe, 0x3, 0x2, 0x2, 0x2, 0x207, 
       0x200, 0x3, 0x2, 0x2, 0x2, 0x207, 0x202, 0x3, 0x2, 0x2, 0x2, 0x208, 
       0x61, 0x3, 0x2, 0x2, 0x2, 0x32, 0x65, 0x6c, 0x76, 0x86, 0x8e, 0x98, 
       0xa3, 0xa5, 0xae, 0xb3, 0xc1, 0xc7, 0xcd, 0xdf, 0xe9, 0xf3, 0xfe, 
       0x10a, 0x10c, 0x118, 0x124, 0x126, 0x135, 0x137, 0x13e, 0x14d, 0x150, 
       0x152, 0x15b, 0x165, 0x179, 0x186, 0x18b, 0x191, 0x196, 0x19b, 0x1a4, 
       0x1c4, 0x1c9, 0x1d3, 0x1d8, 0x1e2, 0x1ee, 0x1f3, 0x1f8, 0x1fc, 0x204, 
       0x207, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ShaperParser::Initializer ShaperParser::_init;
