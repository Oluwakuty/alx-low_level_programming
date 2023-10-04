#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *create_buffer(char *file);
void close_file(int fd);

/**
 * create_buffer - Allocates bytes
 * @file: file buffer in which chars are stored.
 * Return: Pointer to the buffer.
 */

char *create_buffer(char *file)
{
	char *bufed;

	bufed = malloc(sizeof(char) * 1024);

	if (bufed == NULL)
	{
		dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", file);
		exit(99);
	}
	return (bufed);
}

/**
 * close_file - File closed.
 * @fild: file to be closed.
 */

void close_file(int fild)
{
	int j;

	j = close(fild);

	if (j == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fild %d\n", fild);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */

int main(int argc, char *argv[])
{
	int from, to, t, m;
	char *bufed;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	bufed = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	t = read(from, bufed, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || t == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't read from file %s\n", argv[1]);
			free(bufed);
			exit(98);
		}
		m = write(to, bufed, t);

		if (to == -1 || m == -1)
		{
			dprintf(STDERR_FILENO,
					"Error: Can't write to %s\n", argv[2]);
			free(bufed);
			exit(99);
		}

		m = read(from, bufed, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	}

	while (t > 0);
	free(bufed);
	close_file(from);
	close_file(to);
	return (0);
}
