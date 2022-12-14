// antlr4 -Dlanguage=Python3 Shaper.g4 -no-listener -visitor -o ..\gen-python\grammar

grammar Shaper;

programm 
    : externalDeclarationList?
    ;

externalDeclarationList
    : externalDeclaration externalDeclarationList
    | externalDeclaration 
    ;


externalDeclaration
    : functionDefinition
    | declaration SEMICOLON
    ;

functionDefinition
    : typeSpecifier identifier declarator compoundStatement
    ;

typeSpecifier
    : VOID
    | BOOL
    | CHAR
    | SHORT
    | INT
    | LONG
    | FLOAT
    | DOUBLE
    | COLOR
    ;

declarator
    : LEFTPAREN RIGHTPAREN
    | LEFTPAREN parameterList RIGHTPAREN
    ;

parameterList
    : parameterDeclaration
    | parameterDeclaration COMMA parameterList
    ;

parameterDeclaration
    : typeSpecifier identifier
    ;

compoundStatement
    : LEFTBRACKET instructionList? RIGHTBRACKET
    ;

instructionList
    : instruction instructionList
    | instruction
    ;

instruction
    : (declaration SEMICOLON) | statement 
    ;

declaration
    : initDeclarator 
    ;

initDeclarator
    : declarationType identifier (assignmentOperator assignmentExpression)?
    ;

declarationType
    : atomicType
    | ARRAY LEFTSQUARE (expression) RIGHTSQUARE atomicType
    ;

atomicType
    : BOOL
    | CHAR
    | SHORT
    | INT
    | LONG
    | FLOAT
    | DOUBLE
    | COLOR
    ;

expression
    : assignmentExpression
    ;

assignmentExpression
    : scopeIdentifier ((DOT channelIndex) | arrayIndex)? assignmentOperator assignmentExpression
    | logicalORExpression
    ;

logicalORExpression
    : logicalANDExpression
    | logicalORExpression OR logicalANDExpression
    ;

logicalANDExpression
    : equalityExpression
    | logicalANDExpression AND equalityExpression
    ;

equalityExpression
    : relationalExpression
    | equalityExpression equalityOperator relationalExpression
    ;

relationalExpression
    : additiveExpression
    | relationalExpression relationalOperator additiveExpression
    ;

additiveExpression
    : multiplicativeExpression
    | additiveExpression additiveOperator multiplicativeExpression
    ;

multiplicativeExpression
    : unaryExpression
    | multiplicativeExpression multiplicativeOperator unaryExpression
    ;

unaryExpression
    : postfixExpression
    | unaryOperator unaryExpression
    ;

postfixExpression
    : primaryExpression
    | postfixExpression PLUSPLUS
    | postfixExpression MINUSMINUS
    ;

primaryExpression
    : scopeIdentifier
    | constant
    | scopeIdentifier arrayIndex
    | scopeIdentifier DOT channelIndex
    | LEFTPAREN expression RIGHTPAREN                        
    | functionCall
    ;


arrayIndex
    : LEFTSQUARE (expression) RIGHTSQUARE
    ;

functionCall
    : identifier LEFTPAREN functionParameterList? RIGHTPAREN 
    ;

functionParameterList
    : expression
    | expression COMMA functionParameterList
    ;

assignmentOperator
    : ASSIGN
    | PLUSASSIGN
    | MINUSASSIGN
    | MULTIPLYASSIGN
    | DIVIDEASSIGN
    | MODULOASSIGN
    ;

equalityOperator
    : EQUAL
    | NOTEQUAL
    ;

relationalOperator
    : LESS
    | MOREE
    | LESSEQUAL
    | MOREEQUAL
    ;

additiveOperator
    : PLUS
    | MINUS
    ;

multiplicativeOperator
    : MULTIPLY
    | DIVIDE
    | MODULO
    ;

unaryOperator
    : MINUSMINUS
    | PLUSPLUS
    | MINUS
    | EXCLAMATION
    ;

statement
    : compoundStatement 
    | expression SEMICOLON
    | paintStatement SEMICOLON
    | selectionStatement 
    | iterationStatement
    | jumpStatement
    ;

paintStatement
    : PAINT  shapeIndicator
    ;

shapeIndicator
    : LINE lineParameters
    | TRIANGLE triangleParameters
    | RECTANGLE rectangleParameters
    | CIRCLE circleParameters
    ;

lineParameters
    : fromStatement toStatement (colorStatement)?
    ;

