#include "lists.h"
/**
 * list_len - length of the list
 * @h: poniter to the first node
 * Return: number of nodes in the list.
 */
size_t list_len(const list_t *h)
{
	int i = 0;

	while (h)
	{
		i++;
		h = h->next;
	}
	return (i);
}
