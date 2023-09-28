#include "main.h"

/**
 * print_binary - outputs the binary representation of a number
 * @n: number to output in binary
 */

void print_binary(unsigned long int n)
{
	int q = 63;
	int tally = 0;
	unsigned long int present;

	while (q >= 0)
	{
		present = n >> q;

		if (present & 1)
		{
			_putchar('1');
			tally++;
		}

		else if (tally)
		{
			_putchar('0');
		}
		q--;
	}
	if (!tally)
	{
		_putchar('0');
	}
}
