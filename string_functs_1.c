#include "shell.h"
#include <string.h>
#include <math.h>

/**
* _zerosCounter - calculates the zeros
* @num: the number
*Return: the digits counted
*/

int _zerosCounter(int num)
{
int counter = 0;

for (; num > 9 || num < -9; num /= 10)
{
counter++;
}

return (counter);
}

/**
* _strlen - finds the length of a string
* @s: string to determine the length of
* Return: length of the string
*/
int _strlen(const char *s)
{
int length = 0;

if (s == NULL)
return (0);
while (s[length] != '\0')
{
length++;
}
return (length);
}

/**
* _strcat - this function concatenates two strings
* @src: the string to join to another
* @dest: the string to be joined to
* Return: the concatenated strings
*/
char *_strcat(char *dest, char *src)
{
size_t dest_len = _strlen(dest), index;
size_t src_len = _strlen(src);
char *conct_str;

conct_str = realloc(dest, dest_len + src_len + 1);

if (conct_str == NULL)
return (NULL);

for (index = 0; index < src_len; index++)
{
conct_str[dest_len + index] = src[index];
}
conct_str[dest_len + src_len] = '\0';
return (conct_str);
}

/**
* _strcpy - copies a string from a source to a specified destination
* @dest: where the string is copied to
* @str: the string to be copied
*Return: the new string
*/

char *_strcpy(char *dest, char *str)
{
int index = 0;


while (str[index] != '\0')
{
dest[index] = str[index];
index++;
}

dest[index] = '\0';
return (dest);
}

