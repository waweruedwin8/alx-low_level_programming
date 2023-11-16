#include <stdlib.h>
#include "lists.h"

/**
 * list_len - returns  num of elem in a linked list
 * @h: *to the list_t list
 *
 * Return:elements contained in h
 */
size_t list_len(const list_t *h)
{
	size_t e = 0;

	while (h)
	{
		e++;
		h = h->next;
	}
	return (e);
}
