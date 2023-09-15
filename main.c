#include "shell.h"

/**
 * main - Simple shell
 * Return: Always 0 or -1.
 */

int main(void)
{
char *promp = "#cisfun$ ", *buff, **env = environ, **command;
size_t num = 0;
ssize_t read;

while (1)
{
	if (isatty(STDIN_FILENO))
		printf("%s", promp);
	read = getline(&buff, &num, stdin);

	if (read == -1)
		break;
	else if (read == 1 && buff[0] == '\n')
		continue;

	if (buff[read - 1] == '\n')
		buff[read - 1] = '\0';

	command = tokenize(buff);
	if (strcmp(command[0], "env") == 0)
	{
		while (*env)
			printf("%s\n", *env++);
		continue;
	}
	if (strcmp(command[0], "exit") == 0)
	{
		if (command[1] != NULL)
			exit(atoi(command[1]));
		break;
	}
	exe(command);
	free(command);
	command = NULL;
	free(buff);
	buff = NULL;
}
	free(command);
	free(buff);
	return (0);
}
