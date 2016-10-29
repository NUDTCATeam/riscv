#include"GlobalVar.h"
char *mem;    
int mem_size = 0x010000;    // 64KB
int reg_size = 32;         // the number of general register
int *registers;                     // pointer of general registers

unsigned long PC;         //PC register
unsigned int ins_buffer;   //instruction register

int IMM;                  // integer buffer
unsigned int UIMM;        // unsigned integer buffer