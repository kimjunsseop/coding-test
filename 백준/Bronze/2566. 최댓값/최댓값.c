#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	


int main()
{
	int board[9][9] = { 0, };
	int max = -1;
	int index1;
	int index2;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] > max)
			{
				max = board[i][j];
				index1 = i;
				index2 = j;
			}
		}
	}
	printf("%d\n", max);
	printf("%d %d", index1+1, index2+1);
}
