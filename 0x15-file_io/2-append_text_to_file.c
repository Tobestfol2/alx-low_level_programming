#include "main.h"
#include <stdlib.h>
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
	if (!filename)
	{
		return (-1);
	}

	FILE(*file)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		fprintf(fileno,% "s", text_content);
	}

	if (fclose(fileno) == EOF)
	{
		return (-1);
	}

	return (1);
}
