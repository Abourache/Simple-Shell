#include "shell.h"
/**
 * main - check the code
 * @ac: ac
 * @av: av
 * @ev: ev
 * Return: int
*/
int main(int ac __attribute__((unused)), char **av, char **ev)
{
	vr v = {NULL, NULL, NULL, 0, 0, 1, 0, NULL};
	char **tok = envi(ev);
	char *path = toke("PATH", tok);
	int interactive;

	interactive = isatty(STDIN_FILENO);
	while ((interactive && write(1, "$ ", 2)) || (!interactive))
	{
		v.p = malloc(_strlen(path) + 1);
		_strcpy(v.p, path);
		v.f = getline(&v.buff, &v.n, stdin);
		if (v.f == -1)
		{
			if (interactive)
				_putchar('\n');
			free(v.buff);
			free(v.p);
			freen(tok);
			free(tok);
			exit(0);
		}
		else if (_strcmp(v.buff, "\n") == 0 || white(v.buff) == 0)
			;
		else if (_strcmp(v.buff, "exit\n") == 0)
		{
			free(v.buff);
			free(v.p);
			freen(tok);
			free(tok);
			if(v.ng == 1)
				exit(0);
			exit(2);
		}
		else
		{
			v.args = split(v.buff);
			v.cmd = getcom(v.args[0], v.p);
			v.status = comexec(v.args, av, ev, v.ng, v.cmd);
			free(v.cmd);
			free(v.args);
		}
		free(v.p);
		v.ng++;
	}
	free(v.buff);
	free(tok);
	freen(v.args);
	free(v.p);
	return (0);
}
