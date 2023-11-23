#include "main.h"

/**
* print_binary - prints the binary equivalent of a decimal number
* @num: number to print in binary
*
* Description: This function prints the binary equivalent of a decimal number.
* It takes an unsigned long integer as input and prints its binary equivalent.
* The prototype of the function is not changed.
*/
void print_binary(unsigned long int num)
{
int e, count = 0;
unsigned long int current;

for (e = 63; e >= 0; e--)
{
current = num >> e;

if (current & 1)
{
_putchar('1');
count++;
}
else if (count)
_putchar('0');
}
if (!count)
_putchar('0');
}
