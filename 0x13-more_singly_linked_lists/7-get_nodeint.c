#include "lists.h"
/**
 * get_nodeint_at_index - founction of nth node of a listint_t linked list
 * @head: pointer of the first node
 * @index: index is the elements index of the node
 * Return: pointer of Index
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int j;

	if (head == NULL)
		return (NULL);
	for (j = 0; j < index; j++)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
	}
	return (head);
}
