#include"RegisterOperate.h"

int get_int(unsigned long addr)
{
	return *((int *)(registers + addr));
}
void put_int(unsigned long addr, int val)
{
	*((int*)(registers+addr)) = val;
}
unsigned int get_uint(unsigned long addr)
{
	return *((unsigned int*)(registers + addr));
}
void put_uint(unsigned long addr, unsigned int val)
{
	*((unsigned int *)(registers + addr)) = val;
}