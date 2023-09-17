#include "shell.h"
/**
 * tokenize - intitializes argv
 * @buf: input string from the user
 * @del: delemeter to cut at
 * Return: tokenized (array of arguments)
 */
char **tokenize(char *buf, char *del)
{
	char **tokenized = malloc(64 * sizeof(char *)), *token;
	int i = 0;

	token = strtok(buf, del);
	if (token == NULL)
		return (NULL);
	while (token)
	{
		tokenized[i++] = token;
		token = strtok(NULL, del);
	}
	tokenized[i] = NULL;
	return (tokenized);
}
