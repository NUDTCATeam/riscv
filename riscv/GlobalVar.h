#ifndef _GLOBAL_H_
#define _GLOBAL_H_

extern char *mem;                 //memory pointer
extern int mem_size;    // 64KB
extern int reg_size;         // the number of general register
extern int *registers;                     // pointer of general registers

extern unsigned long PC;         //PC register
extern unsigned int ins_buffer;   //instruction register

extern int IMM;                  // integer buffer
extern unsigned int UIMM;        // unsigned integer buffer

#endif
