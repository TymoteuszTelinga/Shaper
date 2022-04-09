
// Generated from .\Grammar\Shaper.g4 by ANTLR 4.9.3

#pragma once


#include <antlr/antlr4-runtime.h>




class  ShaperLexer : public antlr4::Lexer {
public:
  enum {
    PAINT = 1, LINE = 2, TRIANGLE = 3, RECTANGLE = 4, CIRCLE = 5, AT = 6, 
    OF = 7, FROM = 8, THROUGH = 9, TO = 10, WITH = 11, LEFTPAREN = 12, RIGHTPAREN = 13, 
    LEFTBRACKET = 14, RIGHTBRACKET = 15, COMMA = 16, SEMICOLON = 17, COLON = 18, 
    VOID = 19, BOOL = 20, INT = 21, LONG = 22, CHAR = 23, FLOAT = 24, DOUBLE = 25, 
    COLOR = 26, STRUCT = 27, ARRAY = 28, LIST = 29, CONST = 30, OR = 31, 
    AND = 32, EQUAL = 33, NOTEQUAL = 34, PLUS = 35, MINUS = 36, MULTIPLY = 37, 
    DIVIDE = 38, MODULO = 39, DOT = 40, PLUSPLUS = 41, MINUSMINUS = 42, 
    ASSIGN = 43, PLUSASSIGN = 44, MINUSASSIGN = 45, MULTIPLYASSIGN = 46, 
    DIVIDEASSIGN = 47, MODULOASSIGN = 48, LESS = 49, MOREE = 50, LESSEQUAL = 51, 
    MOREEQUAL = 52, EXCLAMATION = 53, IF = 54, ELIF = 55, ELSE = 56, SWITCH = 57, 
    CASE = 58, DEFAULT = 59, WHILE = 60, FOR = 61, CONTINUE = 62, BREAK = 63, 
    RETURN = 64, Constant = 65, Identifier = 66, WS = 67, WhiteSpace = 68
  };

  explicit ShaperLexer(antlr4::CharStream *input);
  ~ShaperLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

