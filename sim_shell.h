#ifndef SIM_SHELL_H
#define SIM_SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <math.h>

/**
* struct list - linked list for environmental variables
* @str_var: holds string variable
* @node_ptr: pointer to the next node
*/
typedef struct list
{
char *str_var;
struct list *node_ptr;
} list_t;

/*functions for string manipulations*/
char *_strncat(char *dest, char *src);
char *conv_to_string(int num);
size_t _get_line(char **str_buff);
int _strnlen(const char *s);
char *dup_strn(char *strn);
int strncmp_(char *strn1, char *strn2);
char *_strncpy(char *dest, char *str);
int _zerosCounter(int num);
char *exclude_strn(char *strn, int exclude_bytes);

/*Tokenization functions*/
int tok_strnlen(char *strn, int str_index, char delim);
char **strn_token(char *inp_strn, char delim_strn);
int num_of_delims(char *strn, char delim);
char *handle_recurr_delim(char *strn, char delim);
int total_delim(char *strn, char delim_count);
char **_token_array(char *strn, char *delim);

/*Auxilliary Functions*/
char *custom_which(char *cmd, list_t *env_var);
char *_getenv(char *inp_str, list_t *env_var);
void release_ptr(char **str_arr);

/*sim_shell_linked_lists*/
list_t *append_node(list_t **begin, char *node_data);
size_t disp_list(list_t *head);
int del_node(list_t **list_head, int node_index);
void release_list(list_t *head);

/*envLinked_list.c*/
list_t *envLinked_list(char **env_var);

/*Env functions*/
int display_env_var(char **cmd, list_t *env_var);
int simShell_setenv(list_t **env_list, char **cmd);
int simShell_unsetenv(list_t **env_list, char **cmd);
int _env_index_locator(list_t *env_list, char *strn);
void nonInteractive(list_t *env_var);

/*Exit function*/
int exit_simShell(char **inp_cmd, list_t *env_var,
		int cmd_line_numb, char **free_cmd);

/*Error Handlers*/
void print_not_found(char *inp_cmd, int cmd_line_numb, list_t *env_var);
void num_mismatch(char *command_name, int cmd_line_numb, list_t *env_var);
void cd_error(char *dest, int cmd_line_numb, list_t *env_var);

/*Builtin and Change Directory handlers*/
int builtin_handler(char **inp_tok, list_t *env_var,
		int cmd_num_strn, char **cmd);
void cd_without_cmd(list_t *env_var, char *curr_dir);
int change_directory(char **cmd_input, list_t *env_var, int cmd_numb_str);
int cd_cmd_exec(list_t *env_var, char *curr_dir,
		char *new_dir, char *input_cmd, int cmd_numb_str);

/*Singal Handlers*/
void ctrl_c(int num);
void ctrl_d(int index, char *cmd_inp, list_t *env_var);
char *space_handler(char *inp_str);

/*More Helper Files*/
char *ignore_first_char(char *strn1, char *strn2);
int custom_setenv(list_t **env_var, char *name, char *pathname);

#endif /*SIM_SHELL_H*/