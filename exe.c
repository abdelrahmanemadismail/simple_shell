#include "shell.h"

/**
 * exe - Execute a command in a child process.
 * @buff: The command to be executed.
 *
 * Return: 0 when success otherwise 1.
 */

int exe(char *buff)
{
	pid_t pid;
	int i = 0;
	int status;
	char *argv[64], *token = strtok(buff, " ");

	if (token == NULL)
		return (1);
	while (token)
	{
		argv[i++] = token;
		token = strtok(NULL, " ");
	}
	argv[i] = NULL;
	pid=fork();
	if(pid==-1){
	exit(1);
	}
	if(pid==0){
	if(execve(argv[0],argv,NULL)==-1){
	perror("no command");
	exit(127);
	}
	else{
/*	printf(promp);*/
	wait(&status);
	}
	}


	
	return (0);
}
