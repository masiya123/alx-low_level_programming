#include <stddef.h>
#include "main.h"

/**
 * _strpbrk - program entry point
 * @s: input
 * @accept: input
 * Return: a pointer to the byte
 */
char *_strpbrk(char *s, char *accept)
{
	int i;
		while (*s)
		{
			for (i = 0; accept[i]; i++)
			{
				if (*s == accept[i])
					return (s);
			}
			s++;
		}
	return (NULL);
}
