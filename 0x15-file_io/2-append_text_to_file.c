#include "main.h"

/**
 * append_text_to_file - Appends text to the end of an file
 * @filename: pointer to the name of the file.
 * @text_content: string to add to the end of the file.
 * Return: NULL - -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int pen, rite, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	pen = open(filename, O_WRONLY | O_APPEND);
	rite = write(pen, text_content, len);

	if (pen == -1 || rite == -1)
		return (-1);

	close(pen);

	return (1);
}
