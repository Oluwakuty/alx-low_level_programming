#include "main.h"

/**
 * get_bit - function that returns the value of a bit at a given index
 * @n: look through number
 * @index: index
 * Return: success
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int beat_value;
	unsigned int q;

	if (index > 63)
		return (-1);

	for (q = 0; q <= index; q++)
	{
		beat_value = n & 1;
		n >>= 1;
	}
	return (beat_value);
}
