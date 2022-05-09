from grammar.ShaperVisitor import ShaperVisitor
from grammar.ShaperParser import ShaperParser

from Function import Function
from Types import Type
from Atoms import Variable, Constant

from Manager import Manager


# checks semantic correctness for whole file
# gathers function declarations
class CheckVisitor(ShaperVisitor):
    def __init__(self, manager: Manager) -> None:
        self.gatherFunctions = True
        self.manager = manager


    def checkFunctionsBody(self):
        self.manager.setVisitor(self)

        if self.manager.setup_func != None:
            oldScope = self.manager.createNewScope(False)

            self.manager.curr_function = self.manager.setup_func
            self.manager.return_var = None

            self.visit(self.manager.setup_func.ctx)
            self.manager.curr_scope = oldScope

        if self.manager.draw_func != None:
            oldScope = self.manager.createNewScope(False)

            self.manager.curr_function = self.manager.draw_func
            self.manager.return_var = None

            self.visit(self.manager.draw_func.ctx)

            self.manager.curr_scope = oldScope

        self.manager.curr_function = None
        self.manager.return_var = None
        for func in self.manager.user_func.values():
            self.manager.enterFunction(func.name, func.parameters, None)

# programm 
#     : externalDeclarationList?
#     ;
    def visitProgramm(self, ctx: ShaperParser.ProgrammContext):
        
        #file is not empty
        if ctx.externalDeclarationList() != None: 
            #gather functions
            self.visit(ctx.externalDeclarationList()) 

            self.gatherFunctions = False
            # gather global variables
            self.visit(ctx.externalDeclarationList())


# externalDeclarationList
#     : externalDeclaration externalDeclarationList
#     | externalDeclaration 
#     ;    
    def visitExternalDeclarationList(self, ctx: ShaperParser.ExternalDeclarationListContext):
        self.visit(ctx.externalDeclaration()) 

        # visits other declarations if exists
        if(ctx.externalDeclarationList() != None):
            self.visit(ctx.externalDeclarationList())


# externalDeclaration
#     : functionDefinition
#     | declaration SEMICOLON
#     ;
    def visitExternalDeclaration(self, ctx: ShaperParser.ExternalDeclarationContext):
        if self.gatherFunctions: # gathering functions
            if ctx.functionDefinition() != None:
                self.visit(ctx.functionDefinition())
        else: #gathering variables
            if ctx.declaration() != None:
                self.visit(ctx.declaration())


# functionDefinition
#     : typeSpecifier identifier declarator compoundStatement
#     ;
    def visitFunctionDefinition(self, ctx: ShaperParser.FunctionDefinitionContext):
        r_type = self.visit(ctx.typeSpecifier()) # get function return type (Atom)
        name = ctx.identifier().getText() # get function name
        f_param = self.visit(ctx.declarator()) # get list of function parameters [Variables]

        # create function object
        func = Function(name) 
        func.setReturnVar(r_type)
        func.setParameters(f_param)
        func.ctx = ctx.compoundStatement() #pointer to function body in tree 

        self.manager.addFunction(func) # add function to manager


# typeSpecifier
#     : VOID
#     | BOOL
#     | INT
#     | LONG
#     | FLOAT
#     | DOUBLE
#     | COLOR
#     | STRUCT identifier
#     | ARRAY typeSpecifier
#     | LIST typeSpecifier
#     ;
    def visitTypeSpecifier(self, ctx: ShaperParser.TypeSpecifierContext):
        return Type.getType(ctx.getText()) #returns type


# declarator
#     : LEFTPAREN RIGHTPAREN
#     | LEFTPAREN parameterList RIGHTPAREN
#     ;
    def visitDeclarator(self, ctx: ShaperParser.DeclaratorContext):
        if ctx.parameterList() == None: #function doesn't have parameters
            return []
        else:
            return self.visit(ctx.parameterList())


