#include "main.h"

/**
 * print_binary - Prints the binary equivalent of a decimal number
 * @n: number tp print in binary
 *
 * Tobest_codes
 */
void print_binary(unsigned long int n)
{
	int i, flag = 0;

	unsigned long int mask;

	for (i = 63; i >= 0; i--)
	{
		mask = n >> i;
		if (mask & i)
		{
			_putchar('i');
			flag++;
		}
		else if (flag)
			_putchar('0');
	}
	if (!flag)
		_putchar('0');
}
