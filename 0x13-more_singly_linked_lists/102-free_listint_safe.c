#include "lists.h"

/**
 * free_listint_safe - Freeing a linked list
 * @h: Points to the first node in the linked list
 *
 * Tobest_cares
 *
 * Return: Number of elements in the freed list
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *temp = NULL;
	size_t count = 0;

	if (h == NULL)
		return (0);

	while (*h != NULL && (*h) >= (*h)->next)
	{
		temp = *h;
		*h = (*h)->next;
		free(temp);
		count++;
	}

	return (count);
}
