#include "main.h"

/**
 * set_bit - function that sets the value of a bit to 1 at a given index
 * @n: pointer
 * @index: index
 * Return: success
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int cover = 1UL << index;
	*n = cover | *n;

	if (index > 63)
		return (-1);

	return (1);
}
