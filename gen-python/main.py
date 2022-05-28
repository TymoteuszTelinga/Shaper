import sys
import os.path

from antlr4 import *
from antlr4.error.ErrorListener import ErrorListener

from grammar.ShaperLexer import ShaperLexer
from grammar.ShaperParser import ShaperParser

from MyVisitor import MyVisitor
from CheckVisitor import CheckVisitor
from Manager import Manager

class ShaperErrorListener(ErrorListener):
    def __init__(self):
        super(ShaperErrorListener, self).__init__()

    def syntaxError(self, recognizer, offendingSymbol, line, column, msg, e):
        raise Exception(f"ERROR: when parsing line {line} column {column}: {msg}\n")
        
    def reportAmbiguity(self, recognizer, dfa, startIndex, stopIndex, exact, ambigAlts, configs):
        raise Exception("Ambiguity ERROR")

    def reportAttemptingFullContext(self, recognizer, dfa, startIndex, stopIndex, conflictingAlts, configs):
        #raise Exception(f"Attempting full Context ERROR")
        pass

    def reportContextSensitivity(self, recognizer, dfa, startIndex, stopIndex, prediction, configs):
        #raise Exception("ContextSensitivity ERROR")
        pass


def main(argv):
    sys.setrecursionlimit(10000)

    if len(argv)>1 and os.path.isfile(argv[1]):
        input_stream = FileStream(argv[1])

        error_listener = ShaperErrorListener()
        lexer = ShaperLexer(input_stream)
        lexer.removeErrorListeners()
        lexer.addErrorListener(error_listener)

        stream = CommonTokenStream(lexer)

        parser = ShaperParser(stream)
        parser.removeErrorListeners()
        parser.addErrorListener(error_listener)
        

        try:
            tree = parser.programm()
            
            manager = Manager()
            
            checkVisitor = CheckVisitor(manager)


            myVisitor = MyVisitor(manager)
            try:

                checkVisitor.visit(tree)
                checkVisitor.checkFunctionsBody()


                myVisitor.start(tree)
                # print(myVisitor.funDict)
                # myVisitor.visit(tree)
                # #myVisitor.window.show()
            except Exception as e:
                print(e)
                
        except Exception as e:
            print("something went wrong :(")
            print(e)

    else:
        print("File doesn't exist!")

 
if __name__ == '__main__':
    main(sys.argv)