#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE 16
char line[LINE];
char* res;
char cmd[100];

void write(char* addr, char* value)
{
	printf("%s에 %s 쓰기\n", addr, value);
}


void read(int addr)
{
	FILE *nand = fopen("./nand.txt", "r");
	
	// read NAND
	fseek(nand, addr * (LINE - 1), SEEK_SET);
	fgets(line, LINE - 1, nand);
	
	// write RESULT
	strtok_r(line, "]", &res);
	sprintf(cmd, "echo %s > result.txt", res);
	system(cmd);
	
	fclose(nand);
}


void fullWrite(char* value)
{
	for(int i=0; i<100; i++)
	{
		printf("%d에 %s 쓰기\n", i, value);
	}
}


void fullRead()
{
	FILE *nand = fopen("./nand.txt", "r");
	
	for(int i=0; i<100; i++)
	{
		// read NAND
		fgets(line, LINE, nand);
		
		// write RESULT
		strtok_r(line, "]", &res);
		strtok(res, "\n");
		if(i==0) sprintf(cmd, "echo %s > result.txt", res);
		else sprintf(cmd, "echo %s >> result.txt", res);
		system(cmd);
		
	}
		
	fclose(nand);
}


int main(int argc, char *argv[])
{
	//printf("argc= %d\n", argc);
	//for(int i=0;i<argc;i++) printf("%s ", argv[i]);
	//printf("\n");
	
	/*
	FILE *nand = fopen("./nand.txt", "r+");
	FILE *result = fopen("./result.txt", "w");

	// read NAND
	char line[LINE];
	fseek(nand, 2*(LINE-1), SEEK_SET);
	fgets(line, LINE, nand);
	printf("%d line= %s", 0, line);

	// wrete RESULT
	fwrite(line, 1, sizeof(line), result);
	*/
	
	//printf("addr= %d, %s\n", atoi(argv[2]), argv[2]);	
	if(!strcmp(argv[1], "write")) write(argv[2], argv[3]);
	if(!strcmp(argv[1], "read")) read(atoi(argv[2]));
	if(!strcmp(argv[1], "fullwrite")) fullWrite(argv[2]);
	if(!strcmp(argv[1], "fullread")) fullRead();

	return 0;
}