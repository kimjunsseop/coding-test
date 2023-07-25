#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n, m;
	int num[100] = { 0 };
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	int com[970200] = { 0 };
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			for (int k = j+1; k < n; k++)
			{
				com[count] = num[i] + num[j] + num[k];
				count++;
			}
		}
	}

	int max = 0;
	for (int i = 0; i <n*(n-1)*(n-2) ; i++)
	{
		if (com[i] > m)
		{
			continue;
		}
		else
		{
			if (com[i] > max)
			{
				max = com[i];
			}
		}
	}

	printf("%d", max);
}