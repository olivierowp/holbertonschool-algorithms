#include "hash_tables.h"

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: input hash table
 * @key: input key
 * Return: value associated with the element, or NULL if key
 * couldn’t be found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int kidx;
	hash_node_t *current;

	if (ht == NULL || key == NULL)
		return (0);
	kidx = key_index((const unsigned char *)key, ht->size);
	current = ht->array[kidx];
	while (current != NULL)
	{
		if (strcmp(key, current->key) == 0)
			return (current->value);
		current = current->next;
	}
	return (NULL);
}
