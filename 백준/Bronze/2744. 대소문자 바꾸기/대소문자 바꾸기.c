#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>	



int main()
{
	char word[101];
	
	scanf("%s", word);

	int n = strlen(word);
	for (int i = 0; i < n; i++)
	{
		if (word[i]<='Z'&&word[i]>='A')
		{
			word[i] = word[i] + 32;
		}
		else
		{
			word[i] = word[i] - 32;
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		printf("%c", word[i]);
	}
	
}

