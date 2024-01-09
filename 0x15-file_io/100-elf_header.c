#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output.
 * @filename: The name of the file to be read.
 * @letters: The number of letters it should read and print.
 * 
 * Return: The actual number of letters it could read and print.
 *         0 on failure (file cannot be opened or read, filename is NULL,
 *         write fails, or does not write the expected amount of bytes).
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
    int file_descriptor;
    ssize_t bytes_read, bytes_written;
    char *buffer;

    if (filename == NULL)
        return (0);

    file_descriptor = open(filename, O_RDONLY);
    if (file_descriptor == -1)
        return (0);

    buffer = malloc(sizeof(char) * letters);
    if (buffer == NULL)
    {
        close(file_descriptor);
        return (0);
    }

    bytes_read = read(file_descriptor, buffer, letters);
    if (bytes_read == -1)
    {
        free(buffer);
        close(file_descriptor);
        return (0);
    }

    bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
    if (bytes_written == -1 || bytes_written != bytes_read)
    {
        free(buffer);
        close(file_descriptor);
        return (0);
    }

    free(buffer);
    close(file_descriptor);
    return (bytes_written);
}

