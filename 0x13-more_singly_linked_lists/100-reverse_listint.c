#include "lists.h"
/**
 * reverse_listint - function that reverses a listint_t linked list.
 * @head: a head to the pointers
 * Return: pointer to the node of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *revsd, *next;

	if (head == NULL || *head == NULL)
		return (NULL);
	if ((*head)->next == NULL)
		return (*head);
	revsd = NULL;
	while (*head != NULL)
	{
		next = (*head)->next;
		(*head)->next = revsd;
		revsd = *head;
		*head = next;
	}
	*head = revsd;
	return (*head);
}
