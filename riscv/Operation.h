#include "GlobalVar.h"

void ADDI(unsigned int rs1,unsigned int rd);

void SLTI(unsigned int rs1,unsigned int rd);

void SLTIU(unsigned int rs1,unsigned int rd);

void ANDI(unsigned int rs1,unsigned int rd);

void ORI(unsigned int rs1,unsigned int rd);

void XORI(unsigned int rs1,unsigned int rd);

void SLLI(unsigned int rs1,unsigned int rd);

void SRAI(unsigned int rs1,unsigned int rd);

void SRLI(unsigned int rs1,unsigned int rd);

void ADD(unsigned int rs1,unsigned int rs2,unsigned int rd);
void SUB(unsigned int rs1,unsigned int rs2,unsigned int rd);

void SLT(unsigned int rs1,unsigned int rs2,unsigned int rd);

void SLTU(unsigned int rs1,unsigned int rs2,unsigned int rd);

void AND(unsigned int rs1,unsigned int rs2,unsigned int rd);
void OR(unsigned int rs1,unsigned int rs2,unsigned int rd);
void XOR(unsigned int rs1,unsigned int rs2,unsigned int rd);

void SLL(unsigned int rs1,unsigned int rs2,unsigned int rd);
void SRL(unsigned int rs1,unsigned int rs2,unsigned int rd);

void SRA(unsigned int rs1,unsigned int rs2,unsigned int rd);

void LB(unsigned int rs1,unsigned int rd);

void LBU(unsigned int rs1,unsigned int rd);

void LH(unsigned int rs1,unsigned int rd);

void LHU(unsigned int rs1,unsigned int rd);

void LW(unsigned int rs1,unsigned int rd);

void SB(unsigned int rs1,unsigned int rs2);

void SBU(unsigned int rs1,unsigned int rs2);

void SH(unsigned int rs1,unsigned int rs2);

void SHU(unsigned int rs1,unsigned int rs2);

void SW(unsigned int rs1,unsigned int rs2);

void LUIOP(unsigned int rd);

void AUIPCOP(unsigned int rd);