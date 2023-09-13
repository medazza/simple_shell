#include "shell.h"

/**
 * _strdup - duplicate to new memory space location
 * @str: str to duplicates.
 * Return: pointer to dup str.
 */

char *_strdup(const char *str)
{
	int i;
	int length = 0;
	char *duplicate;

	if (str == NULL)
		return (NULL);
	while (str[length] != '\0')
		length++;
	duplicate = (char *)malloc(sizeof(char) * (length + 1));
	if (duplicate == NULL)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		duplicate[i] = str[i];
	duplicate[length] = '\0';
	return (duplicate);
}

/**
 * _strchr - locates a char in a str.
 * @s: input str
 * @c: input c to find in string.
 * Return: pointer to first char find or NULL.
 */

char *_strchr(const char *s, char c)
{
	int i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

/**
 * _strcatpath - concatenates two strs
 * @dest: destination str
 * @src: source str
 * Return: pointer to the concatenated str
 */

char *_strcatpath(const char *dest, const char *src)
{
	size_t i = 0, j = 0;
	char *concat = NULL;
	size_t srcLength = 0;
	size_t destLength = 0;

	while (dest[destLength] != '\0')
		destLength++;
	while (src[srcLength] != '\0')
		srcLength++;
	concat = (char *)malloc(sizeof(char) * (destLength + srcLength + 1));
	if (concat == NULL)
		return (NULL);
	for (i = 0; i < destLength; i++)
		concat[i] = dest[i];
	for (j = 0; j < srcLength; j++)
	{
		concat[i] = src[j];
		i++;
	}
	concat[i] = '\0';
	return (concat);
}

/**
 * _atoi - converts a str to an int.
 * @s: string to be converted.
 * Return: the int converted from the string.
 */

int _atoi(const char *s)
{
	int num = 0;
	int sign = 1;
	bool foundDigit = false;
	int i;

	for (i = 0; s[i] != '\0'; ++i)
	{
		if (s[i] == '-' && !foundDigit)
			sign = -1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			num = num * 10 + (s[i] - '0') * sign;
			foundDigit = true;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
		}
		else
			break;
	}
	return (foundDigit ? num : 0);
}

/**
 * print_err - prints an error message in the prompt.
 * @av: name of the program.
 * @count: number of cmnds entered.
 * @cmnd: cmd entered.
 * @msg: error message.
 */

void print_err(const char *av, int count, const char *cmnd, const char *msg)
{
	char *count_str = NULL;
	size_t argv_len = _constcharlen(av);
	size_t cmd_len = _constcharlen(cmnd);
	size_t msg_len = _constcharlen(msg);
	size_t count_str_len;

	write(STDERR_FILENO, av, argv_len);
	write(STDERR_FILENO, ": ", 2);
	count_str = _itoa(count);
	count_str_len = _constcharlen(count_str);
	write(STDERR_FILENO, count_str, count_str_len);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msg, msg_len);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmnd, cmd_len);
	write(STDERR_FILENO, "\n", 1);
	free(count_str);
}
