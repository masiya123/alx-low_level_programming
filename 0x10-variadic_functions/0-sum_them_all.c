#include "variadic_functions.h"

/**
 * sum_them_all - function that adds all the numbers
 * @n: the number of parameters passed
 * Return: Always 0
 */

int sum_them_all(const unsigned int n, ...)
{
	int sum;
	unsigned int i;
	va_list reslute;

	va_start(reslute, n);

	if (n == 0)
		return (0);

	for (i = 0; i < n; i++)
		sum += va_arg(reslute, int);

	va_end(reslute);

	return (sum);
}