# parameterList
#     : parameterDeclaration
#     | parameterDeclaration COMMA parameterList
#     ;
    def visitParameterList(self, ctx: ShaperParser.ParameterListContext):
        # new Variable 
        var = self.visit(ctx.parameterDeclaration())

        if ctx.parameterList() == None: # no more parameters on the list
            par_list = [var]
        else:
            par_list = self.visit(ctx.parameterList())
            for param in par_list:
                if var.name == param.name:
                    raise Exception(f"line {ctx.start.line} Ambiguity Error: Two or more parameters of this same name in one function")
            
            par_list.insert(0,var) # insert new variable to start of the list 
            
        return par_list       


# parameterDeclaration
#     : typeSpecifier identifier
#     ;
    def visitParameterDeclaration(self, ctx: ShaperParser.ParameterDeclarationContext):
        name = ctx.identifier().getText() # name of parameter
        type = self.visit(ctx.typeSpecifier()) # type of parameter

        var = Variable(name, type) # creates variable 
        return var # and returns it


# declaration
#     : initDeclarator 
#     | structDeclarator 
#     ;
    def visitDeclaration(self, ctx: ShaperParser.DeclarationContext):
        if (ctx.initDeclarator() != None): 
            self.visit(ctx.initDeclarator())



# compoundStatement
#     : LEFTBRACKET instructionList? RIGHTBRACKET
#     ;
    def visitCompoundStatement(self, ctx: ShaperParser.CompoundStatementContext):
        if ctx.instructionList() != None: #function has at least one instruction
            self.visit(ctx.instructionList()) 

# instructionList
#     : instruction instructionList
#     | instruction
#     ;
    def visitInstructionList(self, ctx: ShaperParser.InstructionListContext):
        self.visit(ctx.instruction()) # visit instruction on the list

        if ctx.instructionList() != None: #if list is not empty, go further
            self.visit(ctx.instructionList())

# instruction
#     : (declaration SEMICOLON) | statement 
#     ;           
    def visitInstruction(self, ctx: ShaperParser.InstructionContext):
        if ctx.declaration() != None: # instruction is a declaration
            self.visit(ctx.declaration())
        else: # is a statement
            self.visit(ctx.statement())


# initDeclarator
#     : declarationType identifier ( assignmentOperator assignmentExpression)?
#     ;
    def visitInitDeclarator(self, ctx: ShaperParser.InitDeclaratorContext):
        name = ctx.identifier().getText() # name of declared variable
        type = self.visit(ctx.declarationType()) # type of declared variable
        var = Variable(name, type) # create new variable


        # variable created earlier in current scope
        if not self.manager.isVariableAvailable(name):
            raise Exception(f"line {ctx.start.line} Variable \'{name}\' defined earlier in this scope")

        # initializing value
        if ctx.assignmentExpression() != None:
            r_value = self.visit(ctx.assignmentExpression())
            if var.type != r_value.type:
                raise Exception(f"line {ctx.start.line} Can't use  binary operator \'=\' to type " + repr(var.type) + " and type " + repr(r_value.type))

        self.manager.addVariable(var)


# declarationType
#     : BOOL
#     | INT
#     | LONG
#     | FLOAT
#     | DOUBLE
#     | COLOR
#     | STRUCT identifier
#     | ARRAY LEFTPAREN (identifier | constant)? RIGHTPAREN declarationType
#     | LIST declarationType
#     ;
    def visitDeclarationType(self, ctx: ShaperParser.DeclarationTypeContext) -> Type:
        return Type.getType(ctx.getText())


# expression
#     : assignmentExpression
#     ;
    def visitExpression(self, ctx: ShaperParser.ExpressionContext) -> Variable:
        return self.visitChildren(ctx)


