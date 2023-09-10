#include "shell.h"
/**
 * _strtok - tokenizes a string
 * @str: string to tokenize
 * @delim: delimiter
 * Return: pointer to the first token found
 */

char *_strtok(char *str, const char *delim)
{
    static char *nextToken;
    char *tokenStart;
    char *delimPtr;

    if (str != NULL) {
        nextToken = str;
    }
    
    if (nextToken == NULL) {
        return NULL;
    }
    
    tokenStart = nextToken;
    delimPtr = _strchr(tokenStart, *delim);

    if (delimPtr != NULL) {
        *delimPtr = '\0';
        nextToken = delimPtr + 1;
    } else {
        nextToken = NULL;
    }
    
    return (tokenStart);
}

/**
 * _itoa - converts an integer to a string
 * @num: integer to be converted
 * Return: pointer to the converted string
 */

char *_itoa(int num)
{
    int i = 0, j = 0, k = 0;
    char *str = NULL;
    int m;
    
    int isNegative = 0;
    
    if (num == 0) {
        str = (char *)malloc(sizeof(char) * 2);
        if (str == NULL) {
            return NULL;
        }
        str[0] = '0';
        str[1] = '\0';
        return str;
    }
    
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }
    
    m = num;
    while (m != 0) {
        m /= 10;
        i++;
    }
    
    str = (char *)malloc(sizeof(char) * (i + 1 + isNegative));
    if (str == NULL) {
        return NULL;
    }
    
    if (isNegative) {
        str[0] = '-';
    }
    
    for (j = i + isNegative - 1; j >= isNegative; j--) {
        k = num % 10;
        str[j] = k + '0';
        num /= 10;
    }
    
    str[i + isNegative] = '\0';
    return str;
}

/**
 * _constcharlen - counts the number of characters in a constant string
 * @str: constant string
 * Return: number of characters in the string
 */

size_t _constcharlen(const char *str)
{
    size_t length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

/**
 * *_realloc - reallocates a memory block using malloc and free
 * @ptr: pointer to the memory previsouly allocated by malloc
 * @old_size: size of the allocated memory for ptr
 * @new_size: new size of the new memory block
 *
 * Return: pointer to the newly allocated memory block
 */
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
    char *new_ptr;
    char *old_ptr;
    size_t i;

    if (new_size == old_size) {
        return ptr;
    }

    if (new_size == 0 && ptr) {
        free(ptr);
        return NULL;
    }

    if (!ptr) {
        return malloc(new_size);
    }

    new_ptr = malloc(new_size);
    if (!new_ptr) {
        return NULL;
    }

    old_ptr = ptr;

    if (new_size < old_size) {
        for (i = 0; i < new_size; i++) {
            new_ptr[i] = old_ptr[i];
        }
    } else {
        for (i = 0; i < old_size; i++) {
            new_ptr[i] = old_ptr[i];
        }
    }

    free(ptr);
    return new_ptr;
}


/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
