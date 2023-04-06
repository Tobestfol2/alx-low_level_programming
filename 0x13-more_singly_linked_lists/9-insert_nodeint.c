#include "lists.h"

/**
 * insert_nodeint_at_index - inserting a new node in a linked list,
 * at a given position
 * @head: Pointer to the first node in the list
 * @idx: Index where the new code is added
 * @n: Data to insert in the new code
 *
 * Tobest_codes
 *
 * Return: Pointer to the node
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current;
	unsigned int i;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	current = *head;
	i = 0;
	while (i < idx - 1 && current != NULL)
	{
		current = current->next;
		i++;
	}

	if (current == NULL)
		return (NULL);

	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
