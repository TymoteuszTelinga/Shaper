class ParametersHandler:

    def __init__(self, params):
        self.showHelp = False
        self.inputName = None
        self.outputName = "paint.hae"
        self.debug = False

        self.parameters = params
        self.par_index = 1

        

    def fetchParameters(self):
        self.par_index = 1
        
        while self.par_index < len(self.parameters):
            self.checkNext()

        if self.inputName == None:
            self.showHelp = True

    def checkNext(self):
        parameter = self.getNext()

        if parameter == '--help':
            self.showHelp = True
        elif parameter == '-o':
            self.setOutputDir(self.getNext())
        elif parameter == '--debug':
            self.debug = True
        elif self.inputName == None:
            self.inputName = parameter
                

    def getNext(self):
        if self.par_index < len(self.parameters):
            temp = self.parameters[self.par_index]
            self.addToIndex(1)
        else:
            temp = None

        return temp


    def setOutputDir(self, outputName):
        if outputName != None:
            self.outputName = outputName
        

        
    def addToIndex(self, value):
        self.par_index += value