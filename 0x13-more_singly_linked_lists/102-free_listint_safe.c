#include "lists.h"

/**
 * free_listint_safe - frees a linked list
 * @head: pointer to the first node in the linked list
 *
 * Return: number of elements in the freed list
 */
size_t free_listint_safe(listint_t **head)
{
	size_t num_elements = 0;
	int difference;
	listint_t *temp_node;

	if (!head || !*head)
		return (0);

	while (*head)
	{
		difference = *head - (*head)->next;
		if (difference > 0)
		{
			temp_node = (*head)->next;
			free(*head);
			*head = temp_node;
			num_elements++;
		}
		else
		{
			free(*head);
			*head = NULL;
			num_elements++;
			break;
		}
	}

	*head = NULL;

	return (num_elements);
}
