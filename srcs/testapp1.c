#include <stdio.h>
#include <stdlib.h>

// Step1. exec: fullwrite
// Step2. exec fullread

int main()
{
	FILE *fd;

	// ssd will make a result.txt
	system("./ssd fullwrite 0xAAAAAAAA");
	// ssd fullread to result_1.txt
	system("./ssd fullread > ./test_result/result_1.txt");
	// diff result_1.txt and test1.txti to diff.txt
	system("diff ./test_result/test1.txt ./test_result/result_1.txt > ./test_result/diff.txt");
	// open diff.txt
	fd = fopen("./test_result/diff.txt", "r");
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
		system("cat ./test_result/result1.txt");
		printf("===================================\n");
		printf("# SORRY YOUR SSD FAIL TEST CASE 1 #\n");	
		printf("===================================\n");
	}
	fclose(fd);
	system("rm ./test_result/result_1.txt && rm ./test_result/diff.txt");
	return (0);
}
