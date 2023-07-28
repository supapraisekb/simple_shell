#include "shell.h"

/**
* str_tok - splits a string into smaller substrings known as tokens
* @inp_strn: the input string
* @delim_strn: the delimiter
* Return: an array of tokens
*/
char **str_tok(char *inp_strn, char *delim_strn)
{
int buff_size = 0, tok_index = 0, str_index = 0, token_len = 0;
int end_input = 0, j;
char **str_tokens = NULL, delim_char;

delim_char = delim_strn[0];
inp_strn = handle_recurr_delim(inp_strn, delim_char);
buff_size = num_of_delims(inp_strn, delim_char);
str_tokens = malloc(sizeof(char *) * (buff_size + 2));
if (!str_tokens)
return (NULL);
while (inp_strn[end_input] != '\0')
end_input++;
while (str_index < end_input)
{
if (inp_strn[str_index] != delim_char)
{
token_len = tok_strnlen(inp_strn, str_index, delim_char);
str_tokens[tok_index] = malloc(sizeof(char) * (token_len + 1));
if (str_tokens[tok_index] == NULL)
return (NULL);
j = 0;
while ((inp_strn[str_index] != delim_char)&&
(inp_strn[str_index] != '\0'))
{
str_tokens[tok_index][j] = inp_strn[str_index];
j++;
str_index++;
}
str_tokens[tok_index][j] = '\0';
tok_index++;
}
str_index++;
}
str_tokens[tok_index] = NULL;
return (str_tokens);
}
