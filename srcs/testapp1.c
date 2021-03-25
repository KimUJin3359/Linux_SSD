#include <stdio.h>
#include <stdlib.h>

// Step1. exec: fullwrite
// Step2. exec fullread

int main()
{
	FILE *fd;

	// ssd will make a result.txt
	system("./ssd fullwrite 0xAAAAAAAA");
	system("./ssd fullread");
	// diff result.txt and test1.txti
	system("diff ./test_result/test1.txt ./result.txt > ./test_result/result1.txt");
	// open result1.txt
	fd = fopen("./test_result/result1.txt", "r");
	if (fd == NULL)
	{
		printf("# CAN'T READ THE RESULT TEST FILE #\n");
		return (0);
	}
	if (fgetc(fd) && feof(fd))
	{
		printf("======================================\n");
		printf("# CONGRATULATION SUCCESS TEST CASE 1 #\n");	
		printf("======================================\n");
	}
	else
	{
		printf("===================================\n");
		printf("# SORRY YOUR SSD FAIL TEST CASE 1 #\n");	
		printf("===================================\n");
	}
	fclose(fd);
	system("rm ./test_result/result1.txt");
	return (0);
}
