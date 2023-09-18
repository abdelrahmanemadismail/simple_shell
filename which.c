#include "shell.h"
/**
 * which - gets the valid pathh of the entered command
 * @token: coammand string
 * Return: the path string
 */
char *which(char *token)
{
	char *path, *path_cpy, **path_token, *file_path;
	int tkn_len, dir_len, i = 0;
	struct stat buffer;

	if (stat(token, &buffer) == 0)
		return (strdup(token));
	path = getenv("PATH");
	if (!path)
		return (NULL);
	path_cpy = strdup(path);
	if (!path_cpy)
		return (NULL);
	path_token = tokenize(path_cpy, ":");
	if (!path_token)
	{
		free(path_cpy);
		return (NULL);
	}
	tkn_len = strlen(token);
	while (path_token[i] != NULL)
	{
		dir_len = strlen(path_token[i]);
		file_path = malloc(tkn_len + dir_len + 2);
		if (!file_path)
			break;
		strcpy(file_path, path_token[i]);
		strcat(file_path, "/");
		strcat(file_path, token);
		strcat(file_path, "\0");
		if (stat(file_path, &buffer) == 0)
		{
			free(path_cpy);
			free(path_token);
			return (file_path);
		}
		free(file_path);
		i++;
	}
	free(path_cpy);
	free(path_token);
	return (NULL);
}

