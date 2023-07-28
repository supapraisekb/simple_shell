#include "sim_shell.h"

/**
* change_directory - enables the cd command
* @cmd_input: user command input
* @env_var: linked list of the environment variable
* @cmd_numb_str: user command at index n
* Return: 0 on success
*/
int change_directory(char **cmd_input, list_t *env_var, int cmd_numb_str)
{
char *curr_dir = NULL, *new_dir = NULL;
int x_status = 0;

curr_dir = getcwd(curr_dir, 0);

if (cmd_input[1] != NULL)
{
if (cmd_input[1][0] == '~')
{
new_dir = _getenv("HOME", env_var);
new_dir = ignore_first_char(new_dir, cmd_input[1]);
}
else if (cmd_input[1][0] == '-')
{
if (cmd_input[1][1] == '\0')
{
new_dir = _getenv("OLDPWD", env_var);
}
}
else
{
if (cmd_input[1][0] != '/')
{
new_dir = getcwd(NULL, 0);
new_dir = _strncat(new_dir, "/");
new_dir = _strncat(new_dir, cmd_input[1]);
}
else
{
new_dir = dup_strn(cmd_input[1]);
}
}
}
else
{
cd_without_cmd(env_var, curr_dir);
free(curr_dir);
release_ptr(cmd_input);
return (0);
}

x_status = cd_cmd_exec(env_var, curr_dir, new_dir, cmd_input[1], cmd_numb_str);
free(curr_dir);
free(new_dir);
release_ptr(cmd_input);

return (x_status);
}


/**
* cd_without - change directory to home whnen only cd is entered
* @env_var: bring in environmental linked list to update PATH and OLDPWD
* @curr_dir: bring in current working directotry
*/
cd_without_cmd(list_t *env_var, char *curr_dir)
{
char *home_environ = NULL;

home_environ = _getenv("HOME", env_var);

custom_setenv(&env_var, "OLDPWD", curr_dir);
free(curr_dir);
if (access(home_environ, F_OK) == 0)
chdir(home_environ);

curr_dir = NULL;
curr_dir = getcwd(curr_dir, 0);
custom_setenv(&env_var, "PWD", curr_dir);
free(curr_dir);
free(home_environ);

}

/**
* cd_cmd_exec - responsible for excuting the cd command
* @env_var: the env_linked list to update
* @curr_dir:
* @new_dir:
* @input_cmd:
* @cmd_numb_strn: the line numner of the nth command
* used to write the error
* Return:  0 on success, 3 if unsuccessful
*/

cd_cmd_exec(list_t *env_var, char *curr_dir, char *new_dir, char *input_cmd, int cmd_numb_strn)
{
int index = 0;

if (access(new_dir, F_OK) == 0)
{
custom_setenv(&env_var, "OLDPWD", curr_dir);
free(curr_dir);
chdir(new_dir);
curr_dir = NULL;
curr_dir = getcwd(curr_dir, 0);
custom_setenv(&env_var, "PWD", curr_dir);
free(curr_dir);
}

else
{
cd_error(input_cmd, cmd_numb_strn, env_var);
index = 3;
}
return (index);
}

