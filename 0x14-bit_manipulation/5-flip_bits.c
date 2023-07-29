#include "main.h"
#include <stdio.h>

/**
 * flip_bits - Flip bits to convert one number to another
 * @n: First number
 * @n: Second number to convert to
 *
 * Tobest_codes
 *
 * Return: number of bits that was needed to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int counter = 0;
	unsigned long int xor = n ^ m;

	while (xor)
	{
		counter += xor & 1;
		xor >>= 1;
	}
	return (counter);
}
