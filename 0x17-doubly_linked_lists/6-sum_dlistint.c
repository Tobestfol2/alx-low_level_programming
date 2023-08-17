#include "lists.h"

/**
 * sum_dlistint - returns the sum of all data (n)
 * of doubly linked-list
 *
 * @head: head of the list
 *
 * Tobest_codes
 *
 * Return: sum of the data
 */
int sum_dlistint(dlistint_t *head)
{
	int sum;

	sum = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;
		while (head != NULL)
		{
			sum += head->n;
			head = head->next;
		}
	}
	return (sum);
}
