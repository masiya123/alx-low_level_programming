#include "main.h"

/**
 * _calloc - function that allocates memory for an
 * array of @nmemb elements of
 * @size bytes each and returns a pointer to the allocated memory.
 * @nmemb: allocate memory for array
 * @size: allocate element of size bytes
 * Return: pointer to the allocated memory.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *n;
	unsigned int i;

	if (nmemb == 0 || size == 0)
		return (NULL);
	n = malloc(nmemb * size);
	if (n == NULL)
		return (NULL);
	for (i = 0; i < (nmemb * size); i++)
		n[i] = 0;
	return (n);
}