# assignmentExpression
#     : logicalORExpression
#     | unaryExpression assignmentOperator assignmentExpression
#     ;
    def visitAssignmentExpression(self, ctx: ShaperParser.AssignmentExpressionContext) -> Variable:
        if ctx.unaryExpression() == None:
            return self.visit(ctx.logicalORExpression())
        else:
            l = self.visit(ctx.unaryExpression())
            r = self.visit(ctx.assignmentExpression())
            op = ctx.assignmentOperator().getText()

            if(type(l) is Constant):
                raise Exception(f"line {ctx.start.line} Can't assign value to a non-variable atom")

            if l.type != r.type :
                raise Exception(f"line {ctx.start.line} Can't use  binary operator \'{op}\' to type " + repr(l.type) + " and type " + repr(r.type))

            if op == '+=':
                if l.type not in [Type.FLOAT, Type.INT]:
                    raise Exception(f"line {ctx.start.line} Can't use  assign operator \'{op}\' to type " + repr(l.type))
            elif op == '-=':
                if l.type not in [Type.FLOAT, Type.INT]:
                    raise Exception(f"line {ctx.start.line} Can't use  assign operator \'{op}\' to type " + repr(l.type)) 
            elif op == '*=':
                if l.type not in [Type.FLOAT, Type.INT]:
                    raise Exception(f"line {ctx.start.line} Can't use  assign operator \'{op}\' to type " + repr(l.type))
            elif op == '/=':
                if l.type not in [Type.FLOAT, Type.INT]:
                    raise Exception(f"line {ctx.start.line} Can't use  assign operator \'{op}\' to type " + repr(l.type))
            elif op == '%=':
                if l.type not in [Type.INT]:
                    raise Exception(f"line {ctx.start.line} Can't use  assign operator \'{op}\' to type " + repr(l.type))

            return l


# logicalORExpression
#     : logicalANDExpression
#     | logicalORExpression OR logicalANDExpression
#     ;
    def visitLogicalORExpression(self, ctx: ShaperParser.LogicalORExpressionContext) -> Variable:
        if ctx.logicalORExpression() == None:
            return self.visit(ctx.logicalANDExpression())
        else:
            l = self.visit(ctx.logicalORExpression())
            r = self.visit(ctx.logicalANDExpression())
            
            if l.type not in [Type.BOOL]:
                raise Exception(f"line {ctx.start.line} Can't use  binary operator \'|\' to type " + repr(l.type))
            
            if r.type not in [Type.BOOL]:
                raise Exception(f"line {ctx.start.line} Can't use  binary operator \'|\' to type " + repr(r.type))

            ret = Constant(Type.BOOL, None)

            return ret


# logicalANDExpression
#     : equalityExpression
#     | logicalANDExpression AND equalityExpression
#     ;
    def visitLogicalANDExpression(self, ctx: ShaperParser.LogicalANDExpressionContext) -> Variable:
        if ctx.logicalANDExpression() == None:
            return self.visit(ctx.equalityExpression())
        else:
            l = self.visit(ctx.logicalANDExpression())
            r = self.visit(ctx.equalityExpression())
            
            if l.type not in [Type.BOOL]:
                raise Exception(f"line {ctx.start.line} Can't use  binary operator \'&\' to type " + repr(l.type))
            
            if r.type not in [Type.BOOL]:
                raise Exception(f"line {ctx.start.line} Can't use  binary operator \'&\' to type " + repr(r.type))

            ret = Constant(Type.BOOL, None)

            return ret


# equalityExpression
#     : relationalExpression
#     | equalityExpression equalityOperator relationalExpression
#     ;
    def visitEqualityExpression(self, ctx: ShaperParser.EqualityExpressionContext) -> Variable:
        if ctx.equalityExpression() == None:
            return self.visit(ctx.relationalExpression())
        else:
            l = self.visit(ctx.equalityExpression())
            r = self.visit(ctx.relationalExpression())
            op = ctx.equalityOperator().getText()

            if l.type not in [Type.INT, Type.FLOAT, Type.BOOL, Type.COLOR]:
                raise Exception(f"line {ctx.start.line} Can't use  binary operator \'{op}\' to type " + repr(l.type))
            
            if r.type not in [Type.INT, Type.FLOAT, Type.BOOL, Type.COLOR]:
                raise Exception(f"line {ctx.start.line} Can't use  binary operator \'{op}\' to type " + repr(r.type))

            if l.type != r.type and (Type.BOOL in [l.type, r.type] or Type.Color in [l.type, r.type]):
                raise Exception(f"line {ctx.start.line} Can't use  binary operator \'{op}\' to type " + repr(l.type) + " and type " + repr(r.type))
            
            return Constant(Type.BOOL, None)


