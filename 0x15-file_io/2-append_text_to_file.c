#include "main.h"
#include <stdlib.h>

/**
* append_text_to_file - Appends text at the end of a file.
* @filename: A pointer to the name of the file.
* @text_content: The string to add to the end of the file.
*
* Return: If the function fails or filename is NULL - -1.
*         If the file does not exist or the user lacks write permissions - -1.
*         Otherwise - 1.
*/
int append_text_to_file(const char *filename, char *text_content)
{
int file_descriptor, bytes_written, length = 0;

// Check if the filename is NULL
if (filename == NULL)
return (-1);

// Determine the length of the text_content string
if (text_content != NULL)
{
for (length = 0; text_content[length];)
length++;
}

// Open the file for writing and appending
file_descriptor = open(filename, O_WRONLY | O_APPEND);

// Write the text_content to the file
bytes_written = write(file_descriptor, text_content, length);

// Check for errors in file opening or writing
if (file_descriptor == -1 || bytes_written == -1)
return (-1);

// Close the file
close(file_descriptor);

// Return success
return (1);
}
