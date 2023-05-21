#include "main.h"

/**
 * append_text_to_file - as named
 * @filename: file to append to
 * @text: text to append
 *
 * Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text)
{
	int fd;

	if (filename == NULL)
	{
		return (-1);
	}
	fd = open(filename, O_APPEND | O_WRONLY);
	if (fd == -1)
	{
		return (-1);
	}
	if (text != NULL)
	{
		if (write(fd, text, strlen(text)) == -1)
		{
			return (-1);
		}
	}
	close(fd);
	return (1);
}
