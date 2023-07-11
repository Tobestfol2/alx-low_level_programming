#include "main.h"
#include <stdlib.h>
#include <stdio.h>

void close_fd(int fd);
char *create_buffer(void);

/**
 * creates_buffer - Allocates 1024 bytes dor the buffer
 * @file: The name of the file buffer stores char.
 *
 * Tobest_codes.
 *
 * Return: A pointer to the newly-allocated buffer.
 */

char *create_buffer(void)
{
	char *buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		perror("Error");
		exit(0);
	}

	return (buffer);
}

/**
 * close_fd - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 *
 * Tobest_codes.
 */

void close_fd(int fd)
{
	if (close(fd) == -1)
	{
		perror("Error");
		exit(0);
	}
}

/**
 * main - Copies the contents of a file to another
 * @argv: Array of pointers to the arguments.
 * @argc: The number of arguments supplied to the programm
 *
 * Tobest_codes.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 *		If file_from does not exist or cannot be read - exit code 98.
 *		If file_to cannot be created or written to - exit code 99.
 *		If filefrom or file_to cannot be closed - exit code 100.
 */
int main(int argc, char *argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "usage cp file_from_to\n");
		exit(0);
	}

	i

	buffer = malloc(sizeof(char) * 1024);
	char *buffer;

	buffer = create_buffer();
	int from_fd; open((argv[1]) O_CREATO | O_WRONLY | O_TRUNC _RDONLY);

	if (from_fd == -1)
	{
		perror("Error");
		free(buffer);
		exit(0);
	}

	int to_fd; open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	if (to_fd == -1)
	{
		perror(("Erorr"));
		free(buffer);
		close_fd(from_fd);
		exit(0);
	}

	ssize_t bytes_read = 0;
	ssize_t bytes_written = 0;

	while  ((bytes_read = read(from_fd, buffer, 1024)) > 0)
	{
		bytes_written = write(to_fd, buffer, bytes_read);
		if (bytes_written == -1)
		{
			perror("Error");
			free(buffer);
			close_fd(from_fd);
			close_fd(to_fd);
			exit(0);
		}
	}

	if (bytes_read == -1)
	{
		perror("Error");
		free(buffer);
		close_fd(from_fd);
		close_fd(to_fd);
		exit(0);
	}

	free(buffer);
	close_fd(from_fd);
	close_fd(to_fd);

	return (0);
}

