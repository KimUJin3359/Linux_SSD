#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE 16
char line[LINE];
char* res;
char cmd[100];

void write(int addr, char* value)
{
	FILE *nand = fopen("./nand.txt", "r");
	
	for(int i=0; i<100; i++)
	{
		// read NAND
		fgets(line, LINE, nand);
		
		// write NAND
		strtok_r(line, "]", &res);
		strtok(res, "\n");
		if(i==0 && i==addr) sprintf(cmd, "echo %s]%s > nand.txt", line, value);
		else if(i==0) sprintf(cmd, "echo %s]%s > nand.txt", line, res);
		else if(i==addr) sprintf(cmd, "echo %s]%s >> nand.txt", line, value);
		else sprintf(cmd, "echo %s]%s >> nand.txt", line, res);
		system(cmd);
	}
	
	fclose(nand);
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
	printf("%s\n", res);
	fclose(nand);
}


void fullWrite(char* value)
{
	FILE *nand = fopen("./nand.txt", "r");
	
	for(int i=0; i<100; i++)
	{
		// read NAND
		fgets(line, LINE, nand);
		
		// write NAND
		strtok_r(line, "]", &res);
		strtok(res, "\n");
		if(i==0) sprintf(cmd, "echo %s]%s > nand.txt", line, value);
		else sprintf(cmd, "echo %s]%s >> nand.txt", line, value);
		system(cmd);
	}

	fclose(nand);
}


void fullRead()
{
	FILE *nand = fopen("./nand.txt", "r");
	
	for(int i=0; i<100; i++)
	{
		// read NAND
		fgets(line, LINE, nand);
		
		// write NAND
		strtok_r(line, "]", &res);
		strtok(res, "\n");
		if(i==0) sprintf(cmd, "echo %s > result.txt", res);
		else sprintf(cmd, "echo %s >> result.txt", res);
		system(cmd);
		printf("%s\n", res);
	}
	
	fclose(nand);
}


int main(int argc, char *argv[])
{
	if(!strcmp(argv[1], "write")) write(atoi(argv[2]), argv[3]);
	if(!strcmp(argv[1], "read")) read(atoi(argv[2]));
	if(!strcmp(argv[1], "fullwrite")) fullWrite(argv[2]);
	if(!strcmp(argv[1], "fullread")) fullRead();

	return 0;
}
