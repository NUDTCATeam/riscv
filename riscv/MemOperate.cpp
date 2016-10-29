#include "MemOperate.h"
//读写一个无符号字
//读写一个无符号字
unsigned int read_mem_uword(unsigned long addr)
{
    return *((unsigned int*)(mem + addr));
}
void write_mem_uword(unsigned long addr, unsigned int word)
{
    *((unsigned int *)(mem + addr)) = word;
}

//读写一个有符号字
int read_mem_word(long addr)
{
    return *((int*)(mem + addr));
}
void write_mem_word(long addr, int val)
{
    *((int *)(mem + addr)) = val;
}

//读写一个无符号字符
unsigned char read_mem_ubyte(unsigned long addr)
{
    return *((unsigned char*)(mem + addr));
}
void write_mem_ubyte(unsigned long addr, unsigned char val)
{
    *((unsigned char *)(mem + addr)) = val;
}

//读写一个有符号字符
char read_mem_byte(long addr)
{
    
    return *((char*)(mem + addr));
}
void write_mem_byte(long addr, char val)
{
    *((char *)(mem + addr)) = val;
}

//读写一个无符号半字
unsigned short read_mem_uhalfword(unsigned long addr)
{
    return *((unsigned short*)(mem + addr));
}
void write_mem_uhalfword(unsigned long addr, unsigned short val)
{
    *((unsigned short *)(mem + addr)) = val;
}
//读写一个有符号半字
short read_mem_halfword(long addr)
{
    return *((unsigned short*)(mem + addr));
}
void write_mem_halfword(long addr, short val)
{
    *((short *)(mem + addr)) = val;
}

