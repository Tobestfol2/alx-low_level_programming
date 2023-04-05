#include "lists.h"

/**
 * get_nodeint_at_index - Returns the code at a certain index in a linked list
 * @head: First node in the linked list
 * @index: Index of the node to return
 *
 * Tobest_codes
 *
 * Return: Pointer to the node we need or NULL
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp = head;

	while (temp && i < index)
	{
		temp = temp->next;
		i++;
	}

	return (temp ? temp : NULL);
}
