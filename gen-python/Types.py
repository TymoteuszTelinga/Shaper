import enum

class Type(enum.Enum):
    VOID = 0;
    BOOL = 1;

    INT = 2;
    LONG = 3;
    FLOAT = 4;
    DOUBLE = 5;

    COLOR = 6;

    STRUCT = 7;
    LIST = 8;
    ARRAY = 9;

    @staticmethod
    def getType(str):
        if str == 'void':
            return Type.VOID
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
        else:
            return Type.VOID

    def __repr__(self) -> str:
        if self == Type.VOID:
            return "\'void\'"
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
        else:
            return "\'void\'"