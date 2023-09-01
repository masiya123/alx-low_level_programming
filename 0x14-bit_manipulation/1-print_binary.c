#include "main.h"
/**
 * _power - calculate (base and power)
 * @base: base of the exponet to the number
 * @pow: power of the exponet to the number
 * Return: value of base and power
 */
unsigned long int _power(unsigned int base, unsigned int pow)
{
	unsigned long int num;
	unsigned int j;

	num = 1;
	for (j = 1; j <= pow; j++)
		num *= base;
	return (num);
}
/**
 * print_binary - prints the binary representation to a number
 * of binary
 * @n: num of prented binary
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int dv, reslt;
	char flag;

	flag = 0;
	dv = _power(2, sizeof(unsigned long int) * 8 - 1);

	while (dv != 0)
	{
		reslt = n & dv;
		if (reslt == dv)
		{
			flag = 1;
			_putchar('1');

		}
		else if (flag == 1 || dv == 1)
		{
			_putchar('0');
		}
		dv >>= 1;
	}
}
