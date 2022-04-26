#ifndef __VM_H__
#define __VM_H__

enum {
    ADD    = 0x00,  // int add -
    SUB    = 0x01,  // int sub -
    MUL    = 0x02,  // int mul -
    DIV    = 0x03,  // int div -
    LT     = 0x04,  // int less than -
    GT     = 0x05,  // int greater than
    LE     = 0x06,  // int less equal
    GE     = 0x07,  // int greater equal
    EQ     = 0x08,  // int equal -
    JMP    = 0x09,  // branch -
    JMPT   = 0x0A,  // branch if true -
    JMPF   = 0x0B,  // branch if false -
    CONST  = 0x0C,  // push constant -
    LOAD   = 0x0D,  // load from local (stack) -
    GLOAD  = 0x0E,  // load from global memory (memory) -
    STORE  = 0x0F,  // store in local (stack) -
    GSTORE = 0x10,  // store in global memory (memory) -
    PRINT  = 0x11,  // ? print value on top of the stack
    POP    = 0x12,  // ? throw away top of the stack
    HALT   = 0x13,  // stop program -
    CALL   = 0x14,  // call procedure -
    RET    = 0x15   // return from procedure -
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