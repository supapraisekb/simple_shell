#include "sim_shell.h"

/**
* append_node - adds a node to the end of the list
* @begin: points to the head of the linked list
* @node_data: data associated with the new node
* Return: a pointer to the new linked list created
*/
list_t *append_node(list_t **begin, char *node_data)
{
list_t *created_node = malloc(sizeof(list_t));

if (!begin || !node_data)
return (NULL);
if (created_node == NULL)
return (NULL);
created_node->str_var = dup_strn(node_data);
if (created_node->str_var == NULL)
{
free(created_node);
return (NULL);
}

created_node->node_ptr = NULL;

if (*begin == NULL)
{
*begin = created_node;
}
else
{
list_t *present_node = *begin;
while (present_node->node_ptr != NULL)
{
present_node = present_node->node_ptr;
}
present_node->node_ptr = created_node;
}

return (*begin);
}

/**
* release_list - frees the linked list
* @list_head: linked list
*/

void release_list(list_t *list_head)
{
list_t *current_node, *new_node;
current_node = list_head;

while (current_node != NULL)
{
new_node = current_node->node_ptr;
free(current_node->str_var);
free(current_node);
current_node = new_node;
}

}

/**
* disp_list - it prints out the simple shell linked list
* @head: pointer to the head of the linked list
* Return: number of elements in the list
*/
size_t disp_list(list_t *head)
{
list_t *node_current = head;
int li_size = 0, len_of_strn;
if (!head)
return (0);

while (node_current != NULL)
{
if (node_current->str_var == NULL)
{
write(STDOUT_FILENO, "(Empty)", 7);
write(STDOUT_FILENO, "\n", 1);
}
else
{
len_of_strn = 0;
while ((node_current->str_var)[len_of_strn] != '\0')
len_of_strn++;

write(STDOUT_FILENO, node_current->str_var, len_of_strn);
write(STDOUT_FILENO, "\n", 1);
}
node_current = node_current->node_ptr;
li_size++;
}
return (li_size);
}

/**
* del_node - removes a node at a given index
* @list_head: address that points to the head of the list
* @node_index: index of the node to be removed
* Return: 1 if success, -1 if fail
*/
int del_node(list_t **list_head, int node_index)
{
list_t *node_1, *node_buff;
int counter = 1;

if (*list_head == NULL)
return (-1);

if (node_index == 0)
{
node_buff = *list_head;
*list_head = node_buff->node_ptr;
free(node_buff->str_var);
free(node_buff);
return (1);
}

node_1 = *list_head;

while (node_1 != NULL && counter < node_index)
{
node_1 = node_1->node_ptr;
counter++;
}

if (node_1 == NULL || node_1->node_ptr == NULL)
return (-1);

node_buff = node_1->node_ptr;
node_1->node_ptr = node_buff->node_ptr;
free(node_buff->str_var);
free(node_buff);
return (1);
}

