#include "main.h"
#include <string.h>

/**
 * create_file - Cretes a file Create
 * @filename: Points to the name of the file to create.
 * @text_content: A pointer to a string that writes to the file.
 *
 * Tobest_codes
 *
 * Return: If the function fails - -1 or -1 if otherwise
 */

int create_file(const char *filename, char *text_content)
{
	int o = 0;

	if (filename == NULL)
	{
		return (-1);
	}

	o = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0600);

	if (o == -1)
	{
		return (-1);
	}

	if (text_content != NULL)
	{
		size_t length = strlen(text_content);
		ssize_t ret = write(o, text_content, length);

		if (ret == -1)
		{
			close(o);

			return (1);
		}
	}
}
