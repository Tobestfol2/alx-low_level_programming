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
	int oen, rite, lend = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (lend = 0; text_content[lend];)
			lend++;
	}

	oen = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	rite = write(oen, text_content, lend);

	if (oen == -1 || rite == -1)
		return (-1);

	close(oen);

	return (1);
}
