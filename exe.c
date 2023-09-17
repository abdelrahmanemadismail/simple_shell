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
	char *cmd;

	cmd = which(command[0]);
	if (cmd == NULL)
	{
		perror("hsh");
		return (1);
	}
	pid = fork();
	if (pid == -1)
	{
		free(cmd);
		exit(1);
		return (1);
	}
	if (pid == 0)
	{
		if (execve(cmd, command, NULL) == -1)
		{
			free(cmd);
			perror("no command");
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
	free(cmd);
	cmd = NULL;
	return (0);
}
