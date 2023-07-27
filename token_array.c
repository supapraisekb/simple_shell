#include "sim_shell.h"

/**
* _token_array - produces tokens from a string
* @strn: the input string
* @delim_type: delimiter type used to produce tokens
* Return: An array of tokens
*/
char **_token_array(char *strn, char *delim_type)
{
char **token_array = NULL;
int len_of_tok = 0, tok_index = 0, str_index = 0, inp_str_index = 0;
int count = 0;

count = total_delim(strn, delim_type[0]);
token_array = malloc(sizeof(char *) * (count + 1));
if (token_array == NULL)
return (NULL);

inp_str_index = 0;
while (strn[inp_str_index] != '\0')
{
while (strn[inp_str_index] == delim_type[0])
inp_str_index++;

len_of_tok = tok_strnlen(strn, inp_str_index, delim_type[0]);

token_array[tok_index] = malloc(sizeof(char) * (len_of_tok + 1));
if (token_array[tok_index] == NULL)
{
for (str_index = 0; str_index < tok_index; str_index++)
free(token_array[str_index]);
free(token_array);
return (NULL);
}
for (str_index = 0; str_index < len_of_tok; str_index++)
token_array[tok_index][str_index] = strn[inp_str_index + str_index];
token_array[tok_index][len_of_tok] = '\0';
tok_index++;
inp_str_index += len_of_tok;
}
return (token_array);
}
