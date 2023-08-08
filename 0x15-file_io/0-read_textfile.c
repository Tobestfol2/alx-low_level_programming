#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX standdard output
 * @filename: Points to the name of the file.
 * @letters: Number of letters function reads and print.
 *
 * Tobest_codes.
 *
 * Return: Actual number of bytes read and printed,
 * 0 when function fails or filename is NULL.
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o;
	ssize_t t;
	ssize_t w;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	t = read(o, buf, letters);
	w = write(STDOUT_FILENO, buf, t);

	if (0 == -1 || t == -1 || w == -1 || w != t)
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(o);

	return (w);
}

