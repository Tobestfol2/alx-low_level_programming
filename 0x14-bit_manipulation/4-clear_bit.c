#include "main.h"
#include <stdio.h>

/**
 * clear_bit - Set value of bit to 0 at the index
 * @n: Points to decimal number to change
 * @index: Index position to change
 *
 * Tobest_codes
 *
 * Return: 1 if successful, -1 if not successful
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i;
	unsigned int count;

	if (index > 64)
		return (-1);
	count = index;
	for (i = 1; count > 0; i *= 2, count--)
		;
	if ((*n >> index) & 1)
		*n -= i;

	return (1);
}
