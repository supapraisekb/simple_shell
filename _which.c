#include "shell.h"

/**
* _which - locates and handles the executable path of a cmd
* @cmd: the first command only is considered
* @env_var: the environment variable under consideration
* Return: the absolute path which contains the particular command
*/
char *_which(char *cmd, list_t *env_var)
{
int index;
char **tok_arr, *path_Env, *abs_pathName = NULL;

/* Retrieve PATH directories and convert to tokens */
path_Env = _getenv("PATH", env_var);
tok_arr = _token_array(path_Env, ":");
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
abs_pathName = _strdup(tok_arr[index]);
abs_pathName = _strcat(abs_pathName, "/");
abs_pathName = _strcat(abs_pathName, cmd);
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
