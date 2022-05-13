#ifndef __VM_H__
#define __VM_H__

// C - char
// S - short
// I - int    b
// F - float  b
// L - long   b
// D - double b

// computonal val int
// char   = 1 int
// short  = 1 int
// int    = 1 int
// float  = 1 int
// long   = 2 int
// double = 2 int

enum {
    ADD_I    = 0x00,  // int add -
    SUB_I    ,  // int substracion -
    MUL_I    ,  // int multyply -
    DIV_I    ,  // int divde -
    MOD_I    ,  // int modulo

    ADD_F    ,  // float add -
    SUB_F    ,  // float substracion -
    MUL_F    ,  // float multyply -
    DIV_F    ,  // float divde -

    ADD_L    ,  // long add -
    SUB_L    ,  // long substracion -
    MUL_L    ,  // long multyply -
    DIV_L    ,  // long divde -
    MOD_L    ,  // long modulo -

    ADD_D    ,  // double add -
    SUB_D    ,  // double substracion -
    MUL_D    ,  // double multyply -
    DIV_D    ,  // double divde -

    CONST_I  ,  // push constant -

    I2S ,       // cast int to short
    I2C ,       // cast int to char
    I2F ,       // cast int to float

    LT     ,  // int less than -
    GT     ,  // int greater than
    LE     ,  // int less equal
    GE     ,  // int greater equal
    EQ     ,  // int equal -

    JMP    ,  // branch -
    JMPT   ,  // branch if true -
    JMPF   ,  // branch if false -

    LOAD   ,  // load from local (stack) -
    GLOAD  ,  // load from global memory (memory) -
    STORE  ,  // store in local (stack) -
    GSTORE ,  // store in global memory (memory) -
    
    PRINT_I  ,  // ? print value on top of the stack
    PRINT_F,  // print value as float
    PRINT_L,  // print long value
    PRINT_D,  // print double value

    POP    ,  // ? throw away top of the stack
    HALT   ,  // stop program -
    CALL   ,  // call procedure -
    RET       // return from procedure -
};

class VM
{
private:
    const int* code;    // code memory
    int* memory;        // global memory
    int* stack;         // operational stack
    unsigned int pc;    // program counter
    int sp;             // stack pointer
    unsigned int fp;    // frame pointer

    bool bDied = false;

public:
    VM(const int* code, const int PC, const unsigned int memSize = 300);
    ~VM();

    void showCode() const;
    void showMemory(unsigned int start = 0, unsigned int end = 300) const;
    void execute();

    void displayMode(const char c) const;

private:
    void showStack() const;      //debug
    void push(int value);        // int to stack
    void pushL(long long value); // long to stack
    int pop ();                  // int from stack
    long long popL();            // long from stack
    int next();                  // load next instruction
};

#endif // __VM_H__