# relationalExpression
#     : additiveExpression
#     | relationalExpression relationalOperator additiveExpression
#     ;
    def visitRelationalExpression(self, ctx: ShaperParser.RelationalExpressionContext) -> Variable:
        if ctx.relationalExpression() == None:
            return self.visit(ctx.additiveExpression())
        else:
            l = self.visit(ctx.relationalExpression())
            r = self.visit(ctx.additiveExpression())
            op = ctx.relationalOperator().getText()

            if l.type not in [Type.INT, Type.FLOAT]:
                raise Exception(f"line {ctx.start.line} Can't use  binary operator \'{op}\' to type " + repr(l.type))
            
            if r.type not in [Type.INT, Type.FLOAT]:
                raise Exception(f"line {ctx.start.line} Can't use  binary operator \'{op}\' to type " + repr(r.type))

            return  Constant(Type.BOOL, None)


# additiveExpression
#     : multiplicativeExpression
#     | additiveExpression additiveOperator multiplicativeExpression
#     ;
    def visitAdditiveExpression(self, ctx: ShaperParser.AdditiveExpressionContext) -> Variable:
        if ctx.additiveExpression() == None:
            return self.visit(ctx.multiplicativeExpression())
        else:
            l = self.visit(ctx.additiveExpression())
            r = self.visit(ctx.multiplicativeExpression())
            op = ctx.additiveOperator().getText()

            if l.type not in [Type.INT, Type.FLOAT]:
                raise Exception(f"line {ctx.start.line} Can't use  binary operator \'{op}\' to type " + repr(l.type))
            
            if r.type not in [Type.INT, Type.FLOAT]:
                raise Exception(f"line {ctx.start.line} Can't use  binary operator \'{op}\' to type " + repr(r.type))
            
            ret_type = Type.INT    
            if r.type == Type.FLOAT or l.type == Type.FLOAT:
                ret_type = Type.FLOAT
            

            return Constant(ret_type, None)


# #multiplicativeExpression
#     : unaryExpression
#     | multiplicativeExpression multiplicativeOperator unaryExpression
#     ;
    def visitMultiplicativeExpression(self, ctx: ShaperParser.MultiplicativeExpressionContext) -> Variable:
        if ctx.multiplicativeExpression() == None:
            return self.visit(ctx.unaryExpression())
        else:

            l = self.visit(ctx.multiplicativeExpression())
            r = self.visit(ctx.unaryExpression())
            op = ctx.multiplicativeOperator().getText()
            
            if l.type not in [Type.INT, Type.FLOAT]:
                raise Exception(f"line {ctx.start.line} Can't use  multiplicative operator \'{op}\' to type " + repr(l.type))
            
            if r.type not in [Type.INT, Type.FLOAT]:
                raise Exception(f"line {ctx.start.line} Can't use  binary operator \'{op}\' to type " + repr(r.type))

            ret_type = Type.INT    
            if r.type == Type.FLOAT or l.type == Type.FLOAT:
                ret_type = Type.FLOAT
            
            if op == '%':
                if ret_type != Type.INT:
                    raise Exception(f"line {ctx.start.line} Can't use  binary operator \'{op}\' to type \'float\'" )

            return Constant(ret_type, None)
    
