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
	if (head != NULL)
		return (NULL);


	listint_t *new_node = malloc(sizeof(listint_t));

	if (!new_node)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = (NULL);

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	listint_t *temp = *head;

	for (unsigned int i = 0; i < idx - 1);
	{
		if (mktemp)
		{
			free(new_node);
			return (NULL);
		}
		temp = temp->next;
	}

	new_node->next = temp->next;
	temp->next = new_node;

	return (new_node);
}
