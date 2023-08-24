#include "shell.h"

/**
 * perform_actions - function to execute entered commands
 * @parsed_arguments: parsed inputted arguments
 */

void perform_actions(char **parsed_arguments)
{
	char *shell_name;
	pid_t odam_process_id;
	char *command_to_execute = is_odam_path_available(parsed_arguments[0])
	? parsed_arguments[0] : get_command_path(parsed_arguments[0]);

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

/**
 * is_odam_path_available - checks if supplied command path is available
 * @full_command_path: command full path
 * Return: int
 */
int is_odam_path_available(char *full_command_path)
{
	int is_available = 0;

	if (access(full_command_path, F_OK) == 0
	&& access(full_command_path, X_OK) == 0)
	{
		is_available = 1;
	}
	return (is_available);
}

