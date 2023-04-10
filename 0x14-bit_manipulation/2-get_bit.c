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
	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}

	return ((n >> index) & 1);
}

int main(void)
{
	unsigned long int n = 64;
	unsigned int index = 2;

	int binary = set_bit(unsigned int, unsigned long int *n, index);

	if (binary == -1)
	{
		printf("Error: Invalid index|n");
	}

	else
	{
		printf("B value at index %d of number %lu", index, n, binary);

	}

	return (0);
}
