#include "main.h"
/**
 * flip_bits - flip to get from one number to another
 * @n: first number
 * @m: second number
 * Return: the number of bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int differnce, result;
	unsigned int i, x;

	i = 0;
	result = 1;
	differnce = n ^ m;
	for (x = 0; x < (sizeof(unsigned long int) * 8); x++)
	{
		if (result == (differnce & result))
			i++;
		result <<= 1;
	}

	return (i);
}
