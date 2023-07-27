#include "sim_shell.h"
#include "sim_shell.h"

/**
* exit_free_ - it frees up the command before exit
* @inp_cmd: user command input
* @env_var: the environment variable llinked list
*/

void exit_free_(char **inp_cmd, list_t *env_var)
{
release_ptr(inp_cmd);
release_list(env_var);
exit(0);
}

/**
* exit_simShell - exits the shell program with an integer value
*  @inp_cmd: user input command
* @env_var: environment var to free if an error is encountered
* @cmd_line_numb: command line input
* @free_cmd: command to free
*  Return: 0 if successful 3 if it fails
*/

int exit_simShell(char **inp_cmd, list_t *env_var,
		int cmd_line_numb, char **free_cmd)
{
int exit_val = 0;

if (inp_cmd[1] != NULL)
exit_val = _atoi(inp_cmd[1]);

if (exit_val == -1)
{
_exit_error_msg(inp_cmd[1], cmd_line_numb, env_var);
release_ptr(inp_cmd);
return (3);
}
release_ptr(inp_cmd);
release_list(env_var);
release_ptr(free_cmd);
exit(exit_val);
}
