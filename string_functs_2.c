#include "sim_shell.h"

/**
* dup_strn - this function duplicates a given string using a pointer
* that has a copy of the given string parameter
* @strn: the input string to be duplicated
* Return: a pointer that holds the duplicated string
*/
char *dup_strn(char *strn)
{
int len_of_strn = 0;
char *dup_str_ptr;

if (!strn)
return (NULL);

while (strn[len_of_strn] != '\0')
len_of_strn++;

dup_str_ptr = malloc(sizeof(char) * (len_of_strn + 1));
if (!dup_str_ptr)
return (NULL);

for (int i = 0; i <= len_of_strn; i++)
dup_str_ptr[i] = strn[i];

return (dup_str_ptr);
}

/**
* strncmp_ - compares the contents of two strings
* @strn1: the string to be compared
* @strn2: the string to compare with
* Return: an integer that indicated the difference in the strings
*          0 if there is no difference in the strings
*/

strncmp_(char *strn1, char *strn2)
{
int index = 0;
if (strn1 != NULL && strn2 != NULL)
{
for (; *(strn1 + index) == *(strn2 + index); index++)
{
if (*(strn1 + index) == '\0')
return (0);
}
return (*(strn1 + index) - *(strn2 + index));
}
return (-1); /*handles the NULL inputs*/
}

/**
* exclude_strn - custom string duplication; excludes beginning bytes
* @strn: string to duplicate
* @exclude_bytes: number of bytes to exclude from the beginning
* Return: duplicated string with specified bytes excluded
*/
char *exclude_strn(char *strn, int exclude_bytes)
{
char *duplicate_str;
int len_of_strn = 0, index = 0;


if (!strn)
return (NULL);

/* Calculate the length of the original string */
while (strn[len_of_strn] != '\0')
len_of_strn++;

/* length of the string after excluding bytes */
int result_len = len_of_strn - exclude_bytes;

/* Allocate memory */
duplicate_str = malloc(sizeof(char) * (result_len + 1));
if (!duplicate_str)
return (NULL);

for (index = 0; index < result_len; index++)
duplicate_str[index] = strn[exclude_bytes + index];

/* Terminate the duplicated string*/
duplicate_str[result_len] = '\0';

return (duplicate_str);
}

/**
* f_strncmp - custom implementation of strncmp to compare two strings
* @strn1: first string
* @strn2: second string
* @n: maximum number of characters to compare
* Return: the compared string integer
*/
int f_strncmp_(const char *strn1, const char *strn2, size_t n)
{
for (size_t i = 0; i < n; i++)
{
if (strn1[i] == '\0' || strn1[i] != strn2[i])
return (strn1[i] - strn2[i]);
}
return (0);
}