triangleParameters
    : fromStatement throughStatement toStatement (colorStatement)?
    ;

rectangleParameters
    : atStatement ofStatement (colorStatement)?
    ;

circleParameters
    : atStatement ofStatement (colorStatement)?
    ;

atStatement
    : AT posSizeParent
    ;

ofStatement
    : OF posSizeParent
    ;

fromStatement
    : FROM posSizeParent 
    ;

throughStatement
    : THROUGH posSizeParent
    ;

toStatement
    : TO posSizeParent
    ;

colorStatement
    : WITH expression
    ;

posSizeParent
    : LEFTPAREN left=expression (COMMA right=expression)? RIGHTPAREN
    ;

selectionStatement
    : IF LEFTPAREN expression RIGHTPAREN compoundStatement 
        (ELIF LEFTPAREN expression RIGHTPAREN compoundStatement)* 
        ( ELSE compoundStatement )?
    ;
    
iterationStatement
    : whileLoopStatement
    | forLoopStatement
    ;

whileLoopStatement
    : WHILE LEFTPAREN expression RIGHTPAREN compoundStatement
    ;


forLoopStatement
    : FOR LEFTPAREN (initExpr=expression | initDec = declaration)? SEMICOLON (condition=expression)? SEMICOLON (loopExpr=expression)? RIGHTPAREN compoundStatement
    ;

jumpStatement
    : RETURN expression? SEMICOLON
    ;


scopeIdentifier
    : globalScope? identifier
    ;

identifier
    : Identifier
    ;

globalScope
    : GLOBAL
    ;

constant
    : integer = IntegerConstant
    | floating = FloatingConstant
    | logical = LogicalConstant
    | color = ColorConstant
    ;

channelIndex
    : R
    | G
    | B
    | A
    ;


PAINT: 'paint';

LINE: 'line';

TRIANGLE: 'triangle';

RECTANGLE: 'rectangle';

CIRCLE: 'circle';

AT: 'at';

OF: 'of';

FROM: 'from';

THROUGH: 'through';

TO: 'to';

WITH: 'with';

LEFTPAREN: '(';

RIGHTPAREN: ')';

LEFTBRACKET: '{';

RIGHTBRACKET: '}';

LEFTSQUARE: '[';

RIGHTSQUARE: ']';

COMMA: ',';

SEMICOLON: ';';

COLON: ':';

VOID: 'void';

BOOL: 'bool';

INT: 'int';

LONG: 'long';

CHAR: 'char';

SHORT: 'short';

FLOAT: 'float';

DOUBLE: 'double';

COLOR: 'color';

STRUCT: 'struct';

ARRAY: 'array';

LIST: 'list';

OR: '|';

AND: '&';

EQUAL: '==';

NOTEQUAL: '!=';

PLUS: '+';

MINUS: '-';

MULTIPLY: '*';

DIVIDE: '/';

MODULO: '%';

DOT: '.';

PLUSPLUS: '++';

MINUSMINUS: '--';

ASSIGN : '=';

PLUSASSIGN: '+=';

MINUSASSIGN: '-=';

MULTIPLYASSIGN: '*=';

DIVIDEASSIGN: '/=';

MODULOASSIGN: '%=';

LESS: '<';

MOREE: '>';

LESSEQUAL: '<=';

MOREEQUAL: '>=';

EXCLAMATION: '!';

IF: 'if';

ELIF: 'elif';

ELSE: 'else';

WHILE: 'while';

FOR: 'for';

RETURN: 'return';

GLOBAL: 'global:';

R: 'R';

G: 'G';

B: 'B';

A: 'A';

IntegerConstant
    : NonZeroDigit Digit*
    | [0]
    ;

fragment
NonZeroDigit
    : [1-9]
    ;
    

FloatingConstant
    : Digit+ '.' Digit+
    ;


LogicalConstant
    : 'false'
    | 'true'
    ;


ColorConstant
    : 'BLACK'
    | 'WHITE'
    | 'RED'
    | 'GREEN'
    | 'BLUE'
    | 'YELLOW'
    ;

Identifier
    : NonDigit 
      ( NonDigit 
      | Digit
      )*
    ;


fragment
NonDigit
    : [a-zA-Z_]
    ;

fragment
Digit
    : [0-9]
    ;

WS
    : [\r\n]+ -> skip
    ;

WhiteSpace
    : [ \t]+ -> skip
    ;

LINE_COMMENT
    :   '//' ~[\r\n]* -> skip
    ;
