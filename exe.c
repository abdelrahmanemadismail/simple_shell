#include "shell.h"

/**
 * exe - Execute a command in a child process.
 * @command: The command to be executed.
 *
 * Return: 0 when success otherwise 1.
 */

int exe(char *command[])
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		exit(1);
		return (1);
	}
	if (pid == 0)
	{
		if (execve(command[0], command, NULL) == -1)
		{
			perror("no command");
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
	return (0);
}
