#include "main.h"

/**
 * main -prints the alphabet, in lowercase, followed by a new line.
 *
 * Return: o
 */

void print_alphabet(void)

{
	char c = 'a';

	while (c <= 'z')
	{
		_putchar(c);
		c++;

	}

	_putchar('\n');
}
