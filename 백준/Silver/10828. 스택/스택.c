#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int toP = -1;
int stack[10000] = { 0 };
void push(int n)
{
	toP++;
	stack[toP] = n;
}

int pop(void)
{
	if (toP == -1)
	{
		return -1;
	}
	toP--;
	return stack[toP + 1];
}

int size(void)
{
	return toP+1;
}

int empty(void)
{
	if (toP != -1)
	{
		return 0;
	}
	else
	{
		return 1;
	}

}
int top(void)
{
	if (toP == -1)
	{
		return -1;
	}
	return stack[toP];
}

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		char fuct[6] = { '\0' };
		int element;
		scanf("%s", fuct);
		if (strcmp(fuct,"push")==0)
		{
			scanf("%d", &element);
			push(element);
		}
		else if (strcmp(fuct, "pop") == 0)
		{
			printf("%d\n", pop());
		}
		else if (strcmp(fuct, "size") == 0)
		{
			printf("%d\n", size());
		}
		else if (strcmp(fuct, "empty") == 0)
		{
			printf("%d\n", empty());
		}
		else if(strcmp(fuct, "top") == 0)
		{
			printf("%d\n", top());
		}
	}
}