#include "shell.h"
/**
 * _strncat - concatenate two strings
 * using at most n bytes from src
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: dest
 */
char *_strncat(char *dest, const char *src, int n)
{
    int destLength = 0;
    int srcIndex = 0;

    while (dest[destLength] != '\0') {
        destLength++;
    }

    while (srcIndex < n && src[srcIndex] != '\0') {
        dest[destLength] = src[srcIndex];
        destLength++;
        srcIndex++;
    }

    dest[destLength] = '\0';

    return (dest);
}

/**
 * _strncpy - copy a string
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: dest
 */
char *_strncpy(char *dest, const char *src, int n)
{
    int index = 0;

    while (index < n && src[index] != '\0') {
        dest[index] = src[index];
        index++;
    }

    while (index < n) {
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
 * @buffer: buffer to store the line
 * @bufsize: size of the buffer
 * @fd: file descriptor
 * Return: number of characters read
 */

ssize_t _getline(char **bfr, size_t *bfrsize, int fd)
{
    ssize_t n_chars = 0;

    if (bfrsize == NULL || bfr == NULL) {
        return (-1);
    }
    
    if (*bfr == NULL) {
        *bfr = (char *)malloc(sizeof(char) * 1024);
        if (*bfr == NULL) {
            return (-1);
        }
        *bfrsize = 1024;
    }
    
    n_chars = read(fd, *bfr, *bfrsize);
    if (n_chars == -1) {
        free(*bfr);
        return (-1);
    }
    
    return (n_chars);
}
