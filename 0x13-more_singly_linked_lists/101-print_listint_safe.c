#include "lists.h"

/**
 * looped_listint_len - Counts the number of unique nodes
 *                      in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 *         Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
	const listint_t *tortoise_node, *hare_node;
	size_t num_nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	tortoise_node = head->next;
	hare_node = (head->next)->next;

	while (hare_node)
	{
		if (tortoise_node == hare_node)
		{
			tortoise_node = head;
			while (tortoise_node != hare_node)
			{
				num_nodes++;
				tortoise_node = tortoise_node->next;
				hare_node = hare_node->next;
			}

			tortoise_node = tortoise_node->next;
			while (tortoise_node != hare_node)
			{
				num_nodes++;
				tortoise_node = tortoise_node->next;
			}

			return (num_nodes);
		}

		tortoise_node = tortoise_node->next;
		hare_node = (hare_node->next)->next;
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t num_nodes, index = 0;

	num_nodes = looped_listint_len(head);

	if (num_nodes == 0)
	{
		for (; head != NULL; num_nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}

	else
	{
		for (index = 0; index < num_nodes; index++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}

		printf("-> [%p] %d\n", (void *)head, head->n);
	}

	return (num_nodes);
}
