#include "shell.h"

/**
 * copy_string - copies a string
 * @destination: the destination
 * @source: the source
 *
 * Return: pointer to destination
 */
char *copy_string(char *destination, char *source)
{
	int i = 0;

	if (destination == source || source == 0)
		return (destination);
	while (source[i])
	{
		destination[i] = source[i];
		i++;
	}
	destination[i] = 0;
	return (destination);
}

/**
 * duplicate_string - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *duplicate_string(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *print_string - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void print_string(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		print_char(str[i]);
		i++;
	}
}

/**
 * print_char - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_char(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

