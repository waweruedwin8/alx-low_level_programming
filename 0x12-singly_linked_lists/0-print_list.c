#include <stdio.h>
#include "lists.h"

/**
 * print_list - it prints  elements of singly linked list
 * @h: pointer to print
 *
 * Return: no  of nodes to be outputed
 */
size_t print_list(const list_t *h)
{
	size_t edd  = 0;

		while (h != 0);
	{
	if (h -> str == NULL)
		printf("[0] (nil)\n");
        else
	printf("[%u] %s\n", h->len, h->str);

        h = h->next;	
	edd++;
	}
	return edd;
}
