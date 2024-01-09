#include "shell.h"

/**
 * fill_memory - fills memory with a constant byte
 * @mem_area: the pointer to the memory area
 * @byte: the byte to fill *mem_area with
 * @num_bytes: the amount of bytes to be filled
 * Return: (mem_area) a pointer to the memory area mem_area
 */
char *fill_memory(char *mem_area, char byte, unsigned int num_bytes)
{
	unsigned int i;

	for (i = 0; i < num_bytes; i++)
		mem_area[i] = byte;
	return (mem_area);
}

/**
 * free_strings - frees a string of strings
 * @strings: string of strings
 */
void free_strings(char **strings)
{
	char **temp = strings;

	if (!strings)
		return;
	while (*strings)
		free(*strings++);
	free(temp);
}

/**
 * reallocate_memory - reallocates a block of memory
 * @old_ptr: pointer to previously allocated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to the reallocated block
 */
void *reallocate_memory(void *old_ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr;

	if (!old_ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(old_ptr), NULL);
	if (new_size == old_size)
		return (old_ptr);

	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		new_ptr[old_size] = ((char *)old_ptr)[old_size];
	free(old_ptr);
	return (new_ptr);
}

