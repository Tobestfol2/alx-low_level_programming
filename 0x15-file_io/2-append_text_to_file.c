#include "main.h"
#include <string.h>
#include <stdio.h>
/**
 * append_text_to_file - Appending text at the end of a file.
 * @filename: Points to the name of the file.
 * @text_content: The string to add to the end of the file.
 *
 * Tobest_codes
 *
 * Return: If the function falls or filename is NULL - -1.
 *	    the user lacks write permission if the file does not exist -1
 *	    otherwise -1
 */

int append_text_to_file(const char *filename, char *text_content)
{
	if (filename == NULL)
	{
		return (-1);
	}

	if (text_content == NULL)
	{
		return (1);
	}

	int *o = fopen(filename, "a");

	if (o == NULL)
	{
		return (-1);
	}

	size_t length = strlen(text_content);
	size_t written = fwrite(text_content, sizeof(char), length, o);

	close(o);

	if (written != length)
	{
		return (-1);
	}

	return (1);
}
