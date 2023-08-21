#include <stdio.h>
#include "main.h"

/**
 * swap_int - swaps the values of two integers
 * @a: Integer number
 * @b: Integer number
 * Return: Always 0
 */

void swap_int(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
