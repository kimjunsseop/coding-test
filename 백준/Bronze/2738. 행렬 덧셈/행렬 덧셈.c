#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	


int main()
{
	int n = 0;
	int m = 0;
	int a[100][100] = { 0, };
	int b[100][100] = { 0, };
	int sum[100][100] = { 0, };
	scanf("%d%d", &n, &m);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d",& a[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			sum[i][j] = a[i][j] + b[i][j];
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%d ", sum[i][j]);
		}
		printf("\n");
	}

}