#include <stdio.h>

/**
* _strlen - returns length of a str
* @str: the str to get legth
* Return: the lenth of @str
*/
size_t _strlen(const char *str)

{
	size_t length = 0;

	while (*str++)
	length++;
	return (length);
}	
