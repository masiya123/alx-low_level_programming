#include "main.h"
/**
 * binary_to_uint - function that converts a binary
 * number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 * Return:convert number or 0
 */
unsigned int binary_to_uint(const char *b)
{
	int x;
	unsigned int j;

	j = 0;
	if (!b)
		return (0);
	for (x = 0; b[x] != '\0'; x++)
	{
		if (b[x] != '0' && b[x] != '1')
			return (0);
	}
	for (x = 0; b[x] != '\0'; x++)
	{
		j <<= 1;
		if (b[x] == '1')
			j += 1;
	}
	return (j);
}
