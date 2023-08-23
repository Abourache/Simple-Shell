#include "shell.h"
/**
 * envi - check the code
 * @evi: evi
 * Return: char
*/
char **envi(char **evi)
{
	int j;
	int env_count = 0;
	char **env;
	char **cop_env;

	for (env = evi; *env != NULL; env++)
		env_count++;

	cop_env = malloc((env_count + 1) * sizeof(char *));
	if (cop_env == NULL)
	{
		perror("Memory allocation failed");
		return (NULL);
	}
	for (j = 0; j < env_count; j++)
	{
		cop_env[j] = _strdup(evi[j]);
		if (cop_env[j] == NULL)
		{
			perror("Memory allocation failed");
			return (NULL);
		}
	}
	cop_env[env_count] = NULL;
	return (cop_env);
}
/**
 * split - check the code
 * @buff: buff
 * Return: char
*/
char **split(char *buff)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	token = strtok(buff, " \t\n#\\&*`'\"");
	while (token)
	{
		tokens[i] = token;
		token = strtok(NULL, " \t\n#\\&*`'\"");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
/**
 * toke - check the code
 * @str: str
 * @envcop: envcop
 * Return: char
*/
char *toke(char *str, char **envcop)
{
	char *token = NULL;
	int i = 0;

	while (envcop[i])
	{
		token = strtok(envcop[i], "=");
		if (_strcmp(str, token) == 0)
			return (strtok(NULL, "\n"));
		i++;
	}
	return (NULL);
}
/**
 * checkcom - check the code
 * @com: com
 * Return: int
*/
int checkcom(char *com)
{
	if (access(com, F_OK) == 0)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
