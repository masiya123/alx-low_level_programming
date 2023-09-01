#include "main.h"
/**
 * set_bit - value of a bit to 1 at a given index.
 * @index: start from 0 to the bit you want to set
 * @n: pointer number of j
 * Return: 1 if it worked, or -1 if an error occurred
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int j;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	j = 1 << index;
	*n = *n | j;

	return (1);
}
