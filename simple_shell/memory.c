#include "shell.h"

/**
 * free_and_nullify - frees a pointer and sets the address to NULL
 * @pointer: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int free_and_nullify(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}

