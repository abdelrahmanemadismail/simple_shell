#include "shell.h"

/**
 * main - Simple shell
 * @ac: number of element in av
 * @av: array of parameters
 * Return: Always 0 or -1.
 */

int main(int ac, char **av)
{
char *promp = "#cisfun$ ", *buff = NULL, **command;
size_t num = 0;
ssize_t read;
int count = 0, status = 0;

while (1)
{
	count++;
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
	if (!command)
		continue;
	status = exit_shell(command, av[0], count, status);
	if (status != -1)
		break;
	if (!(print_env(command) || manage_env(command)) && ac > 0)
		status = exe(command, av[0], count);
	free(command);
	command = NULL;
}
	free(command);
	free(buff);
	if (status == -1)
		status = 0;
	_exit(status);
	return (0);
}
