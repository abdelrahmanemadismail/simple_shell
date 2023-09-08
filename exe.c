#include "shell.h"
int exe (char *buff )
{
	int i=0;
	char *buff_cp = buff;
char *argv[64];
char *token = strtok(buff_cp, " ");
	if (token == NULL)
		return (1);
	while (token != NULL)
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
