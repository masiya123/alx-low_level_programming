#include "lists.h"
/**
 * sum_listint - sum all the data of (n) in a listint_t linked list.
 * @head: pointer to the first node of element
 * Return: sum all the data
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
