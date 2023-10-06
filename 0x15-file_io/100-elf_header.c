#include <elf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
void output_type(unsigned int e_type, unsigned char *d_id);
void output_entry(unsigned long int e_entry, unsigned char *d_id);
void close_elf(int elf);
void output_class(unsigned char *d_id);
void output_data(unsigned char *d_id);
void output_version(unsigned char *d_id);
void output_abi(unsigned char *d_id);
void print_osabi(unsigned char *d_id);
void check_elf_file(unsigned char *d_id);
void output_magic(unsigned char *d_id);

/**
 * check_elf_file - To know if a file is file ELF.
 * @d_id: A pointer to an array containing the ELF magic numbers.
 * Description: Return Success
 */
void check_elf_file(unsigned char *d_id)
{
  int index;

    for (index = 0; index < 4; index++)
    {
        if (d_id[index] != 127 &&
        d_id[index] != 'E' &&
        d_id[index] != 'L' &&
        d_id[index] != 'F')
        {
            dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
            exit(98);
            }
            }
            }

/**
 * output_magic - Prints the magic numbers of an ELF header.
 * @d_id: A pointer to an array containing the ELF magic numbers.
 * Description: Magic numbers are separated by spaces.
 */

void output_magic(unsigned char *d_id)
{
    int index;

    printf(" Magic: ");
    for (index = 0; index < EI_NIDENT; index++)
    {
        printf("%02x", d_id[index]);
        if (index == EI_NIDENT - 1)
        printf("\n");
        else
        printf(" ");
        }
        }

/**
 * output_class - Output the class of an ELF header.
 * @d_id: A pointer to an array containing the ELF class.
 */

void output_class(unsigned char *d_id)
{
    printf(" Class: ");
    switch (d_id[EI_CLASS])
    {
        case ELFCLASSNONE:
        printf("none\n");
        break;
        case ELFCLASS32:
        printf("ELF32\n");
        break;
        case ELFCLASS64:
        printf("ELF64\n");
        break;
        default:
        printf("<unknown: %x>\n", d_id[EI_CLASS]);
        }
        }

/**
 * output_data - Prints the data of an ELF header.
 * @d_id: A pointer to an array containing the ELF class.
 */

void output_data(unsigned char *d_id)
{
    printf(" Data: ");
    switch (d_id[EI_DATA])
    {
        case ELFDATANONE:
        printf("none\n");
        break;
        case ELFDATA2LSB:
        printf("2's complement, little endian\n");
        break;
        case ELFDATA2MSB:
        printf("2's complement, big endian\n");
        break;
        default:
        printf("<unknown: %x>\n", d_id[EI_CLASS]);
        }
        }
/**
 * output_version -Output the version of an ELF header.
 * @d_id: A pointer to an array containing the ELF version.
 */

void output_version(unsigned char *d_id)
{
    printf(" Version: %d",
    d_id[EI_VERSION]);
    switch (d_id[EI_VERSION])
    {
        case EV_CURRENT:
        printf(" (current)\n");
        break;
        default:
        printf("\n");
        break;
        }
}

/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @d_id: A pointer to an array containing the ELF version.
 */

void print_osabi(unsigned char *d_id)
{
        printf(" OS/ABI: ");
        switch (d_id[EI_OSABI])
        {
            case ELFOSABI_NONE:
            printf("UNIX - System V\n");
            break;
            case ELFOSABI_HPUX:
            printf("UNIX - HP-UX\n");
            break;
            case ELFOSABI_NETBSD:
            printf("UNIX - NetBSD\n");
            break;
            case ELFOSABI_LINUX:
            printf("UNIX - Linux\n");
            break;
            case ELFOSABI_SOLARIS:
            printf("UNIX - Solaris\n")
            break;
            case ELFOSABI_IRIX:
            printf("UNIX - IRIX\n");
            break;
            case ELFOSABI_FREEBSD:
            printf("UNIX - FreeBSD\n");
            break;
            case ELFOSABI_TRU64:
            printf("UNIX - TRU64\n");
            break;
            case ELFOSABI_ARM:
            printf("ARM\n");
            break;
            case ELFOSABI_STANDALONE:
            printf("Standalone App\n");
            break;
            default:
            printf("<unknown: %x>\n", d_id[EI_OSABI]);
            }
            }
/**
 * output_abi - Output the ABI version of an ELF header.
 * @d_id: A pointer to an array containing the ELF ABI version.
 */

void output_abi(unsigned char *d_id)
{
    printf(" ABI Version: %d\n",
    d_id[EI_ABIVERSION]);
    }

/**
 * output_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @d_id: A pointer to an array containing the ELF class.
 */

void output_type(unsigned int e_type, unsigned char *d_id)
{
    if (d_id[EI_DATA] == ELFDATA2MSB)
    e_type >>= 8;
    printf(" Type: ");
    switch (e_type)
    {
        case ET_NONE:
        printf("NONE (None)\n");
        break;
        case ET_REL:
        printf("REL (Relocatable file)\n");
        break;
        case ET_EXEC:
        printf("EXEC (Executable file)\n");
        break;
        case ET_DYN:
        printf("DYN (Shared object file)\n");
        break;
        case ET_CORE:
        printf("CORE (Core file)\n");
        break;
        default:
        printf("<unknown: %x>\n", e_type);
        }
        }

/**
 * output_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @d_id: A pointer to an array containing the ELF class.
 */

void output_entry(unsigned long int e_entry, unsigned char *d_id)
{
    printf(" Entry point address: ");
    if (d_id[EI_DATA] == ELFDATA2MSB)
    {
        e_entry = ((e_entry << 8) & 0xFF00FF00) |
        ((e_entry >> 8) & 0xFF00FF);
        e_entry = (e_entry << 16) | (e_entry >> 16);
        }
        if (d_id[EI_CLASS] == ELFCLASS32)
        printf("%#x\n", (unsigned int)e_entry);
        else
        printf("%#lx\n", e_entry);
        }

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 * Description: If the file cannot be closed - exit code 98.
 */

void close_elf(int elf)
{
  if (close(elf) == -1)
    {
        dprintf(STDERR_FILENO,
        "Error: Can't close fd %d\n", elf);
        exit(98);
        }
        }

/**
 * main - Displays the information contained in the
 * ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 * Description: If the file is not an ELF File or
 * the function fails - exit code 98.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
  Elf64_Ehdr *header;
    int o, r;
    o = open(argv[1], O_RDONLY);
    if (o == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
        exit(98);
        }
        header = malloc(sizeof(Elf64_Ehdr));
        if (header == NULL)
        {
            close_elf(o);
            dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
            exit(98);
            }
            r = read(o, header, sizeof(Elf64_Ehdr));
            if (r == -1)
            {
                free(header);
                close_elf(o);
                dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
                exit(98);
                }check_elf(header->d_id);
        printf("ELF Header:\n");
        output_magic(header->d_id);
        output_class(header->d_id);
        output_data(header->d_id);
        output_version(header->d_id);
        print_osabi(header->d_id);
        output_abi(header->d_id);
        output_type(header->e_type, header->d_id);
        output_entry(header->e_entry, header->d_id);
        free(header);
        close_elf(o);
        return (0);
}
