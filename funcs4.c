#include "shell.h"

/**
 * _strncat - concatenate two strs
 * @dest: input value (dest str).
 * @src: input value (source str).
 * @n: number of char to concatenate.
 * Return: pointer to string be concatenated.
 */

char *_strncat(char *dest, const char *src, int n)
{
	int destLength = 0;
	int srcIndex = 0;

	while (dest[destLength] != '\0')
		destLength++;
	while (srcIndex < n && src[srcIndex] != '\0')
	{
		dest[destLength] = src[srcIndex];
		destLength++;
		srcIndex++;
	}
	dest[destLength] = '\0';
	return (dest);
}

/**
 * _strncpy - copy a string.
 * @dest: destination string.
 * @src: source string.
 * @n: number of char to copy.
 * Return: dest
 */

char *_strncpy(char *dest, const char *src, int n)
{
	int index = 0;

	while (index < n && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}

/**
 * _puts - prints a string, followed by a new line, to stdout
 * @str: string to print
 */

void _puts(char *str)
{
	while (*str != '\0')
	{
		_putchar(*str++);
	}
	_putchar('\n');
}

/**
 * _getline - gets a line from a file descriptor
 * @bfr: buf to store the line.
 * @fd: file descriptor.
 * @bfrsize: size of the buf.
 * Return: number of chars read
 */

ssize_t _getline(char **bfr, size_t *bfrsize, int fd)
{
	ssize_t n_chars = 0;

	if (bfrsize == NULL || bfr == NULL)
		return (-1);
	if (*bfr == NULL)
	{
		*bfr = (char *)malloc(sizeof(char) * 1024);
		if (*bfr == NULL)
			return (-1);
		*bfrsize = 1024;
	}
	n_chars = read(fd, *bfr, *bfrsize);
	if (n_chars == -1)
	{
		free(*bfr);
		return (-1);
	}
	return (n_chars);
}


/**
 * empty_line - execute if no command
 * @l: buffer.
 * Return: 0 or 1.
 */

int empty_line(const char *l)
{
	if (l == NULL)
		return (1);
	while (*l)
	{
		if (!isspace(*l) && *l != '\0')
			return (0);
		l++;
	}
	return (1);
}
