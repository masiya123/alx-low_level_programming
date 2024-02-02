#include "main.h"

/**
 *_strncpy - program copies a string
 *
 * @src: The source of strings
 * @dest: input value
 * @n: The length of int
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
int i;

	for (i = 0; i < n && *(src + i); i++)
	{
		*(dest + i) = *(src + i);
	}
	for (; i < n; i++)
	{
	*(dest + i) = '\0';
	}
	return (dest);

}
