#include "lists.h"
/**
 * print_list - print all element in a sigly linked list 
 * @h: head of the elements of counts
 * Return: the number of nodes in the list
 */
size_t print_list(const list_t *h)
{
	int i = 0;

	while (h)
	{
		if (h->str == NULL)
		{
			printf("[0] (nil)\n");
		}
		else
		{
		printf("[%d] %s\n", h->len, h->str);
		}
		i++;
		h = h->next;
	}
	return (i);
}
