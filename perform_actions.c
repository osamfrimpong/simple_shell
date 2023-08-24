#include "shell.h"

/**
 * perform_actions - function to execute entered commands
 * @parsed_arguments: parsed inputted arguments
 */

void perform_actions(char **parsed_arguments)
{
	char *shell_name, *command_to_execute = get_command_path(parsed_arguments[0]);
	pid_t odam_process_id;

	shell_name = odam_shell_name;

	if (command_to_execute != NULL)
	{
		odam_process_id = fork();
		if (odam_process_id == 0)
		{
			execve(command_to_execute, parsed_arguments, NULL);
			perror(shell_name);
		}
		else if (odam_process_id < 0)
		{
			perror(strcat(shell_name, " :1 : "));
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		printf("%s: 1: %s: command not found\n",
				shell_name, odam_implode(parsed_arguments, " "));
	}

}
