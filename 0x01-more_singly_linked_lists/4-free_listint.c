#include "lists.h"

/**
 * free_listint - frees a listint_t list
 * @head: pointer to head of list
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		current = head->next;
		free(head);
		head = current;
	}
	head = NULL;
}
