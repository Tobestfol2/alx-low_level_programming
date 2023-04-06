#include "lists.h"

/**
 * reverse_listint - Reverse a linked list
 * @head: Pointes to the first node in the list
 *
 * Tobest_codes
 *
 * Return: Pointer to the first node in the new list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev_node = NULL;
	listint_t *temp_node = *head;
	listint_t *next_node = NULL;

	while (temp_node != NULL)
	{
		next_node = temp_node->next;
		temp_node->next = prev_node;
		prev_node = temp_node;
		temp_node = next_node;
	}
	*head = prev_node;
	return (prev_node);
}
