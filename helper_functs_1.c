#include "shell.h"

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

new_str = _strdup(name);
new_str = _strcat(new_str, "=");
new_str = _strcat(new_str, pathname);
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
append_node(env_var, new_str);
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
int len1 = _strlen(strn1), i, j;
int len2 = _strlen(strn2);
int conc_len = len1 + len2 - 1;

char *result = (char *)malloc(conc_len + 1);

if (result == NULL)
{
return (NULL);
}

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


/**
* exclude_strn - custom string duplication; excludes beginning bytes
* @strn: string to duplicate
* @exclude_bytes: number of bytes to exclude from the beginning
* Return: duplicated string with specified bytes excluded
*/
char *exclude_strn(char *strn, int exclude_bytes)
{
char *duplicate_str;
int len_of_strn = 0, index = 0, result_len;

if (!strn)
return (NULL);

/* Calculate the length of the original string */
while (strn[len_of_strn] != '\0')
len_of_strn++;

/* length of the string after excluding bytes */
result_len = len_of_strn - exclude_bytes;

/* Allocate memory */
duplicate_str = malloc(sizeof(char) * (result_len + 1));
if (!duplicate_str)
return (NULL);

for (index = 0; index < result_len; index++)
duplicate_str[index] = strn[exclude_bytes + index];

/* Terminate the duplicated string*/
duplicate_str[result_len] = '\0';

return (duplicate_str);
}
