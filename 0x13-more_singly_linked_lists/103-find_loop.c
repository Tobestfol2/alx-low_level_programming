#include "lists.h"


/**
 * find_listint_loop - Finds the loop in a linked list
 * @head: linked list begining
 *
 * Tobest_codes
 *
 * Return: address of the code where the loop starts or NULL
 */

listint_t *find_listint_loop(listint_t *head)
{
	listint_t *search = head;
	listint_t *stop = head;

	while (stop != NULL && stop->next != NULL)
	{
		search = search->next;
		stop = stop->next->next;

		if (search == stop)
		search = head;


		while (search != stop)
		{
			search = search->next;
			stop = stop->next;
		}

		return (stop);
	}

	return (NULL);
}
