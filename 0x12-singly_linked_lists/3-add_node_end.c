#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* add_node_end - Adds a new node at the end of a linked list.
* @head: A double pointer to the list_t list.
* @str: The string to be stored in the new node.
*
* Return: The address of the new node, or NULL if memory allocation fails.
*/
list_t *add_node_end(list_t **head, const char *str)
{
list_t *new_node;
list_t *current = *head;
unsigned int str_length = 0;

/* Calculate the length of the input string */
while (str[str_length])
str_length++;

/* Allocate memory for the new node */
new_node = malloc(sizeof(list_t));
if (!new_node)
return (NULL);

/* Allocate memory for the string within the node */
new_node->str = strdup(str);
if (!new_node->str)
{
free(new_node);
return (NULL);
}

/* Set the length of the string and update the next pointer to NULL */
new_node->len = str_length;
new_node->next = NULL;

/* If the list is empty, make the new node the head and return */
if (*head == NULL)
{
*head = new_node;
return (new_node);
}

/* Traverse the list to find the last node */
while (current->next)
current = current->next;

/* Attach the new node to the end of the list */
current->next = new_node;

return (new_node);
}

