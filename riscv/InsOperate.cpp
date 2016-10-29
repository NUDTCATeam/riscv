#include"InsOperate.h"

unsigned int OPCode;
unsigned int rs1;
unsigned int rs2;
unsigned int rd;
unsigned int funct3;
unsigned int funct7;
unsigned int imm_12;
unsigned int imm_20;

unsigned int signedExtend(unsigned int val,int bit)
{
	//sign_extend
	int MSB = (val>>(bit-1))&0x01;
	if(bit == 12){
        if(MSB==1)
        {
            val = val | 0xfffff000;
        }
        else
        {
            val = val & 0x00000fff;
        }
    }else if(bit == 20){
        if(MSB ==1)
        {
            val = val | 0xfff00000;
        }
        else{
            val = val & 0x000fffff;
        }
    }
	
	return val;
}

void decode_ins_format(int i_type)
{
	if(i_type == I_type)
	{
		rd = (ins_buffer>>7) & 0x1F;
		funct3 = (ins_buffer>>12) & 0x07;
		rs1 = (ins_buffer>>15) & 0x1f;
		imm_12 = (ins_buffer>>20) & 0xfff;
	}
	else if(i_type == R_type)
    {
        rd = (ins_buffer>>7) & 0x1F;
        funct3 = (ins_buffer>>12) & 0x07;
        rs1 = (ins_buffer>>15) & 0x1f;
        rs2 = (ins_buffer>>20) & 0x1f;
        funct7=(ins_buffer>>25) & 0x7f;
    }
	 if(i_type == S_type)
    {
        int imm1,imm2;
        funct3 = (ins_buffer>>12) & 0x07;
        rs1 = (ins_buffer>>15) & 0x1f;
        rs2 = (ins_buffer>>20) & 0x1f;
        imm1 = (ins_buffer>>7) & 0x1f;
        imm2 = (ins_buffer>>25) & 0x7f;
        imm_12 = (imm2<<5) + imm1;
    }
    
    if(i_type == U_type)
    {
        rd = (ins_buffer>>7) & 0x1f;
        imm_20 = (ins_buffer>>12) & 0xfffff;
    }
}
int loadInstoMemory()
{
	FILE *pFile=fopen("/Users/Alala/Projects/riscv1/riscv/ins.txt","r");
	unsigned int ins;
	int ins_number=0;
	unsigned int addr = 0x0100;

    if (NULL == pFile)
    {
       return 0;       
    }
	while(!feof(pFile))
	{
		fscanf(pFile,"%x",&ins);	     //read a instruction and write memory
		ins_number++;
		//write to memory form Address 0x0100
		write_mem_uword(addr,ins);
		addr = addr+4;
	}
	return ins_number;
}

int fetchInstruction()
{
	 /***fetch ins by PC to ins_buffer****/
	ins_buffer = read_mem_uword(PC);
	printf("%x\n",ins_buffer);
	return 0;

}

