#include <stdio.h>
#include "main.h"

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
		_putchar("%c", str[i]);
		i += 2;
	}
	_putchar("\n");
}
