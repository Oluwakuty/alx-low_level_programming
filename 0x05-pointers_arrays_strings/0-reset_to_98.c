#include <stdio.h>
#include "main.h"

/**
 * reset_to_98 - update the value back to 98
 * @n: Interger number
 * Return: Always 0.
 */

void reset_to_98(int *n)
{
	if (n != NULL)
	{
		*n = 98;
	}
}
