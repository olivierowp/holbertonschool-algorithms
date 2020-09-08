#include "lists.h"

/**
 * sum_listint - returns the sum of all the data (n) of a
 * listint_t linked list
 * @head: pointer to head of list
 * Return: sum of list
 */
int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *current = head;

	if (head == NULL)
		return (0);
	while (current != NULL)
	{
		sum += current->n;
		current = current->next;
	}
	return (sum);
}
