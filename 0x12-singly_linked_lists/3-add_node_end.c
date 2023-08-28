#include "lists.h"
/**
 * _strlen - string of length to be found
 * @str: string to find the length of 
 * Return: length of string
 */
unsigned int _strlen(char *str)
{
	unsigned int j;

	for (j = 0; str[j]; j++)
		;
	return (j);
}

/**
 * add_node_end - function that adds a new node at the end 
 * @head: double pointer to a linked list
 * @str: string to add to the new nod
 * Return: pointer to the new node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new, *tmp;

	if (str == NULL)
		return (NULL);
	new = malloc(sizeof(list_t));
	if (new == NULL)
		return (NULL);
	new->str = strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->len = _strlen(new->str);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (new);
}
