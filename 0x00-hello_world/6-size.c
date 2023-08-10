#include <stdio.h>
/**
 * main - Entry point
 * Return: Always 0 (success)
 */
int main(void)
{
	printf("Size of a char: %lu byte(s)ln", sizeof(char));
	printf("Size of an int: %lu byte(s)ln", sizeof(int));
	printf("Size of a long int: %lu byte(s)ln", sizeof(long int));
	printf("Size of a long long int: %lu byte(s)ln", sizeof(long long int));
	printf("Size of a float: %lu byte(s)ln", sizeof(float));
	return (0);
}
