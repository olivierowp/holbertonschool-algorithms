#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: double pointer to head of list
 * @idx: index to add new node
 * @n: value at new node
 * Return: address of new node, or NULL if failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *current, *new;
	unsigned int i;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}
	i = 0;
	current = *head;
	while (current != NULL)
	{
		if (i == idx - 1)
		{
			new->next = current->next;
			current->next = new;
			return (new);
		}
		current = current->next;
		i++;
	}
	return (NULL);
}
