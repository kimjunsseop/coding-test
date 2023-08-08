#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int queue[10000] = { 0 };
int rear = 0;
int fronT = 0;

void push(int n)
{
	rear++;
	queue[rear] = n;
}
int pop(void)
{
	if (empty() == 1)
	{
		return -1;
	}
	else
	{
		fronT++;
		return queue[fronT];
	}
}
int size(void)
{
	return rear-fronT;
}
int empty(void)
{
	if (fronT == rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int front(void)
{
	if (empty() == 1)
	{
		return -1;
	}
	else
	{
		return queue[fronT + 1];
	}
}

int back(void)
{
	if (empty() == 1)
	{
		return -1;
	}
	else
	{
		return queue[rear];
	}
}

int main()
{
	int n;
	int element = 0;
	char fuct[6] = { '\0' };
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", fuct);
		if (strcmp(fuct, "push") == 0)
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
		else if (strcmp(fuct, "front") == 0)
		{
			printf("%d\n", front());
		}
		else
		{
			printf("%d\n", back());
		}
	}
}