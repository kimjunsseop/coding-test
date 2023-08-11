#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{
	char board[50][51] = { '\0' };
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", board[i]);
	}
	int arr[42][42] = { 0 };

	int min = 64;

	for (int i = 0; i <= n - 8; i++)
	{
		for (int j = 0; j <= m - 8; j++)
		{
			int ctb = 0;
			int ctw = 0;
			for (int k = 0; k < 8; k++)
			{
				for (int h = 0; h < 8; h++)
				{
					if ((i + j + k + h) % 2 == 0)
					{
						if (board[i + k][j + h] != 'B')
						{
							ctb++;
						}
					}
					else
					{
						if (board[i + k][j + h] != 'W')
						{
							ctb++;
						}
					}
				}
			}
			for (int k = 0; k < 8; k++)
			{
				for (int h = 0; h < 8; h++)
				{
					if ((i + j + k + h) % 2 == 0)
					{
						if (board[i + k][j + h] != 'W')
						{
							ctw++;
						}
					}
					else
					{
						if (board[i + k][j + h] != 'B')
						{
							ctw++;
						}
					}
				}
			}
			if (ctb > ctw)
			{
				arr[i][j] = ctw;
			}
			else
			{
				arr[i][j] = ctb;
			}

			if (arr[i][j] < min)
			{
				min = arr[i][j];
			}
		}
	}	
	printf("%d", min);
}