#include "shell.h"

/**
* display_env_var -  it prints out the environment variables to
* @cmd: user's "env" command
* @env_var: THe environment variables to be printed
* Return: 0 to indicate successful execution
*/

int display_env_var(char **cmd, list_t *env_var)
{
release_ptr(cmd);
disp_list(env_var);

return (0);
}

/**
* simShell_setenv - creates or changes an env variable
* @env_list: the linked list
* @cmd: the command typed in by user
* Return: 0 if successful
*/
int simShell_setenv(list_t **env_list, char **cmd)
{
char *new_node_ptr;
list_t *curr_node_ptr;
int i, k = 0;

if (!cmd[0] || !cmd[1])
{
write(STDOUT_FILENO, "incomplete arguments, try again\n", 31);
free(cmd[0]);
free(cmd[1]);
free(cmd);
return (-1);
}
new_node_ptr = dup_strn(cmd[0]);
new_node_ptr = _strncat(new_node_ptr, "=");
new_node_ptr = _strncat(new_node_ptr, cmd[1]);
i = _env_index_locator(*env_list, cmd[0]);
if (i == -1)
{
append_node(env_list, new_node_ptr);
}
else
{
curr_node_ptr = *env_list;
while (curr_node_ptr != NULL && k < i)
{
curr_node_ptr = curr_node_ptr->node_ptr;
k++;
}
if (curr_node_ptr != NULL)
{
free(curr_node_ptr->str_var);
curr_node_ptr->str_var = dup_strn(new_node_ptr);
}
}
free(new_node_ptr);
free(cmd[0]);
free(cmd[1]);
free(cmd);
return (0);
}

/**
* simShell_unsetenv - handles node removal in the env linked list
* @env_list: env linked list
* @cmd: the input command from the user
* Return: 0 if successful
*/

int simShell_unsetenv(list_t **env_list, char **cmd)
{
int var_index = 0, k = 0;

if (!cmd[0])
{
write(STDOUT_FILENO, "Please enter a valid command\n", 30);
release_ptr(cmd);
return (-1);
}

var_index = _env_index_locator(*env_list, cmd[1]);

release_ptr(cmd);
if (var_index == -1)
{
write(STDOUT_FILENO, "Wrong input\n", 13);
return (-1);
}
k = del_node(env_list, var_index);
if (k == -1)
{
write(STDOUT_FILENO, "wrong input\n", 13);
return (-1);
}
return (0);
}

/**
* _env_index_locator - searches for an environment variable in a liked list
* @env_list: liked list containing the env variables
* @strn: the variable to be searched for in the linked list
* Return: node index in the linked list
*/
int _env_index_locator(list_t *env_list, char *strn)
{
int index = 0;

while (env_list != NULL)
{
if (strncmp_(env_list->str_var, strn) == 0)
return (index);

env_list = env_list->node_ptr;
index++;
}

return (-1);
}

