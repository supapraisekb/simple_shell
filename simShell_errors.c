#include "sim_shell.h"

/**
* num_mismatch - Write error message
* @command_name: The name of the command that resulted in the error
* @cmd_line_numb: The user's typed command
* @env_var: Linked list containing environmental variables to write shell name
* Return: void
*/

void num_mismatch(char *command_name, int cmd_line_numb, list_t *env_var)
void num_mismatch(char *command_name, int cmd_line_numb, list_t *env_var)
{
int k;
char *shell_name = NULL;
char *cmd_num_strn = NULL;

shell_name = _getenv("_", env_var);
k = 0;
while (shell_name[k] != '\0')
{
k++;
}
write(STDOUT_FILENO, shell_name, k);
free(shell_name);

write(STDOUT_FILENO, ": ", 2);

cmd_num_strn = conv_to_string(cmd_line_numb);
k = 0;
while (cmd_num_strn[k] != '\0')
{
k++;
}
write(STDOUT_FILENO, cmd_num_strn, k);
free(cmd_num_strn);

write(STDOUT_FILENO, ": ", 2);
write(STDOUT_FILENO, command_name, _strnlen(command_name));
write(STDOUT_FILENO, ": number of arguments does not match\n", 37);
}


/**
* print_not_found - writes the command not found error message to stdout
* @inp_cmd: command inputed by the user (argv)
* @cmd_line_numb: the command arg that resulted in the error (argc)
* @env_var: the environment variable list
*/
void print_not_found(char *inp_cmd, int cmd_line_numb, list_t *env_var)
{
int k;
char *name_of_shell;
char *cmd_num_strn;

name_of_shell = _getenv("_", env_var);
k = 0;

while (name_of_shell[k] != '\0')
{
k++;
}

write(STDOUT_FILENO, name_of_shell, k);
free(name_of_shell);

write(STDOUT_FILENO, ": ", 2);

cmd_num_strn = int_to_string(cmd_line_numb);
k = 0;

while (cmd_num_strn[k] != '\0')
{
k++;
}

write(STDOUT_FILENO, cmd_num_strn, k);
free(cmd_num_strn);

write(STDOUT_FILENO, ": ", 2);

k = 0;
while (inp_cmd[k] != '\0')
{
k++;
}

write(STDOUT_FILENO, inp_cmd, k);
write(STDOUT_FILENO, ": ", 2);
write(STDOUT_FILENO, "command not found\n", 19);
}


/**
* cd_error - Write error message ("sh: 2: cd: can't cd to xyz")
* @dest: User's typed argument after the "cd" command
* @cmd_line_numb: The nth user's typed command
* @env_var: Linked list containing environmental variables to write shell name
*/
void cd_error(char *dest, int cmd_line_numb, list_t *env_var)
{
int k;
char *shell_name = NULL;
char *cmd_num_strn = NULL;

shell_name = _getenv("_", env_var);
k = 0;
while (shell_name[k] != '\0')
{
k++;
}
write(STDOUT_FILENO, shell_name, k);
free(shell_name);

write(STDOUT_FILENO, ": ", 2);

cmd_num_strn = int_to_string(cmd_line_numb);
k = 0;
while (cmd_num_strn[k] != '\0')
{
k++;
}
write(STDOUT_FILENO, cmd_num_strn, k);
free(cmd_num_strn);

write(STDOUT_FILENO, ": ", 2);
write(STDOUT_FILENO, "cd: invalid destination directory", 35);

k = 0;
while (dest[k] != '\0')
{
k++;
}
write(STDOUT_FILENO, dest, k);
write(STDOUT_FILENO, "\n", 1);
}

