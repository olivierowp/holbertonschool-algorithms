#include "lists.h"
/**
 * add_node_end - adds a new node at the end of a list_t list;
 * @head: reference to head of list
 * @str: string to be added to linked list
 * Return: address of new node
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node;
	list_t *last;

	if (str == NULL)
		return (NULL);
	node = malloc(sizeof(list_t));
	if (node == NULL)
		return (NULL);
	node->str = strdup(str);
	if (node->str == NULL)
	{
		free(node);
		return (NULL);
	}
	node->len = _strlen(node->str);
	node->next = NULL;
	if (*head == NULL)
	{
		*head = node;
		return (node);
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->next = node;
	return (last);
}

/**
 * _strlen - returns the length of a string
 * @s: string s
 * Return: length of string
 */
int _strlen(char *s)
{
	char *start = s;

	while (*s)
	{
		s++;
	}
	return (s - start);
}
