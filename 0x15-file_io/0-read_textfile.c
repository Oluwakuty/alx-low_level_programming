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
	int fild = open(filename, O_RDONLY);
	char *buff = malloc(letters);
	ssize_t bytes_read = read(fild, buff, letters);
	ssize_t bytes_written = (bytes_read > 0) ?
		write(STDOUT_FILENO, buff, bytes_read) : -1;

	if (filename == NULL)
		return (0);

	if (fild == -1)
		return (0);

	if (!buff)
	{
		close(fild);
		return (0);
	}
	free(buff);
	close(fild);

	return (bytes_written);
}
