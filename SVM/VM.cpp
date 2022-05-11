
#include "VM.hpp"
#include <iostream>

const int STACK_SIZE = 100;

VM::VM(const int* code, const int PC, const unsigned int memSize):code(code)
{
    memory = new int[memSize];
    stack = new int[STACK_SIZE];
    pc = PC;
    fp = 0;
    sp = -1;
}

VM::~VM()
{
    delete [] code;
    delete [] stack;
    delete [] memory;
}

void VM::showCode() const
{
    for (size_t i = 0; i < 10; i++)
    {
        std::cout<<i<<": "<<code[i]<<'\n';
    }
    std::cout<<"PC: "<<pc<<'\n';
}

void VM::showMemory(unsigned int start, unsigned int end) const
{
    for (unsigned int i = start; i < end; i++)
    {
        std::cout<<memory[i]<<':';
    }
    std::cout<<'\n';
}

void VM::showStack() const
{
    std::cout<<'|';
    for (int i = 0; i <= sp; i++)
    {
        std::cout<<stack[i]<<"|";
    }
    std::cout<<'\n';
}

void VM::execute()
{
    if(!code)
    {
        return;
    }
    
    for (;;)
    {
        int instrucion = next();
        switch (instrucion)
        {
        case ADD:
            {
                int b = pop();
                int a = pop();
                push(a+b);
            }
            break;
        case SUB:
            {
                int b = pop();
                int a = pop();
                push(a-b);
            }
            break;
        case MUL:
            {
                int b = pop();
                int a = pop();
                push(a*b);
            }
            break;
        case DIV:
            {
                int b = pop();
                int a = pop();
                push(a/b);
            }
            break;
        case LT:
            {
                int b = pop();
                int a = pop();
                push(a<b);
            }
            break;
        case EQ:
            {
                int b = pop();
                int a = pop();
                push(a==b);
            }
            break;
        case JMP:
            {
                pc = next();
            }
            break;
        case JMPT:
            {
                int addr = next();
                if (pop())
                {
                    pc = addr;
                }
            }
            break;
        case JMPF:
            {
                int addr = next();
                if (!pop())
                {
                    pc = addr;
                }
            }
            break;
        case CONST:
            {
                push(next());
            }
            break;
        case LOAD:
            {
                int offset = next();
                push(stack[fp+offset]);
            }
            break;
        case GLOAD:
            {
                int addr = next();
                push(memory[addr]);
            }
            break;
        case STORE:
            {
                int offset = next();
                int v = pop();
                stack[fp+offset] = v;
            }
            break;
        case GSTORE:
            {
                int addr = next();
                int v = pop();
                memory[addr] = v;
            }
            break;
        case PRINT:
            {
                std::cout<<pop()<<'\n';
            }
            break;
        case HALT:
            return;
        case CALL:
            {
                int addr = next();
                int argc = next();
                push(argc);
                push(fp);
                push(pc);
                fp = sp;
                pc = addr;
            }
            break;
        case RET:
            {
                int rval = pop();
                sp = fp;
                pc = pop();
                fp = pop();
                sp -= pop();
                push(rval);
            }
            break;
        default:
            {
                std::cerr<<"PC: "<<pc<<" unknown instruction: "<<instrucion<<'\n';
            }
            return;
        }

        if (bDied)
        {
            return;
        }
    }
}

void VM::push(int value)
{
    if (sp >= STACK_SIZE)
    {
        std::cerr<<"stack overflow\n";
        bDied = true;
        return;
    }
    
    stack[++sp] = value;
}

int VM::pop()
{
    return stack[sp--];
}

int VM::next()
{
    return code[pc++];
}
