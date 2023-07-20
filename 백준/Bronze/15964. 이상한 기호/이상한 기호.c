#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	



int main()
{
	int a, b;
	scanf("%d%d", &a, &b);

	int res = strange(a, b);

	printf("%d", res);
}

int strange(int a, int b)
{
	return (a + b) * (a - b);
}


