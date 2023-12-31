#include "main.h"

/**
 * _realloc - function that reallocates a memory
 * block using malloc and free
 * @ptr: pointer to the memory previously allocated
 * @old_size:is the size, in bytes, of the allocated space for ptr
 * @new_size: the new size, in bytes of the new memory block
 * Return: pointer allocate new size memory, or NULL
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *n;
	unsigned int i, x = new_size;
	char *oldp = ptr;

	if (ptr == NULL)
	{
		n = malloc(new_size);
		return (n);
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size == old_size)
		return (ptr);
	n = malloc(new_size);
	if (n == NULL)
		return (NULL);
	if (new_size > old_size)
		x = old_size;
	for (i = 0; i < x; i++)
		n[i] = oldp[i];
	free(ptr);
	return (n);
}
