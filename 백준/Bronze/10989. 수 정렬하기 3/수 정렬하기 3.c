#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main()
{
	int n, num;
	scanf("%d", &n);
	int arr[10001] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		arr[num]++;
	}

	for (int i = 0; i < 10001; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			printf("%d\n", i);
		}
	}
}