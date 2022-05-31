#ifndef __MMU_H__
#define __MMU_H__

#include <vector>

class MMU
{
private:
    const int memSize = 0;
    const int offset = 0;
    struct Block
    {
        int adr;
        int length;

        Block(int _adr, int _length);
    };
    std::vector<Block> reserved;

public:
    
    MMU(int size, int off);
    ~MMU();

    int lock(int size);
    void free(int adr);

    void show() const;
};

#endif // __MMU_H__