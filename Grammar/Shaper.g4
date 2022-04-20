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
    : functionSpecifier identifier declarator compoundStatement
    ;

functionSpecifier
    : typeSpecifier
    | CONST typeSpecifier
    ;

typeSpecifier
    : VOID
    | BOOL
    | INT
    | LONG
    | FLOAT
    | DOUBLE
    | COLOR
    | STRUCT identifier
    | ARRAY functionSpecifier
    | LIST functionSpecifier
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
    : functionSpecifier identifier
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
    | structDeclarator 
    ;

initDeclarator
    : declarationSpecifier identifier ( assignmentOperator assignmentExpression)?
    ;

declarationSpecifier
    : declarationType
    | CONST declarationType
    ;

declarationType
    : BOOL
    | INT
    | LONG
    | FLOAT
    | DOUBLE
    | COLOR
    | STRUCT identifier
    | ARRAY LEFTPAREN (identifier | constant)? RIGHTPAREN declarationSpecifier
    | LIST declarationSpecifier
    ;

structDeclarator
    : STRUCT identifier LEFTBRACKET structDeclarationList RIGHTBRACKET
    ;


structDeclarationList
    : declaration SEMICOLON
    | structDeclarationList declaration SEMICOLON
    ;

expression
    : assignmentExpression
    ;

assignmentExpression
    : logicalORExpression
    | unaryExpression assignmentOperator assignmentExpression
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
    | postfixExpression DOT identifier
    | postfixExpression PLUSPLUS
    | postfixExpression MINUSMINUS
    ;

primaryExpression
    : identifier
    | constant
    | LEFTPAREN expression RIGHTPAREN                        
    | functionCall
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
    | labeledStatement 
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
    : WITH (identifier|constant)
    ;

posSizeParent
    : LEFTPAREN left=expression (COMMA right=expression)? RIGHTPAREN
    ;

selectionStatement
    : IF LEFTPAREN expression RIGHTPAREN compoundStatement 
        (ELIF LEFTPAREN expression RIGHTPAREN)* 
        ( ELSE compoundStatement )?
    | SWITCH LEFTPAREN expression RIGHTPAREN LEFTBRACKET labeledStatement* RIGHTBRACKET
    ;
    
labeledStatement
    : CASE logicalORExpression COLON expression
    | DEFAULT COLON expression
    ;

iterationStatement
    : WHILE LEFTPAREN expression RIGHTPAREN compoundStatement
    | FOR LEFTPAREN (expression|declaration)? SEMICOLON (expression|declaration)? SEMICOLON (expression|declaration)? RIGHTPAREN compoundStatement
    ;

jumpStatement
    : CONTINUE SEMICOLON
    | BREAK SEMICOLON
    | RETURN expression? SEMICOLON
    ;

identifier
    : Identifier
    ;

constant
    : integer = IntegerConstant
    | floating = FloatingConstant
    | logical = LogicalConstant
    | color = ColorConstant
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

COMMA: ',';

SEMICOLON: ';';

COLON: ':';

VOID: 'void';

BOOL: 'bool';

INT: 'int';

LONG: 'long';

CHAR: 'char';

FLOAT: 'float';

DOUBLE: 'double';

COLOR: 'color';

STRUCT: 'struct';

ARRAY: 'array';

LIST: 'list';

CONST: 'const';

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

SWITCH: 'switch';

CASE: 'case';

DEFAULT: 'default';

WHILE: 'while';

FOR: 'for';

CONTINUE: 'continue';

BREAK: 'break';

RETURN: 'return';

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
    : [a-zA-Z]
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