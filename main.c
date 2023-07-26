#include "sim_shell.h"
/**
* free_string_array - frees the memory allocated for an array
* @arr: the array to free
*/
void free_string_array(char **arr)
{
{
if (arr == NULL)
return;

for (size_t i = 0; arr[i] != NULL; i++)
{
free(arr[i]);
arr[i] = NULL;
}

free(arr);
}
}


/**
* simShell_environ - the environment that holds the shell prompt
* users enter command here which are executed
* @environ: the environment variables
* Return: 0 on successful execution
*/
int simShell_environ(char **environ)
{
list_t *env_var;
int xit_status = 0;

env_var = envLinked_list(environ);

while (1)
{
print_prompt();

char *cmd = read_command();

if (cmd == NULL)
break;

if (cmd[0] == '\0') /* if user hits enter without any cmd, reprompt user */
{
free(cmd);
continue;
}

char **cmd_tokens = tokenize_command(cmd);
free(cmd);

xit_status = handle_builtin_commands(cmd_tokens, env_var);

if (xit_status != 0)
{
free_string_array(cmd_tokens);
continue;
}

xit_status = execute_external_command(cmd_tokens, env_var);
free_string_array(cmd_tokens);

break;
}

release_list(env_var);
return (xit_status);
}

/**
* main - enables and runs a simple shell
* @argcount: The argument counter tracking number of arguments
* @argvector: pointers to the arguments or argument vector
* @env_var: the environment variables
* Return: 0 if successful
*/
int main(int argcount, char **argvector, char **env_var)
{
(void)argcount;
(void)argvector;

int exit_status = simShell_environ(env_var);

return (exit_status);
}
