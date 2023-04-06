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
	listint_t *current = head;

	while (current)
	{
		sum = sum + current->n;
		current = current->next;
	}
	return (sum);
}
