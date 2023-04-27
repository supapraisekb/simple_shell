#include "egshell.h"


char **get_env(const char *var);
char **copy_ShellEnv(void);
void releaseEnv(void);

/**
* get_env - gets the environment variable
* @var: the environment variable to be retrieved
*
* Return: a pointer to the environment variable
*        NULL if the variable is not found
*/
char **get_env(const char *var)
{
int var_len = lenofStrn(var);
for (int i = 0; environ[i] != NULL; i++)
{
if (compStrn_n(environ[i], var, var_len) == 0)
{
return (&environ[i]);
}
}
return (NULL);
}

/**
* copy_ShellEnv - copies the shell environment
*
* Return: a pointer to the copied shell environment
*         NULL if an error occurs
*/
char **copy_ShellEnv(void)
{
char **env_copy = NULL;
size_t env_len = 0;
int i;

for (i = 0; environ[i] != NULL; i++)
{
env_len++;
env_copy = realloc(env_copy, sizeof(char *) * (env_len + 1));
if (env_copy == NULL)
{
for (int j = i-1; j >= 0; j--)
free(env_copy[j]);
return (NULL);
}

env_copy[i] = malloc(lenofStrn(environ[i]) + 1);
if (env_copy[i] == NULL)
{
for (int j = i-1; j >= 0; j--)
free(env_copy[j]);
free(env_copy);
return (NULL);
}

copyStrn(env_copy[i], environ[i]);
}

env_copy[i] = NULL;
return (env_copy);
}

/**
* releaseEnv - releases the memory allocated for the environment
*
* Return: None
*/

void releaseEnv(void)
{int i;
for (i = 0; environ[i] != NULL; i++)
{
free(environ[i]);
}
free(environ);
}
