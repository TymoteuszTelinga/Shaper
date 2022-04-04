grammar Shaper;

programm 
    : (externalDeclaration)*
    ;

externalDeclaration
    : functionDefinition
    | declaration SEMICOLON
    ;

functionDefinition
    : functionSpecifier Identifier declarator compoundStatement
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
    | STRUCT Identifier
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
    : functionSpecifier Identifier
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
    | STRUCT Identifier
    | ARRAY LEFTPAREN (Identifier | Constant)? RIGHTPAREN declarationSpecifier
    | LIST declarationSpecifier
    ;

initDeclarator
    : Identifier ( assignmentOperator assignmentExpression)?
    ;

structDeclarator
    : STRUCT Identifier LEFTBRACKET structDeclarationList RIGHTBRACKET
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
    | additiveExpression PLUS multiplicativeExpression
    | additiveExpression MINUS multiplicativeExpression
    ;

multiplicativeExpression
    : unaryExpression
    | multiplicativeExpression MULTIPLY unaryExpression
    | multiplicativeExpression DIVIDE unaryExpression
    | multiplicativeExpression MODULO unaryExpression
    ;

unaryExpression
    : postfixExpression
    | unaryOperator unaryExpression
    ;

postfixExpression
    : primaryExpression
    | postfixExpression DOT Identifier
    | postfixExpression PLUSPLUS
    | postfixExpression MINUSMINUS
    | postfixExpression LEFTPAREN functionParameterList? RIGHTPAREN
    ;

primaryExpression
    : Identifier
    | Constant
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

unaryOperator
    : MINUS
    | EXCLAMATION
    | PLUSPLUS
    | MINUSMINUS
    ;

statement
    : compoundStatement 
    | expression SEMICOLON
    | selectionStatement 
    | labeledStatement 
    | iterationStatement
    | jumpStatement
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