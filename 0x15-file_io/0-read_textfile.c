#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stddef.h>
/**
 * e_malloc - error checked malloc
 * @mem_size: dynamic memory size requested
 *
 * Return: pointer to dynamic mem
 */

void *e_malloc(unsigned int mem_size)
{
	void *ptr;

	ptr = malloc(mem_size);
	if (ptr == NULL)
	{
		perror("mem allocation failed");
		exit(-1);
	}
	return (ptr);
}

/**
 * read_textfile - reads texts file
 * @filename: file to read
 * @letters: Number of chars to be read
 *
 * Return: chars printed actually
 */


ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	char *buffer;
	ssize_t ret;
	ssize_t ret2;

	if (filename == NULL)
	{
		return (0);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		return (0);
	}
	buffer = e_malloc(sizeof(char) * letters);
	ret = read(fd, buffer, letters);
	if (ret == -1)
	{
		return (0);
	}
	ret2 = write(STDOUT_FILENO, buffer, ret);
	if (ret2 != (ssize_t) ret)
	{
		return (0);
	}
	free(buffer);
	close(fd);
	return (ret);
}

