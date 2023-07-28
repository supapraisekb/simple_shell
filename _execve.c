#include "shell.h"
/**
* _execve - custom execve that executes the user command
* @inpt_cmd: user command input
* @env_var: linked list of environmental variables
* @cmd_num: user command displayed with the error output
* Return: 0 if successful
*/
int _execve(char **inpt_cmd, list_t *env_var, int cmd_num)
{
pid_t pid;
char *curr_node = NULL;
int process_stat = 0;

if (access(inpt_cmd[0], F_OK) == 0)
{
curr_node = inpt_cmd[0];
}
else
{
curr_node = _which(inpt_cmd[0], env_var);
}
if (access(curr_node, X_OK) != 0)
{
print_not_found(inpt_cmd[0], cmd_num, env_var);
release_ptr(inpt_cmd);
return (127);
}
pid = fork();
if (pid < 0) /* Indicates that a failure occurred */
{
exit(EXIT_FAILURE);
}
else if (pid == 0)
{
if (execve(curr_node, inpt_cmd, NULL) == -1)
{
print_not_found(inpt_cmd[0], cmd_num, env_var);
exit_free_(inpt_cmd, env_var);
}
}
else
{
wait(&process_stat);
}
release_ptr(inpt_cmd);
if (curr_node != inpt_cmd[0])
free(curr_node);
return (0);
}

