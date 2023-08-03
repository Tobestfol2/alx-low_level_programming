#include "main.h"
#include <stdio.h>

/**
 * set_bit -Sets value of a bit or 1 at a given index
 * @n: decimal number passed by poniter
 * @index: index position to change, starting from 0
 *
 * Tobest_codes
 *
 * Return: 1 if succesfsul, -1 if it's error
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	int cover;

	if (index > 63)
	{
		return (-1);
	}

	cover = 1 << index;

	*n = (*n & ~cover) | (1 << index);
	return (1);
}
