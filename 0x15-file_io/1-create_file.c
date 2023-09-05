#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: pointer to the name of the file to create.
 * @text_content: pointer to a string to write to the file.
 * Return: If the function fails - -1.
 *         Otherwise - 1.
 */
int create_file(const char *filename, char *text_content)
{
	int f, rite, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	f = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	rite = write(f, text_content, len);

	if (f == -1 || rite == -1)
		return (-1);

	close(f);

	return (1);
}
