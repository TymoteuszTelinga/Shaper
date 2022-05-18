
#include <iostream>
#include <fstream>
#include "VM.hpp"

using std::cout;
using std::string;

int* loadProgram(const string& src)
{
    std::ifstream file(src);
    if (!file.is_open())
    {
        return nullptr;
    }

    int linesNum = 0;
    string s;
    while (getline(file,s))
    {
        linesNum++;
    }

    int* prog = new int[linesNum];
    file.clear();
    file.seekg(0,file.beg);
    for (size_t i = 0; i < linesNum; i++)
    {
        file>>prog[i];
    }
    file.close();

    return prog;
}

int main(int argc, char *argv[])
{
    cout<<"Hello\n";

    // int *program = loadProgram("fib.txt");

    // int x = 4;
    // int y = 10;
    // for (int i = x; i <= y; i++)
    // {
    //     cout<<i<<'\n';
    // }
    // return 0;

    // x: 0
    // y: 1
    // i: 2
    int program[] = {
        CONST_I, 4,
        CONST_I, 10, 
        LOAD, 0,     
        LOAD, 2,
        LOAD, 1,
        LE,
        JMPF, 20,
        LOAD, 2,
        PRINT_I,
        INC, 2,
        JMP, 6,
        HALT          
        };
    VM svm(program,0);
    svm.displayMode('d');
    // svm.showCode();
    svm.execute();
    // svm.showMemory(0,4);
    
    cout<<"END\n";
    return 0;
}

// int program[] = {
//     // int fib(n)
//     // if (n == 0) return 0;
//     LOAD, -3,       // 0 - load last function argument N
//     CONST_I, 0,       // 2 - put 0
//     EQ,             // 4 - check equality: N == 0
//     JMPF, 10,       // 5 - if they are NOT equal, goto 10
//     CONST_I, 0,       // 7 - otherwise put 0
//     RET,            // 9 - and return it
//     // if(n < 3) return 1;
//     LOAD, -3,       // 10 - load last function argument N
//     CONST_I, 3,       // 12 - put 3
//     LT,             // 14 - check if 3 is less than N
//     JMPF, 20,       // 15 - if 3 is NOT less than N, goto 20
//     CONST_I, 1,       // 17 - otherwise put 1
//     RET,            // 19 - and return it
//     // else return fib(n-1) + fib(n-2);
//     LOAD, -3,       // 20 - load last function argument N
//     CONST_I, 1,       // 22 - put 1
//     SUB_I,            // 24 - calculate: N-1, result is on the stack
//     CALL, fib, 1,   // 25 - call fib function with 1 arg. from the stack
//     LOAD, -3,       // 28 - load N again
//     CONST_I, 2,       // 30 - put 2
//     SUB_I,            // 32 - calculate: N-2, result is on the stack
//     CALL, fib, 1,   // 33 - call fib function with 1 arg. from the stack
//     ADD,            // 36 - since 2 fibs pushed their ret values on the stack, just add them
//     RET,            // 37 - return from procedure
//     // entrypoint - main function
//     CONST_I, 0,       // 38
//     GSTORE, 0xFE,   // 40 
//     GLOAD, 0xFE,    // 42 
//     CALL, fib, 1,   // 44 - call function: fib(n);
//     PRINT,          // 47 - print result
//     GLOAD, 0xFE,    // 48
//     CONST_I, 1,       // 50
//     ADD,            // 51
//     GSTORE, 0xFE,   // 53
//     GLOAD, 0xFE,    // 55   
//     CONST_I, 30,      // 57 - numbers of loop
//     LT,             // 58
//     JMPT, 42,       // 60
//     HALT            // 62
//     };