#include "shell.h"

/**
* _getline - stores the user's input command in a buffer
* dynamically obtained by malloc
* @str_buff: pointer to the buffer holding the string
* Return: the characters read from the user's input
*/
size_t _getline(char **str_buff)
{
ssize_t index = 0;
ssize_t count = 0;
ssize_t newline_flag = 0;
char BUFFER[1024];
ssize_t strings_read = 0;

while (newline_flag == 0 &&
(index = read(STDIN_FILENO, BUFFER, 1024 - 1)) > 0)
{
BUFFER[index] = '\0';

while (BUFFER[count] != '\0')
{
if (BUFFER[count] == '\n')
newline_flag = 1;
count++;
}

if (*str_buff == NULL)
{
*str_buff = malloc(sizeof(char) * (index + 1));
if (*str_buff == NULL)
{
perror("malloc");
return (-1);
}
*str_buff = _strcpy(*str_buff, BUFFER);
strings_read = index;
}
else
{
strings_read += index;
*str_buff = _strcat(*str_buff, BUFFER);
}
}

if (index == -1)
return (-1);

return (strings_read);
}

