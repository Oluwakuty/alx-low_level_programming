#include "main.h"

/**
 * main - Main function
 * @argc: argument count
 * @argv: argument vector
 * Return: Always success
 */

int main(int argc, char *argv[])
{
	const char *file_from = argv[1];
	const char *file_to = argv[2];
	int fd_from, fd_to;
	ssize_t bytes_read;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	/** Open the source file for reading */
	if ((fd_from = open(file_from, O_RDONLY)) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		return (98);
	}
	
	/** Open or create the destination file for writing, truncating it if it exists */
	if ((fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0644)) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", file_to);
		close(fd_from);
		return (99);
	}
	while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		if (write(fd_to, buffer, bytes_read) != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", file_to);
			close(fd_from);
			close(fd_to);
			return (99);
		}
	}

	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error reading from file %s\n", file_from);
		close(fd_from);
		close(fd_to);
		return (98);
	}

	/** Close the file descriptors */
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd\n");
		return (100);
	}
	return (0);
}
