#include "shell.h" 

int main(void){

char *promp = "#cisfun$ ";
char *buff;
size_t num=0;
ssize_t read;

while (1)
{
	if (isatty(STDIN_FILENO))
		printf("%s", promp);
	read = getline(&buff, &num, stdin);
	if(read == -1)
	{
		return (-1);
	}
	if (buff[read - 1] == '\n')
		buff[read - 1] = '\0';
	printf("%s", buff);
	free(buff);
	buff = NULL;
}
	free(buff);
	return (0);
}
