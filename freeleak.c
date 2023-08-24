#include "shell.h"
/**
 * freen - check the code
 * @args: args
*/
void freen(char **args)
{
	int i = 0;

	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
}
/**
 * allfree - hh
 * @buf: buf
 * @p: p
 * @t: t
*/
void allfree(char *buf, char *p, char **t)
{
free(buf);
free(p);
freen(t);
free(t);
}
/**
 * allfree2 - kh
 * @buf: buf
 * @p: p
 * @ar: ar
 * @t: t
*/
void allfree2(char *buf, char *p, char **ar, char **t)
{
free(buf);
free(t);
freen(ar);
free(p);
}
