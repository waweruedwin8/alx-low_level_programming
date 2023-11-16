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
	size_t e = 0;

	while (h)
	{
		if (!h->str)
			printf("[0] (nil)\n");
		else
			printf("[%u] %s\n", h->len, h->str);
		h = h->next;
		e++;
	}

	return (e);
}
