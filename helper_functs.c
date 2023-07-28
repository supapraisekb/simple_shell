#include "shell.h"

/**
* _getenv - used to find an environment variable
* @inp_str: the command indicating the requested env variable
* @env_var: the shell environment variables
* Return: the requested env variable
*/
char *_getenv(char *inp_str, list_t *env_var)
{
int i = 0, name_length = 0;

while (env_var != NULL)
{
while ((env_var->str_var)[i] == inp_str[i])
i++;
if (inp_str[i] == '\0' && (env_var->str_var)[i] == '=')
break;
env_var = env_var->node_ptr;
}

while (inp_str[name_length] != '\0') /* determine the name length in bytes */
{
name_length++;
}
while (env_var->str_var[name_length] != '\0')
name_length++;
name_length++; /* because of the equality sign */

return (exclude_strn(env_var->str_var, name_length));
}


/**
* release_ptr - frees up memory allocation allocated to arrays using malloc
* @str_arr: the string arrays
*/
void release_ptr(char **str_arr)
{
int str_index;
for (str_index = 0; str_arr[str_index] != NULL; str_index++)
{
free(str_arr[str_index]);
}
free(str_arr);
}
