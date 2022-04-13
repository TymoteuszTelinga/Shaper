import sys
import os.path
from antlr4 import *
from grammar.ShaperLexer import ShaperLexer
from grammar.ShaperParser import ShaperParser
from MyVisitor import MyVisitor
from WindowMaker import WindowMaker
from antlr4.error.ErrorListener import ErrorListener

class ShaperErrorListener(ErrorListener):
    def __init__(self):
        super(ShaperErrorListener, self).__init__()

    def syntaxError(self, recognizer, offendingSymbol, line, column, msg, e):
        raise Exception("ERROR: when parsing line %d column %d: %s\n" (line, column, msg))
        
    def reportAmbiguity(self, recognizer, dfa, startIndex, stopIndex, exact, ambigAlts, configs):
        raise Exception("Oh no!")

    def reportAttemptingFullContext(self, recognizer, dfa, startIndex, stopIndex, conflictingAlts, configs):
        raise Exception("Oh no!!")

    def reportContextSensitivity(self, recognizer, dfa, startIndex, stopIndex, prediction, configs):
        raise Exception("Oh no!!!")
 
def main(argv):

    if len(argv)>1 and os.path.isfile(argv[1]):
        input_stream = FileStream(argv[1])

        error_listener =    ShaperErrorListener()
        lexer = ShaperLexer(input_stream)
        lexer.removeErrorListeners()
        lexer.addErrorListener(error_listener)

        stream = CommonTokenStream(lexer)

        parser = ShaperParser(stream)
        parser.removeErrorListeners()
        parser.addErrorListener(error_listener)
        
        try:
            tree = parser.programm()
        except Exception:
            print("samethink go wrong")
            return

        myVisitor = MyVisitor()
        
        myVisitor.visit(tree)
            

        myVisitor.window.show()

    else:
        print("File doesn't exist!")

 
if __name__ == '__main__':
    main(sys.argv)