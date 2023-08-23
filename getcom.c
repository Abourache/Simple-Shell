#include "shell.h"
/**
 * getcom - check the code
 * @com: com
 * @path: path
 * Return: char
*/
char *getcom(char *com, char *path)
{
	char *token;
	char *all;
	int check = 0;

	token = strtok(path, ":");
	while (token)
	{
		all = malloc(strlen(token) + strlen(com) + 2);
		if (all == NULL)
		{
			perror("failed to allocate");
			exit(1);
		}
		_strcpy(all, token);
		_strcat(all, "/");
		_strcat(all, com);
		check = checkcom(all);
		if (check == 0)
			return (all);
		free(all);
		token = strtok(NULL, ":");
	}
	return (NULL);
}
