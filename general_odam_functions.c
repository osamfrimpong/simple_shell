#include "shell.h"


/**
 * is_odam_interactive - checks whether shell is in interactive mode
 * Return: 1 or 0 as int
 */

int is_odam_interactive(void)
{
	return (isatty(STDIN_FILENO));
}

/**
 * execute_odam_command - function to execute command
 * @parsed_command: pointer to parsed commands
 * Return: void
 */

void execute_odam_command(char **parsed_command)
{
	BuiltIn odam_built_in_functions[4] = {
		{"exit", odam_exit},
		{"env", odam_env},
		{"cd", odam_cd},
		{"echo", odam_echo}
	};
	int odam_built_in_num, is_built_in = 0, odam_counter = 0;

	odam_built_in_num = sizeof(odam_built_in_functions) /
		sizeof(odam_built_in_functions[0]);

	while (odam_counter < odam_built_in_num)
	{
		if (strcmp(parsed_command[0],
					odam_built_in_functions[odam_counter].name) == 0)
		{
			is_built_in = 1;
			odam_built_in_functions[odam_counter].command(parsed_command);
			break;
		}
		odam_counter++;
	}

	if (is_built_in == 0)
		perform_actions(parsed_command);

}

/**
 * odam_is_white_space - checks if
 * string contains only whitespace characters
 * @input_string: pointer to string to check
 * Return: 1 if whitespace else 0
*/

int odam_is_white_space(char *input_string)
{
	int is_white = 1, odam_counter = 0;

	while (input_string[odam_counter])
	{
		if (!isspace(input_string[odam_counter]))
		{
			is_white = 0;
			break;
		}

		odam_counter++;
	}

	return (is_white);
}
