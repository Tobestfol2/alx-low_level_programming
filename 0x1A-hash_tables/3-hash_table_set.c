#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * hash_table_set - adds an element to a hash table
 * @ht: a pointer to the hashtable
 * @key: the key of the entry
 * @value: the value of the entry
 * Return: Returns an integer
 * Tobest_codes
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int hash;
	hash_node_t *temp;
	hash_node_t *node;

	if (strlen(key) == 0 || strlen(value) == 0)
		return (0);
	node = malloc(sizeof(hash_node_t));
	if (!node)
		return (0);
	node->key = malloc(strlen(key) + 1);
	node->value = malloc(strlen(value) + 1);
	if (node->key == NULL || node->value == NULL)
	{
		free(node);
		return (0);
	}
	node->next = NULL;
	strcpy(node->key, key);
	strcpy(node->value, value);
	hash =  hash_djb2(key);
	printf("Working here\n");

	/**
	 * if (strcmp(ht->array[hash]->key, node->key) == 0)
	{
		ht->array[hash]->value = node->value;
	}
	*/

	if (ht->array[hash] == NULL)
	{
		ht->array[hash] = node;
	}
	else
	{
		temp = ht->array[hash];
		temp->next = NULL;
		node->next = temp;
	}
	return (1);
}
