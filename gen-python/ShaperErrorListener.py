from antlr4.error.ErrorListener import ErrorListener

class ShaperErrorListener(ErrorListener):
    def __init__(self):
        self.errorOccured = False
        super(ShaperErrorListener, self).__init__()

    def syntaxError(self, recognizer, offendingSymbol, line, column, msg, e):
        print(f"ERROR: when parsing line {line} column {column}: {msg}\n")
        self.errorOccured = True
        
    def reportAmbiguity(self, recognizer, dfa, startIndex, stopIndex, exact, ambigAlts, configs):
        raise Exception("Ambiguity ERROR")

    def reportAttemptingFullContext(self, recognizer, dfa, startIndex, stopIndex, conflictingAlts, configs):
        raise Exception(f"Attempting full Context ERROR")

    def reportContextSensitivity(self, recognizer, dfa, startIndex, stopIndex, prediction, configs):
        raise Exception("ContextSensitivity ERROR")