#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * print_rev - print string in a reverse mode
 * @s: Variable text
 * Return: Always everytime return 0
 */

void print_rev(char *s)
{
	int length = strlen(s);

	for (int i = length - 1; i >= 0; i--)
	{
		printf("%c", s[i]);
	}
	printf("\n");
}
