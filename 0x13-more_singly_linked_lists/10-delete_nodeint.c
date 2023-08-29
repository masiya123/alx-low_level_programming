#include "lists.h"
/**
 * delete_nodeint_at_index - function that deletes the node at index
 * index of a listint_t linked list
 * @head: double pointer to an elements
 * @index: index of node
 * Return: pointer to the index node
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int j;
	listint_t *count1, *next;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		next = (*head)->next;
		free(*head);
		*head = next;
		return (1);
	}
	count1 = *head;
	for (j = 0; j < index - 1; j++)
	{
		if (count1->next == NULL)
			return (-1);
		count1 = count1->next;
	}
	next = count1->next;
	count1->next = next->next;
	free(next);
	return (1);

}
