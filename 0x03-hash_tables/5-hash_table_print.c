#include "hash_tables.h"
#include <stdbool.h>

/**
 * hash_table_print - prints a hash table
 * @ht: input ht
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *current;
	_Bool first;

	if (ht == NULL)
		return;
	printf("{");
	first = true;
	for (i = 0; i < ht->size; i++)
	{
		current = ht->array[i];
		while (current != NULL)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", current->key, current->value);
			current = current->next;
			first = false;
		}
	}
	printf("}\n");
}
