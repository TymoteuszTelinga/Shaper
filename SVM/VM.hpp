#ifndef __VM_H__
#define __VM_H__

#include "MMU.hpp"
#include "Graphic.hpp"

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
// color  = 1 int

enum {
    ADD_I = 0x00, // int add -
    SUB_I   ,  // int substracion -
    MUL_I   ,  // int multyply -
    DIV_I   ,  // int divde -
    MOD_I   ,  // int modulo -

    ADD_F   ,  // float add -
    SUB_F   ,  // float substracion -
    MUL_F   ,  // float multyply -
    DIV_F   ,  // float divde -

    ADD_L   ,  // long add -
    SUB_L   ,  // long substracion -
    MUL_L   ,  // long multyply -
    DIV_L   ,  // long divde -
    MOD_L   ,  // long modulo -

    ADD_D   ,  // double add -
    SUB_D   ,  // double substracion -
    MUL_D   ,  // double multyply -
    DIV_D   ,  // double divde -

    CONST_I ,  // push constant -

    I2C     ,  // cast int to char -
    I2S     ,  // cast int to short -
    I2F     ,  // cast int to float -
    I2L     ,  // cast int to long -
    I2D     ,  // cast int to double -

    F2I     ,  // cast float to int -
    F2L     ,  // cast float to long -
    F2D     ,  // cast float to double -

    L2I     ,  // cast long to int -
    L2F     ,  // cast long to float -
    L2D     ,  // cast long to double -

    D2I     ,  // cast double to int -
    D2F     ,  // cast double to float -
    D2L     ,  // cast double to long -

    INC     ,  // increment local int variable
    DEC     ,  // decrement local int variable

    LT      ,  // int less than -
    GT      ,  // int greater than -
    LE      ,  // int less equal -
    GE      ,  // int greater equal -
    EQ      ,  // int equal -

    AND     ,  // boolean and
    OR      ,  // boolean or
    NEG     ,  // boolean negate

    JMP     ,  // branch -
    JMPT    ,  // branch if true -
    JMPF    ,  // branch if false -

    LOAD    ,  // load from local (stack) -
    GLOAD   ,  // load from global memory (memory) -
    ALOAD_I ,  // load int from array -
    LOAD_CH ,  // get color chanel

    STORE   ,  // store in local (stack) -
    GSTORE  ,  // store in global memory (memory) -
    ASTORE_I,  // store int in array -
    STORE_CH,  // set color chanel
    
    PRINT_C ,  // ? print value as char - 
    PRINT_I ,  // ? print value on top of the stack -
    PRINT_F ,  // ? print value as float -
    PRINT_L ,  // ? print long value -
    PRINT_D ,  // ? print double value -

    POP     ,  // ? throw away top of the stack -
    POP2    ,  // ? throw away two values or long from top of the stack -
    HALT    ,  // stop program -
    CALL    ,  // call procedure -
    RET     ,  // return from procedure -
    DUMMY   ,  // do nothink
    RANDOM  ,  // put random int on top of stack

    NEWARR  ,  // alocate memory for new array
    LENGTH  ,  // length of reserved block
    FREE    ,  // free memory from pointer

    DISPLAY  ,// display window
    CLEAR    ,// clear window screen
    RECT     ,// draw rectangle
    ELIPSE   ,// draw elipse
    LINE     ,// draw line
    TRIANGLE  // draw triangle
};

struct Parameters
{
    unsigned int memSize = 300;
    unsigned int stackSize = 100;
    unsigned int fps = 240;
    bool debug = false;
    unsigned int width = 400;
    unsigned int height = 400;
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

    MMU mmu;
    Graphic graphic;
    Parameters parameters;

public:
    VM(const int* code, const int PC, const Parameters params);
    ~VM();

    void execute();
    // debug
    void displayMode(const char c) const;
    void showCode(int len = 10) const;
    void showMemory(unsigned int start = 0, unsigned int end = 300) const;

private:
    void showStack() const;      //debug
    void push(int value);        // int to stack
    void pushL(long long value); // long to stack
    int pop ();                  // int from stack
    long long popL();            // long from stack
    int next();                  // load next instruction
};

#endif // __VM_H__