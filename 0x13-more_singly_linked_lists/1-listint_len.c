#include "lists.h"

/**
 * listint_len - number of elements in a linked listint_t list
 * @h: head pointer to the elements
 * Return: number of elements
 *
 */
size_t listint_len(const listint_t *h)
{
	size_t new = 0;

	while (h != NULL)
	{
	h = h->next;
		new++;
	}
	return (new);
}
