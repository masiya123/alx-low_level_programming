#include "lists.h"
/**
 * insert_nodeint_at_index - function that inserts a
 * new node at a given position
 * @head: double pointer of element
 * @idx: index of the nodes
 * @n: new node value
 * Return: the address of new node
 */
listint_t *insert_nodeint_at_index(listint_t **head,
		unsigned int idx, int n)
{
	unsigned int j;
	listint_t *count1, *count2;

	if (head == NULL)
		return (NULL);
	if (idx != 0)
	{
		count1 = *head;
		for (j = 0; j < idx - 1 && count1 != NULL; j++)
		{
			count1 = count1->next;
		}
		if (count1 == NULL)
			return (NULL);
	}
	count2 = malloc(sizeof(listint_t));
	if (count2 == NULL)
		return (NULL);
	count2->n = n;
	if (idx == 0)
	{
		count2->next = *head;
		*head = count2;
		return (count2);
	}
	count2->next = count1->next;
	count1->next = count2;
	return (count2);
}
