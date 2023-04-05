#include "lists.h"

/**
 * sum_listint - A function to calculate sum of all data in a listint_t list
 * @head: First node in the linked list
 *
 * Tobest_codes
 *
 * Return: The sum of all data
 */

int sum_listint(listint_t *head)
{
	int sum = 0;
	listint_t *temp = head;

	if (head == NULL)
	{
		return (0);
	}

	for (temp = head; temp != NULL; temp->next)
	{
		sum += temp->next;
	}

	return (sum);
}
