#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	while (1)
	{
		int stack = 0;
		char arr[101] = { '\0' };
		char gh[101] = { '\0' };
		gets(arr);
		if (arr[0] == '.')
		{
			break;
		}
		else
		{
			if (arr[0] == ')' || arr[0] == ']')
			{
				printf("no\n");
			}
			else
			{
				int k = strlen(arr);
				int i;
				for (i = 0; i < k; i++)
				{
					if (arr[i] == '(')
					{
						gh[stack] = '(';
						stack++;
					}
					else if (arr[i] == '[')
					{
						gh[stack] = '[';
						stack++;
					}
					else if (arr[i] == ')')
					{
						if (stack == 0)
						{
							stack++;
							break;
						}
						else if (gh[stack - 1] == '(')
						{
							stack = stack - 1;
						}
						else if (gh[stack - 1] == ')')
						{
							break;
						}
						else if (gh[stack - 1] == '[')
						{
							break;
						}
						else if (gh[stack - 1] == ']')
						{
							break;
						}
					}
					else if (arr[i] == ']')
					{
						if(stack==0)
						{
							stack++;
							break;
						}
						else if (gh[stack - 1] == '[')
						{
							stack = stack - 1;
						}
						else if (gh[stack - 1] == ')')
						{
							break;
						}
						else if (gh[stack - 1] == '(')
						{
							break;
						}
						else if (gh[stack - 1] == ']')
						{
							break;
						}
					}
				}
				if (stack == 0)
				{
					printf("yes\n");
				}
				else
				{
					printf("no\n");
				}
			}
		}
	}
}