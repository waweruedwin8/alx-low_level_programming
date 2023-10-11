#include "main.h"
#include <ctype.h>

/**
 * _islower - checks for lowercase character.
 * @c: The char to be checked
 * Return: returns 1 if char is lowercase else returns 0
 */
int _islower(int c)
{
if (c >= 97 && c <= 122)
{
return (1);
}
return (0);
}
