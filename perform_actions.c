#include "shell.h"

/**
 * perform_actions - function to execute entered commands
 * @parsed_arguments: parsed inputted arguments
 */

void perform_actions(char **parsed_arguments)
{
	char *full_command_path;

	if (is_odam_path_available(parsed_arguments[0]) == 1)
	{
		odam_do_system_call(parsed_arguments[0], parsed_arguments);
	}
	else
	{
		full_command_path = get_command_path(parsed_arguments[0]);
		odam_do_system_call(full_command_path, parsed_arguments);
		free(full_command_path);
	}
}

/**
 * odam_do_system_call - function to execute entered commands
 * @command_to_execute: actual command to be executed
 * @parsed_arguments: parsed inputted arguments
 */
void odam_do_system_call(char *command_to_execute, char **parsed_arguments)
{
	pid_t odam_process_id;
	char *imploded_command;

	if (command_to_execute != NULL)
	{
		odam_process_id = fork();
		if (odam_process_id == 0)
		{
			execve(command_to_execute, parsed_arguments, NULL);
			perror(odam_shell_name);
		}
		else if (odam_process_id < 0)
		{
			perror(strcat(odam_shell_name, " :1 : "));
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		imploded_command = odam_implode(parsed_arguments, " ");
		odam_write_error(imploded_command);
		free(imploded_command);
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

	if (access(full_command_path, F_OK) == 0 &&
		access(full_command_path, X_OK) == 0)
	{
		is_available = 1;
	}
	return (is_available);
}

/**
 * odam_write_error - prints error message to stderr
 * @imploded_command: pointer to command as string
 * Return: int
 */
int odam_write_error(char *imploded_command)
{
	char *error_message;

	error_message = malloc(ODAM_MAX_BUFFER_SIZE * sizeof(char));

	if (error_message == NULL)
	{
		perror(odam_shell_name);
		return (1);
	}

	snprintf(error_message, 1024,
			 "%s: 1: %s: command not found\n",
			 odam_shell_name, imploded_command);

	write(STDERR_FILENO, error_message, strlen(error_message));
	free(error_message);

	return (0);
}
