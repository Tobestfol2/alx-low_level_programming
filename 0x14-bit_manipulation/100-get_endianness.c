#include "main.h"

/**
 * get_endianess - Checks for endianess
 *
 * Tobest_codes
 * Return: 0 for big endian, 1 for small endian
 */

int get_endianness(void)
{
	int num;

	num = 1;
	if (*(char *)&num == 1)
		return (1);
	else
		return (0);
}
