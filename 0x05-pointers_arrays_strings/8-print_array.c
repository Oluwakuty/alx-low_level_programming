#include <stdio.h>

/**
 * print_array - print array number
 * @a: parameters to be printed
 * @n: parameters to be printed
 * Return: Alwas return success 0
 */

void print_array(int *a, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		printf("%d", a[i]);
		if (i < n - 1)
			printf(", ");
	}
	printf("\n");
}
