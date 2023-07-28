#include "shell.h"

/**
* ctrl_c - ignores ctrl-c command input direncts cursor to prompt
* @num: integer input delivered from signal
*/
void ctrl_c(int num)
{
(void)num;
write(STDOUT_FILENO, "\n$ ", 3);
}


/**
* ctrl_d - exits the shell if user types ctrl-d
* @index: characters read via get_line
* @cmd_inp: user's typed in command
* @env_var: environment variable linked list
*/
void ctrl_d(int index, char *cmd_inp, list_t *env_var)
{
if (index == 0)
{
free(cmd_inp);
release_list(env_var);
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "\n", 1);
exit(0);
}
}

/**
* space_handler - return string without spaces or newline
* @inp_str: the full string entered by the user
* Return: new string without spaces
*/
char *space_handler(char *inp_str)
{
while (*inp_str == ' ' || *inp_str == '\n')
inp_str++;
return (inp_str);
}
