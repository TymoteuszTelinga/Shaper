
#include "VM.hpp"
#include <iostream>

const int STACK_SIZE = 100;

#define asfloat *(float*)&
#define asint *(int*)&
#define asdouble *(double*)&
#define aslong *(long long*)&

VM::VM(const int* code, const int PC, const unsigned int memSize):code(code), mmu(memSize,0)
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
    long long X;
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
        case ADD_D:
            {
                X = popL();
                double b = asdouble X;
                X = popL();
                double a = asdouble X;
                double c = a+b;
                pushL(aslong c);
            }
            break;
        case SUB_D:
            {
                X = popL();
                double b = asdouble X;
                X = popL();
                double a = asdouble X;
                double c = a-b;
                pushL(aslong c);
            }
            break;
        case MUL_D:
            {
                X = popL();
                double b = asdouble X;
                X = popL();
                double a = asdouble X;
                double c = a*b;
                pushL(aslong c);
            }
            break;
        case DIV_D:
            {
                X = popL();
                double b = asdouble X;
                X = popL();
                double a = asdouble X;
                double c = a/b;
                pushL(aslong c);
            }
            break;
        case I2C:
            {
                char c = pop();
                push (c);
            }
            break;
        case I2S:
            {
                short s = pop();
                push(s);
            }
            break;
        case I2F:
            {
                x = pop();
                float f = x; // value cast to float
                push(asint f);
            }
            break;
        case I2L:
            {
                x = pop();
                pushL(x);
            }
            break;
        case I2D:
            {
                x = pop();
                double d = x;
                pushL(aslong d);
            }
            break;
        case F2I:
            {
                x = pop();
                push(asfloat x);
            }
            break;
        case F2L:
            {
                x = pop();
                pushL(asfloat x);
            }
            break;
        case F2D:
            {
                x = pop();
                double d = asfloat x;
                pushL( aslong d);
            }
            break;
        case L2I:
            {
                X = popL();
                push(X);
            }
            break;
        case L2F:
            {
                X = popL();
                float f = X;
                push(asint f);
            }
            break;
        case L2D:
            {
                X = popL();
                double d = X;
                pushL(aslong d);
            }
            break;
        case D2I:
            {
                X = popL();
                push(asdouble X);
            }
            break;
        case D2F:
            {
                X = popL();
                float f = asdouble X;
                push(asint f);
            }
            break;
        case D2L:
            {
                X = popL();
                pushL(asdouble X);
            }
            break;
        case INC:
            {
                int offset = next();
                stack[fp+offset]++;
            }
            break;
        case DEC:
            {
                int offset = next();
                stack[fp+offset]--;
            }
            break;
        case LT:
            {
                int b = pop();
                int a = pop();
                push(a<b);
            }
            break;
        case GT:
            {
                int b = pop();
                int a = pop();
                push(a>b);
            }
            break;
        case LE:
            {
                int b = pop();
                int a = pop();
                push(a<=b);
            }
            break;
        case GE:
            {
                int b = pop();
                int a = pop();
                push(a>=b);
            }
            break;
        case EQ:
            {
                int b = pop();
                int a = pop();
                push(a==b);
            }
            break;
        case AND:
            {
                int b = pop();
                int a = pop();
                push(a&&b);
            }
            break;
        case OR:
            {
                int b = pop();
                int a = pop();
                push(a||b);
            }
            break;
        case NEG:
            {
                int a = pop();
                push(!(bool)a);
            }
            break;
        case JMP:
            {
                pc += next();
            }
            break;
        case JMPT:
            {
                int offset = next();
                if (pop())
                {
                    pc += offset;
                }
            }
            break;
        case JMPF:
            {
                int offset = next();
                if (!pop())
                {
                    pc += offset;
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
        case ALOAD_I:
            {
                int index = pop();
                int addr = pop();
                push(memory[addr+index]);
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
        case ASTORE_I:
            {
                int val = pop();
                int index = pop();
                int addr = pop();
                memory[addr+index] = val;
            }
            break;
        case PRINT_C:
            {
                char c = pop();
                std::cout<<c;
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
        case PRINT_D:
            {
                X = popL();
                std::cout<<asdouble X<<'\n';
            }
            break;
        case POP:
            {
                pop();
            }
            break;
        case POP2:
            {
                popL();
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
        case DUMMY:
            break;
        case NEWARR:
            {
                int size = pop();
                int adr = mmu.lock(size);
                if (adr < 0)
                {
                    std::cerr<<"not enough memory\n";
                    bDied = true;
                }
                push(adr);
            }
            break;
        case LENGTH:
            {
                push(mmu.size(pop()));
            }
            break;
        case FREE:
            {
                mmu.free(pop());
            }
            break;
        case DISPLAY:
            {
                graphic.Display();
            }
            break;
        case CLEAR:
            {
                graphic.Clear();
            }
            break;
        case RECT:
            {
                int color  = pop();
                int height = pop();
                int width  = pop();
                int y      = pop();
                int x      = pop();

                graphic.DrawRect(x,y,width,height,color);
            }
            break;
        case ELIPSE:
            {
                int color = pop();
                int R2    = pop();
                int R1    = pop();
                int y     = pop();
                int x     = pop();

                graphic.DrawEpise(x,y,R1,R2,color);
            }
            break;
        case LINE:
            {
                int color = pop();
                int y2    = pop();
                int x2    = pop();
                int y1    = pop();
                int x1    = pop();

                graphic.DrawLine(x1,y1,x2,y2,color);
            }
            break;
        case TRIANGLE:
            {
                int color = pop();
                int y3    = pop();
                int x3    = pop();
                int y2    = pop();
                int x2    = pop();
                int y1    = pop();
                int x1    = pop();

                graphic.DrawTriangle(x1,y1,x2,y2,x3,y3,color);
            }
            break;
        default:
            {
                std::cerr<<"PC: "<<pc<<" unknown instruction: "<<instrucion<<'\n';
            }
            return;
        }

        // showStack();
        // std::cout<<"PC: "<<pc<<std::endl;
        if (graphic.isOpen())
        {
            graphic.ProcedEvents();
        }
        else
        {
            bDied = true;
            std::cerr<<"window closed\n";
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
    push(((int*)&value)[0]);
    push(((int*)&value)[1]);
}

int VM::pop()
{
    return stack[sp--];
}

long long VM::popL()
{
    long long x;
    ((int*)&x)[1] = pop();
    ((int*)&x)[0] = pop();
    return x;
}

int VM::next()
{
    return code[pc++];
}
