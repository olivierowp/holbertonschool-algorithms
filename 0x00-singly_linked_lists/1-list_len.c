#include "lists.h"

/**
 * print_list - prints all the elements of a list_t list
 * @h: head of list
 * Return: number of elements in linked list
 */
size_t list_len(const list_t *h)
{
	int count;

	count = 0;
	while (h != NULL)
	{
		h = h->next;
		count++;
	}
	return (count);
}
