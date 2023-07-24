#include "sim_shell.h"

/**
* custom_which - locates and handles the executable path of a cmd
* @cmd: the first command only is considered
* @env_var: the environment variable under consideration
* Return: the absolute path which contains the particular command
*/
char *custom_which(char *cmd, list_t *env_var)
{
int index;
char **tok_arr, *path_Env, *abs_pathName = NULL;

/* Retrieve PATH directories and convert to tokens */
path_Env = _getenv("PATH", env_var);
tok_arr = token_array(path_Env, ":");
free(path_Env);

/* Check the directory by adding a forward slash ("/") */
while (tok_arr[index] != NULL)
{
if (tok_arr[index][0] == '\0')
{
abs_pathName = getcwd(abs_pathName, 0);
}
else
{
abs_pathName = dup_strn(tok_arr[index]);
abs_pathName = _strncat(abs_pathName, "/");
abs_pathName = _strncat(abs_pathName, cmd);
if (access(abs_pathName, F_OK) == 0)
{
/* Release the token array before returning legit fleshed path */
release_ptr(tok_arr);
return (abs_pathName);
}
}
index++;
}

/* If command is absent, free the concatenated pathname */
free(abs_pathName);
release_ptr(tok_arr);
return (cmd);
}

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
