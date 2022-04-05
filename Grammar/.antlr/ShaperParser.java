// Generated from c:\Dane\Kompilator\komp22-shaper\Grammar\Shaper.g4 by ANTLR 4.8
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.misc.*;
import org.antlr.v4.runtime.tree.*;
import java.util.List;
import java.util.Iterator;
import java.util.ArrayList;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ShaperParser extends Parser {
	static { RuntimeMetaData.checkVersion("4.8", RuntimeMetaData.VERSION); }

	protected static final DFA[] _decisionToDFA;
	protected static final PredictionContextCache _sharedContextCache =
		new PredictionContextCache();
	public static final int
		PAINT=1, LINE=2, TRIANGLE=3, RECTANGLE=4, SQUARE=5, CIRCLE=6, ELLIPSE=7, 
		AT=8, OF=9, FROM=10, THROUGH=11, TO=12, WITH=13, LEFTPAREN=14, RIGHTPAREN=15, 
		LEFTBRACKET=16, RIGHTBRACKET=17, COMMA=18, SEMICOLON=19, COLON=20, VOID=21, 
		BOOL=22, INT=23, LONG=24, CHAR=25, FLOAT=26, DOUBLE=27, COLOR=28, STRUCT=29, 
		ARRAY=30, LIST=31, CONST=32, OR=33, AND=34, EQUAL=35, NOTEQUAL=36, PLUS=37, 
		MINUS=38, MULTIPLY=39, DIVIDE=40, MODULO=41, DOT=42, PLUSPLUS=43, MINUSMINUS=44, 
		ASSIGN=45, PLUSASSIGN=46, MINUSASSIGN=47, MULTIPLYASSIGN=48, DIVIDEASSIGN=49, 
		MODULOASSIGN=50, LESS=51, MOREE=52, LESSEQUAL=53, MOREEQUAL=54, EXCLAMATION=55, 
		IF=56, ELIF=57, ELSE=58, SWITCH=59, CASE=60, DEFAULT=61, WHILE=62, FOR=63, 
		CONTINUE=64, BREAK=65, RETURN=66, Constant=67, Identifier=68, WS=69, WhiteSpace=70;
	public static final int
		RULE_programm = 0, RULE_externalDeclaration = 1, RULE_functionDefinition = 2, 
		RULE_functionSpecifier = 3, RULE_typeSpecifier = 4, RULE_declarator = 5, 
		RULE_parameterList = 6, RULE_parameterDeclaration = 7, RULE_compoundStatement = 8, 
		RULE_declaration = 9, RULE_declarationSpecifier = 10, RULE_declarationType = 11, 
		RULE_initDeclarator = 12, RULE_structDeclarator = 13, RULE_structDeclarationList = 14, 
		RULE_expression = 15, RULE_assignmentExpression = 16, RULE_logicalORExpression = 17, 
		RULE_logicalANDExpression = 18, RULE_equalityExpression = 19, RULE_relationalExpression = 20, 
		RULE_additiveExpression = 21, RULE_multiplicativeExpression = 22, RULE_unaryExpression = 23, 
		RULE_postfixExpression = 24, RULE_primaryExpression = 25, RULE_functionParameterList = 26, 
		RULE_assignmentOperator = 27, RULE_relationalOperator = 28, RULE_unaryOperator = 29, 
		RULE_statement = 30, RULE_paintStatement = 31, RULE_shapeIndicator = 32, 
		RULE_lineParameters = 33, RULE_triangleParameters = 34, RULE_rectangleParameters = 35, 
		RULE_circleParameters = 36, RULE_atStatement = 37, RULE_ofStatement = 38, 
		RULE_fromStatement = 39, RULE_throughStatement = 40, RULE_toStatement = 41, 
		RULE_colorStatement = 42, RULE_posSizeParent = 43, RULE_selectionStatement = 44, 
		RULE_labeledStatement = 45, RULE_iterationStatement = 46, RULE_jumpStatement = 47;
	private static String[] makeRuleNames() {
		return new String[] {
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
	}
	public static final String[] ruleNames = makeRuleNames();

	private static String[] makeLiteralNames() {
		return new String[] {
			null, "'paint'", "'line'", "'triangle'", "'rectangle'", "'square'", "'circle'", 
			"'ellipse'", "'at'", "'of'", "'from'", "'through'", "'to'", "'with'", 
			"'('", "')'", "'{'", "'}'", "','", "';'", "':'", "'void'", "'bool'", 
			"'int'", "'long'", "'char'", "'float'", "'double'", "'color'", "'struct'", 
			"'array'", "'list'", "'const'", "'|'", "'&'", "'=='", "'!='", "'+'", 
			"'-'", "'*'", "'/'", "'%'", "'.'", "'++'", "'--'", "'='", "'+='", "'-='", 
			"'*='", "'/='", "'%='", "'<'", "'>'", "'<='", "'>='", "'!'", "'if'", 
			"'elif'", "'else'", "'switch'", "'case'", "'default'", "'while'", "'for'", 
			"'continue'", "'break'", "'return'"
		};
	}
	private static final String[] _LITERAL_NAMES = makeLiteralNames();
	private static String[] makeSymbolicNames() {
		return new String[] {
			null, "PAINT", "LINE", "TRIANGLE", "RECTANGLE", "SQUARE", "CIRCLE", "ELLIPSE", 
			"AT", "OF", "FROM", "THROUGH", "TO", "WITH", "LEFTPAREN", "RIGHTPAREN", 
			"LEFTBRACKET", "RIGHTBRACKET", "COMMA", "SEMICOLON", "COLON", "VOID", 
			"BOOL", "INT", "LONG", "CHAR", "FLOAT", "DOUBLE", "COLOR", "STRUCT", 
			"ARRAY", "LIST", "CONST", "OR", "AND", "EQUAL", "NOTEQUAL", "PLUS", "MINUS", 
			"MULTIPLY", "DIVIDE", "MODULO", "DOT", "PLUSPLUS", "MINUSMINUS", "ASSIGN", 
			"PLUSASSIGN", "MINUSASSIGN", "MULTIPLYASSIGN", "DIVIDEASSIGN", "MODULOASSIGN", 
			"LESS", "MOREE", "LESSEQUAL", "MOREEQUAL", "EXCLAMATION", "IF", "ELIF", 
			"ELSE", "SWITCH", "CASE", "DEFAULT", "WHILE", "FOR", "CONTINUE", "BREAK", 
			"RETURN", "Constant", "Identifier", "WS", "WhiteSpace"
		};
	}
	private static final String[] _SYMBOLIC_NAMES = makeSymbolicNames();
	public static final Vocabulary VOCABULARY = new VocabularyImpl(_LITERAL_NAMES, _SYMBOLIC_NAMES);

	/**
	 * @deprecated Use {@link #VOCABULARY} instead.
	 */
	@Deprecated
	public static final String[] tokenNames;
	static {
		tokenNames = new String[_SYMBOLIC_NAMES.length];
		for (int i = 0; i < tokenNames.length; i++) {
			tokenNames[i] = VOCABULARY.getLiteralName(i);
			if (tokenNames[i] == null) {
				tokenNames[i] = VOCABULARY.getSymbolicName(i);
			}

			if (tokenNames[i] == null) {
				tokenNames[i] = "<INVALID>";
			}
		}
	}

	@Override
	@Deprecated
	public String[] getTokenNames() {
		return tokenNames;
	}

	@Override

	public Vocabulary getVocabulary() {
		return VOCABULARY;
	}

	@Override
	public String getGrammarFileName() { return "Shaper.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public ATN getATN() { return _ATN; }

	public ShaperParser(TokenStream input) {
		super(input);
		_interp = new ParserATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	public static class ProgrammContext extends ParserRuleContext {
		public List<ExternalDeclarationContext> externalDeclaration() {
			return getRuleContexts(ExternalDeclarationContext.class);
		}
		public ExternalDeclarationContext externalDeclaration(int i) {
			return getRuleContext(ExternalDeclarationContext.class,i);
		}
		public ProgrammContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_programm; }
	}

	public final ProgrammContext programm() throws RecognitionException {
		ProgrammContext _localctx = new ProgrammContext(_ctx, getState());
		enterRule(_localctx, 0, RULE_programm);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(99);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << VOID) | (1L << BOOL) | (1L << INT) | (1L << LONG) | (1L << CHAR) | (1L << FLOAT) | (1L << DOUBLE) | (1L << COLOR) | (1L << STRUCT) | (1L << ARRAY) | (1L << LIST) | (1L << CONST))) != 0)) {
				{
				{
				setState(96);
				externalDeclaration();
				}
				}
				setState(101);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ExternalDeclarationContext extends ParserRuleContext {
		public FunctionDefinitionContext functionDefinition() {
			return getRuleContext(FunctionDefinitionContext.class,0);
		}
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(ShaperParser.SEMICOLON, 0); }
		public ExternalDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_externalDeclaration; }
	}

	public final ExternalDeclarationContext externalDeclaration() throws RecognitionException {
		ExternalDeclarationContext _localctx = new ExternalDeclarationContext(_ctx, getState());
		enterRule(_localctx, 2, RULE_externalDeclaration);
		try {
			setState(106);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,1,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(102);
				functionDefinition();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(103);
				declaration();
				setState(104);
				match(SEMICOLON);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionDefinitionContext extends ParserRuleContext {
		public FunctionSpecifierContext functionSpecifier() {
			return getRuleContext(FunctionSpecifierContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(ShaperParser.Identifier, 0); }
		public DeclaratorContext declarator() {
			return getRuleContext(DeclaratorContext.class,0);
		}
		public CompoundStatementContext compoundStatement() {
			return getRuleContext(CompoundStatementContext.class,0);
		}
		public FunctionDefinitionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionDefinition; }
	}

	public final FunctionDefinitionContext functionDefinition() throws RecognitionException {
		FunctionDefinitionContext _localctx = new FunctionDefinitionContext(_ctx, getState());
		enterRule(_localctx, 4, RULE_functionDefinition);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(108);
			functionSpecifier();
			setState(109);
			match(Identifier);
			setState(110);
			declarator();
			setState(111);
			compoundStatement();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionSpecifierContext extends ParserRuleContext {
		public TypeSpecifierContext typeSpecifier() {
			return getRuleContext(TypeSpecifierContext.class,0);
		}
		public TerminalNode CONST() { return getToken(ShaperParser.CONST, 0); }
		public FunctionSpecifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionSpecifier; }
	}

	public final FunctionSpecifierContext functionSpecifier() throws RecognitionException {
		FunctionSpecifierContext _localctx = new FunctionSpecifierContext(_ctx, getState());
		enterRule(_localctx, 6, RULE_functionSpecifier);
		try {
			setState(116);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case VOID:
			case BOOL:
			case INT:
			case LONG:
			case CHAR:
			case FLOAT:
			case DOUBLE:
			case COLOR:
			case STRUCT:
			case ARRAY:
			case LIST:
				enterOuterAlt(_localctx, 1);
				{
				setState(113);
				typeSpecifier();
				}
				break;
			case CONST:
				enterOuterAlt(_localctx, 2);
				{
				setState(114);
				match(CONST);
				setState(115);
				typeSpecifier();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TypeSpecifierContext extends ParserRuleContext {
		public TerminalNode VOID() { return getToken(ShaperParser.VOID, 0); }
		public TerminalNode BOOL() { return getToken(ShaperParser.BOOL, 0); }
		public TerminalNode INT() { return getToken(ShaperParser.INT, 0); }
		public TerminalNode LONG() { return getToken(ShaperParser.LONG, 0); }
		public TerminalNode CHAR() { return getToken(ShaperParser.CHAR, 0); }
		public TerminalNode FLOAT() { return getToken(ShaperParser.FLOAT, 0); }
		public TerminalNode DOUBLE() { return getToken(ShaperParser.DOUBLE, 0); }
		public TerminalNode COLOR() { return getToken(ShaperParser.COLOR, 0); }
		public TerminalNode STRUCT() { return getToken(ShaperParser.STRUCT, 0); }
		public TerminalNode Identifier() { return getToken(ShaperParser.Identifier, 0); }
		public TerminalNode ARRAY() { return getToken(ShaperParser.ARRAY, 0); }
		public FunctionSpecifierContext functionSpecifier() {
			return getRuleContext(FunctionSpecifierContext.class,0);
		}
		public TerminalNode LIST() { return getToken(ShaperParser.LIST, 0); }
		public TypeSpecifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_typeSpecifier; }
	}

	public final TypeSpecifierContext typeSpecifier() throws RecognitionException {
		TypeSpecifierContext _localctx = new TypeSpecifierContext(_ctx, getState());
		enterRule(_localctx, 8, RULE_typeSpecifier);
		try {
			setState(132);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case VOID:
				enterOuterAlt(_localctx, 1);
				{
				setState(118);
				match(VOID);
				}
				break;
			case BOOL:
				enterOuterAlt(_localctx, 2);
				{
				setState(119);
				match(BOOL);
				}
				break;
			case INT:
				enterOuterAlt(_localctx, 3);
				{
				setState(120);
				match(INT);
				}
				break;
			case LONG:
				enterOuterAlt(_localctx, 4);
				{
				setState(121);
				match(LONG);
				}
				break;
			case CHAR:
				enterOuterAlt(_localctx, 5);
				{
				setState(122);
				match(CHAR);
				}
				break;
			case FLOAT:
				enterOuterAlt(_localctx, 6);
				{
				setState(123);
				match(FLOAT);
				}
				break;
			case DOUBLE:
				enterOuterAlt(_localctx, 7);
				{
				setState(124);
				match(DOUBLE);
				}
				break;
			case COLOR:
				enterOuterAlt(_localctx, 8);
				{
				setState(125);
				match(COLOR);
				}
				break;
			case STRUCT:
				enterOuterAlt(_localctx, 9);
				{
				setState(126);
				match(STRUCT);
				setState(127);
				match(Identifier);
				}
				break;
			case ARRAY:
				enterOuterAlt(_localctx, 10);
				{
				setState(128);
				match(ARRAY);
				setState(129);
				functionSpecifier();
				}
				break;
			case LIST:
				enterOuterAlt(_localctx, 11);
				{
				setState(130);
				match(LIST);
				setState(131);
				functionSpecifier();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclaratorContext extends ParserRuleContext {
		public TerminalNode LEFTPAREN() { return getToken(ShaperParser.LEFTPAREN, 0); }
		public TerminalNode RIGHTPAREN() { return getToken(ShaperParser.RIGHTPAREN, 0); }
		public ParameterListContext parameterList() {
			return getRuleContext(ParameterListContext.class,0);
		}
		public DeclaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declarator; }
	}

	public final DeclaratorContext declarator() throws RecognitionException {
		DeclaratorContext _localctx = new DeclaratorContext(_ctx, getState());
		enterRule(_localctx, 10, RULE_declarator);
		try {
			setState(140);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,4,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(134);
				match(LEFTPAREN);
				setState(135);
				match(RIGHTPAREN);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(136);
				match(LEFTPAREN);
				setState(137);
				parameterList(0);
				setState(138);
				match(RIGHTPAREN);
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ParameterListContext extends ParserRuleContext {
		public ParameterDeclarationContext parameterDeclaration() {
			return getRuleContext(ParameterDeclarationContext.class,0);
		}
		public ParameterListContext parameterList() {
			return getRuleContext(ParameterListContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(ShaperParser.COMMA, 0); }
		public ParameterListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterList; }
	}

	public final ParameterListContext parameterList() throws RecognitionException {
		return parameterList(0);
	}

	private ParameterListContext parameterList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		ParameterListContext _localctx = new ParameterListContext(_ctx, _parentState);
		ParameterListContext _prevctx = _localctx;
		int _startState = 12;
		enterRecursionRule(_localctx, 12, RULE_parameterList, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(143);
			parameterDeclaration();
			}
			_ctx.stop = _input.LT(-1);
			setState(150);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new ParameterListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_parameterList);
					setState(145);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(146);
					match(COMMA);
					setState(147);
					parameterDeclaration();
					}
					} 
				}
				setState(152);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,5,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ParameterDeclarationContext extends ParserRuleContext {
		public FunctionSpecifierContext functionSpecifier() {
			return getRuleContext(FunctionSpecifierContext.class,0);
		}
		public TerminalNode Identifier() { return getToken(ShaperParser.Identifier, 0); }
		public ParameterDeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_parameterDeclaration; }
	}

	public final ParameterDeclarationContext parameterDeclaration() throws RecognitionException {
		ParameterDeclarationContext _localctx = new ParameterDeclarationContext(_ctx, getState());
		enterRule(_localctx, 14, RULE_parameterDeclaration);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(153);
			functionSpecifier();
			setState(154);
			match(Identifier);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CompoundStatementContext extends ParserRuleContext {
		public TerminalNode LEFTBRACKET() { return getToken(ShaperParser.LEFTBRACKET, 0); }
		public TerminalNode RIGHTBRACKET() { return getToken(ShaperParser.RIGHTBRACKET, 0); }
		public List<StatementContext> statement() {
			return getRuleContexts(StatementContext.class);
		}
		public StatementContext statement(int i) {
			return getRuleContext(StatementContext.class,i);
		}
		public List<DeclarationContext> declaration() {
			return getRuleContexts(DeclarationContext.class);
		}
		public DeclarationContext declaration(int i) {
			return getRuleContext(DeclarationContext.class,i);
		}
		public List<TerminalNode> SEMICOLON() { return getTokens(ShaperParser.SEMICOLON); }
		public TerminalNode SEMICOLON(int i) {
			return getToken(ShaperParser.SEMICOLON, i);
		}
		public CompoundStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_compoundStatement; }
	}

	public final CompoundStatementContext compoundStatement() throws RecognitionException {
		CompoundStatementContext _localctx = new CompoundStatementContext(_ctx, getState());
		enterRule(_localctx, 16, RULE_compoundStatement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(156);
			match(LEFTBRACKET);
			setState(163);
			_errHandler.sync(this);
			_la = _input.LA(1);
			while ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << PAINT) | (1L << LEFTPAREN) | (1L << LEFTBRACKET) | (1L << BOOL) | (1L << INT) | (1L << LONG) | (1L << CHAR) | (1L << FLOAT) | (1L << DOUBLE) | (1L << COLOR) | (1L << STRUCT) | (1L << ARRAY) | (1L << LIST) | (1L << CONST) | (1L << MINUS) | (1L << PLUSPLUS) | (1L << MINUSMINUS) | (1L << EXCLAMATION) | (1L << IF) | (1L << SWITCH) | (1L << CASE) | (1L << DEFAULT) | (1L << WHILE) | (1L << FOR))) != 0) || ((((_la - 64)) & ~0x3f) == 0 && ((1L << (_la - 64)) & ((1L << (CONTINUE - 64)) | (1L << (BREAK - 64)) | (1L << (RETURN - 64)) | (1L << (Constant - 64)) | (1L << (Identifier - 64)))) != 0)) {
				{
				setState(161);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case BOOL:
				case INT:
				case LONG:
				case CHAR:
				case FLOAT:
				case DOUBLE:
				case COLOR:
				case STRUCT:
				case ARRAY:
				case LIST:
				case CONST:
					{
					{
					setState(157);
					declaration();
					setState(158);
					match(SEMICOLON);
					}
					}
					break;
				case PAINT:
				case LEFTPAREN:
				case LEFTBRACKET:
				case MINUS:
				case PLUSPLUS:
				case MINUSMINUS:
				case EXCLAMATION:
				case IF:
				case SWITCH:
				case CASE:
				case DEFAULT:
				case WHILE:
				case FOR:
				case CONTINUE:
				case BREAK:
				case RETURN:
				case Constant:
				case Identifier:
					{
					setState(160);
					statement();
					}
					break;
				default:
					throw new NoViableAltException(this);
				}
				}
				setState(165);
				_errHandler.sync(this);
				_la = _input.LA(1);
			}
			setState(166);
			match(RIGHTBRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationContext extends ParserRuleContext {
		public DeclarationSpecifierContext declarationSpecifier() {
			return getRuleContext(DeclarationSpecifierContext.class,0);
		}
		public InitDeclaratorContext initDeclarator() {
			return getRuleContext(InitDeclaratorContext.class,0);
		}
		public StructDeclaratorContext structDeclarator() {
			return getRuleContext(StructDeclaratorContext.class,0);
		}
		public DeclarationContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declaration; }
	}

	public final DeclarationContext declaration() throws RecognitionException {
		DeclarationContext _localctx = new DeclarationContext(_ctx, getState());
		enterRule(_localctx, 18, RULE_declaration);
		try {
			setState(172);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,8,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(168);
				declarationSpecifier();
				setState(169);
				initDeclarator();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(171);
				structDeclarator();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationSpecifierContext extends ParserRuleContext {
		public DeclarationTypeContext declarationType() {
			return getRuleContext(DeclarationTypeContext.class,0);
		}
		public TerminalNode CONST() { return getToken(ShaperParser.CONST, 0); }
		public DeclarationSpecifierContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declarationSpecifier; }
	}

	public final DeclarationSpecifierContext declarationSpecifier() throws RecognitionException {
		DeclarationSpecifierContext _localctx = new DeclarationSpecifierContext(_ctx, getState());
		enterRule(_localctx, 20, RULE_declarationSpecifier);
		try {
			setState(177);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BOOL:
			case INT:
			case LONG:
			case CHAR:
			case FLOAT:
			case DOUBLE:
			case COLOR:
			case STRUCT:
			case ARRAY:
			case LIST:
				enterOuterAlt(_localctx, 1);
				{
				setState(174);
				declarationType();
				}
				break;
			case CONST:
				enterOuterAlt(_localctx, 2);
				{
				setState(175);
				match(CONST);
				setState(176);
				declarationType();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class DeclarationTypeContext extends ParserRuleContext {
		public TerminalNode BOOL() { return getToken(ShaperParser.BOOL, 0); }
		public TerminalNode INT() { return getToken(ShaperParser.INT, 0); }
		public TerminalNode LONG() { return getToken(ShaperParser.LONG, 0); }
		public TerminalNode CHAR() { return getToken(ShaperParser.CHAR, 0); }
		public TerminalNode FLOAT() { return getToken(ShaperParser.FLOAT, 0); }
		public TerminalNode DOUBLE() { return getToken(ShaperParser.DOUBLE, 0); }
		public TerminalNode COLOR() { return getToken(ShaperParser.COLOR, 0); }
		public TerminalNode STRUCT() { return getToken(ShaperParser.STRUCT, 0); }
		public TerminalNode Identifier() { return getToken(ShaperParser.Identifier, 0); }
		public TerminalNode ARRAY() { return getToken(ShaperParser.ARRAY, 0); }
		public TerminalNode LEFTPAREN() { return getToken(ShaperParser.LEFTPAREN, 0); }
		public TerminalNode RIGHTPAREN() { return getToken(ShaperParser.RIGHTPAREN, 0); }
		public DeclarationSpecifierContext declarationSpecifier() {
			return getRuleContext(DeclarationSpecifierContext.class,0);
		}
		public TerminalNode Constant() { return getToken(ShaperParser.Constant, 0); }
		public TerminalNode LIST() { return getToken(ShaperParser.LIST, 0); }
		public DeclarationTypeContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_declarationType; }
	}

	public final DeclarationTypeContext declarationType() throws RecognitionException {
		DeclarationTypeContext _localctx = new DeclarationTypeContext(_ctx, getState());
		enterRule(_localctx, 22, RULE_declarationType);
		int _la;
		try {
			setState(197);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case BOOL:
				enterOuterAlt(_localctx, 1);
				{
				setState(179);
				match(BOOL);
				}
				break;
			case INT:
				enterOuterAlt(_localctx, 2);
				{
				setState(180);
				match(INT);
				}
				break;
			case LONG:
				enterOuterAlt(_localctx, 3);
				{
				setState(181);
				match(LONG);
				}
				break;
			case CHAR:
				enterOuterAlt(_localctx, 4);
				{
				setState(182);
				match(CHAR);
				}
				break;
			case FLOAT:
				enterOuterAlt(_localctx, 5);
				{
				setState(183);
				match(FLOAT);
				}
				break;
			case DOUBLE:
				enterOuterAlt(_localctx, 6);
				{
				setState(184);
				match(DOUBLE);
				}
				break;
			case COLOR:
				enterOuterAlt(_localctx, 7);
				{
				setState(185);
				match(COLOR);
				}
				break;
			case STRUCT:
				enterOuterAlt(_localctx, 8);
				{
				setState(186);
				match(STRUCT);
				setState(187);
				match(Identifier);
				}
				break;
			case ARRAY:
				enterOuterAlt(_localctx, 9);
				{
				setState(188);
				match(ARRAY);
				setState(189);
				match(LEFTPAREN);
				setState(191);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==Constant || _la==Identifier) {
					{
					setState(190);
					_la = _input.LA(1);
					if ( !(_la==Constant || _la==Identifier) ) {
					_errHandler.recoverInline(this);
					}
					else {
						if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
						_errHandler.reportMatch(this);
						consume();
					}
					}
				}

				setState(193);
				match(RIGHTPAREN);
				setState(194);
				declarationSpecifier();
				}
				break;
			case LIST:
				enterOuterAlt(_localctx, 10);
				{
				setState(195);
				match(LIST);
				setState(196);
				declarationSpecifier();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class InitDeclaratorContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(ShaperParser.Identifier, 0); }
		public AssignmentOperatorContext assignmentOperator() {
			return getRuleContext(AssignmentOperatorContext.class,0);
		}
		public AssignmentExpressionContext assignmentExpression() {
			return getRuleContext(AssignmentExpressionContext.class,0);
		}
		public InitDeclaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_initDeclarator; }
	}

	public final InitDeclaratorContext initDeclarator() throws RecognitionException {
		InitDeclaratorContext _localctx = new InitDeclaratorContext(_ctx, getState());
		enterRule(_localctx, 24, RULE_initDeclarator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(199);
			match(Identifier);
			setState(203);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if ((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ASSIGN) | (1L << PLUSASSIGN) | (1L << MINUSASSIGN) | (1L << MULTIPLYASSIGN) | (1L << DIVIDEASSIGN) | (1L << MODULOASSIGN))) != 0)) {
				{
				setState(200);
				assignmentOperator();
				setState(201);
				assignmentExpression();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StructDeclaratorContext extends ParserRuleContext {
		public TerminalNode STRUCT() { return getToken(ShaperParser.STRUCT, 0); }
		public TerminalNode Identifier() { return getToken(ShaperParser.Identifier, 0); }
		public TerminalNode LEFTBRACKET() { return getToken(ShaperParser.LEFTBRACKET, 0); }
		public StructDeclarationListContext structDeclarationList() {
			return getRuleContext(StructDeclarationListContext.class,0);
		}
		public TerminalNode RIGHTBRACKET() { return getToken(ShaperParser.RIGHTBRACKET, 0); }
		public StructDeclaratorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_structDeclarator; }
	}

	public final StructDeclaratorContext structDeclarator() throws RecognitionException {
		StructDeclaratorContext _localctx = new StructDeclaratorContext(_ctx, getState());
		enterRule(_localctx, 26, RULE_structDeclarator);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(205);
			match(STRUCT);
			setState(206);
			match(Identifier);
			setState(207);
			match(LEFTBRACKET);
			setState(208);
			structDeclarationList(0);
			setState(209);
			match(RIGHTBRACKET);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StructDeclarationListContext extends ParserRuleContext {
		public DeclarationContext declaration() {
			return getRuleContext(DeclarationContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(ShaperParser.SEMICOLON, 0); }
		public StructDeclarationListContext structDeclarationList() {
			return getRuleContext(StructDeclarationListContext.class,0);
		}
		public StructDeclarationListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_structDeclarationList; }
	}

	public final StructDeclarationListContext structDeclarationList() throws RecognitionException {
		return structDeclarationList(0);
	}

	private StructDeclarationListContext structDeclarationList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		StructDeclarationListContext _localctx = new StructDeclarationListContext(_ctx, _parentState);
		StructDeclarationListContext _prevctx = _localctx;
		int _startState = 28;
		enterRecursionRule(_localctx, 28, RULE_structDeclarationList, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(212);
			declaration();
			setState(213);
			match(SEMICOLON);
			}
			_ctx.stop = _input.LT(-1);
			setState(221);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new StructDeclarationListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_structDeclarationList);
					setState(215);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(216);
					declaration();
					setState(217);
					match(SEMICOLON);
					}
					} 
				}
				setState(223);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,13,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class ExpressionContext extends ParserRuleContext {
		public AssignmentExpressionContext assignmentExpression() {
			return getRuleContext(AssignmentExpressionContext.class,0);
		}
		public ExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_expression; }
	}

	public final ExpressionContext expression() throws RecognitionException {
		ExpressionContext _localctx = new ExpressionContext(_ctx, getState());
		enterRule(_localctx, 30, RULE_expression);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(224);
			assignmentExpression();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AssignmentExpressionContext extends ParserRuleContext {
		public LogicalORExpressionContext logicalORExpression() {
			return getRuleContext(LogicalORExpressionContext.class,0);
		}
		public UnaryExpressionContext unaryExpression() {
			return getRuleContext(UnaryExpressionContext.class,0);
		}
		public AssignmentOperatorContext assignmentOperator() {
			return getRuleContext(AssignmentOperatorContext.class,0);
		}
		public AssignmentExpressionContext assignmentExpression() {
			return getRuleContext(AssignmentExpressionContext.class,0);
		}
		public AssignmentExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignmentExpression; }
	}

	public final AssignmentExpressionContext assignmentExpression() throws RecognitionException {
		AssignmentExpressionContext _localctx = new AssignmentExpressionContext(_ctx, getState());
		enterRule(_localctx, 32, RULE_assignmentExpression);
		try {
			setState(231);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,14,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(226);
				logicalORExpression(0);
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(227);
				unaryExpression();
				setState(228);
				assignmentOperator();
				setState(229);
				assignmentExpression();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LogicalORExpressionContext extends ParserRuleContext {
		public LogicalANDExpressionContext logicalANDExpression() {
			return getRuleContext(LogicalANDExpressionContext.class,0);
		}
		public LogicalORExpressionContext logicalORExpression() {
			return getRuleContext(LogicalORExpressionContext.class,0);
		}
		public TerminalNode OR() { return getToken(ShaperParser.OR, 0); }
		public LogicalORExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicalORExpression; }
	}

	public final LogicalORExpressionContext logicalORExpression() throws RecognitionException {
		return logicalORExpression(0);
	}

	private LogicalORExpressionContext logicalORExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		LogicalORExpressionContext _localctx = new LogicalORExpressionContext(_ctx, _parentState);
		LogicalORExpressionContext _prevctx = _localctx;
		int _startState = 34;
		enterRecursionRule(_localctx, 34, RULE_logicalORExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(234);
			logicalANDExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(241);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new LogicalORExpressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_logicalORExpression);
					setState(236);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(237);
					match(OR);
					setState(238);
					logicalANDExpression(0);
					}
					} 
				}
				setState(243);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,15,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class LogicalANDExpressionContext extends ParserRuleContext {
		public EqualityExpressionContext equalityExpression() {
			return getRuleContext(EqualityExpressionContext.class,0);
		}
		public LogicalANDExpressionContext logicalANDExpression() {
			return getRuleContext(LogicalANDExpressionContext.class,0);
		}
		public TerminalNode AND() { return getToken(ShaperParser.AND, 0); }
		public LogicalANDExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_logicalANDExpression; }
	}

	public final LogicalANDExpressionContext logicalANDExpression() throws RecognitionException {
		return logicalANDExpression(0);
	}

	private LogicalANDExpressionContext logicalANDExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		LogicalANDExpressionContext _localctx = new LogicalANDExpressionContext(_ctx, _parentState);
		LogicalANDExpressionContext _prevctx = _localctx;
		int _startState = 36;
		enterRecursionRule(_localctx, 36, RULE_logicalANDExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(245);
			equalityExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(252);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new LogicalANDExpressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_logicalANDExpression);
					setState(247);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(248);
					match(AND);
					setState(249);
					equalityExpression(0);
					}
					} 
				}
				setState(254);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,16,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class EqualityExpressionContext extends ParserRuleContext {
		public RelationalExpressionContext relationalExpression() {
			return getRuleContext(RelationalExpressionContext.class,0);
		}
		public EqualityExpressionContext equalityExpression() {
			return getRuleContext(EqualityExpressionContext.class,0);
		}
		public TerminalNode EQUAL() { return getToken(ShaperParser.EQUAL, 0); }
		public TerminalNode NOTEQUAL() { return getToken(ShaperParser.NOTEQUAL, 0); }
		public EqualityExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_equalityExpression; }
	}

	public final EqualityExpressionContext equalityExpression() throws RecognitionException {
		return equalityExpression(0);
	}

	private EqualityExpressionContext equalityExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		EqualityExpressionContext _localctx = new EqualityExpressionContext(_ctx, _parentState);
		EqualityExpressionContext _prevctx = _localctx;
		int _startState = 38;
		enterRecursionRule(_localctx, 38, RULE_equalityExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(256);
			relationalExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(266);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(264);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,17,_ctx) ) {
					case 1:
						{
						_localctx = new EqualityExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_equalityExpression);
						setState(258);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(259);
						match(EQUAL);
						setState(260);
						relationalExpression(0);
						}
						break;
					case 2:
						{
						_localctx = new EqualityExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_equalityExpression);
						setState(261);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(262);
						match(NOTEQUAL);
						setState(263);
						relationalExpression(0);
						}
						break;
					}
					} 
				}
				setState(268);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,18,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class RelationalExpressionContext extends ParserRuleContext {
		public AdditiveExpressionContext additiveExpression() {
			return getRuleContext(AdditiveExpressionContext.class,0);
		}
		public RelationalExpressionContext relationalExpression() {
			return getRuleContext(RelationalExpressionContext.class,0);
		}
		public RelationalOperatorContext relationalOperator() {
			return getRuleContext(RelationalOperatorContext.class,0);
		}
		public RelationalExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_relationalExpression; }
	}

	public final RelationalExpressionContext relationalExpression() throws RecognitionException {
		return relationalExpression(0);
	}

	private RelationalExpressionContext relationalExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		RelationalExpressionContext _localctx = new RelationalExpressionContext(_ctx, _parentState);
		RelationalExpressionContext _prevctx = _localctx;
		int _startState = 40;
		enterRecursionRule(_localctx, 40, RULE_relationalExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(270);
			additiveExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(278);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new RelationalExpressionContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_relationalExpression);
					setState(272);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(273);
					relationalOperator();
					setState(274);
					additiveExpression(0);
					}
					} 
				}
				setState(280);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,19,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class AdditiveExpressionContext extends ParserRuleContext {
		public MultiplicativeExpressionContext multiplicativeExpression() {
			return getRuleContext(MultiplicativeExpressionContext.class,0);
		}
		public AdditiveExpressionContext additiveExpression() {
			return getRuleContext(AdditiveExpressionContext.class,0);
		}
		public TerminalNode PLUS() { return getToken(ShaperParser.PLUS, 0); }
		public TerminalNode MINUS() { return getToken(ShaperParser.MINUS, 0); }
		public AdditiveExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_additiveExpression; }
	}

	public final AdditiveExpressionContext additiveExpression() throws RecognitionException {
		return additiveExpression(0);
	}

	private AdditiveExpressionContext additiveExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		AdditiveExpressionContext _localctx = new AdditiveExpressionContext(_ctx, _parentState);
		AdditiveExpressionContext _prevctx = _localctx;
		int _startState = 42;
		enterRecursionRule(_localctx, 42, RULE_additiveExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(282);
			multiplicativeExpression(0);
			}
			_ctx.stop = _input.LT(-1);
			setState(292);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(290);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,20,_ctx) ) {
					case 1:
						{
						_localctx = new AdditiveExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_additiveExpression);
						setState(284);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(285);
						match(PLUS);
						setState(286);
						multiplicativeExpression(0);
						}
						break;
					case 2:
						{
						_localctx = new AdditiveExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_additiveExpression);
						setState(287);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(288);
						match(MINUS);
						setState(289);
						multiplicativeExpression(0);
						}
						break;
					}
					} 
				}
				setState(294);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,21,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class MultiplicativeExpressionContext extends ParserRuleContext {
		public UnaryExpressionContext unaryExpression() {
			return getRuleContext(UnaryExpressionContext.class,0);
		}
		public MultiplicativeExpressionContext multiplicativeExpression() {
			return getRuleContext(MultiplicativeExpressionContext.class,0);
		}
		public TerminalNode MULTIPLY() { return getToken(ShaperParser.MULTIPLY, 0); }
		public TerminalNode DIVIDE() { return getToken(ShaperParser.DIVIDE, 0); }
		public TerminalNode MODULO() { return getToken(ShaperParser.MODULO, 0); }
		public MultiplicativeExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_multiplicativeExpression; }
	}

	public final MultiplicativeExpressionContext multiplicativeExpression() throws RecognitionException {
		return multiplicativeExpression(0);
	}

	private MultiplicativeExpressionContext multiplicativeExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		MultiplicativeExpressionContext _localctx = new MultiplicativeExpressionContext(_ctx, _parentState);
		MultiplicativeExpressionContext _prevctx = _localctx;
		int _startState = 44;
		enterRecursionRule(_localctx, 44, RULE_multiplicativeExpression, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(296);
			unaryExpression();
			}
			_ctx.stop = _input.LT(-1);
			setState(309);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(307);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,22,_ctx) ) {
					case 1:
						{
						_localctx = new MultiplicativeExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_multiplicativeExpression);
						setState(298);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(299);
						match(MULTIPLY);
						setState(300);
						unaryExpression();
						}
						break;
					case 2:
						{
						_localctx = new MultiplicativeExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_multiplicativeExpression);
						setState(301);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(302);
						match(DIVIDE);
						setState(303);
						unaryExpression();
						}
						break;
					case 3:
						{
						_localctx = new MultiplicativeExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_multiplicativeExpression);
						setState(304);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(305);
						match(MODULO);
						setState(306);
						unaryExpression();
						}
						break;
					}
					} 
				}
				setState(311);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,23,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class UnaryExpressionContext extends ParserRuleContext {
		public PostfixExpressionContext postfixExpression() {
			return getRuleContext(PostfixExpressionContext.class,0);
		}
		public UnaryOperatorContext unaryOperator() {
			return getRuleContext(UnaryOperatorContext.class,0);
		}
		public UnaryExpressionContext unaryExpression() {
			return getRuleContext(UnaryExpressionContext.class,0);
		}
		public UnaryExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unaryExpression; }
	}

	public final UnaryExpressionContext unaryExpression() throws RecognitionException {
		UnaryExpressionContext _localctx = new UnaryExpressionContext(_ctx, getState());
		enterRule(_localctx, 46, RULE_unaryExpression);
		try {
			setState(316);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LEFTPAREN:
			case Constant:
			case Identifier:
				enterOuterAlt(_localctx, 1);
				{
				setState(312);
				postfixExpression(0);
				}
				break;
			case MINUS:
			case PLUSPLUS:
			case MINUSMINUS:
			case EXCLAMATION:
				enterOuterAlt(_localctx, 2);
				{
				setState(313);
				unaryOperator();
				setState(314);
				unaryExpression();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PostfixExpressionContext extends ParserRuleContext {
		public PrimaryExpressionContext primaryExpression() {
			return getRuleContext(PrimaryExpressionContext.class,0);
		}
		public PostfixExpressionContext postfixExpression() {
			return getRuleContext(PostfixExpressionContext.class,0);
		}
		public TerminalNode DOT() { return getToken(ShaperParser.DOT, 0); }
		public TerminalNode Identifier() { return getToken(ShaperParser.Identifier, 0); }
		public TerminalNode PLUSPLUS() { return getToken(ShaperParser.PLUSPLUS, 0); }
		public TerminalNode MINUSMINUS() { return getToken(ShaperParser.MINUSMINUS, 0); }
		public TerminalNode LEFTPAREN() { return getToken(ShaperParser.LEFTPAREN, 0); }
		public TerminalNode RIGHTPAREN() { return getToken(ShaperParser.RIGHTPAREN, 0); }
		public FunctionParameterListContext functionParameterList() {
			return getRuleContext(FunctionParameterListContext.class,0);
		}
		public PostfixExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_postfixExpression; }
	}

	public final PostfixExpressionContext postfixExpression() throws RecognitionException {
		return postfixExpression(0);
	}

	private PostfixExpressionContext postfixExpression(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		PostfixExpressionContext _localctx = new PostfixExpressionContext(_ctx, _parentState);
		PostfixExpressionContext _prevctx = _localctx;
		int _startState = 48;
		enterRecursionRule(_localctx, 48, RULE_postfixExpression, _p);
		int _la;
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(319);
			primaryExpression();
			}
			_ctx.stop = _input.LT(-1);
			setState(336);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					setState(334);
					_errHandler.sync(this);
					switch ( getInterpreter().adaptivePredict(_input,26,_ctx) ) {
					case 1:
						{
						_localctx = new PostfixExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_postfixExpression);
						setState(321);
						if (!(precpred(_ctx, 4))) throw new FailedPredicateException(this, "precpred(_ctx, 4)");
						setState(322);
						match(DOT);
						setState(323);
						match(Identifier);
						}
						break;
					case 2:
						{
						_localctx = new PostfixExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_postfixExpression);
						setState(324);
						if (!(precpred(_ctx, 3))) throw new FailedPredicateException(this, "precpred(_ctx, 3)");
						setState(325);
						match(PLUSPLUS);
						}
						break;
					case 3:
						{
						_localctx = new PostfixExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_postfixExpression);
						setState(326);
						if (!(precpred(_ctx, 2))) throw new FailedPredicateException(this, "precpred(_ctx, 2)");
						setState(327);
						match(MINUSMINUS);
						}
						break;
					case 4:
						{
						_localctx = new PostfixExpressionContext(_parentctx, _parentState);
						pushNewRecursionContext(_localctx, _startState, RULE_postfixExpression);
						setState(328);
						if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
						setState(329);
						match(LEFTPAREN);
						setState(331);
						_errHandler.sync(this);
						_la = _input.LA(1);
						if (((((_la - 14)) & ~0x3f) == 0 && ((1L << (_la - 14)) & ((1L << (LEFTPAREN - 14)) | (1L << (MINUS - 14)) | (1L << (PLUSPLUS - 14)) | (1L << (MINUSMINUS - 14)) | (1L << (EXCLAMATION - 14)) | (1L << (Constant - 14)) | (1L << (Identifier - 14)))) != 0)) {
							{
							setState(330);
							functionParameterList(0);
							}
						}

						setState(333);
						match(RIGHTPAREN);
						}
						break;
					}
					} 
				}
				setState(338);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,27,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class PrimaryExpressionContext extends ParserRuleContext {
		public TerminalNode Identifier() { return getToken(ShaperParser.Identifier, 0); }
		public TerminalNode Constant() { return getToken(ShaperParser.Constant, 0); }
		public TerminalNode LEFTPAREN() { return getToken(ShaperParser.LEFTPAREN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode RIGHTPAREN() { return getToken(ShaperParser.RIGHTPAREN, 0); }
		public PrimaryExpressionContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_primaryExpression; }
	}

	public final PrimaryExpressionContext primaryExpression() throws RecognitionException {
		PrimaryExpressionContext _localctx = new PrimaryExpressionContext(_ctx, getState());
		enterRule(_localctx, 50, RULE_primaryExpression);
		try {
			setState(345);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case Identifier:
				enterOuterAlt(_localctx, 1);
				{
				setState(339);
				match(Identifier);
				}
				break;
			case Constant:
				enterOuterAlt(_localctx, 2);
				{
				setState(340);
				match(Constant);
				}
				break;
			case LEFTPAREN:
				enterOuterAlt(_localctx, 3);
				{
				setState(341);
				match(LEFTPAREN);
				setState(342);
				expression();
				setState(343);
				match(RIGHTPAREN);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FunctionParameterListContext extends ParserRuleContext {
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public FunctionParameterListContext functionParameterList() {
			return getRuleContext(FunctionParameterListContext.class,0);
		}
		public TerminalNode COMMA() { return getToken(ShaperParser.COMMA, 0); }
		public FunctionParameterListContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_functionParameterList; }
	}

	public final FunctionParameterListContext functionParameterList() throws RecognitionException {
		return functionParameterList(0);
	}

	private FunctionParameterListContext functionParameterList(int _p) throws RecognitionException {
		ParserRuleContext _parentctx = _ctx;
		int _parentState = getState();
		FunctionParameterListContext _localctx = new FunctionParameterListContext(_ctx, _parentState);
		FunctionParameterListContext _prevctx = _localctx;
		int _startState = 52;
		enterRecursionRule(_localctx, 52, RULE_functionParameterList, _p);
		try {
			int _alt;
			enterOuterAlt(_localctx, 1);
			{
			{
			setState(348);
			expression();
			}
			_ctx.stop = _input.LT(-1);
			setState(355);
			_errHandler.sync(this);
			_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
			while ( _alt!=2 && _alt!=org.antlr.v4.runtime.atn.ATN.INVALID_ALT_NUMBER ) {
				if ( _alt==1 ) {
					if ( _parseListeners!=null ) triggerExitRuleEvent();
					_prevctx = _localctx;
					{
					{
					_localctx = new FunctionParameterListContext(_parentctx, _parentState);
					pushNewRecursionContext(_localctx, _startState, RULE_functionParameterList);
					setState(350);
					if (!(precpred(_ctx, 1))) throw new FailedPredicateException(this, "precpred(_ctx, 1)");
					setState(351);
					match(COMMA);
					setState(352);
					expression();
					}
					} 
				}
				setState(357);
				_errHandler.sync(this);
				_alt = getInterpreter().adaptivePredict(_input,29,_ctx);
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			unrollRecursionContexts(_parentctx);
		}
		return _localctx;
	}

	public static class AssignmentOperatorContext extends ParserRuleContext {
		public TerminalNode ASSIGN() { return getToken(ShaperParser.ASSIGN, 0); }
		public TerminalNode PLUSASSIGN() { return getToken(ShaperParser.PLUSASSIGN, 0); }
		public TerminalNode MINUSASSIGN() { return getToken(ShaperParser.MINUSASSIGN, 0); }
		public TerminalNode MULTIPLYASSIGN() { return getToken(ShaperParser.MULTIPLYASSIGN, 0); }
		public TerminalNode DIVIDEASSIGN() { return getToken(ShaperParser.DIVIDEASSIGN, 0); }
		public TerminalNode MODULOASSIGN() { return getToken(ShaperParser.MODULOASSIGN, 0); }
		public AssignmentOperatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_assignmentOperator; }
	}

	public final AssignmentOperatorContext assignmentOperator() throws RecognitionException {
		AssignmentOperatorContext _localctx = new AssignmentOperatorContext(_ctx, getState());
		enterRule(_localctx, 54, RULE_assignmentOperator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(358);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << ASSIGN) | (1L << PLUSASSIGN) | (1L << MINUSASSIGN) | (1L << MULTIPLYASSIGN) | (1L << DIVIDEASSIGN) | (1L << MODULOASSIGN))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RelationalOperatorContext extends ParserRuleContext {
		public TerminalNode LESS() { return getToken(ShaperParser.LESS, 0); }
		public TerminalNode MOREE() { return getToken(ShaperParser.MOREE, 0); }
		public TerminalNode LESSEQUAL() { return getToken(ShaperParser.LESSEQUAL, 0); }
		public TerminalNode MOREEQUAL() { return getToken(ShaperParser.MOREEQUAL, 0); }
		public RelationalOperatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_relationalOperator; }
	}

	public final RelationalOperatorContext relationalOperator() throws RecognitionException {
		RelationalOperatorContext _localctx = new RelationalOperatorContext(_ctx, getState());
		enterRule(_localctx, 56, RULE_relationalOperator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(360);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << LESS) | (1L << MOREE) | (1L << LESSEQUAL) | (1L << MOREEQUAL))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class UnaryOperatorContext extends ParserRuleContext {
		public TerminalNode MINUS() { return getToken(ShaperParser.MINUS, 0); }
		public TerminalNode EXCLAMATION() { return getToken(ShaperParser.EXCLAMATION, 0); }
		public TerminalNode PLUSPLUS() { return getToken(ShaperParser.PLUSPLUS, 0); }
		public TerminalNode MINUSMINUS() { return getToken(ShaperParser.MINUSMINUS, 0); }
		public UnaryOperatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_unaryOperator; }
	}

	public final UnaryOperatorContext unaryOperator() throws RecognitionException {
		UnaryOperatorContext _localctx = new UnaryOperatorContext(_ctx, getState());
		enterRule(_localctx, 58, RULE_unaryOperator);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(362);
			_la = _input.LA(1);
			if ( !((((_la) & ~0x3f) == 0 && ((1L << _la) & ((1L << MINUS) | (1L << PLUSPLUS) | (1L << MINUSMINUS) | (1L << EXCLAMATION))) != 0)) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class StatementContext extends ParserRuleContext {
		public CompoundStatementContext compoundStatement() {
			return getRuleContext(CompoundStatementContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode SEMICOLON() { return getToken(ShaperParser.SEMICOLON, 0); }
		public PaintStatementContext paintStatement() {
			return getRuleContext(PaintStatementContext.class,0);
		}
		public SelectionStatementContext selectionStatement() {
			return getRuleContext(SelectionStatementContext.class,0);
		}
		public LabeledStatementContext labeledStatement() {
			return getRuleContext(LabeledStatementContext.class,0);
		}
		public IterationStatementContext iterationStatement() {
			return getRuleContext(IterationStatementContext.class,0);
		}
		public JumpStatementContext jumpStatement() {
			return getRuleContext(JumpStatementContext.class,0);
		}
		public StatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_statement; }
	}

	public final StatementContext statement() throws RecognitionException {
		StatementContext _localctx = new StatementContext(_ctx, getState());
		enterRule(_localctx, 60, RULE_statement);
		try {
			setState(375);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LEFTBRACKET:
				enterOuterAlt(_localctx, 1);
				{
				setState(364);
				compoundStatement();
				}
				break;
			case LEFTPAREN:
			case MINUS:
			case PLUSPLUS:
			case MINUSMINUS:
			case EXCLAMATION:
			case Constant:
			case Identifier:
				enterOuterAlt(_localctx, 2);
				{
				setState(365);
				expression();
				setState(366);
				match(SEMICOLON);
				}
				break;
			case PAINT:
				enterOuterAlt(_localctx, 3);
				{
				setState(368);
				paintStatement();
				setState(369);
				match(SEMICOLON);
				}
				break;
			case IF:
			case SWITCH:
				enterOuterAlt(_localctx, 4);
				{
				setState(371);
				selectionStatement();
				}
				break;
			case CASE:
			case DEFAULT:
				enterOuterAlt(_localctx, 5);
				{
				setState(372);
				labeledStatement();
				}
				break;
			case WHILE:
			case FOR:
				enterOuterAlt(_localctx, 6);
				{
				setState(373);
				iterationStatement();
				}
				break;
			case CONTINUE:
			case BREAK:
			case RETURN:
				enterOuterAlt(_localctx, 7);
				{
				setState(374);
				jumpStatement();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PaintStatementContext extends ParserRuleContext {
		public TerminalNode PAINT() { return getToken(ShaperParser.PAINT, 0); }
		public ShapeIndicatorContext shapeIndicator() {
			return getRuleContext(ShapeIndicatorContext.class,0);
		}
		public PaintStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_paintStatement; }
	}

	public final PaintStatementContext paintStatement() throws RecognitionException {
		PaintStatementContext _localctx = new PaintStatementContext(_ctx, getState());
		enterRule(_localctx, 62, RULE_paintStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(377);
			match(PAINT);
			setState(378);
			shapeIndicator();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ShapeIndicatorContext extends ParserRuleContext {
		public TerminalNode LINE() { return getToken(ShaperParser.LINE, 0); }
		public LineParametersContext lineParameters() {
			return getRuleContext(LineParametersContext.class,0);
		}
		public TerminalNode TRIANGLE() { return getToken(ShaperParser.TRIANGLE, 0); }
		public TriangleParametersContext triangleParameters() {
			return getRuleContext(TriangleParametersContext.class,0);
		}
		public TerminalNode RECTANGLE() { return getToken(ShaperParser.RECTANGLE, 0); }
		public RectangleParametersContext rectangleParameters() {
			return getRuleContext(RectangleParametersContext.class,0);
		}
		public TerminalNode CIRCLE() { return getToken(ShaperParser.CIRCLE, 0); }
		public CircleParametersContext circleParameters() {
			return getRuleContext(CircleParametersContext.class,0);
		}
		public ShapeIndicatorContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_shapeIndicator; }
	}

	public final ShapeIndicatorContext shapeIndicator() throws RecognitionException {
		ShapeIndicatorContext _localctx = new ShapeIndicatorContext(_ctx, getState());
		enterRule(_localctx, 64, RULE_shapeIndicator);
		try {
			setState(388);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case LINE:
				enterOuterAlt(_localctx, 1);
				{
				setState(380);
				match(LINE);
				setState(381);
				lineParameters();
				}
				break;
			case TRIANGLE:
				enterOuterAlt(_localctx, 2);
				{
				setState(382);
				match(TRIANGLE);
				setState(383);
				triangleParameters();
				}
				break;
			case RECTANGLE:
				enterOuterAlt(_localctx, 3);
				{
				setState(384);
				match(RECTANGLE);
				setState(385);
				rectangleParameters();
				}
				break;
			case CIRCLE:
				enterOuterAlt(_localctx, 4);
				{
				setState(386);
				match(CIRCLE);
				setState(387);
				circleParameters();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LineParametersContext extends ParserRuleContext {
		public FromStatementContext fromStatement() {
			return getRuleContext(FromStatementContext.class,0);
		}
		public ToStatementContext toStatement() {
			return getRuleContext(ToStatementContext.class,0);
		}
		public ColorStatementContext colorStatement() {
			return getRuleContext(ColorStatementContext.class,0);
		}
		public LineParametersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_lineParameters; }
	}

	public final LineParametersContext lineParameters() throws RecognitionException {
		LineParametersContext _localctx = new LineParametersContext(_ctx, getState());
		enterRule(_localctx, 66, RULE_lineParameters);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(390);
			fromStatement();
			setState(391);
			toStatement();
			setState(393);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WITH) {
				{
				setState(392);
				colorStatement();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class TriangleParametersContext extends ParserRuleContext {
		public FromStatementContext fromStatement() {
			return getRuleContext(FromStatementContext.class,0);
		}
		public ThroughStatementContext throughStatement() {
			return getRuleContext(ThroughStatementContext.class,0);
		}
		public ToStatementContext toStatement() {
			return getRuleContext(ToStatementContext.class,0);
		}
		public ColorStatementContext colorStatement() {
			return getRuleContext(ColorStatementContext.class,0);
		}
		public TriangleParametersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_triangleParameters; }
	}

	public final TriangleParametersContext triangleParameters() throws RecognitionException {
		TriangleParametersContext _localctx = new TriangleParametersContext(_ctx, getState());
		enterRule(_localctx, 68, RULE_triangleParameters);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(395);
			fromStatement();
			setState(396);
			throughStatement();
			setState(397);
			toStatement();
			setState(399);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WITH) {
				{
				setState(398);
				colorStatement();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class RectangleParametersContext extends ParserRuleContext {
		public AtStatementContext atStatement() {
			return getRuleContext(AtStatementContext.class,0);
		}
		public OfStatementContext ofStatement() {
			return getRuleContext(OfStatementContext.class,0);
		}
		public ColorStatementContext colorStatement() {
			return getRuleContext(ColorStatementContext.class,0);
		}
		public RectangleParametersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_rectangleParameters; }
	}

	public final RectangleParametersContext rectangleParameters() throws RecognitionException {
		RectangleParametersContext _localctx = new RectangleParametersContext(_ctx, getState());
		enterRule(_localctx, 70, RULE_rectangleParameters);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(401);
			atStatement();
			setState(402);
			ofStatement();
			setState(404);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WITH) {
				{
				setState(403);
				colorStatement();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class CircleParametersContext extends ParserRuleContext {
		public AtStatementContext atStatement() {
			return getRuleContext(AtStatementContext.class,0);
		}
		public OfStatementContext ofStatement() {
			return getRuleContext(OfStatementContext.class,0);
		}
		public ColorStatementContext colorStatement() {
			return getRuleContext(ColorStatementContext.class,0);
		}
		public CircleParametersContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_circleParameters; }
	}

	public final CircleParametersContext circleParameters() throws RecognitionException {
		CircleParametersContext _localctx = new CircleParametersContext(_ctx, getState());
		enterRule(_localctx, 72, RULE_circleParameters);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(406);
			atStatement();
			setState(407);
			ofStatement();
			setState(409);
			_errHandler.sync(this);
			_la = _input.LA(1);
			if (_la==WITH) {
				{
				setState(408);
				colorStatement();
				}
			}

			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class AtStatementContext extends ParserRuleContext {
		public TerminalNode AT() { return getToken(ShaperParser.AT, 0); }
		public PosSizeParentContext posSizeParent() {
			return getRuleContext(PosSizeParentContext.class,0);
		}
		public AtStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_atStatement; }
	}

	public final AtStatementContext atStatement() throws RecognitionException {
		AtStatementContext _localctx = new AtStatementContext(_ctx, getState());
		enterRule(_localctx, 74, RULE_atStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(411);
			match(AT);
			setState(412);
			posSizeParent();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class OfStatementContext extends ParserRuleContext {
		public TerminalNode OF() { return getToken(ShaperParser.OF, 0); }
		public PosSizeParentContext posSizeParent() {
			return getRuleContext(PosSizeParentContext.class,0);
		}
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public OfStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_ofStatement; }
	}

	public final OfStatementContext ofStatement() throws RecognitionException {
		OfStatementContext _localctx = new OfStatementContext(_ctx, getState());
		enterRule(_localctx, 76, RULE_ofStatement);
		try {
			setState(418);
			_errHandler.sync(this);
			switch ( getInterpreter().adaptivePredict(_input,36,_ctx) ) {
			case 1:
				enterOuterAlt(_localctx, 1);
				{
				setState(414);
				match(OF);
				setState(415);
				posSizeParent();
				}
				break;
			case 2:
				enterOuterAlt(_localctx, 2);
				{
				setState(416);
				match(OF);
				setState(417);
				expression();
				}
				break;
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class FromStatementContext extends ParserRuleContext {
		public TerminalNode FROM() { return getToken(ShaperParser.FROM, 0); }
		public PosSizeParentContext posSizeParent() {
			return getRuleContext(PosSizeParentContext.class,0);
		}
		public FromStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_fromStatement; }
	}

	public final FromStatementContext fromStatement() throws RecognitionException {
		FromStatementContext _localctx = new FromStatementContext(_ctx, getState());
		enterRule(_localctx, 78, RULE_fromStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(420);
			match(FROM);
			setState(421);
			posSizeParent();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ThroughStatementContext extends ParserRuleContext {
		public TerminalNode THROUGH() { return getToken(ShaperParser.THROUGH, 0); }
		public PosSizeParentContext posSizeParent() {
			return getRuleContext(PosSizeParentContext.class,0);
		}
		public ThroughStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_throughStatement; }
	}

	public final ThroughStatementContext throughStatement() throws RecognitionException {
		ThroughStatementContext _localctx = new ThroughStatementContext(_ctx, getState());
		enterRule(_localctx, 80, RULE_throughStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(423);
			match(THROUGH);
			setState(424);
			posSizeParent();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ToStatementContext extends ParserRuleContext {
		public TerminalNode TO() { return getToken(ShaperParser.TO, 0); }
		public PosSizeParentContext posSizeParent() {
			return getRuleContext(PosSizeParentContext.class,0);
		}
		public ToStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_toStatement; }
	}

	public final ToStatementContext toStatement() throws RecognitionException {
		ToStatementContext _localctx = new ToStatementContext(_ctx, getState());
		enterRule(_localctx, 82, RULE_toStatement);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(426);
			match(TO);
			setState(427);
			posSizeParent();
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class ColorStatementContext extends ParserRuleContext {
		public TerminalNode WITH() { return getToken(ShaperParser.WITH, 0); }
		public TerminalNode Identifier() { return getToken(ShaperParser.Identifier, 0); }
		public TerminalNode Constant() { return getToken(ShaperParser.Constant, 0); }
		public ColorStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_colorStatement; }
	}

	public final ColorStatementContext colorStatement() throws RecognitionException {
		ColorStatementContext _localctx = new ColorStatementContext(_ctx, getState());
		enterRule(_localctx, 84, RULE_colorStatement);
		int _la;
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(429);
			match(WITH);
			setState(430);
			_la = _input.LA(1);
			if ( !(_la==Constant || _la==Identifier) ) {
			_errHandler.recoverInline(this);
			}
			else {
				if ( _input.LA(1)==Token.EOF ) matchedEOF = true;
				_errHandler.reportMatch(this);
				consume();
			}
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class PosSizeParentContext extends ParserRuleContext {
		public TerminalNode LEFTPAREN() { return getToken(ShaperParser.LEFTPAREN, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode COMMA() { return getToken(ShaperParser.COMMA, 0); }
		public TerminalNode RIGHTPAREN() { return getToken(ShaperParser.RIGHTPAREN, 0); }
		public PosSizeParentContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_posSizeParent; }
	}

	public final PosSizeParentContext posSizeParent() throws RecognitionException {
		PosSizeParentContext _localctx = new PosSizeParentContext(_ctx, getState());
		enterRule(_localctx, 86, RULE_posSizeParent);
		try {
			enterOuterAlt(_localctx, 1);
			{
			setState(432);
			match(LEFTPAREN);
			setState(433);
			expression();
			setState(434);
			match(COMMA);
			setState(435);
			expression();
			setState(436);
			match(RIGHTPAREN);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class SelectionStatementContext extends ParserRuleContext {
		public TerminalNode IF() { return getToken(ShaperParser.IF, 0); }
		public List<TerminalNode> LEFTPAREN() { return getTokens(ShaperParser.LEFTPAREN); }
		public TerminalNode LEFTPAREN(int i) {
			return getToken(ShaperParser.LEFTPAREN, i);
		}
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public List<TerminalNode> RIGHTPAREN() { return getTokens(ShaperParser.RIGHTPAREN); }
		public TerminalNode RIGHTPAREN(int i) {
			return getToken(ShaperParser.RIGHTPAREN, i);
		}
		public List<CompoundStatementContext> compoundStatement() {
			return getRuleContexts(CompoundStatementContext.class);
		}
		public CompoundStatementContext compoundStatement(int i) {
			return getRuleContext(CompoundStatementContext.class,i);
		}
		public List<TerminalNode> ELIF() { return getTokens(ShaperParser.ELIF); }
		public TerminalNode ELIF(int i) {
			return getToken(ShaperParser.ELIF, i);
		}
		public TerminalNode ELSE() { return getToken(ShaperParser.ELSE, 0); }
		public TerminalNode SWITCH() { return getToken(ShaperParser.SWITCH, 0); }
		public TerminalNode LEFTBRACKET() { return getToken(ShaperParser.LEFTBRACKET, 0); }
		public TerminalNode RIGHTBRACKET() { return getToken(ShaperParser.RIGHTBRACKET, 0); }
		public List<LabeledStatementContext> labeledStatement() {
			return getRuleContexts(LabeledStatementContext.class);
		}
		public LabeledStatementContext labeledStatement(int i) {
			return getRuleContext(LabeledStatementContext.class,i);
		}
		public SelectionStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_selectionStatement; }
	}

	public final SelectionStatementContext selectionStatement() throws RecognitionException {
		SelectionStatementContext _localctx = new SelectionStatementContext(_ctx, getState());
		enterRule(_localctx, 88, RULE_selectionStatement);
		int _la;
		try {
			setState(470);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case IF:
				enterOuterAlt(_localctx, 1);
				{
				setState(438);
				match(IF);
				setState(439);
				match(LEFTPAREN);
				setState(440);
				expression();
				setState(441);
				match(RIGHTPAREN);
				setState(442);
				compoundStatement();
				setState(450);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==ELIF) {
					{
					{
					setState(443);
					match(ELIF);
					setState(444);
					match(LEFTPAREN);
					setState(445);
					expression();
					setState(446);
					match(RIGHTPAREN);
					}
					}
					setState(452);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(455);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (_la==ELSE) {
					{
					setState(453);
					match(ELSE);
					setState(454);
					compoundStatement();
					}
				}

				}
				break;
			case SWITCH:
				enterOuterAlt(_localctx, 2);
				{
				setState(457);
				match(SWITCH);
				setState(458);
				match(LEFTPAREN);
				setState(459);
				expression();
				setState(460);
				match(RIGHTPAREN);
				setState(461);
				match(LEFTBRACKET);
				setState(465);
				_errHandler.sync(this);
				_la = _input.LA(1);
				while (_la==CASE || _la==DEFAULT) {
					{
					{
					setState(462);
					labeledStatement();
					}
					}
					setState(467);
					_errHandler.sync(this);
					_la = _input.LA(1);
				}
				setState(468);
				match(RIGHTBRACKET);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class LabeledStatementContext extends ParserRuleContext {
		public TerminalNode CASE() { return getToken(ShaperParser.CASE, 0); }
		public LogicalORExpressionContext logicalORExpression() {
			return getRuleContext(LogicalORExpressionContext.class,0);
		}
		public TerminalNode COLON() { return getToken(ShaperParser.COLON, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public TerminalNode DEFAULT() { return getToken(ShaperParser.DEFAULT, 0); }
		public LabeledStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_labeledStatement; }
	}

	public final LabeledStatementContext labeledStatement() throws RecognitionException {
		LabeledStatementContext _localctx = new LabeledStatementContext(_ctx, getState());
		enterRule(_localctx, 90, RULE_labeledStatement);
		try {
			setState(480);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CASE:
				enterOuterAlt(_localctx, 1);
				{
				setState(472);
				match(CASE);
				setState(473);
				logicalORExpression(0);
				setState(474);
				match(COLON);
				setState(475);
				expression();
				}
				break;
			case DEFAULT:
				enterOuterAlt(_localctx, 2);
				{
				setState(477);
				match(DEFAULT);
				setState(478);
				match(COLON);
				setState(479);
				expression();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class IterationStatementContext extends ParserRuleContext {
		public TerminalNode WHILE() { return getToken(ShaperParser.WHILE, 0); }
		public TerminalNode LEFTPAREN() { return getToken(ShaperParser.LEFTPAREN, 0); }
		public List<ExpressionContext> expression() {
			return getRuleContexts(ExpressionContext.class);
		}
		public ExpressionContext expression(int i) {
			return getRuleContext(ExpressionContext.class,i);
		}
		public TerminalNode RIGHTPAREN() { return getToken(ShaperParser.RIGHTPAREN, 0); }
		public CompoundStatementContext compoundStatement() {
			return getRuleContext(CompoundStatementContext.class,0);
		}
		public TerminalNode FOR() { return getToken(ShaperParser.FOR, 0); }
		public List<TerminalNode> SEMICOLON() { return getTokens(ShaperParser.SEMICOLON); }
		public TerminalNode SEMICOLON(int i) {
			return getToken(ShaperParser.SEMICOLON, i);
		}
		public List<DeclarationContext> declaration() {
			return getRuleContexts(DeclarationContext.class);
		}
		public DeclarationContext declaration(int i) {
			return getRuleContext(DeclarationContext.class,i);
		}
		public IterationStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_iterationStatement; }
	}

	public final IterationStatementContext iterationStatement() throws RecognitionException {
		IterationStatementContext _localctx = new IterationStatementContext(_ctx, getState());
		enterRule(_localctx, 92, RULE_iterationStatement);
		try {
			setState(506);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case WHILE:
				enterOuterAlt(_localctx, 1);
				{
				setState(482);
				match(WHILE);
				setState(483);
				match(LEFTPAREN);
				setState(484);
				expression();
				setState(485);
				match(RIGHTPAREN);
				setState(486);
				compoundStatement();
				}
				break;
			case FOR:
				enterOuterAlt(_localctx, 2);
				{
				setState(488);
				match(FOR);
				setState(489);
				match(LEFTPAREN);
				setState(492);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case LEFTPAREN:
				case MINUS:
				case PLUSPLUS:
				case MINUSMINUS:
				case EXCLAMATION:
				case Constant:
				case Identifier:
					{
					setState(490);
					expression();
					}
					break;
				case BOOL:
				case INT:
				case LONG:
				case CHAR:
				case FLOAT:
				case DOUBLE:
				case COLOR:
				case STRUCT:
				case ARRAY:
				case LIST:
				case CONST:
					{
					setState(491);
					declaration();
					}
					break;
				case SEMICOLON:
					break;
				default:
					break;
				}
				setState(494);
				match(SEMICOLON);
				setState(497);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case LEFTPAREN:
				case MINUS:
				case PLUSPLUS:
				case MINUSMINUS:
				case EXCLAMATION:
				case Constant:
				case Identifier:
					{
					setState(495);
					expression();
					}
					break;
				case BOOL:
				case INT:
				case LONG:
				case CHAR:
				case FLOAT:
				case DOUBLE:
				case COLOR:
				case STRUCT:
				case ARRAY:
				case LIST:
				case CONST:
					{
					setState(496);
					declaration();
					}
					break;
				case SEMICOLON:
					break;
				default:
					break;
				}
				setState(499);
				match(SEMICOLON);
				setState(502);
				_errHandler.sync(this);
				switch (_input.LA(1)) {
				case LEFTPAREN:
				case MINUS:
				case PLUSPLUS:
				case MINUSMINUS:
				case EXCLAMATION:
				case Constant:
				case Identifier:
					{
					setState(500);
					expression();
					}
					break;
				case BOOL:
				case INT:
				case LONG:
				case CHAR:
				case FLOAT:
				case DOUBLE:
				case COLOR:
				case STRUCT:
				case ARRAY:
				case LIST:
				case CONST:
					{
					setState(501);
					declaration();
					}
					break;
				case RIGHTPAREN:
					break;
				default:
					break;
				}
				setState(504);
				match(RIGHTPAREN);
				setState(505);
				compoundStatement();
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public static class JumpStatementContext extends ParserRuleContext {
		public TerminalNode CONTINUE() { return getToken(ShaperParser.CONTINUE, 0); }
		public TerminalNode SEMICOLON() { return getToken(ShaperParser.SEMICOLON, 0); }
		public TerminalNode BREAK() { return getToken(ShaperParser.BREAK, 0); }
		public TerminalNode RETURN() { return getToken(ShaperParser.RETURN, 0); }
		public ExpressionContext expression() {
			return getRuleContext(ExpressionContext.class,0);
		}
		public JumpStatementContext(ParserRuleContext parent, int invokingState) {
			super(parent, invokingState);
		}
		@Override public int getRuleIndex() { return RULE_jumpStatement; }
	}

	public final JumpStatementContext jumpStatement() throws RecognitionException {
		JumpStatementContext _localctx = new JumpStatementContext(_ctx, getState());
		enterRule(_localctx, 94, RULE_jumpStatement);
		int _la;
		try {
			setState(517);
			_errHandler.sync(this);
			switch (_input.LA(1)) {
			case CONTINUE:
				enterOuterAlt(_localctx, 1);
				{
				setState(508);
				match(CONTINUE);
				setState(509);
				match(SEMICOLON);
				}
				break;
			case BREAK:
				enterOuterAlt(_localctx, 2);
				{
				setState(510);
				match(BREAK);
				setState(511);
				match(SEMICOLON);
				}
				break;
			case RETURN:
				enterOuterAlt(_localctx, 3);
				{
				setState(512);
				match(RETURN);
				setState(514);
				_errHandler.sync(this);
				_la = _input.LA(1);
				if (((((_la - 14)) & ~0x3f) == 0 && ((1L << (_la - 14)) & ((1L << (LEFTPAREN - 14)) | (1L << (MINUS - 14)) | (1L << (PLUSPLUS - 14)) | (1L << (MINUSMINUS - 14)) | (1L << (EXCLAMATION - 14)) | (1L << (Constant - 14)) | (1L << (Identifier - 14)))) != 0)) {
					{
					setState(513);
					expression();
					}
				}

				setState(516);
				match(SEMICOLON);
				}
				break;
			default:
				throw new NoViableAltException(this);
			}
		}
		catch (RecognitionException re) {
			_localctx.exception = re;
			_errHandler.reportError(this, re);
			_errHandler.recover(this, re);
		}
		finally {
			exitRule();
		}
		return _localctx;
	}

	public boolean sempred(RuleContext _localctx, int ruleIndex, int predIndex) {
		switch (ruleIndex) {
		case 6:
			return parameterList_sempred((ParameterListContext)_localctx, predIndex);
		case 14:
			return structDeclarationList_sempred((StructDeclarationListContext)_localctx, predIndex);
		case 17:
			return logicalORExpression_sempred((LogicalORExpressionContext)_localctx, predIndex);
		case 18:
			return logicalANDExpression_sempred((LogicalANDExpressionContext)_localctx, predIndex);
		case 19:
			return equalityExpression_sempred((EqualityExpressionContext)_localctx, predIndex);
		case 20:
			return relationalExpression_sempred((RelationalExpressionContext)_localctx, predIndex);
		case 21:
			return additiveExpression_sempred((AdditiveExpressionContext)_localctx, predIndex);
		case 22:
			return multiplicativeExpression_sempred((MultiplicativeExpressionContext)_localctx, predIndex);
		case 24:
			return postfixExpression_sempred((PostfixExpressionContext)_localctx, predIndex);
		case 26:
			return functionParameterList_sempred((FunctionParameterListContext)_localctx, predIndex);
		}
		return true;
	}
	private boolean parameterList_sempred(ParameterListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 0:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean structDeclarationList_sempred(StructDeclarationListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 1:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean logicalORExpression_sempred(LogicalORExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 2:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean logicalANDExpression_sempred(LogicalANDExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 3:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean equalityExpression_sempred(EqualityExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 4:
			return precpred(_ctx, 2);
		case 5:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean relationalExpression_sempred(RelationalExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 6:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean additiveExpression_sempred(AdditiveExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 7:
			return precpred(_ctx, 2);
		case 8:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean multiplicativeExpression_sempred(MultiplicativeExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 9:
			return precpred(_ctx, 3);
		case 10:
			return precpred(_ctx, 2);
		case 11:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean postfixExpression_sempred(PostfixExpressionContext _localctx, int predIndex) {
		switch (predIndex) {
		case 12:
			return precpred(_ctx, 4);
		case 13:
			return precpred(_ctx, 3);
		case 14:
			return precpred(_ctx, 2);
		case 15:
			return precpred(_ctx, 1);
		}
		return true;
	}
	private boolean functionParameterList_sempred(FunctionParameterListContext _localctx, int predIndex) {
		switch (predIndex) {
		case 16:
			return precpred(_ctx, 1);
		}
		return true;
	}

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\3H\u020a\4\2\t\2\4"+
		"\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13\t"+
		"\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\3\2\7\2d\n\2\f\2\16\2g\13\2"+
		"\3\3\3\3\3\3\3\3\5\3m\n\3\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3\5\5\5w\n\5\3\6"+
		"\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\6\5\6\u0087\n\6\3\7"+
		"\3\7\3\7\3\7\3\7\3\7\5\7\u008f\n\7\3\b\3\b\3\b\3\b\3\b\3\b\7\b\u0097\n"+
		"\b\f\b\16\b\u009a\13\b\3\t\3\t\3\t\3\n\3\n\3\n\3\n\3\n\7\n\u00a4\n\n\f"+
		"\n\16\n\u00a7\13\n\3\n\3\n\3\13\3\13\3\13\3\13\5\13\u00af\n\13\3\f\3\f"+
		"\3\f\5\f\u00b4\n\f\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\3\r\5\r"+
		"\u00c2\n\r\3\r\3\r\3\r\3\r\5\r\u00c8\n\r\3\16\3\16\3\16\3\16\5\16\u00ce"+
		"\n\16\3\17\3\17\3\17\3\17\3\17\3\17\3\20\3\20\3\20\3\20\3\20\3\20\3\20"+
		"\3\20\7\20\u00de\n\20\f\20\16\20\u00e1\13\20\3\21\3\21\3\22\3\22\3\22"+
		"\3\22\3\22\5\22\u00ea\n\22\3\23\3\23\3\23\3\23\3\23\3\23\7\23\u00f2\n"+
		"\23\f\23\16\23\u00f5\13\23\3\24\3\24\3\24\3\24\3\24\3\24\7\24\u00fd\n"+
		"\24\f\24\16\24\u0100\13\24\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25\3\25"+
		"\7\25\u010b\n\25\f\25\16\25\u010e\13\25\3\26\3\26\3\26\3\26\3\26\3\26"+
		"\3\26\7\26\u0117\n\26\f\26\16\26\u011a\13\26\3\27\3\27\3\27\3\27\3\27"+
		"\3\27\3\27\3\27\3\27\7\27\u0125\n\27\f\27\16\27\u0128\13\27\3\30\3\30"+
		"\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\3\30\7\30\u0136\n\30\f\30"+
		"\16\30\u0139\13\30\3\31\3\31\3\31\3\31\5\31\u013f\n\31\3\32\3\32\3\32"+
		"\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\3\32\5\32\u014e\n\32\3\32"+
		"\7\32\u0151\n\32\f\32\16\32\u0154\13\32\3\33\3\33\3\33\3\33\3\33\3\33"+
		"\5\33\u015c\n\33\3\34\3\34\3\34\3\34\3\34\3\34\7\34\u0164\n\34\f\34\16"+
		"\34\u0167\13\34\3\35\3\35\3\36\3\36\3\37\3\37\3 \3 \3 \3 \3 \3 \3 \3 "+
		"\3 \3 \3 \5 \u017a\n \3!\3!\3!\3\"\3\"\3\"\3\"\3\"\3\"\3\"\3\"\5\"\u0187"+
		"\n\"\3#\3#\3#\5#\u018c\n#\3$\3$\3$\3$\5$\u0192\n$\3%\3%\3%\5%\u0197\n"+
		"%\3&\3&\3&\5&\u019c\n&\3\'\3\'\3\'\3(\3(\3(\3(\5(\u01a5\n(\3)\3)\3)\3"+
		"*\3*\3*\3+\3+\3+\3,\3,\3,\3-\3-\3-\3-\3-\3-\3.\3.\3.\3.\3.\3.\3.\3.\3"+
		".\3.\7.\u01c3\n.\f.\16.\u01c6\13.\3.\3.\5.\u01ca\n.\3.\3.\3.\3.\3.\3."+
		"\7.\u01d2\n.\f.\16.\u01d5\13.\3.\3.\5.\u01d9\n.\3/\3/\3/\3/\3/\3/\3/\3"+
		"/\5/\u01e3\n/\3\60\3\60\3\60\3\60\3\60\3\60\3\60\3\60\3\60\3\60\5\60\u01ef"+
		"\n\60\3\60\3\60\3\60\5\60\u01f4\n\60\3\60\3\60\3\60\5\60\u01f9\n\60\3"+
		"\60\3\60\5\60\u01fd\n\60\3\61\3\61\3\61\3\61\3\61\3\61\5\61\u0205\n\61"+
		"\3\61\5\61\u0208\n\61\3\61\2\f\16\36$&(*,.\62\66\62\2\4\6\b\n\f\16\20"+
		"\22\24\26\30\32\34\36 \"$&(*,.\60\62\64\668:<>@BDFHJLNPRTVXZ\\^`\2\6\3"+
		"\2EF\3\2/\64\3\2\658\5\2((-.99\2\u0229\2e\3\2\2\2\4l\3\2\2\2\6n\3\2\2"+
		"\2\bv\3\2\2\2\n\u0086\3\2\2\2\f\u008e\3\2\2\2\16\u0090\3\2\2\2\20\u009b"+
		"\3\2\2\2\22\u009e\3\2\2\2\24\u00ae\3\2\2\2\26\u00b3\3\2\2\2\30\u00c7\3"+
		"\2\2\2\32\u00c9\3\2\2\2\34\u00cf\3\2\2\2\36\u00d5\3\2\2\2 \u00e2\3\2\2"+
		"\2\"\u00e9\3\2\2\2$\u00eb\3\2\2\2&\u00f6\3\2\2\2(\u0101\3\2\2\2*\u010f"+
		"\3\2\2\2,\u011b\3\2\2\2.\u0129\3\2\2\2\60\u013e\3\2\2\2\62\u0140\3\2\2"+
		"\2\64\u015b\3\2\2\2\66\u015d\3\2\2\28\u0168\3\2\2\2:\u016a\3\2\2\2<\u016c"+
		"\3\2\2\2>\u0179\3\2\2\2@\u017b\3\2\2\2B\u0186\3\2\2\2D\u0188\3\2\2\2F"+
		"\u018d\3\2\2\2H\u0193\3\2\2\2J\u0198\3\2\2\2L\u019d\3\2\2\2N\u01a4\3\2"+
		"\2\2P\u01a6\3\2\2\2R\u01a9\3\2\2\2T\u01ac\3\2\2\2V\u01af\3\2\2\2X\u01b2"+
		"\3\2\2\2Z\u01d8\3\2\2\2\\\u01e2\3\2\2\2^\u01fc\3\2\2\2`\u0207\3\2\2\2"+
		"bd\5\4\3\2cb\3\2\2\2dg\3\2\2\2ec\3\2\2\2ef\3\2\2\2f\3\3\2\2\2ge\3\2\2"+
		"\2hm\5\6\4\2ij\5\24\13\2jk\7\25\2\2km\3\2\2\2lh\3\2\2\2li\3\2\2\2m\5\3"+
		"\2\2\2no\5\b\5\2op\7F\2\2pq\5\f\7\2qr\5\22\n\2r\7\3\2\2\2sw\5\n\6\2tu"+
		"\7\"\2\2uw\5\n\6\2vs\3\2\2\2vt\3\2\2\2w\t\3\2\2\2x\u0087\7\27\2\2y\u0087"+
		"\7\30\2\2z\u0087\7\31\2\2{\u0087\7\32\2\2|\u0087\7\33\2\2}\u0087\7\34"+
		"\2\2~\u0087\7\35\2\2\177\u0087\7\36\2\2\u0080\u0081\7\37\2\2\u0081\u0087"+
		"\7F\2\2\u0082\u0083\7 \2\2\u0083\u0087\5\b\5\2\u0084\u0085\7!\2\2\u0085"+
		"\u0087\5\b\5\2\u0086x\3\2\2\2\u0086y\3\2\2\2\u0086z\3\2\2\2\u0086{\3\2"+
		"\2\2\u0086|\3\2\2\2\u0086}\3\2\2\2\u0086~\3\2\2\2\u0086\177\3\2\2\2\u0086"+
		"\u0080\3\2\2\2\u0086\u0082\3\2\2\2\u0086\u0084\3\2\2\2\u0087\13\3\2\2"+
		"\2\u0088\u0089\7\20\2\2\u0089\u008f\7\21\2\2\u008a\u008b\7\20\2\2\u008b"+
		"\u008c\5\16\b\2\u008c\u008d\7\21\2\2\u008d\u008f\3\2\2\2\u008e\u0088\3"+
		"\2\2\2\u008e\u008a\3\2\2\2\u008f\r\3\2\2\2\u0090\u0091\b\b\1\2\u0091\u0092"+
		"\5\20\t\2\u0092\u0098\3\2\2\2\u0093\u0094\f\3\2\2\u0094\u0095\7\24\2\2"+
		"\u0095\u0097\5\20\t\2\u0096\u0093\3\2\2\2\u0097\u009a\3\2\2\2\u0098\u0096"+
		"\3\2\2\2\u0098\u0099\3\2\2\2\u0099\17\3\2\2\2\u009a\u0098\3\2\2\2\u009b"+
		"\u009c\5\b\5\2\u009c\u009d\7F\2\2\u009d\21\3\2\2\2\u009e\u00a5\7\22\2"+
		"\2\u009f\u00a0\5\24\13\2\u00a0\u00a1\7\25\2\2\u00a1\u00a4\3\2\2\2\u00a2"+
		"\u00a4\5> \2\u00a3\u009f\3\2\2\2\u00a3\u00a2\3\2\2\2\u00a4\u00a7\3\2\2"+
		"\2\u00a5\u00a3\3\2\2\2\u00a5\u00a6\3\2\2\2\u00a6\u00a8\3\2\2\2\u00a7\u00a5"+
		"\3\2\2\2\u00a8\u00a9\7\23\2\2\u00a9\23\3\2\2\2\u00aa\u00ab\5\26\f\2\u00ab"+
		"\u00ac\5\32\16\2\u00ac\u00af\3\2\2\2\u00ad\u00af\5\34\17\2\u00ae\u00aa"+
		"\3\2\2\2\u00ae\u00ad\3\2\2\2\u00af\25\3\2\2\2\u00b0\u00b4\5\30\r\2\u00b1"+
		"\u00b2\7\"\2\2\u00b2\u00b4\5\30\r\2\u00b3\u00b0\3\2\2\2\u00b3\u00b1\3"+
		"\2\2\2\u00b4\27\3\2\2\2\u00b5\u00c8\7\30\2\2\u00b6\u00c8\7\31\2\2\u00b7"+
		"\u00c8\7\32\2\2\u00b8\u00c8\7\33\2\2\u00b9\u00c8\7\34\2\2\u00ba\u00c8"+
		"\7\35\2\2\u00bb\u00c8\7\36\2\2\u00bc\u00bd\7\37\2\2\u00bd\u00c8\7F\2\2"+
		"\u00be\u00bf\7 \2\2\u00bf\u00c1\7\20\2\2\u00c0\u00c2\t\2\2\2\u00c1\u00c0"+
		"\3\2\2\2\u00c1\u00c2\3\2\2\2\u00c2\u00c3\3\2\2\2\u00c3\u00c4\7\21\2\2"+
		"\u00c4\u00c8\5\26\f\2\u00c5\u00c6\7!\2\2\u00c6\u00c8\5\26\f\2\u00c7\u00b5"+
		"\3\2\2\2\u00c7\u00b6\3\2\2\2\u00c7\u00b7\3\2\2\2\u00c7\u00b8\3\2\2\2\u00c7"+
		"\u00b9\3\2\2\2\u00c7\u00ba\3\2\2\2\u00c7\u00bb\3\2\2\2\u00c7\u00bc\3\2"+
		"\2\2\u00c7\u00be\3\2\2\2\u00c7\u00c5\3\2\2\2\u00c8\31\3\2\2\2\u00c9\u00cd"+
		"\7F\2\2\u00ca\u00cb\58\35\2\u00cb\u00cc\5\"\22\2\u00cc\u00ce\3\2\2\2\u00cd"+
		"\u00ca\3\2\2\2\u00cd\u00ce\3\2\2\2\u00ce\33\3\2\2\2\u00cf\u00d0\7\37\2"+
		"\2\u00d0\u00d1\7F\2\2\u00d1\u00d2\7\22\2\2\u00d2\u00d3\5\36\20\2\u00d3"+
		"\u00d4\7\23\2\2\u00d4\35\3\2\2\2\u00d5\u00d6\b\20\1\2\u00d6\u00d7\5\24"+
		"\13\2\u00d7\u00d8\7\25\2\2\u00d8\u00df\3\2\2\2\u00d9\u00da\f\3\2\2\u00da"+
		"\u00db\5\24\13\2\u00db\u00dc\7\25\2\2\u00dc\u00de\3\2\2\2\u00dd\u00d9"+
		"\3\2\2\2\u00de\u00e1\3\2\2\2\u00df\u00dd\3\2\2\2\u00df\u00e0\3\2\2\2\u00e0"+
		"\37\3\2\2\2\u00e1\u00df\3\2\2\2\u00e2\u00e3\5\"\22\2\u00e3!\3\2\2\2\u00e4"+
		"\u00ea\5$\23\2\u00e5\u00e6\5\60\31\2\u00e6\u00e7\58\35\2\u00e7\u00e8\5"+
		"\"\22\2\u00e8\u00ea\3\2\2\2\u00e9\u00e4\3\2\2\2\u00e9\u00e5\3\2\2\2\u00ea"+
		"#\3\2\2\2\u00eb\u00ec\b\23\1\2\u00ec\u00ed\5&\24\2\u00ed\u00f3\3\2\2\2"+
		"\u00ee\u00ef\f\3\2\2\u00ef\u00f0\7#\2\2\u00f0\u00f2\5&\24\2\u00f1\u00ee"+
		"\3\2\2\2\u00f2\u00f5\3\2\2\2\u00f3\u00f1\3\2\2\2\u00f3\u00f4\3\2\2\2\u00f4"+
		"%\3\2\2\2\u00f5\u00f3\3\2\2\2\u00f6\u00f7\b\24\1\2\u00f7\u00f8\5(\25\2"+
		"\u00f8\u00fe\3\2\2\2\u00f9\u00fa\f\3\2\2\u00fa\u00fb\7$\2\2\u00fb\u00fd"+
		"\5(\25\2\u00fc\u00f9\3\2\2\2\u00fd\u0100\3\2\2\2\u00fe\u00fc\3\2\2\2\u00fe"+
		"\u00ff\3\2\2\2\u00ff\'\3\2\2\2\u0100\u00fe\3\2\2\2\u0101\u0102\b\25\1"+
		"\2\u0102\u0103\5*\26\2\u0103\u010c\3\2\2\2\u0104\u0105\f\4\2\2\u0105\u0106"+
		"\7%\2\2\u0106\u010b\5*\26\2\u0107\u0108\f\3\2\2\u0108\u0109\7&\2\2\u0109"+
		"\u010b\5*\26\2\u010a\u0104\3\2\2\2\u010a\u0107\3\2\2\2\u010b\u010e\3\2"+
		"\2\2\u010c\u010a\3\2\2\2\u010c\u010d\3\2\2\2\u010d)\3\2\2\2\u010e\u010c"+
		"\3\2\2\2\u010f\u0110\b\26\1\2\u0110\u0111\5,\27\2\u0111\u0118\3\2\2\2"+
		"\u0112\u0113\f\3\2\2\u0113\u0114\5:\36\2\u0114\u0115\5,\27\2\u0115\u0117"+
		"\3\2\2\2\u0116\u0112\3\2\2\2\u0117\u011a\3\2\2\2\u0118\u0116\3\2\2\2\u0118"+
		"\u0119\3\2\2\2\u0119+\3\2\2\2\u011a\u0118\3\2\2\2\u011b\u011c\b\27\1\2"+
		"\u011c\u011d\5.\30\2\u011d\u0126\3\2\2\2\u011e\u011f\f\4\2\2\u011f\u0120"+
		"\7\'\2\2\u0120\u0125\5.\30\2\u0121\u0122\f\3\2\2\u0122\u0123\7(\2\2\u0123"+
		"\u0125\5.\30\2\u0124\u011e\3\2\2\2\u0124\u0121\3\2\2\2\u0125\u0128\3\2"+
		"\2\2\u0126\u0124\3\2\2\2\u0126\u0127\3\2\2\2\u0127-\3\2\2\2\u0128\u0126"+
		"\3\2\2\2\u0129\u012a\b\30\1\2\u012a\u012b\5\60\31\2\u012b\u0137\3\2\2"+
		"\2\u012c\u012d\f\5\2\2\u012d\u012e\7)\2\2\u012e\u0136\5\60\31\2\u012f"+
		"\u0130\f\4\2\2\u0130\u0131\7*\2\2\u0131\u0136\5\60\31\2\u0132\u0133\f"+
		"\3\2\2\u0133\u0134\7+\2\2\u0134\u0136\5\60\31\2\u0135\u012c\3\2\2\2\u0135"+
		"\u012f\3\2\2\2\u0135\u0132\3\2\2\2\u0136\u0139\3\2\2\2\u0137\u0135\3\2"+
		"\2\2\u0137\u0138\3\2\2\2\u0138/\3\2\2\2\u0139\u0137\3\2\2\2\u013a\u013f"+
		"\5\62\32\2\u013b\u013c\5<\37\2\u013c\u013d\5\60\31\2\u013d\u013f\3\2\2"+
		"\2\u013e\u013a\3\2\2\2\u013e\u013b\3\2\2\2\u013f\61\3\2\2\2\u0140\u0141"+
		"\b\32\1\2\u0141\u0142\5\64\33\2\u0142\u0152\3\2\2\2\u0143\u0144\f\6\2"+
		"\2\u0144\u0145\7,\2\2\u0145\u0151\7F\2\2\u0146\u0147\f\5\2\2\u0147\u0151"+
		"\7-\2\2\u0148\u0149\f\4\2\2\u0149\u0151\7.\2\2\u014a\u014b\f\3\2\2\u014b"+
		"\u014d\7\20\2\2\u014c\u014e\5\66\34\2\u014d\u014c\3\2\2\2\u014d\u014e"+
		"\3\2\2\2\u014e\u014f\3\2\2\2\u014f\u0151\7\21\2\2\u0150\u0143\3\2\2\2"+
		"\u0150\u0146\3\2\2\2\u0150\u0148\3\2\2\2\u0150\u014a\3\2\2\2\u0151\u0154"+
		"\3\2\2\2\u0152\u0150\3\2\2\2\u0152\u0153\3\2\2\2\u0153\63\3\2\2\2\u0154"+
		"\u0152\3\2\2\2\u0155\u015c\7F\2\2\u0156\u015c\7E\2\2\u0157\u0158\7\20"+
		"\2\2\u0158\u0159\5 \21\2\u0159\u015a\7\21\2\2\u015a\u015c\3\2\2\2\u015b"+
		"\u0155\3\2\2\2\u015b\u0156\3\2\2\2\u015b\u0157\3\2\2\2\u015c\65\3\2\2"+
		"\2\u015d\u015e\b\34\1\2\u015e\u015f\5 \21\2\u015f\u0165\3\2\2\2\u0160"+
		"\u0161\f\3\2\2\u0161\u0162\7\24\2\2\u0162\u0164\5 \21\2\u0163\u0160\3"+
		"\2\2\2\u0164\u0167\3\2\2\2\u0165\u0163\3\2\2\2\u0165\u0166\3\2\2\2\u0166"+
		"\67\3\2\2\2\u0167\u0165\3\2\2\2\u0168\u0169\t\3\2\2\u01699\3\2\2\2\u016a"+
		"\u016b\t\4\2\2\u016b;\3\2\2\2\u016c\u016d\t\5\2\2\u016d=\3\2\2\2\u016e"+
		"\u017a\5\22\n\2\u016f\u0170\5 \21\2\u0170\u0171\7\25\2\2\u0171\u017a\3"+
		"\2\2\2\u0172\u0173\5@!\2\u0173\u0174\7\25\2\2\u0174\u017a\3\2\2\2\u0175"+
		"\u017a\5Z.\2\u0176\u017a\5\\/\2\u0177\u017a\5^\60\2\u0178\u017a\5`\61"+
		"\2\u0179\u016e\3\2\2\2\u0179\u016f\3\2\2\2\u0179\u0172\3\2\2\2\u0179\u0175"+
		"\3\2\2\2\u0179\u0176\3\2\2\2\u0179\u0177\3\2\2\2\u0179\u0178\3\2\2\2\u017a"+
		"?\3\2\2\2\u017b\u017c\7\3\2\2\u017c\u017d\5B\"\2\u017dA\3\2\2\2\u017e"+
		"\u017f\7\4\2\2\u017f\u0187\5D#\2\u0180\u0181\7\5\2\2\u0181\u0187\5F$\2"+
		"\u0182\u0183\7\6\2\2\u0183\u0187\5H%\2\u0184\u0185\7\b\2\2\u0185\u0187"+
		"\5J&\2\u0186\u017e\3\2\2\2\u0186\u0180\3\2\2\2\u0186\u0182\3\2\2\2\u0186"+
		"\u0184\3\2\2\2\u0187C\3\2\2\2\u0188\u0189\5P)\2\u0189\u018b\5T+\2\u018a"+
		"\u018c\5V,\2\u018b\u018a\3\2\2\2\u018b\u018c\3\2\2\2\u018cE\3\2\2\2\u018d"+
		"\u018e\5P)\2\u018e\u018f\5R*\2\u018f\u0191\5T+\2\u0190\u0192\5V,\2\u0191"+
		"\u0190\3\2\2\2\u0191\u0192\3\2\2\2\u0192G\3\2\2\2\u0193\u0194\5L\'\2\u0194"+
		"\u0196\5N(\2\u0195\u0197\5V,\2\u0196\u0195\3\2\2\2\u0196\u0197\3\2\2\2"+
		"\u0197I\3\2\2\2\u0198\u0199\5L\'\2\u0199\u019b\5N(\2\u019a\u019c\5V,\2"+
		"\u019b\u019a\3\2\2\2\u019b\u019c\3\2\2\2\u019cK\3\2\2\2\u019d\u019e\7"+
		"\n\2\2\u019e\u019f\5X-\2\u019fM\3\2\2\2\u01a0\u01a1\7\13\2\2\u01a1\u01a5"+
		"\5X-\2\u01a2\u01a3\7\13\2\2\u01a3\u01a5\5 \21\2\u01a4\u01a0\3\2\2\2\u01a4"+
		"\u01a2\3\2\2\2\u01a5O\3\2\2\2\u01a6\u01a7\7\f\2\2\u01a7\u01a8\5X-\2\u01a8"+
		"Q\3\2\2\2\u01a9\u01aa\7\r\2\2\u01aa\u01ab\5X-\2\u01abS\3\2\2\2\u01ac\u01ad"+
		"\7\16\2\2\u01ad\u01ae\5X-\2\u01aeU\3\2\2\2\u01af\u01b0\7\17\2\2\u01b0"+
		"\u01b1\t\2\2\2\u01b1W\3\2\2\2\u01b2\u01b3\7\20\2\2\u01b3\u01b4\5 \21\2"+
		"\u01b4\u01b5\7\24\2\2\u01b5\u01b6\5 \21\2\u01b6\u01b7\7\21\2\2\u01b7Y"+
		"\3\2\2\2\u01b8\u01b9\7:\2\2\u01b9\u01ba\7\20\2\2\u01ba\u01bb\5 \21\2\u01bb"+
		"\u01bc\7\21\2\2\u01bc\u01c4\5\22\n\2\u01bd\u01be\7;\2\2\u01be\u01bf\7"+
		"\20\2\2\u01bf\u01c0\5 \21\2\u01c0\u01c1\7\21\2\2\u01c1\u01c3\3\2\2\2\u01c2"+
		"\u01bd\3\2\2\2\u01c3\u01c6\3\2\2\2\u01c4\u01c2\3\2\2\2\u01c4\u01c5\3\2"+
		"\2\2\u01c5\u01c9\3\2\2\2\u01c6\u01c4\3\2\2\2\u01c7\u01c8\7<\2\2\u01c8"+
		"\u01ca\5\22\n\2\u01c9\u01c7\3\2\2\2\u01c9\u01ca\3\2\2\2\u01ca\u01d9\3"+
		"\2\2\2\u01cb\u01cc\7=\2\2\u01cc\u01cd\7\20\2\2\u01cd\u01ce\5 \21\2\u01ce"+
		"\u01cf\7\21\2\2\u01cf\u01d3\7\22\2\2\u01d0\u01d2\5\\/\2\u01d1\u01d0\3"+
		"\2\2\2\u01d2\u01d5\3\2\2\2\u01d3\u01d1\3\2\2\2\u01d3\u01d4\3\2\2\2\u01d4"+
		"\u01d6\3\2\2\2\u01d5\u01d3\3\2\2\2\u01d6\u01d7\7\23\2\2\u01d7\u01d9\3"+
		"\2\2\2\u01d8\u01b8\3\2\2\2\u01d8\u01cb\3\2\2\2\u01d9[\3\2\2\2\u01da\u01db"+
		"\7>\2\2\u01db\u01dc\5$\23\2\u01dc\u01dd\7\26\2\2\u01dd\u01de\5 \21\2\u01de"+
		"\u01e3\3\2\2\2\u01df\u01e0\7?\2\2\u01e0\u01e1\7\26\2\2\u01e1\u01e3\5 "+
		"\21\2\u01e2\u01da\3\2\2\2\u01e2\u01df\3\2\2\2\u01e3]\3\2\2\2\u01e4\u01e5"+
		"\7@\2\2\u01e5\u01e6\7\20\2\2\u01e6\u01e7\5 \21\2\u01e7\u01e8\7\21\2\2"+
		"\u01e8\u01e9\5\22\n\2\u01e9\u01fd\3\2\2\2\u01ea\u01eb\7A\2\2\u01eb\u01ee"+
		"\7\20\2\2\u01ec\u01ef\5 \21\2\u01ed\u01ef\5\24\13\2\u01ee\u01ec\3\2\2"+
		"\2\u01ee\u01ed\3\2\2\2\u01ee\u01ef\3\2\2\2\u01ef\u01f0\3\2\2\2\u01f0\u01f3"+
		"\7\25\2\2\u01f1\u01f4\5 \21\2\u01f2\u01f4\5\24\13\2\u01f3\u01f1\3\2\2"+
		"\2\u01f3\u01f2\3\2\2\2\u01f3\u01f4\3\2\2\2\u01f4\u01f5\3\2\2\2\u01f5\u01f8"+
		"\7\25\2\2\u01f6\u01f9\5 \21\2\u01f7\u01f9\5\24\13\2\u01f8\u01f6\3\2\2"+
		"\2\u01f8\u01f7\3\2\2\2\u01f8\u01f9\3\2\2\2\u01f9\u01fa\3\2\2\2\u01fa\u01fb"+
		"\7\21\2\2\u01fb\u01fd\5\22\n\2\u01fc\u01e4\3\2\2\2\u01fc\u01ea\3\2\2\2"+
		"\u01fd_\3\2\2\2\u01fe\u01ff\7B\2\2\u01ff\u0208\7\25\2\2\u0200\u0201\7"+
		"C\2\2\u0201\u0208\7\25\2\2\u0202\u0204\7D\2\2\u0203\u0205\5 \21\2\u0204"+
		"\u0203\3\2\2\2\u0204\u0205\3\2\2\2\u0205\u0206\3\2\2\2\u0206\u0208\7\25"+
		"\2\2\u0207\u01fe\3\2\2\2\u0207\u0200\3\2\2\2\u0207\u0202\3\2\2\2\u0208"+
		"a\3\2\2\2\62elv\u0086\u008e\u0098\u00a3\u00a5\u00ae\u00b3\u00c1\u00c7"+
		"\u00cd\u00df\u00e9\u00f3\u00fe\u010a\u010c\u0118\u0124\u0126\u0135\u0137"+
		"\u013e\u014d\u0150\u0152\u015b\u0165\u0179\u0186\u018b\u0191\u0196\u019b"+
		"\u01a4\u01c4\u01c9\u01d3\u01d8\u01e2\u01ee\u01f3\u01f8\u01fc\u0204\u0207";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}