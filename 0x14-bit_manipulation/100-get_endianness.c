#include "main.h"

/**
 * get_endianess - Checks for endianess
 *
 * Tobest_codes
 * Return: 0 for big endian, 1 for small endian
 */

int get_endianness(void)
{
	int num = 1;
	char *endian = (char *)&num;

	if (*endian == 1)
		return (1);

	return (0);
}
