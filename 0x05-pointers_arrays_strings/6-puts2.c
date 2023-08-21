#include <stdio.h>

/**
 * puts2 - prints character of a string
 * @str: variable string
 * Return: Always return 0
 */

void puts2(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		printf("%c", str[i]);
		i += 2;
	}
	printf("\n");
}
