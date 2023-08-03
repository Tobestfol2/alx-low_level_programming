#include "main.h"
#include <stdio.h>

/**
 * print_binary -prints the binary equivalent of a decimal number
 * @n: number to print in binary
 *
 * Tobest_codes
 */

void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);
	putchar((n & 1) + '0');
}
