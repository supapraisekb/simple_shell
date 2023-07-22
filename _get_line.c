#include "sim_shell.h"

/**
* _get_line - stores the user's input command in a buffer
* dynamically obtained by malloc
* @str_buff: buffer holding the string
* Return: the characters in the string
*/
size_t _get_line(char **str_buff)
{
ssize_t index = 0, m_flag = 0, ssize_t count = 0;
ssize_t newline_flag = 0;
char BUFFER[1024];
ssize_t strings_read = 0;

while (newline_flag == 0 &&
		(index = read(STDIN_FILENO, BUFFER, 1024 - 1)))
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
{
strings_read += index;
*str_buff = _strncat(*str_buff, BUFFER);
}
}
return (strings_read);
}
