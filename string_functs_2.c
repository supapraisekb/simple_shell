#include "sim_shell.h"

/**
* _get_line - stores the user's input command in a buffer
* dynamically obtained by malloc
* @str_buff: buffer holding the string
* Return: the characters in the string
*/
size_t _get_line(char **str_buff)
{
ssize_t index = 0;
ssize_t m_flag = 0;
ssize_t count = 0;
ssize_t newline_flag = 0;
char BUFFER[1024];
ssize_t strings_read = 0;

while (newline_flag == 0 && (index = read(STDIN_FILENO, BUFFER, 1024 - 1)))
{
if (index == -1)
return (-1);

BUFFER[index] = '\0';


while (BUFFER[count] != '\0')
{
if (BUFFER[count] == '\n')
newline_flag = 1;

count++;
}

if (m_flag == 0)
{
index++;
*str_buff = malloc(sizeof(char) * index);
*str_buff = _strncpy(*str_buff, BUFFER);
strings_read = index;
m_flag = 1;
}
else
{
strings_read += index;
*str_buff = _strncat(*str_buff, BUFFER);
}
}
return (strings_read);
}


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
