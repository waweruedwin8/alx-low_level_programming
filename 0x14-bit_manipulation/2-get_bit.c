#include "main.h"

/**
* get_bit - returns the value of a bit at an index in a decimal number
* @num: number to search
* @bitIndex: index of the bit
*
* Return: value of the bit
*/
int get_bit(unsigned long int num, unsigned int bitIndex)
{
int bitValue;

if (bitIndex > 63)
return (-1);

bitValue = (num >> bitIndex) & 1;

return (bitValue);
}
