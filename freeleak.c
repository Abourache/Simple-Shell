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
