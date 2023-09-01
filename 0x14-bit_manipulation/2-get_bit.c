#include "main.h"

/**
 * get_bit - function that returns the value of a bit at a given index
 * @n: checking bits to the index
 * @index: which to check bit
 *
 * Return: the value of the bit at index
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int dv, result;

	if (index > (sizeof(unsigned long int) * 8 - 1))
		return (-1);
	dv = 1 << index;
	result = n & dv;
	if (result == dv)
		return (1);

	return (0);
}
