#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main()
{
	int n;
	scanf("%d", &n);
	int count = 0;
	int num[10] = { 0 };
	int name = 666;
	int tname = 0;
	while (n != count)
	{
		int i = 0;
		tname = name;
		while (name != 0)
		{
			num[i] = name % 10;
			name = name / 10;
			i++;
		}
		i = 0;
		name = tname;
		name++;
		for (int i = 0; i < 7; i++)
		{
			if ((num[i] == 6) && (num[i + 1] == 6) && (num[i + 2] == 6))
			{
				count++;
				break;
			}
		}
	}
	printf("%d", name-1);
}
