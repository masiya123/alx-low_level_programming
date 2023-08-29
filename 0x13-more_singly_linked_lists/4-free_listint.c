#include "lists.h"
/**
 * free_listint - function that frees a listint_t lis
 * @head: the head of elements in a list
 * Return: NULL if error
 */
void free_listint(listint_t *head)
{
	listint_t *next;

	while (head != NULL)
	{
		next = head->next;
		free(head);
		head = next;
	}
}
