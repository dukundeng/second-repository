#include <stdio.h>

int main()
{
	const int limit = 3;
	int board[limit][limit];
	int i = 0;
	int j = 0;
	int numberof0 = 0;
	int numberof1 = 0;
	int ret = -1;

	printf("请由左至右由上至下一次输入数组0或1\n");
	for (i = 0; i < limit; i++) {
		for (j = 0; j < limit; j++) {
			scanf_s("%d", &board[i][j]);
		}
	}

	for (i = 0; i < limit && ret == -1; i++) {
		for (j = 0; j < limit; j++) {
			if (board[i][j] == 0) {
				numberof0++;
			}
			else {
				numberof1++;
			}
			if (numberof0 == limit) {
				ret = 0;
			}
			else if (numberof1 == limit) {
				ret = 1;
			}
		}
	}
	if (ret == -1) {
		for (j = 0; j < limit && ret == -1; j++) {
			for (i = 0; i < limit; i++) {
				if (board[i][j] == 0) {
					numberof0++;
				}
				else {
					numberof1++;
				}
				if (numberof0 == limit) {
					ret = 0;
				}
				else if (numberof1 == limit) {
					ret = 1;
				}
			}
		}
		if (ret == -1) {
			for (i = 0; i < limit; i++) {
				if (board[i][i] == 0) {
					numberof0++;
				}
				else {
					numberof1++;
				}
				if (numberof0 == limit) {
					ret = 0;
				}
				else if (numberof1 == limit) {
					ret = 1;
				}
			}
			if (ret == -1) {
				for (i = 0; i < limit; i++) {
					if (board[i][limit - i - 1] == 0) {
						numberof0++;
					}
					else if (board[i][limit - i - 1] == 1) {
						numberof1++;
					}
					if (numberof0 == limit) {
						ret = 0;
					}
					else if (numberof1 == limit) {
						ret = 1;
					}
				}
			}
		}
	}
		if (ret == -1) {
			printf("谁都没有赢\n");
		}
		else if (ret == 0) {
			printf("0赢了\n");
		}
		else if (ret == 1) {
			printf("1赢了\n");
		}

		return 0;
}