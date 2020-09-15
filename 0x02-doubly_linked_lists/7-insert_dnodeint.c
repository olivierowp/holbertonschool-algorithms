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
	unsigned int imax;

	if (h == NULL)
		return (NULL);
	if (idx == 0)
	{
		return (add_dnodeint(h, n));
	}
	current = *h;
	imax = 0;
	while (current != NULL)
	{
		current = current->next;
		imax++;
	}
	if (imax < idx)
		return (NULL);
	if (imax == idx)
		return (add_dnodeint_end(h, n));
	current = *h;
	while (idx > 1)
	{
		printf(">%d\n", idx);
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
