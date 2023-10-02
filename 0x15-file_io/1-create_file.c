#include "main.h"

/**
 * create_file - Append a file.
 * @filename: A pointer to the file to create.
 * @text_content: A pointer to a string.
 * Return: If the function fails - -1. Otherwise - 1.
 */

int create_file(const char *filename, char *text_content)
{
	int fild, m, lent = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lent = 0; text_content[lent];)
			lent++;
	}
	fild = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	m = write(fild, text_content, lent);

	if (fild == -1 || m == -1)
		return (-1);
	close(fild);
	return (1);

}
