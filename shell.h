#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
typedef struct vr
{
	char **args;
	char *buff;
	char *cmd;
	int status;
	size_t n;
	int ng;
	int f;
	char *p;
} vr;

int checkcom(char *com);
char *toke(char *str, char **envcop);
char **envi(char **evi);
char *getcom(char *com, char *path);
char **split(char *buff);
int comexec(char **args, char **avi, char **evi, int ng, char *cmd);
void freen(char **args);
int _putchar(char c);
void _puts(char *str);
void notfound(char *str, int ng, char *arg);
char* _strdup(const char* str);
char *_strcpy(char *d, char *s);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);
char *_strcat(char *ptr, char *str);
#endif
