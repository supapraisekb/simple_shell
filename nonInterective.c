#include "sim_shell.h"

/**
* nonInteractive - handles multiple inputs via piping
* @env_var: environment variables
*/
void nonInteractive(list_t *env_var)
{
int line_count = 0, xit_status = 0;
char *cmd = NULL, *formatted_cmd = NULL;
char **cmd_token = NULL, **multi_line_tokenizer;

size_t index = 0, counter = 0;

index = _get_line(&cmd);
if (index == 0)
{
free(cmd);
exit(0);
}

formatted_cmd = cmd;
cmd = space_handler(cmd);
multi_line_tokenizer = str_tok(cmd, "\n");

if (formatted_cmd != NULL)
free(formatted_cmd);

counter = 0;
while (multi_line_tokenizer[counter] != NULL)
{
line_count++;
cmd_token = NULL;
cmd_token = str_tok(multi_line_tokenizer[counter], " ");
xit_status = builtin_handler(cmd_token,
		env_var, line_count, multi_line_tokenizer);

if (xit_status != 0)
{
counter++;
continue;
}
xit_status = exe_cve(cmd_token, env_var, line_count);
counter++;
}
release_ptr(multi_line_tokenizer);
release_list(env_var);
exit(xit_status);
}
