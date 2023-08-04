#include "main.h"

/**
 *_memset - program fill a block of memory with constant
 *@s: starting space of memory
 *@b: byte
 *@n: memory area changed
 *
 *Return: change array with the memory area
 */

char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
i = 0;

while (i < n)
{
*(s + i) = b;
i++;
}
return (s);
}
