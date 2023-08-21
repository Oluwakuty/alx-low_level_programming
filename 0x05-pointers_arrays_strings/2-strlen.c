#include <stdio.h>
#include "main.h"

/**
 * strlen - count the length of a string
 * @s: Variable string
 * Return: Always everytime 0
 */

int _strlen(char *s)
{
	int length = 0;

	while
		(s[length] != '\0')
		{
			length++;
		}
	return length;
}
