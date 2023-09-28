#include "main.h"

/**
 * get_endianness - to see whether a machine is big endian or small endian
 * Return: one for small, zero for big
 */

int get_endianness(void)
{
	unsigned int q = 1;
	char *d = (char *) &q;

	return (*d);
}
