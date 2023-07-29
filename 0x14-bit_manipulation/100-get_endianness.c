#include "main.h"

/**
 * get_endianess - Checks for endianess
 *
 * Tobest_codes
 * Return: 0 for big endian, 1 for small endian
 */

int get_endianness(void)
{
	unsigned int i = 1;
	char *e = (char *) &i;

	if (*e)
		return (1);
	return (0);
}
