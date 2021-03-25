#include <stdio.h>
#include <stdlib.h>

// Step1. exec: write 0~5 0xAAAABBBB -> 30 times
// Step2. exec: write 0~5 0x12345678 -> 1 time
// Step3. read right?

int main()
{
	FILE *fd;
	char cmd[128];

	// ssd will make a result.txt
	// Step1. write 30 times
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			sprintf(cmd, "./ssd write %d 0xAAAABBBB", j);
			system(cmd);
		}
	}
	// Step2. write 1 time
	for (int i = 0; i < 5; i++)
	{
		sprintf(cmd, "./ssd write %d 0x12345678", i);
		system(cmd);
	}
	// Step3. read 0~5
	for (int i = 0; i < 5; i++)
	{
		// read ith address
		sprintf(cmd, "./ssd read %d > ./test_result/result_2.txt", i);
		system(cmd);

		// diff result.txt and test2.txt
		system("diff ./test_result/test2.txt ./test_result/result_2.txt > ./test_result/diff.txt");
		
		// open result2.txt
		fd = fopen("./test_result/diff.txt", "r");
		if (fd == NULL)
		{
			printf("# CAN'T READ THE RESULT TEST FILE #\n");
			return (0);
		}

		// fail
		if (!(fgetc(fd) && feof(fd)))
		{
			printf("===================================\n");
			printf("# SORRY YOUR SSD FAIL TEST CASE 2 #\n");	
			printf("===================================\n");
			fclose(fd);
			system("rm ./test_result/result_2.txt && rm ./test_result/diff.txt");
			return (0);
		}
	}
	// success
	printf("======================================\n");
	printf("# CONGRATULATION SUCCESS TEST CASE 2 #\n");	
	printf("======================================\n");
	fclose(fd);
	system("rm ./test_result/result_2.txt && rm ./test_result/diff.txt");
	return (0);
}
