#include "main.h"

/**
 * binary_to_unit - Converts a binary number to unsigned int
 * @b: String containing the binary number
 *
 * Tobest_codes
 *
 * Return: the converted number
 */
unsigned int binary_to_unit(const char *b)
{
	int i;
	unsigned int binary = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > 'i')
			return (0);
		binary = 2 * binary + (b[i] - "0");
	}
	return (binary);
}