grammar Shaper;

programm 
    : (externalDeclaration)*
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
    | CHAR
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
    | parameterList COMMA parameterDeclaration
    ;

parameterDeclaration
    : functionSpecifier identifier
    ;

compoundStatement
    : LEFTBRACKET ( (declaration SEMICOLON) | statement )* RIGHTBRACKET
    ;

declaration
    : declarationSpecifier initDeclarator 
    | structDeclarator 
    ;

declarationSpecifier
    : declarationType
    | CONST declarationType
    ;

declarationType
    : BOOL
    | INT
    | LONG
    | CHAR
    | FLOAT
    | DOUBLE
    | COLOR
    | STRUCT identifier
    | ARRAY LEFTPAREN (identifier | Constant)? RIGHTPAREN declarationSpecifier
    | LIST declarationSpecifier
    ;

initDeclarator
    : identifier ( assignmentOperator assignmentExpression)?
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
    | equalityExpression EQUAL relationalExpression
    | equalityExpression NOTEQUAL relationalExpression
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
    | postfixExpression LEFTPAREN functionParameterList? RIGHTPAREN
    ;

primaryExpression
    : identifier
    | constant
    | LEFTPAREN expression RIGHTPAREN
    ;

functionParameterList
    : expression
    | functionParameterList COMMA expression
    ;

assignmentOperator
    : ASSIGN
    | PLUSASSIGN
    | MINUSASSIGN
    | MULTIPLYASSIGN
    | DIVIDEASSIGN
    | MODULOASSIGN
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
    : MINUS
    | EXCLAMATION
    | PLUSPLUS
    | MINUSMINUS
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
    | OF expression
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
    : LEFTPAREN expression COMMA expression RIGHTPAREN
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
    : Constant
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


Constant
    : IntegerConstant
    | FloatingConstant
    | LogicalConstant
    | ColorConstant
    ;

fragment
IntegerConstant
    : NonZeroDigit Digit*
    | [0]
    ;

fragment
NonZeroDigit
    : [1-9]
    ;
    
fragment
FloatingConstant
    : Digit+ '.' Digit+
    ;

fragment
LogicalConstant
    : 'false'
    | 'true'
    ;

fragment
ColorConstant
    : 'BLACK'
    | 'WHITE'
    | 'RED'
    | 'GREEN'
    | 'BLUE'
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