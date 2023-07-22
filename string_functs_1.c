#include "sim_shell.h"
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
* _strncat - this function concatenates two strings
* @src: the string to join to another
* @dest: the string to be joined to
* Return: the concatenated strings
*/
char *_strncat(char *dest, char *src)
{
size_t dest_len = _strlen(dest);
size_t src_len = _strlen(src);
char *conct_str;

conct_str = realloc(dest, dest_len + src_len + 1);

if (conct_str == NULL)
return (NULL);

strcat(conct_str, src);

return (conct_str);
}

/**
* _strncpy - copies a string from a source to a specified destination
* @dest: where the string is copied to
* @str: the string to be copied
*Return: the new string
*/

char *_strncpy(char *dest, char *str)
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

/**
*conv_to_str - converts an integer to string
*@num: the integer or number
*Return: the converted string on success
*     NULL on failure
*/
char *conv_to_str(int num)
{

int single_digits = num;
int number_in_ten = 1;
int index = 0;
int neg_flag = (num < 0) ? 1 : 0;
char *converted_str;

converted_str = malloc(sizeof(char) *
		(_zerosCounter(single_digits) + 2 + neg_flag));
if (converted_str == NULL)
return (NULL);

if (num < 0)
{
converted_str[index] = '-';
index++;
single_digits *= -1;

}
while (single_digits > 9 || single_digits < -9)
{
single_digits /= 10;
number_in_ten *= 10;
}

while (number_in_ten >= 1)
{
converted_str[index] = (single_digits / number_in_ten) +'0';
index++;
single_digits %= number_in_ten;
number_in_ten /= 10;
}
converted_str[index] = '\0';
return (converted_str);
}

