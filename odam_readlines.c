#include "shell.h"

/**
 * odam_read_lines - reads lines from a file or stdin
 * Return: pointer to lines read as string
 */

char *odam_read_lines(void)
{
	char *input_commands = NULL;
	size_t odam_buffer_size = 0;

	if (getline(&input_commands, &odam_buffer_size, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(input_commands);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(input_commands);
			perror(odam_shell_name);
			exit(EXIT_FAILURE);
		}
	}
	return (input_commands);

}
