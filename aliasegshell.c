#include "egshell.h"

void aliasInput(char *aliasName, char *value);
void aliasOutput(alias_t *alias);
char **aliasSub(char **args);
int egshell_alias(char **args, char __attribute__((unused)) **begin_input);

/**
* aliasInput - Parses the alias input and adds it to the alias list.
* @aliasName: The name of the alias.
* @value: The value of the alias.
*
* Return: the alias value
*/

void aliasInput(char *aliasName, char *value)
{
alias_t *findName = aliases;
int nameLen, i, j;
char *newAlias;
value += strcspn(value, "'\"") + 1;
nameLen = lenofStrn(value) - getPrefix_len(value, "'\"");
newAlias = malloc(sizeof(char) * (nameLen + 1));
if (newAlias == NULL)
{
return;
}
for (i = strcspn(value, "'\""), j = 0; j < nameLen; i++, j++)
{
if (value[i] == '"' || value[i] == '\'')
{
nameLen++;
continue;
}
newAlias[j] = value[i];
}
newAlias[j] = '\0';
while (findName)
{
if (comp_strns(findName->alias_name, aliasName) == 0)
{
free(aliasName);
free(findName->value);
findName->value = newAlias;
return;
}
findName = findName->next;
}
appendAliases(&aliases, &aliasesTail, aliasName, newAlias);
}

/**
* aliasOutput - prints the alias name
* @alias: points to the head of the alias linked list
* Return: an alias name
*/
void aliasOutput(alias_t *alias)
{
int name_len = lenofStrn(alias->name);
int value_len = lenofStrn(alias->value);
int len = name_len + value_len + 4;
char *stringFormat = malloc(sizeof(char) * (len + 1));
if (stringFormat == NULL)
{
return;
}
copyStrn(stringFormat, alias->name);
strConcat(stringFormat, "='");
strConcat(stringFormat, alias->value);
strConcat(stringFormat, "'\n");

write(STDOUT_FILENO, stringFormat, len);
free(stringFormat);
}

/**
 * aliasSub - checks the args then substitutes
 *               the alias name with the alias value
* @args: pointer to a pointer to the head of the alias arguments
* Return: The inputed args
*/
char **aliasSub(char **args)
{
alias_t *findName = aliases;
char *newAlias;
int i, j, k, len, aliasLen, argLen;

for (i = 0; args[i] != NULL; i++)
{
findName = aliases;
while (findName)
{
if (comp_strns(findName->alias_name, args[i]) == 0)
{
aliasLen = lenofStrn(findName->value);
argLen = lenofStrn(args[i]);
len = aliasLen + argLen + 1;
newAlias = malloc(sizeof(char) * (len + 1));
(newAlias == NULL)
{
return (args);
}
for (j = 0; j < aliasLen; j++)
{
newAlias[j] = findName->value[j];
}
for (k = 0; k < argLen; k++)
{
newAlias[j + k] = args[i][k];
}
newAlias[j + k] = '\0';
free(args[i]);
args[i] = newAlias;
break;
}
findName = findName->next;
}
}
return (args);
}
/**
* egshell_alias - checks the args then substitutes the
*               alias name with the alias value
* @args: pointer to a pointer to the head of the alias arguments
* @begin_input: pointer to a pointer to the head of the alias arguments
* Return: 1 on error with a corresponding error message.
*        0 on success.
*/
int egshell_alias(char **args, char __attribute__((unused)) **begin_input)
{
alias_t *findName = aliases;
int i, j, k, len, aliasLen, argLen;
char *newAlias;
char *errMsg = "input: %s: not found\n";
if (args[1] == NULL)
{
while (findName)

aliasOutput(findName);
findName = findName->next;
}
return (1);
}
if (args[2] == NULL)
{
while (findName)
{
if (comp_strns(findName->alias_name, args[1]) == 0)
{
aliasOutput(findName);
return (1);
}
findName = findName->next;
}
write(STDOUT_FILENO, errMsg, lenofStrn(errMsg));
return (1);
}
aliasInput(args[1], args[2]);
return (1);
}
