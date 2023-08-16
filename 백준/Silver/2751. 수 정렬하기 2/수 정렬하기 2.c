#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int tmp[1000000] = { 0 };
int num[1000000] = { 0 };
void merge(int a[], int start, int mid, int end)
{
	int i = start;
	int j = mid+1;
	int k = start;
	

	while (i <= mid && j <= end)
	{
		if (a[i] < a[j])
		{
			tmp[k++] = a[i++];
		}
		else
		{
			tmp[k++] = a[j++];
		}
	}
	while(i<=mid)
	{
		tmp[k++] = a[i++];
	}
	while (j <=end)
	{
		tmp[k++] = a[j++];
	}

	for (int m =start; m <= end; m++)
	{
		a[m] = tmp[m];

	}
}

void mergeSort(int a[], int start, int end)
{
	int p = start;
	int r = end;
	int q;
	if (p < r)
	{
		q = (p + r) / 2;
		mergeSort(a, p, q);
		mergeSort(a, q + 1, r);
		merge(a, p, q, r);
	}
}
int main()
{
	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num[i]);
	}
	mergeSort(num, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", num[i]);
	}
}