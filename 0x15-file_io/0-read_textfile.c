#include "main.h"
#include <stdlib.h>

/**
 * read_textfile- Read text file and print to STDOUT.
 * @filename: readable text
 * @letters: letters to be read
 * Return: actual number of bytes read and printed
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buff;
	ssize_t fild;
	ssize_t m;
	ssize_t y;

	fild = open(filename, O_RDONLY);
	if (fild == -1)
		return (0);

	buff = malloc(sizeof(char) * letters);
	y = read(fild, buff, letters);
	m = write(STDOUT_FILENO, buff, y);
	free(buff);
	close(fild);

	return (m);
}
