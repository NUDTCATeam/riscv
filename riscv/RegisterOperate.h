#ifndef _REGISTER_H_
#define _REGISTER_H_


#include"GlobalVar.h"
int get_int(unsigned long addr);
void put_int(unsigned long addr, int val);
unsigned int get_uint(unsigned long addr);
void put_uint(unsigned long addr, unsigned int val);


#endif