#include "shell.h"

/**
* builtin_handler - controls the builtins
* @inp_toks: input from user represented as tokens
* @env_var: environment variables
* @cmd_num_strn: monitors the user command at ith index to write an error to
* @cmd: writes command to free
* Return: 1 if the builtin was handled otherwise 0
*/

int builtin_handler(char **inp_toks,
		list_t *env_var, int cmd_num_strn, char **cmd)
{
int index = 0;

/* For user input "exit" */
if (_strcmp(inp_toks[0], "exit") == 0)
{
index = exit_simShell(inp_toks, env_var, cmd_num_strn, cmd);
}
/* For user input "env" */
else if (_strcmp(inp_toks[0], "env") == 0)
{
display_env_var(inp_toks, env_var);
index = 1;
}
/* For user input "cd" */
else if (_strcmp(inp_toks[0], "cd") == 0)
{
index = change_directory(inp_toks, env_var, cmd_num_strn);
}
/* For user input "setenv" */
else if (_strcmp(inp_toks[0], "setenv") == 0)
{
simShell_setenv(&env_var, inp_toks);
index = 1;
}
/* For user input "unsetenv" */
else if (_strcmp(inp_toks[0], "unsetenv") == 0)
{
simShell_unsetenv(&env_var, inp_toks);
index = 1;
}
return (index);
}

