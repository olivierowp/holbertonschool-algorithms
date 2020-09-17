#include "hash_tables.h"

/**
 * add_node - adds a new node at the beginning of a hash table
 * @head: reference to head of linked list
 * @key: input key
 * @value: value associed with the key
 * Return: 1 if succeeded, 0 otherwise
 */
int add_node(hash_node_t **head, const char *key, const char *value)
{
	hash_node_t *new;

	if (head == NULL)
		return (0);
	new = malloc(sizeof(hash_node_t));
	if (new == NULL)
		return (0);
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(new);
		return (0);
	}
	new->value = strdup(value);
	if (new->value == NULL)
	{
		free(new);
		return (0);
	}
	new->next = *head;
	*head = new;
	return (1);
}

/**
 * hash_table_set - adds an element to the hash table
 * @ht: hash table you want to add or update the key/value to
 * @key: input key, cannot be empty
 * @value: value associated with the key, can be empty
 * Return: 1 if succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int kidx;
	hash_node_t *current;

	if (ht == NULL || key == NULL || value == NULL)
		return (0);
	kidx = key_index(key, ht->size);
	current = ht->array[kidx];
	while (current != NULL)
	{
		if (strcmp(key, current->key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			if (current->value == NULL)
				return (0);
			return (1);
		}
	}
	if (add_node(&ht->array[kidx], key, value) == 0)
		return (0);
	return (1);
}
