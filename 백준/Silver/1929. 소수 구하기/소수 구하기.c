#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n,m;
	scanf("%d%d", &n, &m);
	int k = sqrt(m);

	int count = 0;
	for (int i = n;i<=m;i++)
	{
		for (int j = 2; j <= k; j++)
		{
			if (i % j == 0)
			{
				if (i != j)
				{
					count++;
					break;
				}
			}
		}
		if (count == 0)
		{
			if (i != 1)
			{
				printf("%d\n", i);
			}
		}
		count = 0;
	}
}