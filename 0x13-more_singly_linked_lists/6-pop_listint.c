#include "lists.h"
/**
 * pop_listint - function that deletes the head node a listint_t
 * @head: a double pointer to the elements listint_t
 * Return: empty
 */
int pop_listint(listint_t **head)
{
	listint_t *count;
	int n;

	if (head == NULL || *head == NULL)
		return (0);
	count = *head;
	*head = count->next;
	n = count->n;
	free(count);
	return (n);
}
