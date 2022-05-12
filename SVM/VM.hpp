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

    CONST_I  ,  // push constant -

    I2S ,       // cast int to short
    I2C ,       // cast int to char

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
    
    PRINT  ,  // ? print value on top of the stack
    POP    ,  // ? throw away top of the stack
    HALT   ,  // stop program -
    CALL   ,  // call procedure -
    RET       // return from procedure -
};

/*
data type control by compilator or VM
create specifik instruction like ADD_I , ADD_F ...
*/

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

private:
    void showStack() const; //debug
    void push(int value);   // add to stack
    int pop ();             // remove from stack
    int next();             // load next instruction
};

#endif // __VM_H__