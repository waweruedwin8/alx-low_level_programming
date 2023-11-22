#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node in a linked list,
 * at a given position
 * @head: pointer to the first node in the list
 * @idx: index where the new node is added
 * @n: data to insert in the new node
 *
 * Return: pointer to the new node, or NULL
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *temp_node;
	int data;

	if (!head || !*head)
		return (0);

	data = (*head)->n;
	temp_node = (*head)->next;
	free(*head);
	*head = temp_node;

	return (data);
}
