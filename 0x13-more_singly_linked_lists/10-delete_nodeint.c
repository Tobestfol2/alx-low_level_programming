#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node in a linked list,
 * at a particular index
 * @head: Points to the first element in the list
 * @index: Index of node to be deleted
 *
 * Tobest_codes
 *
 * Return: 1 (Succeded), or -1(Failed)
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	if (head == NULL || *head == NULL)
		return (-1);

	listint_t *current = *head;


	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}

	for (unsigned int i = 0; current != NULL && i < index - 1; i++)
		current = current->next;

	if (current == NULL || current->next == NULL)
		return (-1);

	listint_t *next_node = current->next->next;

	free(current->next);
	current->next = next_node;

	return (1);
}
