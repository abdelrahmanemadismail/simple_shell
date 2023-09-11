#include "shell.h"

/**
 * main - Simple shell
 * Return: Always 0 or -1.
 */

int main(void)
{

char *promp = "#cisfun$ ", *buff, **env = environ;
size_t num = 0;
ssize_t read;

while (1)
{
	if (isatty(STDIN_FILENO))
		printf("%s", promp);
	read = getline(&buff, &num, stdin);
	if (read == -1 || _strcmp(buff, "exit\n") == 0)
	{
		return (-1);
	}
	if (buff[read - 1] == '\n')
		buff[read - 1] = '\0';

	if (_strcmp(buff, "env") == 0)
	{
		while (*env)
		{
			printf("%s\n", *env);
			env++;
		}
		continue;
	}

	exe(buff);

	free(buff);
	buff = NULL;
}
	free(buff);
	return (0);
}
