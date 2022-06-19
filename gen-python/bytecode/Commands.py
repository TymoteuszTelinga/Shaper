import enum


class Command(enum.Enum):
    ADD_I = 0       # int add -
    SUB_I = 1       # int substracion -
    MUL_I = 2       # int multyply -
    DIV_I = 3       # int divde -
    MOD_I = 4       # int modulo -

    ADD_F = 5       # float add -
    SUB_F = 6       # float substracion -
    MUL_F = 7       # float multyply -
    DIV_F = 8       # float divde -

    ADD_L = 9       # long add -
    SUB_L = 10      # long substracion -
    MUL_L = 11      # long multyply -
    DIV_L = 12      # long divde -
    MOD_L = 13      # long modulo -
    
    ADD_D = 14      # double add -
    SUB_D = 15      # double substracion -
    MUL_D = 16      # double multyply -
    DIV_D = 17      # double divde -
    
    CONST_I = 18    # push constant -

    I2C = 19        # cast int to char -
    I2S = 20        # cast int to short -
    I2F = 21        # cast int to float -
    I2L = 22        # cast int to long -
    I2D = 23        # cast int to double -

    F2I = 24        # cast float to int -
    F2L = 25        # cast float to long -
    F2D = 26        # cast float to double -

    L2I = 27        # cast long to int -
    L2F = 28        # cast long to float -
    L2D = 29        # cast long to double -

    D2I = 30        # cast double to int -
    D2F = 31        # cast double to float -
    D2L = 32        # cast double to long -

    INC = 33        # increment local int variable
    DEC = 34        # decrement local int variable

    LT = 35         # int less than -
    GT = 36         # int greater than -
    LE = 37         # int less equal -
    GE = 38         # int greater equal -
    EQ = 39         # int equal -
        
    AND = 40        # boolean and
    OR = 41         # boolean or
    NEG = 42        # boolean negate

    JMP = 43        # branch -
    JMPT = 44       # branch if true -
    JMPF = 45       # branch if false -

    LOAD = 46       # load from local (stack) -
    GLOAD = 47      # load from global memory (memory) -
    ALOAD_I = 48    # load int from array -
    LOAD_CH = 49    # get color chanel

    STORE = 50      # store in local (stack) -
    GSTORE = 51     # store in global memory (memory) -
    ASTORE_I = 52   # store int in array -
    STORE_CH = 53   # set color chanel
    
    PRINT_C = 54    # ? print value as char - 
    PRINT_I = 55    # ? print value on top of the stack -
    PRINT_F = 56    # ? print value as float -
    PRINT_L = 57    # ? print long value -
    PRINT_D = 58    # ? print double value -

    POP = 59        # ? throw away top of the stack -
    POP2 = 60       # ? throw away two values or long from top of the stack -
    HALT = 61       # stop program -
    CALL = 62       # call procedure -
    RET = 63        # return from procedure -
    DUMMY = 64      # do nothink
    RANDOM = 65     # put random int on top of stack

    NEWARR = 66     # alocate memory for new array
    LENGTH = 67     # length of reserved block
    FREE = 68       # free memory from pointer

    DISPLAY = 69    # display window
    CLEAR = 70      # clear window screen
    RECT = 71       # draw rectangle
    ELIPSE = 72     # draw elipse
    LINE = 73       # draw line
    TRIANGLE = 74   # draw triangle