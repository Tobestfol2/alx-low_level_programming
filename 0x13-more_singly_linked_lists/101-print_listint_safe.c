#include "lists.h"

/**
 * print_listint_safe - To print a linked list with loop safely
 * @head: Points to the 1st node of the linked list
 *
 * Tobest_codes
 *
 * Return: new_node
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *l_n = NULL;
	const listint_t *tmp_n = NULL;
	size_t new_n;
	size_t counter = 0;

	l_n = head;
	while (l_n)
	{
		printf("[%p] %d\n", (void *)l_n, l_n->n);
		counter++;
		l_n = l_n->next;
		tmp_n = head;
		new_n = 0;
		while (new_n < counter)
		{
			if (l_n == tmp_n)
			{
				printf("-> [%p] %d\n", (void *)l_n, l_n->n);
				return (counter);
			}
			tmp_n = tmp_n->next;
			new_n++;
		}
		if (!head)
			exit(98);
	}
	return (counter);
}
