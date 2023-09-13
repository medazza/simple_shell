#include "shell.h"

/**
 * _strlen - returns the length of a string.
 * @s: string.
 * Return: length of str.
 */

size_t _strlen(const char *s)
{
	size_t length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: pointer to copied str.
 */

char *_strcpy(char *dest, const char *src)
{
	int srcLength = 0;
	int i;

	while (src[srcLength] != '\0')
		srcLength++;
	for (i = 0; i < srcLength; i++)
		dest[i] = src[i];
	dest[srcLength] = '\0';
	return (dest);
}

/**
 * _strcmp - compare 2 strings.
 * @s1: input value(first str).
 * @s2: input value(second str).
 *
 * Return: 0 if iquals -1 if not.
 */

int _strcmp(const char *s1, const char *s2)
{
	int ind = 0;

	while (s1[ind] != '\0' && s2[ind] != '\0')
	{
		if (s1[ind] != s2[ind])
			return ((int)(s1[ind] - s2[ind]));
		ind++;
	}
	if (s1[ind] == '\0' && s2[ind] == '\0')
		return (0);
	else if (s1[ind] == '\0')
		return (-1);
	else
		return (1);
}

/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 * Return: pointer to concatenated str.
 */

char *_strcat(char *dest, const char *src)
{
	int destLength = 0;
	int srcIndex = 0;

	while (dest[destLength] != '\0')
		destLength++;
	while (src[srcIndex] != '\0')
	{
		dest[destLength] = src[srcIndex];
		destLength++;
		srcIndex++;
	}
	dest[destLength] = '\0';
	return (dest);
}

/**
 * _strncmp - compares two strs.
 * @str1: first str.
 * @str2: second str.
 * @n: num of bytes to compare.
 * Return: 0 if strs are equal, -1 otherwise.
 */

int _strncmp(const char *str1, const char *str2, int n)
{
	int ind = 0;

	while (ind < n && str1[ind] != '\0' && str2[ind] != '\0')
	{
		if (str1[ind] != str2[ind])
			return ((int)(str1[ind] - str2[ind]));
		ind++;
	}
	if (ind == n)
		return (0);
	return ((int)(str1[ind] - str2[ind]));
}
