#include "shell.h"

/**
 * main - main entry to shell
 * @argc: argument count
 * @argv: string arguments
 * Return: 0 for success
 */

int main(int argc, char *argv[])
{
	odam_shell_name = argv[0] == NULL ? "tsh" : argv[0];

	if (argc == 2)
	{

		odam_process_file(argv[1]);
	}
	else
	{

		if (is_odam_interactive() == 1)
		{
			initiate_odam_interactive();
		}
		else
		{
			initiate_odam_non_interactive();
		}
	}
	return (0);
}
