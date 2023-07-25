#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
	int n;
	char word[50] = { '\0' };
	int hash = 0;
	scanf("%d", &n);
	scanf("%s", word);
	for (int i = 0; i < n; i++)
	{
		hash = hash + (word[i]-96) * pow(31, i);
	}

	printf("%d", hash);
}