#include "lists.h"
/**
 * dlistint_len - the number of elements in a linked dlistint_t list
 * @h: pointer to head of list
 * Return: number of nodes
 */

size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *current = h;
	size_t len = 0;

	while (current != NULL)
	{
		current = current->next;
		len++;
	}
	return (len);
}
