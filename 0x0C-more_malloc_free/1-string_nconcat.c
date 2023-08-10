#include "main.h"

/**
 * string_nconcat - concatenates two strings.
 * @s1: first char
 * @s2: secound char
 * @n: unsigned int
 * Return: If the function fails, it should return NULL
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int i, y, z;
	char *s;

	if (s1 == NULL)
	{
		i = 0;
	}
	else
	{
		for (i = 0; s1[i]; ++i)
		;
	}
	if (s2 == NULL)
	{
		y = 0;
	}
	else
	{
		for (y = 0; s2[y]; ++y)
		;
	}
	if (y > n)
		y = n;
	s = malloc(sizeof(char) * (i + y + 1));
	if (s == NULL)
		return (NULL);
	for (z = 0; z < i; z++)
		s[z] = s1[z];
	for (z = 0; z < y; z++)
		s[z + i] = s2[z];
	s[i + y] = '\0';
	return (s);
}
