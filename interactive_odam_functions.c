#include "shell.h"

/**
 * initiate_odam_interactive - starts ODAM shell in interactive mode
 * Return: void
 */

void initiate_odam_interactive(void)
{
	char *command_input = malloc(sizeof(char) * ODAM_TOKEN_BUFFER_SIZE);
	size_t odam_linecap = 0;
	int shell_status = 1;
	ssize_t getline_result;
	char **parsed_command;

	while (shell_status == 1)
	{
		printf("$ ");

		getline_result = getline(&command_input, &odam_linecap, stdin);

		if (getline_result == -1)
		{
			shell_status = -1;
			exit(EXIT_SUCCESS);
		}
		else
		{
			if (!odam_is_white_space(command_input))
			{
				parsed_command = parse_command_input(command_input, ODAM_TOKEN_SEPARATOR);
				execute_odam_command(parsed_command);
				odam_free_command_memory(parsed_command);
			}

		}
	}

	free(command_input);
}
