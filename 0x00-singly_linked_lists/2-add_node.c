#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: reference to head of linked list
 * @str: string to be added on new node
 * Return: address of new head;
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *firstNode;

	if (str == NULL)
		return (NULL);
	firstNode = malloc(sizeof(list_t));
	if (firstNode == NULL)
		return (NULL);
	firstNode->str = strdup(str);
	if (firstNode == NULL)
	{
		free(firstNode);
		return (NULL);
	}
	firstNode->len = _strlen(firstNode->str);
	firstNode->next = *head;
	*head = firstNode;
	return (firstNode);
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
