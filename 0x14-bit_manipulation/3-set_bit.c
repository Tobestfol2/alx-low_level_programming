#include "main.h"
#include <stdio.h>

/**
 * set_bit - Sets value of a bit o 1 at a given index
 * @n: decimal number passed by pointer
 * @index: index position to change, starting from 0
 *
 * Tobest_codes
 *
 * Return: 1 if successful, -1 if it's error
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	const unsigned int bit_count = sizeof(unsigned long int) * 8;

	if (index >= bit_count)
	{
		return (-1);
	}

	*n |= (1UL << index);

	return (1);
}
