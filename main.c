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
	free(buff);
	buff = NULL;
	if (isatty(STDIN_FILENO))
		printf("%s", promp);
	read = getline(&buff, &num, stdin);
	if (read == -1)
		break;
	else if (read == 1 && buff[0] == '\n')
		continue;
	if (buff[read - 1] == '\n')
		buff[read - 1] = '\0';
	command = tokenize(buff, " ");
	if(!command)
		continue;
	status = exit_shell(command);
	if (status != -1)
		break;
	status = 0;
	if (!print_env(command[0]))
		exe(command);
	free(command);
	command = NULL;
}
	free(command);
	free(buff);
	exit(status);
	return (0);
}
