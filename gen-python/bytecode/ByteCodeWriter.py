
from bytecode.Commands import Command

"""
Writes commands to bytecode file
"""
class ByteCodeWriter:
    def __init__(self, filename="..\SVM\paint.hae"):
        self.filename = filename
        self.fileHandler = None

    def writeToFile(self, offset, commands):
        self.fileHandler = open(self.filename, "wb")

        self.writeOffset(offset)

        for command in commands:
            if(type(command) == tuple):
                self.writeSingleCommand(command)
            else:
                self.writeSingleByte(command)

    def writeSingleCommand(self, command):
        for byte in command:
            self.writeSingleByte(byte)
        
    def writeSingleByte(self, byte):
        if self.fileHandler != None:
            if type(byte) == Command:
                byte = byte.value
                    
            if byte < 0:
                byte = byte & 0xffffffff
                    
            self.fileHandler.write(byte.to_bytes(4, byteorder="little"))

    def writeOffset(self, offset):
        self.writeSingleByte(offset)