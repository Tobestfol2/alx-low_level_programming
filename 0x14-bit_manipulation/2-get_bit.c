#include "main.h"
#include <stdio.h>

/**
 * get_bit - get the value of a bit at a given index
 * @n: number to evaluate
 * @index: index starting from 0, of the bit we want to get
 *
 * Tobest_codes
 *
 * Return: Value of bit at index, or -1 if error
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bit_size;

	if (index > 63)
		return (-1);
	bit_size = (n >> index) & 1;

	return (bit_size);
}
