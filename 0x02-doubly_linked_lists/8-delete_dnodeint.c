#include "lists.h"
/**
 * delete_dnodeint_at_index - deletes the node at index
 * of a dlistint_t linked list
 * @head: double point to head of linked list
 * @index: index of node to be deleted
 * Return: 1 if success, -1 if failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int len;

	if (head == NULL || *head == NULL)
		return (-1);
	current = *head;
	len = 0;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	if (index + 1 > len)
		return (-1);
	current = *head;
	if (index == 0)
		*head = current->next;
	while (index != 0)
	{
		index--;
		current = current->next;
	}
	if (current->prev != NULL)
		current->prev->next = current->next;
	if (current->next != NULL)
		current->next->prev = current->prev;
	free(current);
	return (1);
}
