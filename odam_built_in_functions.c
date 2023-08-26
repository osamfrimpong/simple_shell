#include "shell.h"

/**
 * odam_exit - function to implement in-built exit
 * @parsed_commands: parsed command to execute
 * Return: int
 */
int odam_exit(char **parsed_commands)
{
	if (parsed_commands[1])
	{
		exit(atoi(parsed_commands[1]));
		return (atoi(parsed_commands[1]));
	}
	else
	{
		exit(0);
		return (0);
	}
}

/**
 * odam_env - function to implement in-built env
 * @parsed_commands: parsed command to execute
 * Return: int
 */
int odam_env(char **parsed_commands __attribute__((unused)))
{
	int odam_counter = 0;

	while (environ[odam_counter] != NULL)
	{
		printf("%s\n", environ[odam_counter]);
		odam_counter++;
	}

	return (odam_counter);
}

/**
 * odam_cd - function to implement in-built cd
 * @parsed_commands: parsed command to execute
 * Return: int
 */
int odam_cd(char **parsed_commands __attribute__((unused)))
{
	return (0);
}

/**
 * odam_echo - function to implement in-built echo
 * @parsed_commands: parsed command to execute
 * Return: int
 */
int odam_echo(char **parsed_commands)
{
	int odam_process_id;

	if (parsed_commands[2])
		write(2, "Too many arguments\n", 20);
	else
	{
		if (strcmp("$$", parsed_commands[1]) == 0)
		{
			odam_process_id = getpid();
			printf("%i\n", odam_process_id);
		}
		else if (strcmp("$?", parsed_commands[1]) == 0)
		{
			int odam_exit_status;

			wait(&odam_exit_status);

			printf("%d", odam_exit_status);
		}
		else
		{
			printf("%s\n", parsed_commands[1]);
		}
	}

	return (0);
}
