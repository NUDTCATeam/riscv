#include "InsOperate.h"
#include "GlobalVar.h"
int main()
{
	int insNum,i;
	PC = 0x0100;                          //initial PC pointer
	mem = (char *)malloc(sizeof(char)* mem_size);
	if (mem == NULL)
	{
		printf("Main memory allocate failed\n");
		system("pause");
		exit(-1);
	}
	registers = (int *)malloc(sizeof(int)* reg_size);
	if (registers ==NULL)
	{
		printf(" Register file allocate failed\n");
		system("pause");
		exit(-1);
	}
	
	/*****read instruction file******/
    insNum = loadInstoMemory();
	for(i=0;i<insNum;i++)
	{
		int ret = fetchInstruction();
		if(ret != 0)
		{
			printf(" fetch Instruction failed\n");
			system("pause");
			exit(-1);
		}

		PC = PC+4;

		decodeInstruction();
	}
	printf("%s","instruction execute finish\n");
	free(mem);
	free(registers);
//	system("pause");
	return 0;
}