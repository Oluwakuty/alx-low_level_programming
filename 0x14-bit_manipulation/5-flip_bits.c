#include "main.h"

/**
 * flip_bits - note number of changed bits
 * @n: number one
 * @m: number two
 * Return: success
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int counter = 0;
	unsigned long int exc = n ^ m;
	int q = 63;

	while (q >= 0)
	{
		if (exc & (1UL << q))
		{
			counter++;
		}
		q--;
	}
	return (counter);
}
