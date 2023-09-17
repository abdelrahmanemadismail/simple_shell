#include "shell.h"
/**
 * print_env  - prints the current environment
 * @command: input string from the user
 *
 * Return: 1 if run 0 if not
 */
int print_env(char *command)
{
	char **env = environ;

	if (strcmp(command, "env") == 0)
	{
		while (*env)
			printf("%s\n", *env++);
		return (1);
	}
	return (0);
}

/**
 * exit_shell - built-in, that exits the shell
 * @command: input string from the user
 *
 * Return: status code
 */
int exit_shell(char **command)
{
	if (strcmp(command[0], "exit") == 0)
	{
		if (command[1] != NULL)
			return (atoi(command[1]));
		return (0);
	}
	return (-1);
}
