#include "main.h"

/**
 * main -prints the alphabet, in lowercase, followed by a new line.
 *
 * Return: o
 */

void _putchar__alphabet(void)

{
	char c = 'a';

	while (c <= 'z')
	{
		_putchar(c);
		c++;

	}

	_putchar('\n');
}