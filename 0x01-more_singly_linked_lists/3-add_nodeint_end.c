#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: double pointer to head of list
 * @n: integer to be added
 * Return: address of node added
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new;
	listint_t *node;

	if (head == NULL)
	{
		return (NULL);
	}
	new = malloc(sizeof(listint_t));
	if (new == NULL)
	{
		return (NULL);
	}
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		node = *head;
		while (node->next != NULL)
		{
			node = node->next;
		}
		node->next = new;
	}
	new->n = n;
	new->next = NULL;
	return (*head);
}
