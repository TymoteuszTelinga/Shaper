
#include <iostream>
#include <fstream>
#include "VM.hpp"

using std::cout;

int main(int argc, char *argv[])
{
    cout<<"Hello\n";
    const int fib = 0;
    int program[] = {
        // int fib(n)
        // if (n == 0) return 0;
        LOAD, -3,       // 0 - load last function argument N
        CONST, 0,       // 2 - put 0
        EQ,             // 4 - check equality: N == 0
        JMPF, 10,       // 5 - if they are NOT equal, goto 10
        CONST, 0,       // 7 - otherwise put 0
        RET,            // 9 - and return it
        // if(n < 3) return 1;
        LOAD, -3,       // 10 - load last function argument N
        CONST, 3,       // 12 - put 3
        LT,             // 14 - check if 3 is less than N
        JMPF, 20,       // 15 - if 3 is NOT less than N, goto 20
        CONST, 1,       // 17 - otherwise put 1
        RET,            // 19 - and return it
        // else return fib(n-1) + fib(n-2);
        LOAD, -3,       // 20 - load last function argument N
        CONST, 1,       // 22 - put 1
        SUB,            // 24 - calculate: N-1, result is on the stack
        CALL, fib, 1,   // 25 - call fib function with 1 arg. from the stack
        LOAD, -3,       // 28 - load N again
        CONST, 2,       // 30 - put 2
        SUB,            // 32 - calculate: N-2, result is on the stack
        CALL, fib, 1,   // 33 - call fib function with 1 arg. from the stack
        ADD,            // 36 - since 2 fibs pushed their ret values on the stack, just add them
        RET,            // 37 - return from procedure
        // entrypoint - main function
        CONST, 0,       // 38
        GSTORE, 0xFE,   // 40 
        GLOAD, 0xFE,    // 42 
        CALL, fib, 1,   // 44 - call function: fib(n);
        PRINT,          // 47 - print result
        GLOAD, 0xFE,    // 48
        CONST, 1,       // 50
        ADD,            // 51
        GSTORE, 0xFE,   // 53
        GLOAD, 0xFE,    // 55   
        CONST, 30,      // 57 - numbers of loop
        LT,             // 58
        JMPT, 42,       // 60
        HALT            // 62
        };
    VM svm(program,38);
    // svm.showCode();
    svm.execute();
    // svm.showMemory(254,256);
    

    cout<<"END\n";
    return 0;
}