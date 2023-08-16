#include "function_pointers.h"

/**
  * int_index - returns the index of the first element
  * @array: the elements of an array
  * @size: the size of elements in an array
  * @cmp: is a pointer to the function
  *
  * Return: a pointer to the size of element or 0 , -1
  */
int int_index(int *array, int size, int (*cmp)(int))
{
	int j = 0;

	if (size > 0)
	{
		if (array != NULL && cmp != NULL)
		{
			while (j < size)
			{
				if (cmp(array[j]))
					return (j);

				j++;
			}
		}
	}

	return (-1);
}
