#include "shell.h"
/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
size_t _strlen(const char *s)
{
    size_t length = 0;

    while (*s != '\0') {
        length++;
        s++;
    }
    
    return (length);
}

/**
 * char *_strcpy - a function that copies the string pointed to by src
 * @dest: copy to
 * @src: copy from
 * Return: string
 */

char *_strcpy(char *dest, const char *src)
{
    int srcLength = 0;
    int i;

    while (src[srcLength] != '\0') {
        srcLength++;
    }

    for (i = 0; i < srcLength; i++) {
        dest[i] = src[i];
    }
    
    dest[srcLength] = '\0';
    
    return (dest);
}

/**
 * _strcmp - compare string values
 * @s1: input value
 * @s2: input value
 *
 * Return: s1[i] - s2[i]
 */
int _strcmp(const char *s1, const char *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (int)(s1[i] - s2[i]);
        }
        i++;
    }

    if (s1[i] == '\0' && s2[i] == '\0') {
        return 0;
    } else if (s1[i] == '\0') {
        return -1;
    } else {
        return 1;
    }
}

/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 * Return: void
 */
char *_strcat(char *dest, const char *src)
{
    int destLength = 0;
    int srcIndex = 0;

    while (dest[destLength] != '\0') {
        destLength++;
    }

    while (src[srcIndex] != '\0') {
        dest[destLength] = src[srcIndex];
        destLength++;
        srcIndex++;
    }

    dest[destLength] = '\0';

    return (dest);
}

/**
 * _strncmp - compares two strings
 * @str1: first string
 * @str2: second string
 * @n: number of bytes to compare
 * Return: 0 if strings are equal, -1 if not
 */

int _strncmp(const char *str1, const char *str2, int n)
{
    int i = 0;

    while (i < n && str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return (int)(str1[i] - str2[i]);
        }
        i++;
    }

    if (i == n) {
        return 0;
    }
    
    return (int)(str1[i] - str2[i]);
}
