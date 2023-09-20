#include "shell.h"

/**
 * main - Simple shell
 * @ac: number of element in av
 * @av: array of parameters
 * Return: Always 0 or -1.
 */

int main(int ac, char **av)
{
char *promp = "#cisfun$ ", *buff = NULL, **cmd;
size_t num = 0;
ssize_t read;
int c = 0, status = 0;

while (1)
{
	c++;
	free(buff);
	buff = NULL;
	if (isatty(STDIN_FILENO))
		printf("%s", promp);
	num = 0;
	read = getline(&buff, &num, stdin);
	if (read == -1)
		break;
	else if (read == 1 && buff[0] == '\n')
		continue;
	if (buff[read - 1] == '\n')
		buff[read - 1] = '\0';
	cmd = tokenize(buff, " ");
	if (!cmd)
		continue;
	status = exit_sh(cmd, av[0], c, status);
	if (status != -1)
		break;
	if (!(print_env(cmd) || mng_env(cmd) || cd_sh(cmd, av[0], c)) && ac > 0)
		status = exe(cmd, av[0], c);
	free(cmd);
	cmd = NULL;
}
	free(cmd);
	free(buff);
	if (status == -1)
		status = 0;
	_exit(status);
	return (0);
}
