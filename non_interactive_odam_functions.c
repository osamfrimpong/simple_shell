#include "shell.h"

/**
 * initiate_odam_non_interactive - starts ODAM shell in non_interactive mode
 * Return: void
 */

void initiate_odam_non_interactive(void)
{
	char *command_inputs;
	char **parsed_command;

	while ((command_inputs = odam_read_lines()) != NULL)
	{
		if (!odam_is_white_space(command_inputs))
		{
		parsed_command = parse_command_input(command_inputs, ODAM_TOKEN_SEPARATOR);
		execute_odam_command(parsed_command);
		odam_free_command_memory(parsed_command);
		}
		free(command_inputs);
	}

}
