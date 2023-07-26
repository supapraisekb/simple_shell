#include "sim_shell.h"

#include "sim_shell.h"

/**
* custom_setenv - concatenates strn before setenv
* @env_var: environment var
* @name: env var name
* @pathname: the path to the directory
* Return: 0 on success
*/
int custom_setenv(list_t **env_var, char *name, char *pathname)
{
int i = 0;
char *new_str;
list_t *curr_node_ptr;

new_str = dup_strn(name);
new_str = _strncat(new_str, "=");
new_str = _strncat(new_str, pathname);
i = _env_index_locator(*env_var, name);

curr_node_ptr = *env_var;
while (i > 0 && curr_node_ptr != NULL)
{
curr_node_ptr = curr_node_ptr->node_ptr;
i--;
}

/* If the environment variable is found, update its value */
if (curr_node_ptr != NULL)
{
free(curr_node_ptr->str_var);
curr_node_ptr->str_var = _strdup(new_str);
}
/* If the environment variable is not found, add it to the linked list */
else
{
add_node_end(env_var, new_str);
}

free(new_str);
return (0);
}

/**
* ignore_first_char - ignores the first character before concatenation
* @strn1: first string that strn2 will be appended to
* @strn2: the string to be joined to strn1 (with the first character ignored)
* Return: the new concatenated string
*/


char *ignore_first_char(char *strn1, char *strn2)
{
int len1 = _strnlen(strn1);
int len2 = _strnlen(strn2);
int conc_len = len1 + len2 - 1;

char *result = (char *)malloc(conc_len + 1);

if (result == NULL)
{
return (NULL);
}

int i = 0;
int j = 1;

while (strn1[i] != '\0')
{
result[i] = strn1[i];
i++;
}

while (strn2[j] != '\0')
{
result[i] = strn2[j];
i++;
j++;
}

result[i] = '\0';
return (result);
}

