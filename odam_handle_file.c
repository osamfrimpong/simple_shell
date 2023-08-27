#include "shell.h"

/**
 * odam_handle_file - handles passed file
 * @file_name: pointer to hold file_name
 * Return: void
 */

void odam_handle_file(char *file_name)
{
	char **parsed_command;
	char odam_file_buffer[ODAM_MAX_BUFFER_SIZE];
	ssize_t bytes_read;
	int file_handler = open(file_name, O_RDONLY);

	if (file_handler == -1)
	{
		perror("Error opening the file");
		return;
	}
	else
	{

		while ((bytes_read = read(file_handler,
						odam_file_buffer, sizeof(odam_file_buffer))) > 0)
		{

			odam_file_buffer[bytes_read] = '\0';
			if (!odam_is_white_space(odam_file_buffer))
			{
				parsed_command = parse_command_input(odam_file_buffer,
						ODAM_TOKEN_SEPARATOR);
				execute_odam_command(parsed_command);
				odam_free_command_memory(parsed_command);
			}
		}

		if (bytes_read == -1)
		{
			perror(odam_shell_name);
			close(file_handler);
			return;
		}
	}

	close(file_handler);
}

/**
 * odam_process_file - processes file
 * @file_name: pointer to filename
 * Return:void
 */
void odam_process_file(char *file_name)
{
	char *error_message;
	struct stat odam_file_struct;

	if (access(file_name, F_OK) == -1)
	{
		error_message = malloc(ODAM_MAX_BUFFER_SIZE * sizeof(char));

		if (error_message == NULL)
		{
			perror(odam_shell_name);
			exit(EXIT_FAILURE);
		}

		snprintf(error_message, ODAM_MAX_BUFFER_SIZE,
				"%s: 0: Can't open %s\n",
				odam_shell_name, file_name);

		write(STDERR_FILENO, error_message, strlen(error_message));
		free(error_message);
		exit(127);
	}

	if (stat(file_name, &odam_file_struct) == -1)
	{
		perror("Error getting file information");
		exit(EXIT_FAILURE);
	}

	if (odam_file_struct.st_size == 0)
	{
		/* fprintf(stderr, "File is empty\n"); */
		exit(EXIT_SUCCESS);
	}

	odam_handle_file(file_name);
}
