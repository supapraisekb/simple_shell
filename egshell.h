#ifndef EGSHELL_H
#define EGSHELL_H

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <stdbool.h>

#define END_OF_FILE -2
#define EXIT -3

/* Egshell Environment prototypes */
extern char **environ;
/* Global program name */
extern char *shell_name;
/* Global history counter */
extern int command_history;

/**
* struct list_s - A struct defining a linked list.
* @dir: path to the egshell directories.
* @next: A pointer to another struct list_s.
*/
typedef struct list_s
{
char *dir;
struct list_s *next;
} list_t;

/**
* struct inbuiltFunct_s - A struct type defining the builtin commands.
* @builtin_name: name of the builtin command.
* @func_b: A function pointer to the builtin command's function.
*/
typedef struct inbuiltFunct_s
{
char *builtin_name;
int (*func_b)(char **args, char **begin_input);
} builtin_t;

/**
* struct alias_s - A new struct defining aliases.
* @alias_name: The name of the alias.
* @value: The value of the alias.
* @next: A pointer to another struct alias_s.
*/
typedef struct alias_s
{
char *alias_name;
char *value;
struct alias_s *next;
} alias_t;

/* Egshell aliases linked list */
extern alias_t *aliases;

/* Helper Function Prototypes */
ssize_t egshell_getline(char **lineptr_var,
		size_t *lineptrSize, FILE *charStream);

void *_realloc(void *ptr, unsigned int initialSize,
		unsigned int newSize);
char **_strtok(char *line, char *delim);
char *locate_cursor(char *command);
list_t *get_path_dir(char *path);
int execute(char **args, char **begin_input);
void free_list(list_t *head);
char *_itoa(int num);

/* Input Enabler function prototypes */
void handle_line(char **line, ssize_t read);
void variable_replacement(char **args, int *exit_pointer);
char *get_args(char *line, int *exit_pointer);
int call_args(char **args, char **begin_input, int *exit_pointer);
int run_args(char **args, char **begin_input, int *exit_pointer);
int arg_handler(int *exit_pointer);
int check_args(char **args);
void releaseArgs(char **args, char **begin_input);
char **replace_aliases(char **args);

/* String functions handlers */
char *strConcat_n(char *dest, const char *src, size_t n);
size_t lenofStrn(const char *s);
char *copyStrn(char *dest, const char *src, size_t n);
char *strConcat(char *dest, const char *src);
int comp_strns(const char *str1, const char *str2);
int compStrn_n(const char *str1, const char *str2, size_t n);
size_t getPrefix_len(const char *str, const char *prefix);
char *locateChar(const char *str, char ch);

/* Egshell Builtin function prototypes */
int (*get_inbuiltFunct(const char *cmd))(char **args, char **begin_input);
int egshell_exit(char **args, char __attribute__((unused)) **begin_input);
int egshell_env(char **args, char __attribute__((unused)) **begin_input);
int egshell_setenv(char **args, char __attribute__((unused)) **begin_input);
int egshell_unsetenv(char **args, char __attribute__((unused)) **begin_input);
int egshell_cd(char **args, char __attribute__((unused)) **begin_input);
int egshell_alias(char **args, char __attribute__((unused)) **begin_input);
int egshell_help(char **args, char __attribute__((unused)) **begin_input);

/* Builtin Enabler function prototypes */
char **copy_ShellEnv(void);
void releaseEnv(char **envp);
char **get_env(const char *var);

/* Error indicator functions */
int err_notice(char **args, int err);
char *err_indicator_env(const char *var);
char *err_indicator_1(const char *cmd);
char *err_indicator_2_exit(const char *cmd);
char *err_indicator_2_cd(void);
char *err_indicator_2_syntax(const char *cmd);
char *err_indicator_126(const char *cmd);
char *error_127(const char *cmd);

/* Linkedlist Enabler function prototypes */
alias_t *appendAliases(alias_t **head, const
		char *alias_name, const char *value);
void releaseAliases(alias_t *head);
list_t *append_node(list_t **head, const char *dir);
void releaseList(list_t *head);

void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);

int file_commands_exec(const char *file_path, int *exit_pointer);

#endif /* EGSHELL_H */
