// Generated from c:\Dane\Kompilator\komp22-shaper\Grammar\Shaper.g4 by ANTLR 4.8
import org.antlr.v4.runtime.Lexer;
import org.antlr.v4.runtime.CharStream;
import org.antlr.v4.runtime.Token;
import org.antlr.v4.runtime.TokenStream;
import org.antlr.v4.runtime.*;
import org.antlr.v4.runtime.atn.*;
import org.antlr.v4.runtime.dfa.DFA;
import org.antlr.v4.runtime.misc.*;

@SuppressWarnings({"all", "warnings", "unchecked", "unused", "cast"})
public class ShaperLexer extends Lexer {
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
	public static String[] channelNames = {
		"DEFAULT_TOKEN_CHANNEL", "HIDDEN"
	};

	public static String[] modeNames = {
		"DEFAULT_MODE"
	};

	private static String[] makeRuleNames() {
		return new String[] {
			"PAINT", "LINE", "TRIANGLE", "RECTANGLE", "SQUARE", "CIRCLE", "ELLIPSE", 
			"AT", "OF", "FROM", "THROUGH", "TO", "WITH", "LEFTPAREN", "RIGHTPAREN", 
			"LEFTBRACKET", "RIGHTBRACKET", "COMMA", "SEMICOLON", "COLON", "VOID", 
			"BOOL", "INT", "LONG", "CHAR", "FLOAT", "DOUBLE", "COLOR", "STRUCT", 
			"ARRAY", "LIST", "CONST", "OR", "AND", "EQUAL", "NOTEQUAL", "PLUS", "MINUS", 
			"MULTIPLY", "DIVIDE", "MODULO", "DOT", "PLUSPLUS", "MINUSMINUS", "ASSIGN", 
			"PLUSASSIGN", "MINUSASSIGN", "MULTIPLYASSIGN", "DIVIDEASSIGN", "MODULOASSIGN", 
			"LESS", "MOREE", "LESSEQUAL", "MOREEQUAL", "EXCLAMATION", "IF", "ELIF", 
			"ELSE", "SWITCH", "CASE", "DEFAULT", "WHILE", "FOR", "CONTINUE", "BREAK", 
			"RETURN", "Constant", "IntegerConstant", "NonZeroDigit", "FloatingConstant", 
			"LogicalConstant", "Identifier", "NonDigit", "Digit", "WS", "WhiteSpace"
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


	public ShaperLexer(CharStream input) {
		super(input);
		_interp = new LexerATNSimulator(this,_ATN,_decisionToDFA,_sharedContextCache);
	}

	@Override
	public String getGrammarFileName() { return "Shaper.g4"; }

	@Override
	public String[] getRuleNames() { return ruleNames; }

	@Override
	public String getSerializedATN() { return _serializedATN; }

	@Override
	public String[] getChannelNames() { return channelNames; }

	@Override
	public String[] getModeNames() { return modeNames; }

	@Override
	public ATN getATN() { return _ATN; }

	public static final String _serializedATN =
		"\3\u608b\ua72a\u8133\ub9ed\u417c\u3be7\u7786\u5964\2H\u01f6\b\1\4\2\t"+
		"\2\4\3\t\3\4\4\t\4\4\5\t\5\4\6\t\6\4\7\t\7\4\b\t\b\4\t\t\t\4\n\t\n\4\13"+
		"\t\13\4\f\t\f\4\r\t\r\4\16\t\16\4\17\t\17\4\20\t\20\4\21\t\21\4\22\t\22"+
		"\4\23\t\23\4\24\t\24\4\25\t\25\4\26\t\26\4\27\t\27\4\30\t\30\4\31\t\31"+
		"\4\32\t\32\4\33\t\33\4\34\t\34\4\35\t\35\4\36\t\36\4\37\t\37\4 \t \4!"+
		"\t!\4\"\t\"\4#\t#\4$\t$\4%\t%\4&\t&\4\'\t\'\4(\t(\4)\t)\4*\t*\4+\t+\4"+
		",\t,\4-\t-\4.\t.\4/\t/\4\60\t\60\4\61\t\61\4\62\t\62\4\63\t\63\4\64\t"+
		"\64\4\65\t\65\4\66\t\66\4\67\t\67\48\t8\49\t9\4:\t:\4;\t;\4<\t<\4=\t="+
		"\4>\t>\4?\t?\4@\t@\4A\tA\4B\tB\4C\tC\4D\tD\4E\tE\4F\tF\4G\tG\4H\tH\4I"+
		"\tI\4J\tJ\4K\tK\4L\tL\4M\tM\3\2\3\2\3\2\3\2\3\2\3\2\3\3\3\3\3\3\3\3\3"+
		"\3\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\4\3\5\3\5\3\5\3\5\3\5\3\5\3\5\3\5"+
		"\3\5\3\5\3\6\3\6\3\6\3\6\3\6\3\6\3\6\3\7\3\7\3\7\3\7\3\7\3\7\3\7\3\b\3"+
		"\b\3\b\3\b\3\b\3\b\3\b\3\b\3\t\3\t\3\t\3\n\3\n\3\n\3\13\3\13\3\13\3\13"+
		"\3\13\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\f\3\r\3\r\3\r\3\16\3\16\3\16\3\16"+
		"\3\16\3\17\3\17\3\20\3\20\3\21\3\21\3\22\3\22\3\23\3\23\3\24\3\24\3\25"+
		"\3\25\3\26\3\26\3\26\3\26\3\26\3\27\3\27\3\27\3\27\3\27\3\30\3\30\3\30"+
		"\3\30\3\31\3\31\3\31\3\31\3\31\3\32\3\32\3\32\3\32\3\32\3\33\3\33\3\33"+
		"\3\33\3\33\3\33\3\34\3\34\3\34\3\34\3\34\3\34\3\34\3\35\3\35\3\35\3\35"+
		"\3\35\3\35\3\36\3\36\3\36\3\36\3\36\3\36\3\36\3\37\3\37\3\37\3\37\3\37"+
		"\3\37\3 \3 \3 \3 \3 \3!\3!\3!\3!\3!\3!\3\"\3\"\3#\3#\3$\3$\3$\3%\3%\3"+
		"%\3&\3&\3\'\3\'\3(\3(\3)\3)\3*\3*\3+\3+\3,\3,\3,\3-\3-\3-\3.\3.\3/\3/"+
		"\3/\3\60\3\60\3\60\3\61\3\61\3\61\3\62\3\62\3\62\3\63\3\63\3\63\3\64\3"+
		"\64\3\65\3\65\3\66\3\66\3\66\3\67\3\67\3\67\38\38\39\39\39\3:\3:\3:\3"+
		":\3:\3;\3;\3;\3;\3;\3<\3<\3<\3<\3<\3<\3<\3=\3=\3=\3=\3=\3>\3>\3>\3>\3"+
		">\3>\3>\3>\3?\3?\3?\3?\3?\3?\3@\3@\3@\3@\3A\3A\3A\3A\3A\3A\3A\3A\3A\3"+
		"B\3B\3B\3B\3B\3B\3C\3C\3C\3C\3C\3C\3C\3D\3D\3D\5D\u01b9\nD\3E\3E\7E\u01bd"+
		"\nE\fE\16E\u01c0\13E\3E\5E\u01c3\nE\3F\3F\3G\6G\u01c8\nG\rG\16G\u01c9"+
		"\3G\3G\6G\u01ce\nG\rG\16G\u01cf\3H\3H\3H\3H\3H\3H\3H\3H\3H\5H\u01db\n"+
		"H\3I\3I\3I\7I\u01e0\nI\fI\16I\u01e3\13I\3J\3J\3K\3K\3L\6L\u01ea\nL\rL"+
		"\16L\u01eb\3L\3L\3M\6M\u01f1\nM\rM\16M\u01f2\3M\3M\2\2N\3\3\5\4\7\5\t"+
		"\6\13\7\r\b\17\t\21\n\23\13\25\f\27\r\31\16\33\17\35\20\37\21!\22#\23"+
		"%\24\'\25)\26+\27-\30/\31\61\32\63\33\65\34\67\359\36;\37= ?!A\"C#E$G"+
		"%I&K\'M(O)Q*S+U,W-Y.[/]\60_\61a\62c\63e\64g\65i\66k\67m8o9q:s;u<w=y>{"+
		"?}@\177A\u0081B\u0083C\u0085D\u0087E\u0089\2\u008b\2\u008d\2\u008f\2\u0091"+
		"F\u0093\2\u0095\2\u0097G\u0099H\3\2\b\3\2\62\62\3\2\63;\4\2C\\c|\3\2\62"+
		";\4\2\f\f\17\17\4\2\13\13\"\"\2\u01fa\2\3\3\2\2\2\2\5\3\2\2\2\2\7\3\2"+
		"\2\2\2\t\3\2\2\2\2\13\3\2\2\2\2\r\3\2\2\2\2\17\3\2\2\2\2\21\3\2\2\2\2"+
		"\23\3\2\2\2\2\25\3\2\2\2\2\27\3\2\2\2\2\31\3\2\2\2\2\33\3\2\2\2\2\35\3"+
		"\2\2\2\2\37\3\2\2\2\2!\3\2\2\2\2#\3\2\2\2\2%\3\2\2\2\2\'\3\2\2\2\2)\3"+
		"\2\2\2\2+\3\2\2\2\2-\3\2\2\2\2/\3\2\2\2\2\61\3\2\2\2\2\63\3\2\2\2\2\65"+
		"\3\2\2\2\2\67\3\2\2\2\29\3\2\2\2\2;\3\2\2\2\2=\3\2\2\2\2?\3\2\2\2\2A\3"+
		"\2\2\2\2C\3\2\2\2\2E\3\2\2\2\2G\3\2\2\2\2I\3\2\2\2\2K\3\2\2\2\2M\3\2\2"+
		"\2\2O\3\2\2\2\2Q\3\2\2\2\2S\3\2\2\2\2U\3\2\2\2\2W\3\2\2\2\2Y\3\2\2\2\2"+
		"[\3\2\2\2\2]\3\2\2\2\2_\3\2\2\2\2a\3\2\2\2\2c\3\2\2\2\2e\3\2\2\2\2g\3"+
		"\2\2\2\2i\3\2\2\2\2k\3\2\2\2\2m\3\2\2\2\2o\3\2\2\2\2q\3\2\2\2\2s\3\2\2"+
		"\2\2u\3\2\2\2\2w\3\2\2\2\2y\3\2\2\2\2{\3\2\2\2\2}\3\2\2\2\2\177\3\2\2"+
		"\2\2\u0081\3\2\2\2\2\u0083\3\2\2\2\2\u0085\3\2\2\2\2\u0087\3\2\2\2\2\u0091"+
		"\3\2\2\2\2\u0097\3\2\2\2\2\u0099\3\2\2\2\3\u009b\3\2\2\2\5\u00a1\3\2\2"+
		"\2\7\u00a6\3\2\2\2\t\u00af\3\2\2\2\13\u00b9\3\2\2\2\r\u00c0\3\2\2\2\17"+
		"\u00c7\3\2\2\2\21\u00cf\3\2\2\2\23\u00d2\3\2\2\2\25\u00d5\3\2\2\2\27\u00da"+
		"\3\2\2\2\31\u00e2\3\2\2\2\33\u00e5\3\2\2\2\35\u00ea\3\2\2\2\37\u00ec\3"+
		"\2\2\2!\u00ee\3\2\2\2#\u00f0\3\2\2\2%\u00f2\3\2\2\2\'\u00f4\3\2\2\2)\u00f6"+
		"\3\2\2\2+\u00f8\3\2\2\2-\u00fd\3\2\2\2/\u0102\3\2\2\2\61\u0106\3\2\2\2"+
		"\63\u010b\3\2\2\2\65\u0110\3\2\2\2\67\u0116\3\2\2\29\u011d\3\2\2\2;\u0123"+
		"\3\2\2\2=\u012a\3\2\2\2?\u0130\3\2\2\2A\u0135\3\2\2\2C\u013b\3\2\2\2E"+
		"\u013d\3\2\2\2G\u013f\3\2\2\2I\u0142\3\2\2\2K\u0145\3\2\2\2M\u0147\3\2"+
		"\2\2O\u0149\3\2\2\2Q\u014b\3\2\2\2S\u014d\3\2\2\2U\u014f\3\2\2\2W\u0151"+
		"\3\2\2\2Y\u0154\3\2\2\2[\u0157\3\2\2\2]\u0159\3\2\2\2_\u015c\3\2\2\2a"+
		"\u015f\3\2\2\2c\u0162\3\2\2\2e\u0165\3\2\2\2g\u0168\3\2\2\2i\u016a\3\2"+
		"\2\2k\u016c\3\2\2\2m\u016f\3\2\2\2o\u0172\3\2\2\2q\u0174\3\2\2\2s\u0177"+
		"\3\2\2\2u\u017c\3\2\2\2w\u0181\3\2\2\2y\u0188\3\2\2\2{\u018d\3\2\2\2}"+
		"\u0195\3\2\2\2\177\u019b\3\2\2\2\u0081\u019f\3\2\2\2\u0083\u01a8\3\2\2"+
		"\2\u0085\u01ae\3\2\2\2\u0087\u01b8\3\2\2\2\u0089\u01c2\3\2\2\2\u008b\u01c4"+
		"\3\2\2\2\u008d\u01c7\3\2\2\2\u008f\u01da\3\2\2\2\u0091\u01dc\3\2\2\2\u0093"+
		"\u01e4\3\2\2\2\u0095\u01e6\3\2\2\2\u0097\u01e9\3\2\2\2\u0099\u01f0\3\2"+
		"\2\2\u009b\u009c\7r\2\2\u009c\u009d\7c\2\2\u009d\u009e\7k\2\2\u009e\u009f"+
		"\7p\2\2\u009f\u00a0\7v\2\2\u00a0\4\3\2\2\2\u00a1\u00a2\7n\2\2\u00a2\u00a3"+
		"\7k\2\2\u00a3\u00a4\7p\2\2\u00a4\u00a5\7g\2\2\u00a5\6\3\2\2\2\u00a6\u00a7"+
		"\7v\2\2\u00a7\u00a8\7t\2\2\u00a8\u00a9\7k\2\2\u00a9\u00aa\7c\2\2\u00aa"+
		"\u00ab\7p\2\2\u00ab\u00ac\7i\2\2\u00ac\u00ad\7n\2\2\u00ad\u00ae\7g\2\2"+
		"\u00ae\b\3\2\2\2\u00af\u00b0\7t\2\2\u00b0\u00b1\7g\2\2\u00b1\u00b2\7e"+
		"\2\2\u00b2\u00b3\7v\2\2\u00b3\u00b4\7c\2\2\u00b4\u00b5\7p\2\2\u00b5\u00b6"+
		"\7i\2\2\u00b6\u00b7\7n\2\2\u00b7\u00b8\7g\2\2\u00b8\n\3\2\2\2\u00b9\u00ba"+
		"\7u\2\2\u00ba\u00bb\7s\2\2\u00bb\u00bc\7w\2\2\u00bc\u00bd\7c\2\2\u00bd"+
		"\u00be\7t\2\2\u00be\u00bf\7g\2\2\u00bf\f\3\2\2\2\u00c0\u00c1\7e\2\2\u00c1"+
		"\u00c2\7k\2\2\u00c2\u00c3\7t\2\2\u00c3\u00c4\7e\2\2\u00c4\u00c5\7n\2\2"+
		"\u00c5\u00c6\7g\2\2\u00c6\16\3\2\2\2\u00c7\u00c8\7g\2\2\u00c8\u00c9\7"+
		"n\2\2\u00c9\u00ca\7n\2\2\u00ca\u00cb\7k\2\2\u00cb\u00cc\7r\2\2\u00cc\u00cd"+
		"\7u\2\2\u00cd\u00ce\7g\2\2\u00ce\20\3\2\2\2\u00cf\u00d0\7c\2\2\u00d0\u00d1"+
		"\7v\2\2\u00d1\22\3\2\2\2\u00d2\u00d3\7q\2\2\u00d3\u00d4\7h\2\2\u00d4\24"+
		"\3\2\2\2\u00d5\u00d6\7h\2\2\u00d6\u00d7\7t\2\2\u00d7\u00d8\7q\2\2\u00d8"+
		"\u00d9\7o\2\2\u00d9\26\3\2\2\2\u00da\u00db\7v\2\2\u00db\u00dc\7j\2\2\u00dc"+
		"\u00dd\7t\2\2\u00dd\u00de\7q\2\2\u00de\u00df\7w\2\2\u00df\u00e0\7i\2\2"+
		"\u00e0\u00e1\7j\2\2\u00e1\30\3\2\2\2\u00e2\u00e3\7v\2\2\u00e3\u00e4\7"+
		"q\2\2\u00e4\32\3\2\2\2\u00e5\u00e6\7y\2\2\u00e6\u00e7\7k\2\2\u00e7\u00e8"+
		"\7v\2\2\u00e8\u00e9\7j\2\2\u00e9\34\3\2\2\2\u00ea\u00eb\7*\2\2\u00eb\36"+
		"\3\2\2\2\u00ec\u00ed\7+\2\2\u00ed \3\2\2\2\u00ee\u00ef\7}\2\2\u00ef\""+
		"\3\2\2\2\u00f0\u00f1\7\177\2\2\u00f1$\3\2\2\2\u00f2\u00f3\7.\2\2\u00f3"+
		"&\3\2\2\2\u00f4\u00f5\7=\2\2\u00f5(\3\2\2\2\u00f6\u00f7\7<\2\2\u00f7*"+
		"\3\2\2\2\u00f8\u00f9\7x\2\2\u00f9\u00fa\7q\2\2\u00fa\u00fb\7k\2\2\u00fb"+
		"\u00fc\7f\2\2\u00fc,\3\2\2\2\u00fd\u00fe\7d\2\2\u00fe\u00ff\7q\2\2\u00ff"+
		"\u0100\7q\2\2\u0100\u0101\7n\2\2\u0101.\3\2\2\2\u0102\u0103\7k\2\2\u0103"+
		"\u0104\7p\2\2\u0104\u0105\7v\2\2\u0105\60\3\2\2\2\u0106\u0107\7n\2\2\u0107"+
		"\u0108\7q\2\2\u0108\u0109\7p\2\2\u0109\u010a\7i\2\2\u010a\62\3\2\2\2\u010b"+
		"\u010c\7e\2\2\u010c\u010d\7j\2\2\u010d\u010e\7c\2\2\u010e\u010f\7t\2\2"+
		"\u010f\64\3\2\2\2\u0110\u0111\7h\2\2\u0111\u0112\7n\2\2\u0112\u0113\7"+
		"q\2\2\u0113\u0114\7c\2\2\u0114\u0115\7v\2\2\u0115\66\3\2\2\2\u0116\u0117"+
		"\7f\2\2\u0117\u0118\7q\2\2\u0118\u0119\7w\2\2\u0119\u011a\7d\2\2\u011a"+
		"\u011b\7n\2\2\u011b\u011c\7g\2\2\u011c8\3\2\2\2\u011d\u011e\7e\2\2\u011e"+
		"\u011f\7q\2\2\u011f\u0120\7n\2\2\u0120\u0121\7q\2\2\u0121\u0122\7t\2\2"+
		"\u0122:\3\2\2\2\u0123\u0124\7u\2\2\u0124\u0125\7v\2\2\u0125\u0126\7t\2"+
		"\2\u0126\u0127\7w\2\2\u0127\u0128\7e\2\2\u0128\u0129\7v\2\2\u0129<\3\2"+
		"\2\2\u012a\u012b\7c\2\2\u012b\u012c\7t\2\2\u012c\u012d\7t\2\2\u012d\u012e"+
		"\7c\2\2\u012e\u012f\7{\2\2\u012f>\3\2\2\2\u0130\u0131\7n\2\2\u0131\u0132"+
		"\7k\2\2\u0132\u0133\7u\2\2\u0133\u0134\7v\2\2\u0134@\3\2\2\2\u0135\u0136"+
		"\7e\2\2\u0136\u0137\7q\2\2\u0137\u0138\7p\2\2\u0138\u0139\7u\2\2\u0139"+
		"\u013a\7v\2\2\u013aB\3\2\2\2\u013b\u013c\7~\2\2\u013cD\3\2\2\2\u013d\u013e"+
		"\7(\2\2\u013eF\3\2\2\2\u013f\u0140\7?\2\2\u0140\u0141\7?\2\2\u0141H\3"+
		"\2\2\2\u0142\u0143\7#\2\2\u0143\u0144\7?\2\2\u0144J\3\2\2\2\u0145\u0146"+
		"\7-\2\2\u0146L\3\2\2\2\u0147\u0148\7/\2\2\u0148N\3\2\2\2\u0149\u014a\7"+
		",\2\2\u014aP\3\2\2\2\u014b\u014c\7\61\2\2\u014cR\3\2\2\2\u014d\u014e\7"+
		"\'\2\2\u014eT\3\2\2\2\u014f\u0150\7\60\2\2\u0150V\3\2\2\2\u0151\u0152"+
		"\7-\2\2\u0152\u0153\7-\2\2\u0153X\3\2\2\2\u0154\u0155\7/\2\2\u0155\u0156"+
		"\7/\2\2\u0156Z\3\2\2\2\u0157\u0158\7?\2\2\u0158\\\3\2\2\2\u0159\u015a"+
		"\7-\2\2\u015a\u015b\7?\2\2\u015b^\3\2\2\2\u015c\u015d\7/\2\2\u015d\u015e"+
		"\7?\2\2\u015e`\3\2\2\2\u015f\u0160\7,\2\2\u0160\u0161\7?\2\2\u0161b\3"+
		"\2\2\2\u0162\u0163\7\61\2\2\u0163\u0164\7?\2\2\u0164d\3\2\2\2\u0165\u0166"+
		"\7\'\2\2\u0166\u0167\7?\2\2\u0167f\3\2\2\2\u0168\u0169\7>\2\2\u0169h\3"+
		"\2\2\2\u016a\u016b\7@\2\2\u016bj\3\2\2\2\u016c\u016d\7>\2\2\u016d\u016e"+
		"\7?\2\2\u016el\3\2\2\2\u016f\u0170\7@\2\2\u0170\u0171\7?\2\2\u0171n\3"+
		"\2\2\2\u0172\u0173\7#\2\2\u0173p\3\2\2\2\u0174\u0175\7k\2\2\u0175\u0176"+
		"\7h\2\2\u0176r\3\2\2\2\u0177\u0178\7g\2\2\u0178\u0179\7n\2\2\u0179\u017a"+
		"\7k\2\2\u017a\u017b\7h\2\2\u017bt\3\2\2\2\u017c\u017d\7g\2\2\u017d\u017e"+
		"\7n\2\2\u017e\u017f\7u\2\2\u017f\u0180\7g\2\2\u0180v\3\2\2\2\u0181\u0182"+
		"\7u\2\2\u0182\u0183\7y\2\2\u0183\u0184\7k\2\2\u0184\u0185\7v\2\2\u0185"+
		"\u0186\7e\2\2\u0186\u0187\7j\2\2\u0187x\3\2\2\2\u0188\u0189\7e\2\2\u0189"+
		"\u018a\7c\2\2\u018a\u018b\7u\2\2\u018b\u018c\7g\2\2\u018cz\3\2\2\2\u018d"+
		"\u018e\7f\2\2\u018e\u018f\7g\2\2\u018f\u0190\7h\2\2\u0190\u0191\7c\2\2"+
		"\u0191\u0192\7w\2\2\u0192\u0193\7n\2\2\u0193\u0194\7v\2\2\u0194|\3\2\2"+
		"\2\u0195\u0196\7y\2\2\u0196\u0197\7j\2\2\u0197\u0198\7k\2\2\u0198\u0199"+
		"\7n\2\2\u0199\u019a\7g\2\2\u019a~\3\2\2\2\u019b\u019c\7h\2\2\u019c\u019d"+
		"\7q\2\2\u019d\u019e\7t\2\2\u019e\u0080\3\2\2\2\u019f\u01a0\7e\2\2\u01a0"+
		"\u01a1\7q\2\2\u01a1\u01a2\7p\2\2\u01a2\u01a3\7v\2\2\u01a3\u01a4\7k\2\2"+
		"\u01a4\u01a5\7p\2\2\u01a5\u01a6\7w\2\2\u01a6\u01a7\7g\2\2\u01a7\u0082"+
		"\3\2\2\2\u01a8\u01a9\7d\2\2\u01a9\u01aa\7t\2\2\u01aa\u01ab\7g\2\2\u01ab"+
		"\u01ac\7c\2\2\u01ac\u01ad\7m\2\2\u01ad\u0084\3\2\2\2\u01ae\u01af\7t\2"+
		"\2\u01af\u01b0\7g\2\2\u01b0\u01b1\7v\2\2\u01b1\u01b2\7w\2\2\u01b2\u01b3"+
		"\7t\2\2\u01b3\u01b4\7p\2\2\u01b4\u0086\3\2\2\2\u01b5\u01b9\5\u0089E\2"+
		"\u01b6\u01b9\5\u008dG\2\u01b7\u01b9\5\u008fH\2\u01b8\u01b5\3\2\2\2\u01b8"+
		"\u01b6\3\2\2\2\u01b8\u01b7\3\2\2\2\u01b9\u0088\3\2\2\2\u01ba\u01be\5\u008b"+
		"F\2\u01bb\u01bd\5\u0095K\2\u01bc\u01bb\3\2\2\2\u01bd\u01c0\3\2\2\2\u01be"+
		"\u01bc\3\2\2\2\u01be\u01bf\3\2\2\2\u01bf\u01c3\3\2\2\2\u01c0\u01be\3\2"+
		"\2\2\u01c1\u01c3\t\2\2\2\u01c2\u01ba\3\2\2\2\u01c2\u01c1\3\2\2\2\u01c3"+
		"\u008a\3\2\2\2\u01c4\u01c5\t\3\2\2\u01c5\u008c\3\2\2\2\u01c6\u01c8\5\u0095"+
		"K\2\u01c7\u01c6\3\2\2\2\u01c8\u01c9\3\2\2\2\u01c9\u01c7\3\2\2\2\u01c9"+
		"\u01ca\3\2\2\2\u01ca\u01cb\3\2\2\2\u01cb\u01cd\7\60\2\2\u01cc\u01ce\5"+
		"\u0095K\2\u01cd\u01cc\3\2\2\2\u01ce\u01cf\3\2\2\2\u01cf\u01cd\3\2\2\2"+
		"\u01cf\u01d0\3\2\2\2\u01d0\u008e\3\2\2\2\u01d1\u01d2\7h\2\2\u01d2\u01d3"+
		"\7c\2\2\u01d3\u01d4\7n\2\2\u01d4\u01d5\7u\2\2\u01d5\u01db\7g\2\2\u01d6"+
		"\u01d7\7v\2\2\u01d7\u01d8\7t\2\2\u01d8\u01d9\7w\2\2\u01d9\u01db\7g\2\2"+
		"\u01da\u01d1\3\2\2\2\u01da\u01d6\3\2\2\2\u01db\u0090\3\2\2\2\u01dc\u01e1"+
		"\5\u0093J\2\u01dd\u01e0\5\u0093J\2\u01de\u01e0\5\u0095K\2\u01df\u01dd"+
		"\3\2\2\2\u01df\u01de\3\2\2\2\u01e0\u01e3\3\2\2\2\u01e1\u01df\3\2\2\2\u01e1"+
		"\u01e2\3\2\2\2\u01e2\u0092\3\2\2\2\u01e3\u01e1\3\2\2\2\u01e4\u01e5\t\4"+
		"\2\2\u01e5\u0094\3\2\2\2\u01e6\u01e7\t\5\2\2\u01e7\u0096\3\2\2\2\u01e8"+
		"\u01ea\t\6\2\2\u01e9\u01e8\3\2\2\2\u01ea\u01eb\3\2\2\2\u01eb\u01e9\3\2"+
		"\2\2\u01eb\u01ec\3\2\2\2\u01ec\u01ed\3\2\2\2\u01ed\u01ee\bL\2\2\u01ee"+
		"\u0098\3\2\2\2\u01ef\u01f1\t\7\2\2\u01f0\u01ef\3\2\2\2\u01f1\u01f2\3\2"+
		"\2\2\u01f2\u01f0\3\2\2\2\u01f2\u01f3\3\2\2\2\u01f3\u01f4\3\2\2\2\u01f4"+
		"\u01f5\bM\2\2\u01f5\u009a\3\2\2\2\r\2\u01b8\u01be\u01c2\u01c9\u01cf\u01da"+
		"\u01df\u01e1\u01eb\u01f2\3\b\2\2";
	public static final ATN _ATN =
		new ATNDeserializer().deserialize(_serializedATN.toCharArray());
	static {
		_decisionToDFA = new DFA[_ATN.getNumberOfDecisions()];
		for (int i = 0; i < _ATN.getNumberOfDecisions(); i++) {
			_decisionToDFA[i] = new DFA(_ATN.getDecisionState(i), i);
		}
	}
}