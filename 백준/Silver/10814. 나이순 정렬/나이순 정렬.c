#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int atmp[100000] = { 0 };
char* ntmp[100000] = { NULL };

void merge(int a[], char *n[], int gp[], int start, int mid, int end)
{
	int i = start;
	int j = mid + 1;
	int k = start;

	while (i <= mid && j <= end)
	{
		if (a[i] < a[j])
		{
			atmp[k] = a[i];
			ntmp[k] = n[i];
			k++;
			i++;
		}
		else if (a[i] == a[j])
		{
			if (gp[i] < gp[j])
			{
				atmp[k] = a[i];
				ntmp[k] = n[i];
				k++;
				i++;
			}
			else
			{
				atmp[k] = a[j];
				ntmp[k] = n[j];
				k++;
				j++;
			}
		}
		else
		{
			atmp[k] = a[j];
			ntmp[k] = n[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		atmp[k] = a[i];
		ntmp[k] = n[i];
		k++;
		i++;
	}
	while (j <= end)
	{
		atmp[k] = a[j];
		ntmp[k] = n[j];
		k++;
		j++;
	}
	for (int m = start; m <= end; m++)
	{
		a[m] = atmp[m];
		n[m] = ntmp[m];
	}
}

void mergeSort(int a[], char* n[], int gp[], int start, int end)
{
	int q;
	if (start < end)
	{
		q = (start + end) / 2;
		mergeSort(a, n, gp, start, q);
		mergeSort(a, n, gp,q + 1, end);
		merge(a, n, gp, start, q, end);
	}
}
char* name[100000] = { NULL };
int age[100000] = { 0 };
int gp[100000] = { 0 };

int main()
{
	int n;
	scanf("%d", &n);
	char tmp[101] = { 0 };
	for (int i = 0; i < n; i++)
	{
		scanf("%d%s",&age[i] ,tmp);
		int k = strlen(tmp);
		char* str = (char*)malloc(sizeof(char) * k);
		strcpy(str,tmp);
		name[i] = str;
		gp[i] = i;
	}
	mergeSort(age, name, gp, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		printf("%d %s\n", age[i], name[i]);
	}
}