#   unaryExpression
#     : postfixExpression
#     | unaryOperator unaryExpression
#     ;  
    def visitUnaryExpression(self, ctx: ShaperParser.UnaryExpressionContext):
        if ctx.postfixExpression() != None:
            return self.visit(ctx.postfixExpression())

        else:
            ret = self.visit(ctx.unaryExpression())
            op = ctx.unaryOperator().getText()

            if  op == '-':
                if ret.type not in [Type.INT, Type.FLOAT]:
                    raise Exception(f"line {ctx.start.line} Can't use unary operator \'-\' to type " + repr(ret.type))

            elif op == '!':
                if ret.type not in [Type.BOOL]:
                    raise Exception(f"line {ctx.start.line} Can't use unary operator \'!\' to type " + repr(ret.type))

            elif op == '++':
                if type(ret) == Constant:
                    raise Exception(f"line {ctx.start.line} Can't use operator \'++\' to a non-variable atom")
                elif ret.type not in [Type.INT, Type.FLOAT]:
                    raise Exception(f"line {ctx.start.line} Can't use operator \'++\' to type " + repr(ret.type))

            elif op == '--':
                if type(ret) == Constant:
                    raise Exception(f"line {ctx.start.line} Can't use operator \'--\' to a non-variable atom")
                elif ret.type not in [Type.INT, Type.FLOAT]:
                    raise Exception(f"line {ctx.start.line} Can't use operator \'--\' to type " + repr(ret.type))

            return Constant(ret.type, None)

# postfixExpression
#     : primaryExpression
#     | postfixExpression DOT identifier
#     | postfixExpression PLUSPLUS
#     | postfixExpression MINUSMINUS
#     ;
    def visitPostfixExpression(self, ctx: ShaperParser.PostfixExpressionContext):
        if ctx.primaryExpression() != None:
            return self.visit(ctx.primaryExpression())

        else:
            ret = self.visit(ctx.postfixExpression())

            if type(ret) == Constant:
                if ctx.DOT() != None:
                     raise Exception(f"line {ctx.start.line} Can't use operator \'.\' to a non-variable atom")
                elif ctx.PLUSPLUS() != None:
                     raise Exception(f"line {ctx.start.line} Can't use operator \'++\' to a non-variable atom")
                elif ctx.MINUSMINUS() != None:
                     raise Exception(f"line {ctx.start.line} Can't use operator \'--\' to a non-variable atom")
            
            if ctx.DOT() != None:
                if ret.type in [Type.BOOL, Type.INT, Type.FLOAT, Type.VOID]:
                    raise Exception(f"line {ctx.start.line} Can't use operator \'.\' to type " + repr(ret.type))


            elif ctx.PLUSPLUS() != None:
                if ret.type not in [Type.INT, Type.FLOAT]:
                    raise Exception(f"line {ctx.start.line} Can't use operator \'++\' to type " + repr(ret.type))

            elif ctx.MINUSMINUS() != None:
                if ret.type not in [Type.INT, Type.FLOAT]:
                    raise Exception(f"line {ctx.start.line} Can't use operator \'--\' to type " + repr(ret.type))

        
            return Constant(ret.type, None)


# primaryExpression
#     : identifier
#     | constant
#     | LEFTPAREN expression RIGHTPAREN                        
#     | functionCall
#     ;
    def visitPrimaryExpression(self, ctx: ShaperParser.PrimaryExpressionContext):
        if ctx.scopeIdentifier() != None: # get existing variable
            var = self.visit(ctx.scopeIdentifier())
            return var

        elif ctx.constant() != None:
            return self.visit(ctx.constant())
        
        elif ctx.expression() != None:
            return self.visit(ctx.expression())
        
        elif ctx.functionCall() != None:
            return self.visit(ctx.functionCall())

