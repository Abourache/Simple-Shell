#include "shell.h"
/**
 * comexec - check the code
 * @args: args
 * @avi: avi
 * @evi: evi
 * @ng: ng
 * @cmd: cmd
 * Return: int
*/
int comexec(char **args, char **avi, char **evi, int ng, char *cmd)
{
	int status;
	pid_t pid;

	if (checkcom(args[0]) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			if (execve(args[0], args, evi) == -1)
			{
				notfound(avi[0], ng, args[0]);
				freen(args);
				free(cmd);
				exit(0);
			}
		}
		else
		{
			if (pid > 0)
				wait(&status);
			else
				perror("fork");
		}
	}
	else if (cmd)
	{
		pid = fork();
		if (pid == 0)
			execve(cmd, args, evi);
		else if (pid > 0)
			wait(&status);
		else
			perror("fork");
	}
	else
	{
		notfound(avi[0], ng, args[0]);
		exit(127);
	}
	return (status);
}
