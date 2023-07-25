#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d", &n);
	int num;
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		if (num == 1)
		{
			count++;
			continue;
		}
		else 
		{
			for (int k = 2; k < num; k++)
			{
				if (num % k == 0)
				{	
					count++;
					break;
				}
			}
		}
	}
	printf("%d", n-count);
}