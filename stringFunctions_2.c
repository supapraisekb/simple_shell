#include "egshell.h"

char *strConcat_n(char *dest, const char *src, size_t n);
int lenofStrn(const char *s);
char *copyStrn(char *dest, const char *src, size_t n);
char *strConcat(char *dest, const char *src, size_t n);
char *dupString(const char *str);

/**
* strConcat_n - Concatenates two strings where `n` number of
*                  bytes are copied from the source.
* @dest: A pointer to the destination string.
* @src: A pointer to the source string.
* @n:   Number of bytes to copy from src
*
* Return: (pointer) to concatenated string.
*/
char *strConcat_n(char *dest, const char *src, size_t n)
{
size_t dest_len = lenofStrn(dest);
size_t i;

for (i = 0; i < n && src[i] != '\0'; i++)
dest[dest_len + i] = src[i];

dest[dest_len + i] = '\0';

return (dest);
}

/**
* lenofStrn - Returns the length of a string.
* @s: A pointer to the character string.
*
* Return: (Integer) The length of the character string.
*/
int lenofStrn(const char *s)
{
if (!s)
return (0);

int len;
for (len = 0; *s != '\0'; s++)
len++;

return (len);
}

/**
* copyStrn - Copies the string pointed to by src, including the
*               terminating null byte, to the buffer pointed by des.
*@dest: Pointer to the destination of copied string.
*@src: Pointer to the src of the source string.
*@n: the maximum number of bytes to be copied
*
* Return: (Pointer) to dest.
*/
char *copyStrn(char *dest, const char *src, size_t n)
{
size_t i;

for (i = 0; i < n && src[i] != '\0'; i++)
{
dest[i] = src[i];
}

dest[i] = '\0';
return (dest);
}


/**
* strConcat - Concatenates two strings.
* @dest: A pointer to the destination string.
* @src: A pointer to the source string.
* @n: Maximum number of bytes to copy from src.
*
* Return: (Pointer) to destination string.
*/
char *strConcat(char *dest, const char *src, size_t n)
{
size_t dest_len = (dest);
size_t src_len = lenofStrn(src);
size_t i;

for (i = 0; i < n && src[i] != '\0'; i++)
dest[dest_len + i] = src[i];

if (i >= n)
dest[dest_len + n] = '\0';

else
dest[dest_len + src_len] = '\0';

return (dest);
}

/**
* dupString - Duplicates a string.
* @str: A pointer to the string to be duplicated.
*
* Return: (Pointer) to the duplicated string.
*/
char *dupString(const char *str)
{
char *duplStr = malloc(lenofStrn(str) + 1);
if (!duplStr)
return (NULL);
return (copyStrn(duplStr, str, lenofStrn(str) + 1));
}