# functionCall
#     : identifier LEFTPAREN functionParameterList? RIGHTPAREN 
#     ;
    def visitFunctionCall(self, ctx: ShaperParser.FunctionCallContext):
        name = self.visit(ctx.identifier()) # name of called function
        params = []
        if ctx.functionParameterList() != None:
            params = self.visit(ctx.functionParameterList()) # parameters of called function
        
        
        (function, error) = self.manager.functionExists(name, params)

        if error == 0:
            return function.return_atom
        if error == 1:
            raise Exception(f"line {ctx.start.line} Functions 'setup' and 'draw' can't be called directly!")
        elif error == 2:
            raise Exception(f"line {ctx.start.line} Function {name} doesn't exist!") 
        elif error == 3:
            raise Exception(f"line {ctx.start.line} Called function has {len(params)} parameters, but was declared with {len(function.parameters)}")
        elif error == 4:
            raise Exception(f"line {ctx.start.line} At {function[0]} parameter expected type {function[1].type}, but got type {params[function[0]].type}")


# functionParameterList
#     : expression
#     | expression COMMA functionParameterList
#     ;
    def visitFunctionParameterList(self, ctx: ShaperParser.FunctionParameterListContext):

        if ctx.functionParameterList() != None:
            params = self.visit(ctx.functionParameterList())
            params.insert(0,self.visit(ctx.expression()))
            return params
        else:
            return [self.visit(ctx.expression())]


# statement
#     : compoundStatement 
#     | expression SEMICOLON
#     | paintStatement SEMICOLON
#     | selectionStatement 
#     | labeledStatement 
#     | iterationStatement
#     | jumpStatement
#     ;
    def visitStatement(self, ctx: ShaperParser.StatementContext):
        if ctx.paintStatement() != None:
            self.visit(ctx.paintStatement())

        elif ctx.compoundStatement() != None:
            oldScope =  self.manager.createNewScope(True)

            self.visit(ctx.compoundStatement())

            self.manager.curr_scope = oldScope


        elif ctx.expression() != None:
            self.visit(ctx.expression())

        elif ctx.jumpStatement() != None:
            self.visit(ctx.jumpStatement())


# paintStatement
#     : PAINT  shapeIndicator
#     ;
    def visitPaintStatement(self, ctx: ShaperParser.PaintStatementContext):
        self.visit(ctx.shapeIndicator())


# shapeIndicator
#     : LINE lineParameters
#     | TRIANGLE triangleParameters
#     | RECTANGLE rectangleParameters
#     | CIRCLE circleParameters
#     ;
    def visitShapeIndicator(self, ctx: ShaperParser.ShapeIndicatorContext):
        self.visitChildren(ctx)


# lineParameters
#     : fromStatement toStatement (colorStatement)?
#     ;
    def visitLineParameters(self, ctx: ShaperParser.LineParametersContext):
        self.visit(ctx.fromStatement())
        self.visit(ctx.toStatement())

        if(ctx.colorStatement() != None):
            self.visit(ctx.colorStatement())  


# triangleParameters
#     : fromStatement throughStatement toStatement (colorStatement)?
#     ;
    def visitTriangleParameters(self, ctx: ShaperParser.TriangleParametersContext):
        self.visit(ctx.fromStatement())
        self.visit(ctx.throughStatement())
        self.visit(ctx.toStatement())

        if(ctx.colorStatement() != None):
            self.visit(ctx.colorStatement())  


# rectangleParameters
#     : atStatement ofStatement (colorStatement)?
#     ;
    def visitRectangleParameters(self, ctx: ShaperParser.RectangleParametersContext):
        self.visit(ctx.atStatement())
        self.visit(ctx.ofStatement())

        if(ctx.colorStatement() != None):
            self.visit(ctx.colorStatement())  


# circleParameters
#     : atStatement ofStatement (colorStatement)?
#     ;
    def visitCircleParameters(self, ctx: ShaperParser.CircleParametersContext):
        self.visit(ctx.atStatement())
        self.visit(ctx.ofStatement())

        if(ctx.colorStatement() != None):
            self.visit(ctx.colorStatement())  


# atStatement
#     : AT posSizeParent
#     ;
    def visitAtStatement(self, ctx: ShaperParser.AtStatementContext):
        self.visitChildren(ctx)


# ofStatement
#     : OF posSizeParent
#     ;
    def visitOfStatement(self, ctx: ShaperParser.OfStatementContext):
        self.visitChildren(ctx)


