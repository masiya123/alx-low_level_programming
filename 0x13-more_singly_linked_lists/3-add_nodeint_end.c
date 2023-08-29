#include "lists.h"
/**
  * add_nodeint_end - add node in the end of the istint_t list.
  * @head: head of double pointer to elements
  * @n: int add the list
  * Return: NULL if it failed
  */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *counts1;
	listint_t *counts2;

	if (head == NULL)
		return (NULL);
	counts1 = malloc(sizeof(listint_t));
	if (counts1 == NULL)
		return (NULL);
	counts1->n = n;
	counts1->next = NULL;
	if (*head == NULL)
	{
	*head = counts1;
		return (counts1);
	}
	counts2 = *head;
	while (counts2->next != NULL)
	{
		counts2 = counts2->next;
	}
	counts2->next = counts1;
	return (counts1);
}
