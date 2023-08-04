#include "main.h"

/**
 * _puts - program prints a string to 
 * @str: the string to be be printed.
 *
 * Return: the length of the string
 */
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}
