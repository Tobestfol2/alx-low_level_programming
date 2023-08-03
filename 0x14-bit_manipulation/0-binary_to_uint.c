#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * binary_to_uint - Converts a binary number to unsigned unary.
 * @b: String containing the binary number
 *
 * Tobest_codes
 *
 * Return: the converted number
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int n = 0;

	if (b == NULL)
		return (0);

	for (; *b != '\0'; b++)
	{
		if (*b != '0' && *b != '1')
		return (0);

	n = n << 1;
	n += (*b - '0');
	}

	return (n);
}
