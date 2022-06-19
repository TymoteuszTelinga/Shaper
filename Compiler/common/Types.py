import enum

class Type(enum.Enum):
    ANY = 0
    VOID = 1

    BOOL = 2
    COLOR = 3

    CHAR = 4
    SHORT = 5
    INT = 6
    FLOAT = 7

    LONG = 8
    DOUBLE = 9

    ARRAY = 10

    @staticmethod
    def getType(str):
        if str == 'void':
            return Type.VOID
        elif str =='bool':
            return Type.BOOL
        elif str == 'char':
            return Type.INT
        elif str == 'short':
            return Type.INT
        elif str == 'int':
            return Type.INT
        elif str == 'long':
            return Type.INT
        elif str == 'float':
            return Type.FLOAT
        elif str == 'double':
            return Type.FLOAT
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