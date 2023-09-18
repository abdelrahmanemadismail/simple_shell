#include "shell.h"

/**
 * exe - Execute a command in a child process.
 * @command: The command to be executed.
 * @filename: shell filename.
 * @c: line count 
 * Return: 0 when success otherwise 1.
 */

int exe(char *command[], char *filename, int c)
{
	pid_t pid;
	int status;
	char *cmd;

	cmd = which(command[0]);
	if (cmd == NULL)
	{
		fprintf(stderr, "%s: %i: %s: not found\n", filename, c, command[0]);
		return (127);
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
			fprintf(stderr, "%s: %i: %s: not found\n", filename, c, command[0]);
			exit(127);
		}
	}
	else
	{
		wait(&status);
	}
	free(cmd);
	cmd = NULL;
	return (WEXITSTATUS(status));
}
