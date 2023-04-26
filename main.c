#include "egshell.h"

void input_signal(int inpt_sig);

/**
* input_signal - handles the signal for the input
* @inpt_sig: The received signal
*/
void input_signal(int inpt_sig)
{
char *prompt_user = "\n egshell $ ";

(void)inpt_sig;
signal(SIGINT, input_signal);
write(STDOUT_FILENO, prompt_user, lenofStrn(prompt_user));
}

/**
* command_exec - executes the command in child process
* @command_args: array of arguments passed to the command
* @begin_input: pointer to the beginning of the input
*
* Return: 0 on success, an error code on failure
*/
int command_exec(char **command_args, char **begin_input)
{
pid_t ps_child;
int status_of_child, set_flag = 0, return_value = 0;
char *user_inputs = command_args[0];

if (user_inputs[0] != '/' && user_inputs[0] != '.')
{
set_flag = 1;
user_inputs = locate_cursor(user_inputs);
}

if (user_inputs == NULL || access(user_inputs, F_OK) == -1)
{
if (errno == EACCES)
(return_value = err_notice(command_args, 126));
else
(return_value = err_notice(command_args, 127));
}
else
{
ps_child = fork();
if (ps_child == -1)
{
if (set_flag)
free(user_inputs);
perror("Error, Child process failed:");
return (1);
}

if (ps_child == 0)
{
execve(user_inputs, command_args, environ);
if (errno == EACCES)
(return_value = err_notice(command_args, 126));
releaseEnv();
releaseArgs(command_args, begin_input);
releaseAliases(aliases);
exit(return_value);
}
else
{
wait(&status_of_child);
(return_value = WEXITSTATUS(status_of_child));
}
}

if (set_flag)
free(user_inputs);

return (return_value);
}

/**
* main- Runs a UNIX shell command line interpreter
* @argument_count: number of arguments passed to the shell
* @argument_vector: array of arguments passed to the shell
*
* Return: Value of the executed command
*/

int main(int argument_count, char *argument_vector[])
{
int return_value = 0, exit_value;
int *exit_pointer = &exit_value;
char *prompt = "egshell $ ", *new_line = "\n";

shell_name = argument_vector[0];
command_history = 1;
aliases = NULL;
signal(SIGINT, input_signal);
*exit_pointer = 0;
shell_environ = copy_ShellEnv();
if (shell_environ == NULL)
exit(-110);

if (argument_count != 1)
{
(return_value = file_commands_exec(argument_vector[1], exit_pointer));
releaseEnv();
releaseAliases(aliases);
return (*exit_pointer);
}

if (!isatty(STDIN_FILENO))
{
while (return_value != END_OF_FILE && return_value != EXIT)
{
(return_value = arg_handler(exit_pointer));
}
releaseEnv();
releaseAliases(aliases);
return (*exit_pointer);
}

while (true)
{
write(STDOUT_FILENO, prompt, 11);
(return_value = arg_handler(exit_pointer));
if ((return_value == END_OF_FILE) || (return_value == EXIT))
{
if (return_value == END_OF_FILE)
{
write(STDOUT_FILENO, new_line, 1);
}
releaseEnv();
releaseAliases(aliases);
exit(*exit_pointer);
}
}

releaseEnv();
releaseAliases(aliases);
return (*exit_pointer);
}
