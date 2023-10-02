#include "main.h"

/**
 * append_text_to_file - Write text at end of file.
 * @filename: A pointer to the file.
 * @text_content: string to add to the end of the file.
 * Return: If the function fails or filename is NULL - -1.
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int z;
	int m;
	int lent = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lent = 0; text_content[lent];)
			lent++;
	}
	z = open(filename, O_WRONLY | O_APPEND);
	m = write(z, text_content, lent);

	if (z == -1 || m == -1)
		return (-1);
	close(z);
	return (1);
}
