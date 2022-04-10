from ast import arg
import sys
import os.path
from antlr4 import *
from ShaperLexer import ShaperLexer
from ShaperParser import ShaperParser
from MyVisitor import MyVisitor
from WindowMaker import WindowMaker
 
def main(argv):
    
    if len(argv)>1 and os.path.isfile(argv[1]):
        input_stream = FileStream(argv[1])

        lexer = ShaperLexer(input_stream)
        stream = CommonTokenStream(lexer)
        parser = ShaperParser(stream)
        tree = parser.programm()

        myVisitor = MyVisitor()

        myVisitor.visit(tree)

        myVisitor.window.show()

    else:
        print("File doesn't exist!")

 
if __name__ == '__main__':
    main(sys.argv)