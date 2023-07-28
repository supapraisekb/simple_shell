#include "shell.h"

/**
* handle_recurr_delim - this function returns a new string but
* excludes any delimiter previously entered
* @strn:  entered string
* @delim: the delimiter character
* Return: the string without the recurring delimiter
*/

char *handle_recurr_delim(char *strn, char delim)
{
size_t start_index = 0;
size_t len_of_strn = _strnlen(strn);

while (start_index < len_of_strn && strn[start_index] == delim)
{
start_index++;
}
return (&strn[start_index]);
}


/**
* tok_strnlen - handles the token's length using in the
* @strn: the token in consideration
* @strn_index: the index postion of the input commands
* @delim: delimeters used in the command
* Return:  the total length of the toekn
*/

int tok_strnlen(char *strn, int strn_index, char delim)
{
int tok_len = 0;
while ((strn[strn_index] != delim) && (strn[strn_index] != '\0'))
{
strn_index++;
tok_len++;
}

return (tok_len);
}

/**
* num_of_delims - computes the delimiters in a user's command
* @strn: input from the user
* @delim: delimiter present in the input
* Return: The number of delimiters
*/
int num_of_delims(char *strn, char delim)
{
int index = 0;
int delim_count = 0;

for (index = 0; strn[index] != '\0'; index++)
{
if ((strn[index] == delim) && (strn[index + 1] != delim))
{
delim_count++;
}

if ((strn[index] == delim) && (strn[index + 1] == '\0'))
{
delim_count--;
}
}

return (delim_count);
}



/**
*total_delim - calculates all delimiter occurrences in a string
* @strn: command string entered by user
* @delim_count: delimiter character to count
* Return: number of delimiters
*/
int total_delim(char *strn, char delim_count)
{
int index = 0;

for (index = 0; strn[index] != '\0'; index++)
{
if (strn[index] == delim_count)
{
delim_count++;
}
}

return (delim_count);
}
