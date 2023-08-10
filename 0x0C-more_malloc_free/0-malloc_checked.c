#include "main.h"

/**
 * malloc_checked - function should cause normal process termination
 * with a status value of 98
 * @b: function that allocates memory
 * Return: a pointer to the allocated memory
 */
void *malloc_checked(unsigned int b)
{
	void *x;

	x = malloc(b);
	if (x == NULL)
		exit(98);
	return (x);

}
