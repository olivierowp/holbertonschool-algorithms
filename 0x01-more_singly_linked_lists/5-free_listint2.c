#include "lists.h"

/**
 * free_listint2 - frees a listint_t list
 * @head: double pointer to head of list
 */

void free_listint2(listint_t **head)
{
	listint_t *node;
	listint_t *current;

	if (head == NULL)
	{
		return;
	}
	current = *head;
	while (current != NULL)
	{
		node = current;
		current = current->next;
		free(node);
	}
	*head = NULL;
	head = NULL;
}
