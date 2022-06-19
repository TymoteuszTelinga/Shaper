import enum

class Type(enum.Enum):
    ANY = 0
    VOID = 1

    BOOL = 2

    CHAR = 3
    SHORT = 4
    INT = 5
    LONG = 6

    FLOAT = 7
    DOUBLE = 8

    COLOR = 9
    ARRAY = 10

    @staticmethod
    def getType(str):
        if str == 'void':
            return Type.VOID
        elif str =='bool':
            return Type.BOOL
        elif str == 'char':
            return Type.CHAR
        elif str == 'short':
            return Type.SHORT
        elif str == 'int':
            return Type.INT
        elif str == 'long':
            return Type.LONG
        elif str == 'float':
            return Type.FLOAT
        elif str == 'double':
            return Type.DOUBLE
        elif str == 'color':
            return Type.COLOR
        elif str == 'array':
            return Type.ARRAY
        else:
            return Type.VOID

    def __repr__(self) -> str:
        if self == Type.VOID:
            return "\'void\'"
        elif self == Type.BOOL:
            return "\'bool\'"
        elif self == Type.CHAR:
            return "\'char\'"
        elif self == Type.SHORT:
            return "\'short\'"
        elif self == Type.INT:
            return "\'int\'"
        elif self == Type.LONG:
            return "\'long\'"
        elif self == Type.FLOAT:
            return "\'float\'"
        elif self == Type.DOUBLE:
            return "\'double\'"
        elif self == Type.COLOR:
            return "\'color\'"
        elif self == Type.ARRAY:
            return "\'array\'"
        else:
            return "\'void\'"