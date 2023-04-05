#include "lists.h"

/**
 * add_nodeint - Adds a new node at the beginning of a linked list
 * @head: Pointer to the first node in the list
 * @n: value to enter in the new node
 *
 * Tobest_codes
 *
 * Return: pointer to the new code, or NULL if it fails
 */

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = *head;
	*head = new;

	return (new);
}
