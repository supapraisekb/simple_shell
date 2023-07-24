#include "sim_shell.h"

/**
* envLinked_list - handles the environment variables liked list
* @env_var: The environment vriables in the shell
* Return:  the enviroment linked list
*/

list_t *envLinked_list(char **env_var)
{
list_t *list_head = NULL;
int list_index = 0;

while (env_var[list_index])
{
append_node(&list_head, env_var[list_index]);
list_index++;
}
return (list_head);

}
