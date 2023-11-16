#include <stdlib.h>
#include "lists.h"

/**
* free_list - Frees a linked list.
* @head: A pointer to the list_t list to be freed.
*/
void free_list(list_t *head)
{
list_t *current;

while (head)
    {
/* Save the reference to the next node */
current = head->next;

/* Free the string within the current node */
free(head->str);

/* Free the current node */
free(head);

/* Move to the next node in the list */
head = current;
}
}

