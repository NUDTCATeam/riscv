#include"Operation.h"
#include"RegisterOperate.h"
#include"MemOperate.h"
#include<stdio.h>
void ADDI(unsigned int rs1,unsigned int rd)
{
	int oprand1 = get_int(rs1);
	int result = oprand1+IMM;
	put_int(rd,result);
}
void SLTI(unsigned int rs1,unsigned int rd)
{
	int oprand1 = get_int(rs1);
	if(oprand1<IMM)
		put_int(rd,1);
	else
		put_int(rd,0);
}

void SLTIU(unsigned int rs1,unsigned int rd)
{
	unsigned int oprand1 = get_uint(rs1);
	if(oprand1<UIMM)
		put_int(rd,1);
	else
		put_int(rd,0);
}

void ANDI(unsigned int rs1,unsigned int rd)
{
	int result;
    int oprand1 = get_int(rs1);
	result = oprand1 & IMM;
	put_int(rd,result);
}

void ORI(unsigned int rs1,unsigned int rd)
{
	int result;
    int oprand1 = get_int(rs1);
	result = oprand1 | IMM;
	put_int(rd,result);
}

void XORI(unsigned int rs1,unsigned int rd)
{
	int result;
    int oprand1 = get_int(rs1);
	result = oprand1 ^ IMM;
	put_int(rd,result);
}

void SLLI(unsigned int rs1,unsigned int rd)
{
	int result,shift,oprand1;
	shift = IMM & 0x1F;              /***lower 5bits***/
    oprand1 = get_int(rs1);
	result = oprand1<<shift;
	put_int(rd,result);
}

void SRAI(unsigned int rs1,unsigned int rd)
{
	int result,shift,oprand1;
	shift = IMM & 0x1F;              /***lower 5bits***/
    oprand1 = get_int(rs1);
	result = oprand1>>shift;
	put_int(rd,result);
}

void SRLI(unsigned int rs1,unsigned int rd)
{
	int result,shift;
	unsigned int oprand1;
	shift = IMM & 0x1F;              /***lower 5bits***/
    oprand1 = get_uint(rs1);
	result = oprand1>>shift;
	put_int(rd,result);
}

void ADD(unsigned int rs1,unsigned int rs2,unsigned int rd)
{
    int oprand1 = get_int(rs1);
    int oprand2 = get_int(rs2);
    int result = oprand1+oprand2;
    put_int(rd,result);
}

void SUB(unsigned int rs1,unsigned int rs2,unsigned int rd)
{
    int oprand1 = get_int(rs1);
    int oprand2 = get_int(rs2);
    int result = oprand1-oprand2;
    put_int(rd,result);
}

void SLT(unsigned int rs1,unsigned int rs2,unsigned int rd)
{
    int oprand1,oprand2,result;
    if(rs1!=0 && rs2!=0)
    {
        oprand1 = get_int(rs1);
        oprand2 = get_int(rs2);
        result=(oprand1<oprand2)?1:0;
    }
    else if(rs1==0 && rs2!=0)
    {
        oprand1 = 0;
        oprand2 = get_int(rs2);
        printf("op1:%d,op2=%d\n",oprand1,oprand2);
        result=(oprand2!=0)?1:0;
    }
    else if(rs1!=0 && rs2==0)
    {
        oprand1 = get_int(rs1);
        oprand2 = 0;
        printf("op1:%d,op2=%d\n",oprand1,oprand2);
        result=(oprand1!=0)?1:0;
    }
    put_int(rd,result);
}

void SLTU(unsigned int rs1,unsigned int rs2,unsigned int rd)
{
    int oprand1,oprand2,result;
    if(rs1!=0 && rs2!=0)
    {
        oprand1 = get_uint(rs1);
        oprand2 = get_uint(rs2);
        result=(oprand1<oprand2)?1:0;
    }
    else if(rs1==0 && rs2!=0)
    {
        oprand1 = 0;
        oprand2 = get_uint(rs2);
        printf("op1:%d,op2=%d\n",oprand1,oprand2);
        result=(oprand2!=0)?1:0;
    }
    else if(rs1!=0 && rs2==0)
    {
        oprand1 = get_uint(rs1);
        oprand2 = 0;
        printf("op1:%d,op2=%d\n",oprand1,oprand2);
        result=(oprand1!=0)?1:0;
    }
    put_int(rd,result);
}

void AND(unsigned int rs1,unsigned int rs2,unsigned int rd)
{
    int oprand1 = get_int(rs1);
    int oprand2 = get_int(rs2);
    int result = oprand1&oprand2;
    put_int(rd,result);
}

void OR(unsigned int rs1,unsigned int rs2,unsigned int rd)
{
    int oprand1 = get_int(rs1);
    int oprand2 = get_int(rs2);
    int result = oprand1|oprand2;
    put_int(rd,result);
}

