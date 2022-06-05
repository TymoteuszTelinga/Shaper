import sys
import os.path
from tabnanny import check

from antlr4 import *
from antlr4.error.ErrorListener import ErrorListener

from grammar.ShaperLexer import ShaperLexer
from grammar.ShaperParser import ShaperParser

from ByteCodeVisitor import ByteCodeVisitor
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
        raise Exception(f"Attempting full Context ERROR")


    def reportContextSensitivity(self, recognizer, dfa, startIndex, stopIndex, prediction, configs):
        raise Exception("ContextSensitivity ERROR")


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
        

        # try:
        tree = parser.programm()
        
        manager = Manager()
        
        checkVisitor = CheckVisitor(manager)


        checkVisitor.visit(tree)
        checkVisitor.checkFunctionsBody()

        if(len(checkVisitor.errorstack) > 0):
            for error in checkVisitor.errorstack:
                print(error)

        else:      
            byteCodeVisitor = ByteCodeVisitor(checkVisitor.manager)

            byteCodeVisitor.generateCode(tree)

            print(byteCodeVisitor.maker.commandsQueue)


                
        # except Exception as e:
        #     print("something went wrong :(")
        #     print(e)

    else:
        print("File doesn't exist!")

 
if __name__ == '__main__':
    main(sys.argv)