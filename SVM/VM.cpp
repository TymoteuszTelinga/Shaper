
#include "VM.hpp"
#include <iostream>

const int STACK_SIZE = 100;

#define asfloat *(float*)&
#define asint *(int*)&

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
    
    int x;
    for (;;)
    {
        int instrucion = next();
        switch (instrucion)
        {
        case ADD_I:
            {
                int b = pop();
                int a = pop();
                push(a+b);
            }
            break;
        case SUB_I:
            {
                int b = pop();
                int a = pop();
                push(a-b);
            }
            break;
        case MUL_I:
            {
                int b = pop();
                int a = pop();
                push(a*b);
            }
            break;
        case DIV_I:
            {
                int b = pop();
                int a = pop();
                push(a/b);
            }
            break;
        case MOD_I:
            {
                int b = pop();
                int a = pop();
                push(a%b);
            }
            break;
        case ADD_F:
            {
                x = pop();
                float b = asfloat x;
                x = pop();
                float a = asfloat x;
                float c = a+b;
                push(asint c);
            }
            break;
        case SUB_F:
            {
                x = pop();
                float b = asfloat x;
                x = pop();
                float a = asfloat x;
                float c = a-b;
                push(asint c);
            }
            break;
        case MUL_F:
            {
                x = pop();
                float b = asfloat x;
                x = pop();
                float a = asfloat x;
                float c = a*b;
                push(asint c);
            }
            break;
        case DIV_F:
            {
                x = pop();
                float b = asfloat x;
                x = pop();
                float a = asfloat x;
                float c = a/b;
                push(asint c);
            }
            break;
        case ADD_L:
            {
                long long b = popL();
                long long a = popL();
                pushL(a+b);
            }
            break;
        case SUB_L:
            {
                long long b = popL();
                long long a = popL();
                pushL(a-b);
            }
            break;
        case MUL_L:
            {
                long long b = popL();
                long long a = popL();
                pushL(a*b);
            }
            break;
        case DIV_L:
            {
                long long b = popL();
                long long a = popL();
                pushL(a/b);
            }
            break;
        case MOD_L:
            {
                long long b = popL();
                long long a = popL();
                pushL(a%b);
            }
            break;
        case I2S:
            {
                short s = pop();
                push(s);
            }
            break;
        case I2C:
            {
                char c = pop();
                push (c);
            }
            break;
        case I2F:
            {
                x = pop();
                float f = x; // value cast to float
                push(asint f);
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
        case CONST_I:
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
        case PRINT_I:
            {
                std::cout<<pop()<<'\n';
            }
            break;
        case PRINT_F:
            {
                x = pop();
                std::cout<<asfloat x<<'\n';
            }
            break;
        case PRINT_L:
            {
                std::cout<<popL()<<'\n';
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

void VM::displayMode(const char c) const
{
    switch (c)
    {
    case 'h':
        std::cout<<std::hex;
        break;
    case 'd':
        std::cout<<std::dec;
        break;
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

void VM::pushL(long long value)
{
    push(value);
    push((value>>32));
}

int VM::pop()
{
    return stack[sp--];
}

long long VM::popL()
{
    long long x = pop();
    // long long y = pop(); 
    return (x<<32) | (pop() & 0xffffffff);
}

int VM::next()
{
    return code[pc++];
}
