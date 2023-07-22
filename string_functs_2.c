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
return (*(strn1 + index)-*(strn2 + index));
}
return (-1); /*handles the NULL inputs*/
}
