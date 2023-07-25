#include "sim_shell.h"

/**
* exit_simShell - exits the shell program with an integer value
*  @inp_cmd: user input command
* @env_var: environment var to free if an error is encountered
* @cmd_line_numb: command line input
* @free_cmd: command to free
*  Return: 0 if successful 3 if it fails
*/

int exit_simShell(char **inp_cmd, list_t *env_var, i
		nt cmd_line_numb, **free_cmd)
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
if (!cmd_line_numb)
release_ptr(cmd_line_numb);
exit(exit_val);
}
