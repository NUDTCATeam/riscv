#ifndef _COMMON_H_
#define _COMMON_H_

#define R_type 0
#define I_type 1
#define S_type 2
#define SB_type 3
#define U_type 4
#define UJ_type 5

#define OP_IMM 0x13
#define OP 0x33
#define LUI 0x37
#define AUIPC 0x17
#define JAL 0x6F
#define JALR 0x67
#define BRANCH 0x63
#define LOAD 0x03
#define STORE 0x23
//#define MISC_MEM 0x2B
//#define SYSTEM 0x2F

/***OP_IMM***/
#define OP_IMM_ADDI 0x00
#define OP_IMM_SLTI 0x02
#define OP_IMM_SLTIU 0x03
#define OP_IMM_ANDI 0x07
#define OP_IMM_ORI 0x06
#define OP_IMM_XORI 0x04
#define OP_IMM_SLLI 0x01
#define OP_IMM_SR 0x05           /**SRLI and SRAI shared the same OP_IMM_SR and can distinguish by imm[11:5]**/

/****OP,funct7=0****/
#define OP_ALU 0x00    /**ADD and SUB shared the same OP_ALU and can distinguish by imm[11:5]**/
#define OP_SLT 0x02
#define OP_SLTU 0x03
#define OP_AND 0x07
#define OP_OR 0x06
#define OP_XOR 0x04
#define OP_SLL 0x01
#define OP_SHIFT 0x05    /**SRL and SRA shared the same OP_SHIFT and can distinguish by imm[11:5]**/

/****OP,funct7=0x01****/
#define OP_MUL 0x00
#define OP_MULH 0x01
#define OP_MULHU 0x03
#define OP_MULSU 0x02
#define OP_DIV 0x04
#define OP_DIVU 0x05
#define OP_REM 0x06
#define OP_REMU 0x07

/***BRANCH*****/
#define BRANCH_BEQ 0x00
#define BRANCH_BNE 0x01
#define BRANCH_BLT 0x04
#define BRANCH_BLTU 0x06
#define BRANCH_BGE 0x05
#define BRANCH_BGEU 0x07

/***LOAD***/
#define LOAD_LB 0x00
#define LOAD_LBU 0x04
#define LOAD_LH 0x01
#define LOAD_LHU 0x05
#define LOAD_LW 0x02

/**STORE**/
#define STORE_SB 0x00
//#define STORE_SBU 0x01
#define STORE_SH 0x01
//#define STORE_SHU 0x03
#define STORE_SW 0x02

/***MISC_MEM***/
#define MISC_MEM_FENCE 0x00
#define MISC_MEM_FENCEI 0x07

/***SYSTEM***/
#define SYSTEM_CSRRW 0x00
#define SYSTEM_CSRRS 0x01
#define SYSTEM_CSRRC 0x02
#define SYSTEM_CSRRWI 0x03
#define SYSTEM_CSRRSI 0x04
#define SYSTEM_CSRRCI 0x05
#define SYSTEM_PRIV 0x06     /**ECALL and EBREAK share this funct3 and distinguished by funct12**/ 

#endif