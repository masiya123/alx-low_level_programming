#include "main.h"

/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: number of letters to be read
 * Return: j- actual number of bytes read and printed
 *        0 when function fails or filename is NULL.
 */
size_t read_textfile(const char *filename, size_t letters)
{
	char *buf;
	ssize_t f;
	ssize_t j;
	ssize_t x;

	f = open(filename, O_RDONLY);
	if (f == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	x = read(f, buf, letters);
	j = write(STDOUT_FILENO, buf, x);

	free(buf);
	close(f);
	return (j);
}
