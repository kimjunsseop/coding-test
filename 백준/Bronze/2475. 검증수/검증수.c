#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	

int mul(int n)
{
	return n * n;
}

int main()
{
	int a, b, c, d, e;
	scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
	int res = (mul(a) + mul(b) + mul(c) + mul(d) + mul(e))%10;

	printf("%d", res);

}


