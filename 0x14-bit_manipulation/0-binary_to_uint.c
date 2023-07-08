#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * binary_to_uint - Converts a binary number to unsigned int
 * @b: String containing the binary number
 *
 * Tobest_codes
 *
 * Return: the converted number
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int decimal;
	unsigned int i;

	for (decimal = 0, i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == '1')
			decimal = (decimal << 1) | 1;
		else if (b[i] == '0')
			decimal <<= 1;
		else if (b[i] != '0' && b[i] != '1')
			return (0);
	}

	return (decimal);
}
