#include "lists.h"
/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to head of list
 * @idx: index to insert node
 * @n: number of node added
 * Return: node inserted
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *current, *new;
	unsigned int len;

	if (h == NULL)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));
	current = *h;
	len = 0;
	while (current != NULL)
	{
		current = current->next;
		len++;
	}
	if (idx > len)
		return (NULL);
	if (idx == len)
		return (add_dnodeint_end(h, n));
	current = *h;
	idx = idx - 1;
	while (idx != 0)
	{
		current = current->next;
		idx--;
	}
	new = malloc(sizeof(dlistint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = current->next;
	new->prev = current;
	current->next->prev = new;
	current->next = new;
	return (new);
}
