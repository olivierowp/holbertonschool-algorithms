#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index
 * index of a listint_t linked list
 * @head: double pointer to head of list
 * @index: index of node to be deleted
 * Return: 1 if success, 1 if fail
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current, *next;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);
	current = *head;
	if (index == 0)
	{
		*head = current->next;
		free(current);
		return (1);
	}
	i = 0;
	while (current != NULL)
	{
		if (i == index - 1)
		{
			break;
		}
		i++;
		current = current->next;
	}
	if (current == NULL || current->next == NULL)
	{
		return (-1);
	}
	next = current->next->next;
	free(current->next);
	current->next = next;
	return (1);
}
