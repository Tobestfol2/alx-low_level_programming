#ifndef MAIN_H
#define MAIN_H

/*
 * File: 0x15. C - File I/O
 * Auth: Tobest_codes
 * Desc: Header file of prototypes for all functions
 *       written in the 0x15-file_i/o directory.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif /*MAIN_H*/