# fromStatement
#     : FROM posSizeParent 
#     ;
    def visitFromStatement(self, ctx: ShaperParser.FromStatementContext):
        self.visitChildren(ctx)


# throughStatement
#     : THROUGH posSizeParent
#     ;
    def visitThroughStatement(self, ctx: ShaperParser.ThroughStatementContext):
        self.visitChildren(ctx)


# toStatement
#     : TO posSizeParent
#     ;
    def visitToStatement(self, ctx: ShaperParser.ToStatementContext):
        self.visitChildren(ctx)


# colorStatement
#     : WITH (identifier|constant)
#     ;
    def visitColorStatement(self, ctx: ShaperParser.ColorStatementContext):
        if ctx.constant() != None:
            const = self.visit(ctx.constant())

            if const.type != Type.COLOR:
                raise Exception(f"line {ctx.start.line} Incorrect type, expected 'color', got " + repr(const.type))
        else:
            var = self.visit(ctx.scopeIdentifier())


            if var.type != Type.COLOR: 
                raise Exception(f"line {ctx.start.line} Incorrect type, expected 'color', got " + repr(var.type))


# posSizeParent
#     : LEFTPAREN left=expression (COMMA right=expression)? RIGHTPAREN
#     ;
    def visitPosSizeParent(self, ctx: ShaperParser.PosSizeParentContext):        
        if ctx.right != None:

            pos_size_tulp = (self.visit(ctx.left), self.visit(ctx.right))

        else:
            var = self.visit(ctx.left)
            pos_size_tulp = (var, var)
        
        if pos_size_tulp[0].type not in [Type.INT, Type.FLOAT]:
            raise Exception(f"line {ctx.start.line} Incorrect type, expected 'int' or 'float', got " + repr(pos_size_tulp[0].type))

        if pos_size_tulp[1].type not in [Type.INT, Type.FLOAT]:
            raise Exception(f"line {ctx.start.line} Incorrect type, expected 'int' or 'float', got " + repr(pos_size_tulp[0].type))
    

# jumpStatement
#     : CONTINUE SEMICOLON
#     | BREAK SEMICOLON
#     | RETURN expression? SEMICOLON
#     ;  
    def visitJumpStatement(self, ctx: ShaperParser.JumpStatementContext):
        if ctx.expression() != None:
            self.manager.return_var = self.visit(ctx.expression())
        else: 
            self.manager.return_var = Constant(Type.VOID, None)

        if self.manager.return_var.type != self.manager.curr_function.return_atom.type:
            raise Exception(f"line {ctx.start.line} Incorrect return type, expected {self.manager.curr_function.return_atom.type}, but got type {self.manager.return_var.type}")


    def visitScopeIdentifier(self, ctx: ShaperParser.ScopeIdentifierContext):
        name = self.visit(ctx.identifier())
        if ctx.globalScope() != None:
            var = self.manager.global_scope.getVariable(name)

            if var == None:
                raise Exception(f"line {ctx.start.line} Variable " + name + " doesn't exist in global scope")
        else: 
            var = self.manager.getVariable(name)

            if var == None:
                raise Exception(f"line {ctx.start.line} Variable " + name + " doesn't exist")
            
        return var

# identifier
#     : Identifier
#     ;      
    def visitIdentifier(self, ctx: ShaperParser.IdentifierContext) -> str:
        return ctx.getText()


# constant
#     : integer = IntegerConstant
#     | floating = FloatingConstant
#     | logical = LogicalConstant
#     | color = ColorConstant
#     ;
    def visitConstant(self, ctx: ShaperParser.ConstantContext) -> Constant:
        const = None
        if ctx.integer != None:
            const = Constant(Type.INT, None)
        elif ctx.floating != None:
            const = Constant(Type.FLOAT, None)
        elif ctx.logical != None:
            const = Constant(Type.BOOL, None)
        elif ctx.color != None:
            const = Constant(Type.COLOR, None)
        
        return const