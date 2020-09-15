
#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to head of list
 * @index: index of node to return
 * Return: node at index
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;
	dlistint_t *current;

	i = 0;
	current = head;
	while (current != NULL)
	{
		if (index == i)
			return (current);
		current = current->next;
		i++;
	}
	return (NULL);
}
