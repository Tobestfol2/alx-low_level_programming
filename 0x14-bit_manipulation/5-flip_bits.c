#include "main.h"
#include <stdio.h>

/**
 * flip_bits - Flip bits to convert one number to another
 * @n: First number
 * @m: Second number to convert to
 *
 * Tobest_codes
 *
 * Return: number of bits that was needed to flip
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flip;
	int counter;

	flip = n ^ m;
	counter = 0;

	while (flip)
	{
		counter++;
		flip &= (flip - 1);
	}
	return (counter);
}
