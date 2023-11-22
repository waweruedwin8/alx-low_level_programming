#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 *
 * Return: address of the node where the loop starts, or NULL
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow_node = head;
	listint_t *fast_node = head;

	if (!head)
		return (NULL);

	while (slow_node && fast_node && fast_node->next)
	{
		fast_node = fast_node->next->next;
		slow_node = slow_node->next;
		if (fast_node == slow_node)
		{
			slow_node = head;
			while (slow_node != fast_node)
			{
				slow_node = slow_node->next;
				fast_node = fast_node->next;
			}
			return (fast_node);
		}
	}

	return (NULL);
}
