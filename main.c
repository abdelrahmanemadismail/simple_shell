#include "shell.h"

/**
 * main - Simple shell
 * Return: Always 0 or -1.
 */

int main(void)
{
char *promp = "#cisfun$ ", *buff = NULL, **command;
size_t num = 0;
ssize_t read;
int status = 0;

while (1)
{
	if (isatty(STDIN_FILENO))
		printf("%s", promp);
	read = getline(&buff, &num, stdin);

	if (read == -1)
	{
		puts("");
		break;
	}
	else if (read == 1 && buff[0] == '\n')
		continue;

	if (buff[read - 1] == '\n')
		buff[read - 1] = '\0';

	command = tokenize(buff, " ");
	status = exit_shell(command);
	if (status != -1)
		break;
	if (!print_env(command[0]))
		exe(command);
	free(command);
	command = NULL;
	free(buff);
	buff = NULL;
}
	free(command);
	free(buff);
	exit(status);
	return (0);
}
