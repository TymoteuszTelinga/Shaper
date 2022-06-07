
#include <iostream>
#include <fstream>
#include "VM.hpp"

using std::cout;
using std::string;

void loadProgram(const string& src)
{
    std::ifstream file("out.txt", std::ios::binary);
    if (file.is_open())
    {
        file.seekg (0, std::ios::end);
        int length = file.tellg();
        file.seekg (0, std::ios::beg);
        char *buffer = new char[length];
        file.read(buffer,length);
        for (size_t i = 0; i < length/4; i++)
        {
            std::cout<<*(((int*)buffer)+i)<<" | ";
        }
        file.close();
    }
}

int main(int argc, char *argv[])
{
    cout<<"Hello\n";

    int program[] = {
            CONST_I, 200,
            CONST_I, 50,
            CONST_I, 15,
            CONST_I, 10,
            CONST_I, (int)0xFF0000FF,
            CONST_I, 1,// goright = true;
            CONST_I, 1,// go up = true;
            CONST_I, 0,// if bounce == true;
                // horizontal movement
                LOAD, 5,
                JMPT, 4,
                    DEC, 0,
                    JMP, 2,
                INC, 0,
                // vertical movement
                LOAD, 6,
                JMPT, 4,
                    DEC, 1,
                    JMP, 2,
                INC, 1,
                // horizontal bounce
                LOAD, 0,
                LOAD, 2,
                ADD_I,
                CONST_I, 400,
                LT,
                JMPT, 9,
                    LOAD, 5,
                    NEG,
                    STORE, 5,
                    CONST_I, 1,
                    STORE, 7,
                LOAD, 0,
                LOAD, 2,
                SUB_I,
                CONST_I, 0,
                GT,
                JMPT, 9,
                    LOAD, 5,
                    NEG,
                    STORE, 5,
                    CONST_I, 1,
                    STORE, 7,
                //vertical bounce
                LOAD, 1,
                LOAD, 3,
                ADD_I,
                CONST_I, 400,
                LT,
                JMPT, 9,
                    LOAD, 6,
                    NEG,
                    STORE, 6,
                    CONST_I, 1,
                    STORE, 7,
                LOAD, 1,
                LOAD, 3,
                SUB_I,
                CONST_I, 0,
                GT,
                JMPT, 9,
                    LOAD, 6,
                    NEG,
                    STORE, 6,
                    CONST_I, 1,
                    STORE, 7,
                LOAD, 7,
                JMPF, 10,
                    RANDOM,
                    CONST_I, 523,
                    MUL_I,
                    STORE, 4,
                    CONST_I, 0,
                    STORE, 7, 

                // CLEAR,
                DUMMY,
                LOAD, 0,
                LOAD, 1,
                LOAD, 2,
                LOAD, 3,
                LOAD, 4,
                ELIPSE,
                DISPLAY,
            JMP, -125,
            HALT,
        };
    VM svm(program,0);

    // svm.displayMode('h');
    // svm.showCode(53);
    svm.execute();
    // svm.showMemory(0,4);
    
    cout<<"END\n";
    return 0;
}



    // int program[] = {
    //         // int fib(n)
    //         // if (n == 0) return 0;
    //         LOAD, -3,       // 0 - load last function argument N
    //         CONST_I, 0,     // 2 - put 0
    //         EQ,             // 4 - check equality: N == 0
    //         JMPF, 3,        // 5 - if they are NOT equal, goto 10
    //         CONST_I, 0,     // 7 - otherwise put 0
    //         RET,            // 9 - and return it
    //         // if(n < 3) return 1;
    //         LOAD, -3,       // 10 - load last function argument N
    //         CONST_I, 3,     // 12 - put 3
    //         LT,             // 14 - check if 3 is less than N
    //         JMPF, 3,        // 15 - if 3 is NOT less than N, goto 20
    //         CONST_I, 1,     // 17 - otherwise put 1
    //         RET,            // 19 - and return it
    //         // else return fib(n-1) + fib(n-2);
    //         LOAD, -3,       // 20 - load last function argument N
    //         CONST_I, 1,     // 22 - put 1
    //         SUB_I,          // 24 - calculate: N-1, result is on the stack
    //         CALL, 0, 1,     // 25 - call fib function with 1 arg. from the stack
    //         LOAD, -3,       // 28 - load N again
    //         CONST_I, 2,     // 30 - put 2
    //         SUB_I,          // 32 - calculate: N-2, result is on the stack
    //         CALL, 0, 1,     // 33 - call fib function with 1 arg. from the stack
    //         ADD_I,          // 36 - since 2 fibs pushed their ret values on the stack, just add them
    //         RET,            // 37 - return from procedure
    //         // entrypoint - main function
    //         CONST_I, 0,     // 38
    //         GSTORE, 0xFE,   // 40 
    //         GLOAD, 0xFE,    // 42 
    //         CALL, 0, 1,     // 44 - call function: fib(n);
    //         PRINT_I,        // 47 - print result
    //         GLOAD, 0xFE,    // 48
    //         CONST_I, 1,     // 50
    //         ADD_I,          // 51
    //         GSTORE, 0xFE,   // 53
    //         GLOAD, 0xFE,    // 55   
    //         CONST_I, 30,    // 57 - numbers of loop
    //         LT,             // 58
    //         JMPT, -20,      // 60
    //         HALT            // 62      
    //     };