#include "lists.h"

/**
 * add_dnodeint_end - adds node to end of doubly linked list
 * @head: pointer to head of list
 * @n: integer value of node
 * Return: pointer to node added
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *current;

	if (head == NULL)
	{
		return (NULL);
	}
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	current = *head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = new;
	new->prev = current;
	return (new);
}
