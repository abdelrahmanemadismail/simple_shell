#include "shell.h"

/**
 * exe - Execute a command in a child process.
 * @buff: The command to be executed.
 *
 * Return: 0 when success otherwise 1.
 */

int exe(char *buff)
{
	int i = 0;
	char *buff_cp, *argv[64], *token = strtok(buff_cp, " ");

	if (token == NULL)
		return (1);
	while (token)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;

	if (execve(argv[0], argv, NULL) == -1)
	{
		perror("Error:");
	}
	return (0);
}
