#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>	
#define SIZE 101

int main()
{
	char word[SIZE] = { '0' };
	int cycle = 0;
	int  count[26] = { 0 };
	int ns = 0;
	scanf("%d", & cycle);

	for (int i = 0; i < cycle; i++)
	{
		scanf("%s", word);
		for (int i = 0; i < strlen(word); i++)
		{
			if (word[i] != word[i + 1])
			{
				count[word[i] - 'a'] += 1;
			}
		}
		for (int i = 0; i < 26; i++)
		{
			if (count[i] >= 2)
			{
				ns++;
				break;
			}
		}
		for (int i = 0; i < 26; i++)
		{
			count[i] = 0;
		}
	}

	printf("%d", cycle-ns);
	
	
}