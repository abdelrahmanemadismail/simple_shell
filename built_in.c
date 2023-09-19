#include "shell.h"
/**
 * print_env  - prints the current environment
 * @command: input string from the user
 * Return: 1 if run 0 if not
 */
int print_env(char *command[])
{
	int i = 0;
	char **env = environ;

	if (strcmp(command[0], "env") == 0)
	{
		while (env[i])
			printf("%s\n", env[i++]);
		return (1);
	}
	return (0);
}

/**
 * exit_shell - built-in, that exits the shell
 * @command: input string from the user
 * @filename: shell filename.
 * @c: line count
 * @s: last command status
 * Return: status code
 */
int exit_shell(char *command[], char *filename, int c, int s)
{
	char *endptr;
	long status;

	if (strcmp(command[0], "exit") == 0)
	{
		if (command[1] != NULL)
		{
			status = strtol(command[1], &endptr, 10);
			if (*endptr == '\0' && status >= 0)
				return ((int)status);
			fprintf(stderr,
				"%s: %i: %s: Illegal number: %s\n",
				filename, c, command[0], command[1]);
			return (2);
		}
		return (s);
	}
	return (-1);
}
