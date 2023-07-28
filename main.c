#include "shell.h"

/**
* simShell_environ - the environment that holds the shell prompt
* @environ: the environment variables
* Return: 0 on successful execution
*/
int simShell_environ(char **environ)
{
int line_count = 0, xit_status = 0;
char *cmd, **cmd_tokens;
list_t *env_var;
size_t index, counter;
env_var = envLinked_list(environ);
while (1)
{
line_count++;
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
else
nonInteractive(env_var);
signal(SIGINT, ctrl_c);
cmd = NULL;
index = _getline(&cmd);
if (index == 0)
{
free(cmd);
break;
}
cmd = space_handler(cmd);
counter = 0;
while (cmd[counter] != '\n')
{
counter++;
}
cmd[counter] = '\0';
if (cmd[0] == '\0') /* if user hits enter without any cmd reprompt user */
{
free(cmd);
continue;
}
cmd_tokens = NULL;
cmd_tokens = str_tok(cmd, " ");
xit_status = builtin_handler(cmd_tokens, env_var, line_count, NULL);
if (xit_status)
{
continue;
}
xit_status = exe_cve(cmd_tokens, env_var, line_count);
break;
}
release_list(env_var);
return (xit_status);
}

/**
* main - enables and runs a simple shell
* @argcount: The argument counter tracking number of arguments
* @argvector: pointers to the arguments or argument vector
* @env_var: the environment varibles
* Return: 0 if successful
*/

int main(int argcount, char **argvector, char **env_var)
{
(void)argcount;
(void)argvector;
simShell_environ(env_var);
return (0);
}
