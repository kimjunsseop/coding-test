#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{
	int n;
	scanf("%d", &n);
	int warr[50] = { 0 };
	int harr[50] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d", &warr[i], &harr[i]);
	}
	
	for (int i = 0; i < n; i++)
	{
		int count = 0;
		for (int j = 0; j < n; j++)
		{
			if (warr[i] < warr[j]&& harr[i] < harr[j])
			{
				count++;
			}
		}
		printf("%d ", count + 1);
	}
}