void XOR(unsigned int rs1,unsigned int rs2,unsigned int rd)
{
    int oprand1 = get_int(rs1);
    int oprand2 = get_int(rs2);
    int result = oprand1^oprand2;
    put_int(rd,result);
}
void SLL(unsigned int rs1,unsigned int rs2,unsigned int rd)
{
    int oprand1 = get_int(rs1);//操作数
    int oprand2 = get_int(rs2)& 0x1f;//移位次数:rs2的低五位
    int result=oprand1<<oprand2;
    put_int(rd,result);
}
void SRL(unsigned int rs1,unsigned int rs2,unsigned int rd)
{
    unsigned int oprand1 = get_int(rs1);//操作数
    unsigned int oprand2 = get_int(rs2)& 0x1f;//移位次数:rs2的低五位
    unsigned int result=oprand1>>oprand2;
    put_uint(rd,result);
}

void SRA(unsigned int rs1,unsigned int rs2,unsigned int rd)//c语言中的>>对应算术右移
{
    int oprand1 = get_int(rs1);//操作数
    int oprand2 = get_int(rs2)& 0x1f;//移位次数:rs2的低五位
    int result=oprand1>>oprand2;
    put_int(rd,result);
}

void LB(unsigned int rs1,unsigned int rd)
{
    char oprand;
    int oprand_sign_extend;
	int MSB;
    unsigned int addr = get_int(rs1) + (unsigned int)IMM;
    oprand = read_mem_byte(addr);
    MSB = (oprand>>7) & 0x01;
    //sign_extend
    if(MSB==1)
    {
        oprand_sign_extend = (int)oprand | 0xffffff00;
    }
    else
    {
        oprand_sign_extend = (int)oprand & 0x000000ff;
    }
    put_int(rd,oprand_sign_extend);
}

void LBU(unsigned int rs1, unsigned int rd)
{
    unsigned char uoprand;
    int uoprand_zero_extend;
    unsigned int addr = get_int(rs1) + (unsigned int)IMM;
    uoprand = read_mem_ubyte(addr);
    uoprand_zero_extend = (int)uoprand & 0xff; //zero_extend
    put_int(rd, uoprand_zero_extend);
}

void LH(unsigned int rs1,unsigned int rd)
{
    short oprand;
    int oprand_sign_extend;
	int MSB;
    unsigned int addr = get_int(rs1) + (unsigned int)IMM;
    oprand = read_mem_halfword(addr);
    //sign-extend
    MSB = (oprand>>15) & 0x01;
    if(MSB==1)
    {
        oprand_sign_extend = (int)oprand | 0xffff0000;
    }
    else
    {
        oprand_sign_extend = (int)oprand & 0x0000ffff;
    }
    put_int(rd, oprand_sign_extend);
}

void LHU(unsigned int rs1,unsigned int rd)
{
    unsigned short uoprand;
    int uoprand_zero_extend;
    unsigned int addr = get_int(rs1) + (unsigned int)IMM;
    uoprand = read_mem_uhalfword(addr);
    uoprand_zero_extend = (int)uoprand & 0xffff; //zero_extend
    put_int(rd, uoprand_zero_extend);
}

void LW(unsigned int rs1,unsigned int rd)
{
    int oprand;
    unsigned int addr = get_int(rs1) + (unsigned int)IMM;
    oprand = read_mem_word(addr);
    put_int(rd, oprand);
}

void SB(unsigned int rs1,unsigned int rs2)
{
    char oprand;
    unsigned int addr = get_int(rs1) + (unsigned int)IMM;
    oprand = get_int(rs2);
    write_mem_byte(addr, oprand);
}

void SBU(unsigned int rs1,unsigned int rs2)
{
    unsigned char oprand;
    unsigned int addr = get_int(rs1) + (unsigned int)IMM;
    oprand = get_int(rs2);
    write_mem_ubyte(addr, oprand);
}

void SH(unsigned int rs1,unsigned int rs2)
{
    short oprand;
    unsigned int addr = get_int(rs1) + (unsigned int)IMM;
    oprand = get_int(rs2);
    write_mem_halfword(addr, oprand);
}

void SHU(unsigned int rs1,unsigned int rs2)
{
    unsigned short oprand;
    unsigned int addr = get_int(rs1) + (unsigned int)IMM;
    oprand = get_int(rs2);
    write_mem_uhalfword(addr, oprand);
}

void SW(unsigned int rs1,unsigned int rs2)
{
    int oprand;
    unsigned int addr = get_int(rs1) + (unsigned int)IMM;
    oprand = get_int(rs2);
    write_mem_word(addr, oprand);
}

void LUIOP(unsigned int rd)
{
    int oprand;
    oprand = (IMM<<12) & 0xfffff000;
    put_int(rd,oprand);
}

void AUIPCOP(unsigned int rd)
{
    unsigned int offset;
    int oprand;
    offset = (IMM<<12) & 0xfffff000;
    oprand = get_int(PC) + offset;
    put_int(rd, oprand);
}