int decodeInstruction()
{
	int i_type;
	int result;
	OPCode = ins_buffer & 0x7f;

	switch(OPCode)
	{
	case OP_IMM:
		i_type = I_type;
		decode_ins_format(i_type);
		switch(funct3)
		{
		case OP_IMM_SLLI:
			IMM = (int)signedExtend(imm_12,12);
			put_int(rs1,0x3);
			SLLI(rs1,rd);
			result = get_int(rd);
			printf("%x\n",result);
			break;
		case OP_IMM_ADDI:
			IMM = (int)signedExtend(imm_12,12);
			put_int(rs1,0x3);
			ADDI(rs1,rd);
			result = get_int(rd);
			printf("%x\n",result);
			break;
		case OP_IMM_SLTI:
			IMM = (int)signedExtend(imm_12,12);
			put_int(rs1,0x3);
			SLTI(rs1,rd);
			result = get_int(rd);
			printf("%x\n",result);
			break;
		case OP_IMM_SLTIU:
			UIMM = signedExtend(imm_12,12);
			put_int(rs1,0xFFFF0000);
			SLTIU(rs1,rd);
			result = get_int(rd);
			printf("%x\n",result);
			break;
		case OP_IMM_ANDI:
            IMM = (int)signedExtend(imm_12,12);
			put_int(rs1,0x25);
			ANDI(rs1,rd);
			result = get_int(rd);
	        printf("%x\n",result);
			break;
		case OP_IMM_ORI:
			IMM = (int)signedExtend(imm_12,12);
			put_int(rs1,0xf0);
			ORI(rs1,rd);
			result = get_int(rd);
	        printf("%x\n",result);
			break;
		case OP_IMM_XORI:
			IMM = (int)signedExtend(imm_12,12);
			put_int(rs1,0x01);
			XORI(rs1,rd);
			result = get_int(rd);
	        printf("%x\n",result);
			break;
		case OP_IMM_SR:
			/*****SRLI/SRAI*****/
			if((imm_12>>10)==1)          //SRAI
			{
				IMM = (int)signedExtend(imm_12,12);
				put_int(rs1,0xF0000000);
				SRAI(rs1,rd);
				result = get_int(rd);
				printf("%x\n",result);
			}
			else                        //SRLI
			{
				IMM = (int)signedExtend(imm_12,12);
				put_int(rs1,0xF0000000);
				SRLI(rs1,rd);
				result = get_int(rd);
				printf("%x\n",result);
			}
			break;
		}
		break;
	case JALR:
		break;
	case OP:
		i_type = R_type;
		decode_ins_format(i_type);
		 switch(funct3)
        {
            case OP_ALU:
                if(funct7==0)
                {
                    printf("ADD rs%x,rs%x,rs%x:",rs1,rs2,rd);
                    put_int(rs1,0x3);
                    put_int(rs2,0x3);
                    ADD(rs1,rs2,rd);
                    result = get_int(rd);
                    printf("%d\n",result);
                }
                else if(funct7==0x20)
                {
                    printf("SUB rs%x,rs%x,rs%x:",rs1,rs2,rd);
                    put_int(rs1,0x3);
                    put_int(rs2,0x3);
                    SUB(rs1,rs2,rd);
                    result = get_int(rd);
                    printf("%d\n",result);
                }
                break;
            case OP_SLT:
                if(funct7==0)
                {
                 //   put_int(rs1,0x2);
                    printf("SLT rs%x,rs%x,rs%x:",rs1,rs2,rd);
                    put_int(1,0x0);
                    put_int(2,0x2);
                    SLT(rs1,rs2,rd);
                    printf("rs1:%d,rs2=%d\n",rs1,rs2);
                    result = get_int(rd);
                    printf("%d\n",result);
                }
                break;
            case OP_SLTU:
                {
                    printf("SLTU rs%x,rs%x,rs%x:",rs1,rs2,rd);
                    put_int(1,0x0);
                    put_int(2,0x2);
                    SLTU(rs1,rs2,rd);
                    printf("rs1:%d,rs2=%d\n",rs1,rs2);
                    result = get_int(rd);
                    printf("%d\n",result);
                }
                break;
            case OP_AND:
                if(funct7==0)
                {
                    printf("AND rs%x,rs%x,rs%x:",rs1,rs2,rd);
                    put_int(rs1,0x3);
                    put_int(rs2,0x3);
                    AND(rs1,rs2,rd);
                    result = get_int(rd);
                    printf("%d\n",result);
                }
                break;
            case OP_OR:
                if(funct7==0)
                {
                    printf("OR rs%x,rs%x,rs%x:",rs1,rs2,rd);
                    put_int(rs1,0x3);
                    put_int(rs2,0x3);
                    OR(rs1,rs2,rd);
                    result = get_int(rd);
                    printf("%d\n",result);
                }
                break;
            case OP_XOR:
                if(funct7==0)
                {
                    printf("XOR rs%x,rs%x,rs%x:",rs1,rs2,rd);
                    put_int(rs1,0x3);
                    put_int(rs2,0x3);
                    XOR(rs1,rs2,rd);
                    result = get_int(rd);
                    printf("%d\n",result);
                }
                break;
            case OP_SLL:
                if(funct7==0)
                {
                    printf("SLL rs%x,rs%x,rs%x:",rs1,rs2,rd);
                    put_int(rs1,0x3);
                    put_int(rs2,0x3);
                    SLL(rs1,rs2,rd);
                    result = get_int(rd);
                    printf("%d\n",result);
                }
                break;
            case OP_SHIFT://”““∆
                put_int(rs1,0x80000000);
                put_int(rs2,0x3);
                if(funct7==0)
                {
                    printf("SRL rs%x,rs%x,rs%x:",rs1,rs2,rd);
                    SRL(rs1,rs2,rd);
                }
                else
                {
                    printf("SRA rs%x,rs%x,rs%x:",rs1,rs2,rd);
                    SRA(rs1,rs2,rd);
                }
                result = get_int(rd);
                printf("%d\n",result);
                break;
            default:
                break;
        }
		break;
	case LOAD:
        i_type = I_type;
        decode_ins_format(i_type);
        IMM = (int)signedExtend(imm_12,12);
        switch (funct3) {
            case LOAD_LB:
                put_int(rs1,0x3);
                write_mem_byte(0x4,0x97);
                LB(rs1,rd);
                result = get_int(rd);
                printf("LB TEST...%x\n",result);
                break;
            case LOAD_LBU:
                put_int(rs1,0x3);
                write_mem_ubyte(0x4,0x23);
                LBU(rs1,rd);
                result = get_int(rd);
                printf("LBU TEST...%x\n",result);
                break;
            case LOAD_LH:
                put_int(rs1,0x3);
                write_mem_halfword(0x4,0x9122);
                LH(rs1,rd);
                result = get_int(rd);
                printf("LH TEST...%x\n",result);
                break;
            case LOAD_LHU:
                put_int(rs1,0x3);
                write_mem_uhalfword(0x4,0x2333);
                LHU(rs1,rd);
                result = get_int(rd);
                printf("LHU TEST...%x\n",result);
                break;
            case LOAD_LW:
                put_int(rs1,0x3);
                write_mem_word(0x4, 0x93333333);
                LW(rs1,rd);
                result = get_int(rd);
                printf("LW TEST...%x\n",result);
                break;
        }
        break;
    case STORE:
        i_type = S_type;
        decode_ins_format(i_type);
        IMM = (int)signedExtend(imm_12,12);
        switch (funct3) {
            case STORE_SB:
                put_int(rs1, 0x3);
                put_int(rs2, 0x12);
                SB(rs1,rs2);
                result = read_mem_byte(0x24);
                printf("SB TEST...%x\n",result);
                break;
          /*  case STORE_SBU:
                put_int(rs1, 0x3);
                put_int(rs2, 0x91);
                SBU(rs1,rs2);
                result = read_mem_ubyte(0x24);
//                ins_buffer = 0x02109123;
//                decodeInstruction();
                printf("SBU TEST...%x\n",result);
                break;*/
            case STORE_SH:
                put_int(rs1, 0x3);
                put_int(rs2, 0x2222);
                SH(rs1,rs2);
                result = read_mem_halfword(0x24);
                printf("SH TEST... %x\n",result);
                break;
           /* case STORE_SHU:
                put_int(rs1, 0x3);
                put_int(rs2, 0x9222);
                SHU(rs1,rs2);
                result = read_mem_uhalfword(0x24);
                printf("SHU TEST... %x\n",result);
                break;*/
            case STORE_SW:
                put_int(rs1, 0x3);
                put_int(rs2, 0x23333333);
                SW(rs1,rs2);
                result = read_mem_word(0x04);
                printf("SW TEST...%x\n",result);
                break;
        }
        break;
    case LUI:
        i_type = U_type;
        decode_ins_format(i_type);
        IMM = (int)imm_20;
        LUIOP(rd);
        result = get_int(rd);
        printf("LUI TEST...%x\n",result);
        break;
    case AUIPC:
        i_type = U_type;
        decode_ins_format(i_type);
        IMM = (int)imm_20;
        put_int(PC, 0x01);
        AUIPCOP(rd);
        result = get_int(rd);
        printf("AUIPCOP TEST...%x\n",result);
        break;
	default:
		break;
	}

	/*switch(i_type)
	{
	case R_type:
		break;
	}*/
	return 0;
}