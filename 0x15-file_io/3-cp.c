#include "main.h"

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The file buffer stores chars for.
 *
 *  Tobest_Codes
 *
 * Return: Points to the newly-allocated buffer.
 */

char *create_buffer(char *file)
{
	char *buff_er;

	buff_er = malloc(sizeof(char) * 1024);

	if (buff_er == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buff_er);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */

void close_file(int fd)
{
	int klose;

	klose = close(fd);

	if (klose == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: No. of arguments given to the program.
 * @argv: Arrya pointers to the arguments.
 *
 * Tobest_Codes
 *
 * Return: 0 on success.
 *
 * Note: If the argument count is incorrect - exit code 97.
 *       If file_from does not exist or cannot be read - exit code 98.
 *       If file_to cannot be created or written to - exit code 99.
 *       If file_to or file_from cannot be closed - exit code 100.
 *
 *       Tobest_Codes
 */


int main(int argc, char *argv[])
{
	int from, to, r_ead, rite;
	char *buff_er;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buff_er = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	r_ead = read(from, buff_er, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || r_ead == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't read from file %s\n", argv[1]);
			free(buff_er);
			exit(98);
		}

		rite = write(to, buff_er, r_ead);
		if (to == -1 || rite == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buff_er);
			exit(99);
		}

		r_ead = read(from, buff_er, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	} while (r_ead > 0);
	free(buff_er);
	close_file(from);
	close_file(to);
	return (0);
}
