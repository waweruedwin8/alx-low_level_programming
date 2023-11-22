#include "lists.h"

/**
 * get_nodeint_at_index - returns the node at a certain index in a linked list
 * @head: pointer to the first node in the linked list
 * @idx: index of the node to return
 *
 * Return: pointer to the node we're looking for, or NULL
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int idx)
{
	unsigned int i = 0;
	listint_t *temp_node = head;

	while (temp_node && i < idx)
	{
		temp_node = temp_node->next;
		i++;
	}

	return (temp_node ? temp_node : NULL);
}

