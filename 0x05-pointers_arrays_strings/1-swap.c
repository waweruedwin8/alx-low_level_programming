#include <stdio.h>

/**
 * swap_int - Swaps value of 2 int
 * @a: the first int to be swapped
 * @b: the second int to be swapped
 *
 * Return: 0
 */
void swap_int(int *a, int *b)
/* function that swaps the value of 2 int */
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
