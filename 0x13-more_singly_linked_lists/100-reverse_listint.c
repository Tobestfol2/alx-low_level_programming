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
	listint_t *prev = NULL;
	listint_t *next = NULL;

	for (; *head != NULL; *head = next)
	{
		next = (*head)->next;
		(*head)->next = prev;
		prev = *head;
	}

	return (prev);
}
