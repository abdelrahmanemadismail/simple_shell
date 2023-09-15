#include "shell.h"
/**
 * tokenize - intitializes argv
 * @buf: input string from the user
 *
 * Return: tokenized (array of arguments)
 */
char **tokenize(char *buf)
{
	char **tokenized = malloc(64 * sizeof(char *)), *token;
	int i = 0;

	token = strtok(buf, " ");
	if (token == NULL)
		return (NULL);
	while (token)
	{
		tokenized[i++] = token;
		token = strtok(NULL, " ");
	}
	tokenized[i] = NULL;
	return (tokenized);
}
