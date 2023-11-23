#include "main.h"

/**
* binary_to_uint - converts a binary number to unsigned int
* @b: string containing the binary number
*
* Return: the converted number
*/
unsigned int binary_to_uint(const char *b)
{
int e;
unsigned int decimalValue = 0;

if (!b)
return (0);

for (e = 0; b[e]; e++)
{
if (b[e] < '0' || b[e] > '1')
return (0);
decimalValue = 2 * decimalValue + (b[e] - '0');
}

return (decimalValue);
}

