#include "function_pointers.h"

/**
 * array_iterator - function given as a
 * parameter on each element of an array.
 *
 * @array: array to execute function on
 * @size: is the size of the array
 * @action: is a pointer to the function
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t x;

	if (array && action)
	{
		x = 0;
		while (x < size)
		{
			action(array[x]);
			x++;
		}
	}
}
