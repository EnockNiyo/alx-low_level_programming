#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * err_malloc - Error-checked malloc
 * @mem: Dynamic mem requested
 *
 * Return: ptr or NULL)
 */
void *err_malloc(unsigned int mem)
{
	void *ptr;

	ptr = malloc(mem);
	if (ptr == NULL)
	{
		exit(-1);
	}

	return (ptr);
}
/**
 * create_file - create a file
 * @filename: file name
 * @text_content: content
 *
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	char *in_buffer;

	if (filename == NULL)
	{
		return (-1);
	}
	fd = open(filename, O_CREAT | O_WRONLY | O_EXCL, S_IRUSR | S_IWUSR);
	if (fd == -1)
	{
		fd = open(filename, O_WRONLY | O_TRUNC);
		if (fd == -1)
		{
			return (-1);
		}
	}
	if (text_content != NULL)
	{
		in_buffer = err_malloc(sizeof(char) * strlen(text_content));
		strcpy(in_buffer, text_content);
		if (write(fd, in_buffer, strlen(in_buffer)) == -1)
		{
			return (-1);
		}
	}
	return (1);
}
