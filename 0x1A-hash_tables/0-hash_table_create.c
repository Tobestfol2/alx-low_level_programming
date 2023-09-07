#include "hash_tables.h"
#include <stdio.h>
#include <stdlib.h>
/**
* hash_table_create - creates a hash table
* @size: the size of the table
* Return: Returns a pointer to table
*
* Tobest_codes
*/

hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_table = NULL;
	unsigned long int i;

	hash_table = malloc(sizeof(hash_table_t));
	if (!hash_table)
		return (NULL);

	hash_table->array = malloc(sizeof(hash_node_t *) * size);
	if (!hash_table->array)
	{
		free(hash_table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		hash_table->array[i] = NULL;
	hash_table->size = size;

	return (hash_table);
}
