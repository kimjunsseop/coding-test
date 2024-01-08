#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	int* arr = (int*)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
	printf("<");
	int zcount = 0;
	int count = 0;
	int i = 0;
	while (zcount<n)//0이 배열크기만큼 될때 제거되도록 구현
	{
		i += 1;
		if (arr[i-1] != 0)
		{
			count += 1;
			if (count == k)
			{
				if (zcount == n - 1)
				{
					printf("%d", arr[i - 1]);
					arr[i - 1] = 0;
					zcount += 1;
					count = 0;
				}
				else
				{
					printf("%d, ", arr[i - 1]);
					arr[i - 1] = 0;
					zcount += 1;
					count = 0;
				}
			}
		}
		if (i == n)
		{
			i = 0;
		}
	}
	printf(">");
}