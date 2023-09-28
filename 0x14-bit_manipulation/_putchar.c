#include "main.h"
#include <unistd.h>

/**
 * _putchar - ouput the char c to stdout
 * @c: The char to output
 * Return: Always everytime succes
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
