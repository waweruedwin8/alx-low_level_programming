#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int file_descriptor);

/**
* check_elf - Checks if a file is an ELF file.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*
* Description: If the file is not an ELF file - exit code 98.
*/
void check_elf(unsigned char *e_ident)
{
int index;

for (index = 0; index < 4; index++)
{
if (e_ident[index] != 127 &&
e_ident[index] != 'E' &&
e_ident[index] != 'L' &&
e_ident[index] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
}
}

/**
* print_magic - Prints the magic numbers of an ELF header.
* @e_ident: A pointer to an array containing the ELF magic numbers.
*
* Description: Magic numbers are separated by spaces.
*/
void print_magic(unsigned char *e_ident)
{
int index;

printf("  Magic:   ");

for (index = 0; index < EI_NIDENT; index++)
{
printf("%02x", e_ident[index]);

if (index == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
}
}



/**
* close_elf - Closes an ELF file.
* @file_descriptor: The file descriptor of the ELF file. Changed variable name to file_descriptor.
*
* Description: If the file cannot be closed - exit code 98.
*/
void close_elf(int file_descriptor)
{
if (close(file_descriptor) == -1)
{
dprintf(STDERR_FILENO,
"Error: Can't close fd %d\n", file_descriptor);
exit(98);
}
}

/**
* main - Displays the information contained in the
*        ELF header at the start of an ELF file.
* @argc: The number of arguments supplied to the program.
* @argv: An array of pointers to the arguments.
*
* Return: 0 on success.
*
* Description: If the file is not an ELF File or
*              the function fails - exit code 98.
*/
int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *elf_header;
int file_descriptor, read_result;

file_descriptor = open(argv[1], O_RDONLY);
if (file_descriptor == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}

elf_header = malloc(sizeof(Elf64_Ehdr));
if (elf_header == NULL)
{
close_elf(file_descriptor);
dprintf(STDERR_FILENO, "Error: Can't allocate memory for ELF header\n");
exit(98);
}

read_result = read(file_descriptor, elf_header, sizeof(Elf64_Ehdr));
if (read_result == -1)
{
free(elf_header);
close_elf(file_descriptor);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}

check_elf(elf_header->e_ident);
printf("ELF Header:\n");
print_magic(elf_header->e_ident);
print_class(elf_header->e_ident);
print_data(elf_header->e_ident);
print_version(elf_header->e_ident);
print_osabi(elf_header->e_ident);
print_abi(elf_header->e_ident);
print_type(elf_header->e_type, elf_header->e_ident);
print_entry(elf_header->e_entry, elf_header->e_ident);

free(elf_header);
close_elf(file_descriptor);
return (0);


