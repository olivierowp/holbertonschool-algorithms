#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: input hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current, *deleting;

	if (ht == NULL)
		return;
	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			deleting = current;
			free(deleting->key);
			if (deleting->value != NULL)
				free(deleting->value);
			current = current->next;
			free(deleting);
		}
	}
	free(ht->array);
	free(ht);
}
