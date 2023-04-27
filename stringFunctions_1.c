#include "egshell.h"

int comp_strns(const char *str1, const char *str2);
int compStrn_n(const char *str1, const char *str2, size_t n);
int getPrefix_len(char *str, char *prefix);
char *locateChar(const char *str, char ch);

/**
* comp_strns - Compares two strings.
* @str1: The first string to be compared.
* @str2: The second string to be compared.
*
* Return: Positive integer if str1 > str2
*            0 if str1 = str2
*         Negative integer if str1 < str2
*/

int comp_strns(const char *str1, const char *str2)
{
int i;

for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++)
{
if (str1[i] != str2[i])
{
return (str1[i] - str2[i]);
}
}

if (str1[i] == '\0' && str2[i] == '\0')
{
return (0);
}

return (str1[i] == '\0' ? -str2[i] : str1[i]);
}



/**
* compStrn_n - Compare two strings.
* @str1: Pointer to a string.
* @str2: Pointer to a string.
* @n: The first n bytes of the strings to compare.
*
* Return: Less than 0 if str1 is shorter than str2.
*         0 if str1 and str2 match.
*         Greater than 0 if str1 is longer than str2.
*/
int compStrn_n(const char *str1, const char *str2, size_t n)
{
size_t i;

for (i = 0; i < n && str1[i] && str2[i]; i++)
{
if (str1[i] != str2[i])
break;
}

if (i == n)
return (0);

return (str1[i] - str2[i]);
}

/**
* getPrefix_len - Gets the length of a prefix substring.
* @str: The string to be searched.
* @prefix: The prefix to be measured.
*
* Return: The number of bytes in str which consist only of bytes from prefix.
*/
int getPrefix_len(char *str, char *prefix)
{
bool valid[256] = { false };
int bytes = 0;

for (int i = 0; prefix[i]; i++)
{
valid[(unsigned char)prefix[i]] = true;
}

for (; *str && valid[(unsigned char)*str]; str++, bytes++)
;

return (bytes);
}

/**
* locateChar - Locates a character in a null-terminated string.
* @str: The string to be searched.
* @ch: The character to be located.
*
* Return: If ch is found - a pointer to the first occurrence.
*         If ch is not found - NULL.
*/
char *locateChar(const char *str, char ch)
{
for (; *str && *str != ch; str++)
;
return (*str == ch ? (char *)str : NULL);
}
