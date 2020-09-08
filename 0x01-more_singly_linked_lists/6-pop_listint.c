#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list,
 * and returns the head node’s data (n)
 * @head: double pointer to head of list;
 * Return: value at head
 */
int pop_listint(listint_t **head)
{
	listint_t *current;
	int value;

	if (head == NULL || *head == NULL)
		return (0);
	current = *head;
	value = current->n;
	*head = current->next;
	free(current);
	return (value);
}
