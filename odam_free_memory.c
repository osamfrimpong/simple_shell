#include "shell.h"

/**
 * odam_free_command_memory - frees memory
 * Return: void
 * @parsed_command: pointer to memory to be freed.
 */

void odam_free_command_memory(char **parsed_command)
{
	int i;

	if (parsed_command != NULL)
	{
		for (i = 0; parsed_command[i] != NULL; i++)
		{
			free(parsed_command[i]);
		}

		free(parsed_command);
	}
}
