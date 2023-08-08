#include "main.h"

/**
 * create_file - Creates a file.
 * @filename: A pointer that points to the name of the file to create.
 * @text_content: Points to a string to write to the file.
 *
 * Tobest_Codes
 *
 * Return: If the function fails = -1; else = 1
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
