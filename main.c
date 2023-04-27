#include "shell.h"

void input_signal(int inpt_sig);

/**
* input_signal - handles the signal for the input
* @inpt_sig: the received signal
*/
void input_signal(int inpt_sig)
{
char *prompt_user = "\n egshell $ ";

(void)inpt_sig;
signal(sigint, input_signal);
write(stdout_fileno, prompt_user, lenofstrn(prompt_user));
}

/**
* command_exec - executes the command in child process
* @command_args: array of arguments passed to the command
* @begin_input: pointer to the beginning of the input
*
* return: 0 on success, an error code on failure
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

if (user_inputs == null || access(user_inputs, f_ok) == -1)
{
if (errno == eacces)
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
perror("error, child process failed:");
return (1);
}

if (ps_child == 0)
{
execve(user_inputs, command_args, environ);
if (errno == eacces)
(return_value = err_notice(command_args, 126));
releaseenv();
releaseargs(command_args, begin_input);
releasealiases(aliases);
exit(return_value);
}
else
{
wait(&status_of_child);
(return_value = wexitstatus(status_of_child));
}
}

if (set_flag)
free(user_inputs);
return (return_value);
}

/**
* main - runs a unix shell command line interpreter
* @argument_count: number of arguments passed to the shell
* @argument_vector: array of arguments passed to the shell
*
* return: value of the executed command
*/

int main(int argument_count, char *argument_vector[])
{
int return_value = 0, exit_value;
int *exit_pointer = &exit_value;
char *prompt = "egshell $ ", *new_line = "\n";

shell_name = argument_vector[0];
command_history = 1;
aliases = null;
signal(sigint, input_signal);
*exit_pointer = 0;
shell_environ = copy_shellenv();
if (shell_environ == null)
exit(-110);

if (argument_count != 1)
{
(return_value = file_commands_exec(argument_vector[1], exit_pointer));
releaseenv();
releasealiases(aliases);
return (*exit_pointer);
}

if (!isatty(stdin_fileno))
{
while (return_value != end_of_file && return_value != exit)
{
(return_value = arg_handler(exit_pointer));
}
releaseenv();
releasealiases(aliases);
return (*exit_pointer);
}

while (true)
{
write(stdout_fileno, prompt, 11);
(return_value = arg_handler(exit_pointer));
if ((return_value == end_of_file) || (return_value == exit))
{
if (return_value == end_of_file)
{
write(stdout_fileno, new_line, 1);
}
releaseenv();
releasealiases(aliases);
exit(*exit_pointer);
}
}

releaseenv();
releasealiases(aliases);
return (*exit_pointer);
}
