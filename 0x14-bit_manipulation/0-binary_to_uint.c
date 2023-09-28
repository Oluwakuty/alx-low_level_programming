#include "main.h"

/**
 * binary_to_uint - turn a binary to unsigned integer
 * @b: string containing the binary number
 * Return: sucess
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int deci_val = 0;
	int p = 0;

	if (!b)
		return (0);

	while (b[p])
	{
		if (b[p] < '0' || b[p] > '1')
			return (0);

		deci_val = 2 * deci_val + (b[p] - '0');
		p++;
	}
	return (deci_val);
}
