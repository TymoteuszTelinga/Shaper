
#include "MMU.hpp"
#include <algorithm>
#include <iostream>

MMU::Block::Block(int _adr, int _length)
{
    adr = _adr;
    length = _length;
}

MMU::MMU(int size, int off): memSize(size), offset(off)
{
    
}

MMU::~MMU()
{
    
}

int MMU::lock(int size)
{
    int adres = offset;
    for (const Block &block : reserved)
    {
        if ( adres + size > block.adr)
        {
            adres = block.adr + block.length;
        }
    }

    if (adres + size > memSize)
    {
        return -1;
    }
    // TODO
    // poprawic złożonośc / wydajnośc
    reserved.push_back(Block(adres,size));
    sort(reserved.begin(),reserved.end(),[] (const Block& A, const Block& B) { return A.adr < B.adr; });

    return adres;
}

void MMU::free(int adr)
{
    for (auto i = reserved.begin(); i < reserved.end(); i++)
    {
        if ( (*i).adr == adr)
        {
            reserved.erase(i);
            break;
        }
    }
}

int MMU::size(int adr) const
{
    for (size_t i = 0; i < reserved.size(); i++)
    {
        if (reserved[i].adr == adr)
        {
            return reserved[i].length;
        }
    }
    return 0;
}

void MMU::show() const
{
    for (size_t i = 0; i < reserved.size(); i++)
    {
        std::cout<<reserved[i].adr<<" "<<reserved[i].length<<'\n';
    }
}
