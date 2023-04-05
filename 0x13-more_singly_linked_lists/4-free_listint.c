#include "lists.h"

/**
 * free_listint - frees a linked list
 * @head: listint_t list to be freed
 *
 * Tobest_codes
 *
 */

void free_listint(listint_t *head)
{
	listint_t *current = head;
	while (current != NULL)
	{
		listint_t *temp = current;

		current = current->next;
		free(temp);
	}
}
