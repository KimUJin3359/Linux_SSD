#include <stdio.h>
#include <string.h>

char cmd[100];
char value[100];
char f_cmd[300];
char end;
int ad;

int main() {
	while (1) {
		printf("SHELL> ");
		scanf("%s", cmd);

		if (strcmp(cmd, "read") == 0) {
			scanf("%d%c", &ad, &end);
			if (ad < 0 || 99 < ad) {
				printf("주소의 범위를 벗어났습니다.\n");
			}
			else {
				printf("%d 주소의 값을 Read.\n", ad);
				sprintf(f_cmd, "./ssd %s %d", cmd, ad);
				printf("%s\n", f_cmd);
			}
		}
		else if (strcmp(cmd, "write") == 0) {
			scanf("%d %s", &ad, value);
			if (ad < 0 || 99 < ad) printf("주소의 범위를 벗어났습니다.\n");
			else if (strlen(value) != 10) printf("값의 범위를 벗어났습니다.\n");
			else {
				if (value[0] == '0' && value[1] == 'x') {
					for (int i = 2; i < 10; i++) {
						if ((0 <= value[i] - '0' && value[i] - '0' <= 9) || (0 <= (value[i] - 'A') && (value[i] - 'A') <= 5)) {}
						else {
							printf("잘못된 값 형식입니다.\n");
							break;
						}

						if (i == 9) {
							printf("%d 주소에 %s값을 Write.\n", ad, value);
							sprintf(f_cmd, "./ssd %s %d %s", cmd, ad, value);
							printf("%s\n", f_cmd);
						}
					}
				}
				else printf("잘못된 값 형식입니다.\n");

			}
		}
		else if (strcmp(cmd, "fullwrite") == 0 || strcmp(cmd, "fullread") == 0) {
			sprintf(f_cmd, "./ssd %s", cmd);
			printf("%s\n", f_cmd);
		}
		else if (strcmp(cmd, "exit") == 0) break;
		else if (strcmp(cmd, "help") == 0) {
			printf("read 주소: 주소값에 저장된 값을 Read합니다.\n");
			printf("write 주소 값: 주소값에 값을 Write합니다.\n");
			printf("fullread: 0번 주소부터 99번 주소까지 Read를 수행합니다.\n");
			printf("fullwrite 값: 0번 주소부터 99번 주소까지 값을 Write합니다.\n");
			printf("exit: 쉘 스크립트 프로그램을 종료합니다.\n");
		}
		else if (strcmp(cmd, "testapp1") == 0 || strcmp(cmd, "testapp2") == 0 || strcmp(cmd, "testapp3") == 0) {
			sprintf(f_cmd, "./%s", cmd);
			printf("%s\n", f_cmd);
		}
		else printf("INVALID COMMAND.\n");
	}
}
