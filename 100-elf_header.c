#include "main.h"

/**
 * CheckElf - Checks if a file is an ELF file.
 * @e_ident:Points to an array containing the ELF magic numbers.
 *
 */

void CheckElf(unsigned char *e_ident)
{
	int inex;

	for (inex = 0; inex < 4; inex++)
	{
		if (e_ident[inex] != 127 &&
		    e_ident[inex] != 'E' &&
		    e_ident[inex] != 'L' &&
		    e_ident[inex] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * PrintMagic - Prints the magic numbers of an ELF header.
 * @e_ident: Points to an array containing the ELF magic numbers.
 *
 */
void PrintMagic(unsigned char *e_ident)
{
	int inex;

	printf("  Magic:   ");

	for (inex = 0; inex < EI_NIDENT; inex++)
	{
		printf("%02x", e_ident[inex]);

		if (inex == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * PrintClass - Prints the class of an ELF header.
 * @e_ident: Points to an array containing the ELF class.
 */

void PrintClass(unsigned char *e_ident)
{
	printf("  Class:                             ");

	switch (e_ident[EI_CLASS])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * PrintData - Prints the data of an ELF header.
 * @e_ident: Points to an array containing the ELF class.
 */

void PrintData(unsigned char *e_ident)
{
	printf("  Data:                              ");

	switch (e_ident[EI_DATA])
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
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * PrintVersion - Prints the version of an ELF header.
 * @e_ident: Points to an array containing the ELF version.
 */

void PrintVersion(unsigned char *e_ident)
{
	printf("  Version:                           %d",
	       e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
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
 * PrintOsabi - Prints the OS/ABI of an ELF header.
 * @e_ident: Points to an array containing the ELF version.
 */

void PrintOsabi(unsigned char *e_ident)
{
	printf("  OS/ABI:                            ");

	switch (e_ident[EI_OSABI])
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
		printf("UNIX - Solaris\n");
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
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * PrintAbi - Prints the ABI version of an ELF header.
 * @e_ident: Points to an array containing the ELF ABI version.
 */

void PrintAbi(unsigned char *e_ident)
{
	printf("  ABI Version:                       %d\n",
	       e_ident[EI_ABIVERSION]);
}

/**
 * PrintType - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: Points to an array containing the ELF class.
 */

void PrintType(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf("  Type:                              ");

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
 * PrintEntry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 *
 * Tobest_Codes
 *
 * @e_ident: Points to an array containing the ELF class.
 */

void PrintEntry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf("  Entry point address:               ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * CloseElf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exits with code 98.
 */

void CloseElf(int elf)
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
 *        ELF header at the start of an ELF file.
 * @argc: Number of arguments supplied to the program.
 * @argv: Array of pointers to the arguments.
 *
 * Tobest_Codes
 *
 * Return: 0 on success.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *Header;
	int oen, r_ead;

	oen = open(argv[1], O_RDONLY);
	if (oen == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	Header = malloc(sizeof(Elf64_Ehdr));
	if (Header == NULL)
	{
		CloseElf(oen);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r_ead = read(oen, Header, sizeof(Elf64_Ehdr));
	if (r_ead == -1)
	{
		free(Header);
		CloseElf(oen);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	CheckElf(Header->e_ident);
	printf("ELF Header:\n");
	PrintMagic(Header->e_ident);
	PrintClass(Header->e_ident);
	PrintData(Header->e_ident);
	PrintVersion(Header->e_ident);
	PrintOsabi(Header->e_ident);
	PrintAbi(Header->e_ident);
	PrintType(Header->e_type, Header->e_ident);
	PrintEntry(Header->e_entry, Header->e_ident);

	free(Header);
	CloseElf(oen);
	return (0);
}
