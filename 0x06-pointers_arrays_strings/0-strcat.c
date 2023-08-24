#include "main.h"

/**
 * _strcat - concantenates two strings
 * @dest: input value
 * @src: input value
 * Return: Always return everytime void
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;

	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}
