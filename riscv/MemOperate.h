/**define the operate of memory
**/
#ifndef _MEMORY_H_
#define _MEMORY_H_
#include"GlobalVar.h"
#include"Operation.h"
//read and write a unsigned word
unsigned int read_mem_uword(unsigned long addr);
void write_mem_uword(unsigned long addr, unsigned int val);

int read_mem_word(long addr);
void write_mem_word(long addr, int val);

char read_mem_byte(long addr);
void write_mem_byte(long addr, char val);

unsigned char read_mem_ubyte(unsigned long addr);
void write_mem_ubyte(unsigned long addr, unsigned char val);

unsigned short read_mem_uhalfword(unsigned long addr);
void write_mem_uhalfword(unsigned long addr, unsigned short val);

short read_mem_halfword(long addr);
void write_mem_halfword(long addr, short val);



#endif