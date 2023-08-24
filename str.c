#include "shell.h"
/**
 * _putchar - similar to putchar
 * @c: c
 * Return: int
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - puts
 * @str: str
 * Return: nothing
*/
void _puts(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}
/**
 * notfound - print not found message
 * @str: str
 * @ng: ng
 * @arg: arg
*/
void notfound(char *str, int ng, char *arg)
{
	_puts(str);
	_putchar(':');
	_putchar(' ');
	_putchar(ng + '0');
	_putchar(':');
	_putchar(' ');
	_puts(arg);
	_putchar(':');
	_putchar(' ');
	_puts("not found");
	_putchar('\n');
}
/**
 * _strcat - similar to strcat
 * @ptr: ptr
 * @str: str
 * Return: char
*/
char *_strcat(char *ptr, char *str)
{
	char *dup;

	dup = ptr;
	while (*ptr != '\0')
	{
		ptr++;
	}
	while (*str != '\0')
	{
		*ptr = *str;
		ptr++;
		str++;
	}
	*ptr = *str;
	return (dup);
}
/**
 * _strcmp - similar to strcmp
 * @str1: str1
 * @str2: str2
 * Return: int
*/
int _strcmp(char *str1, char *str2)
{
	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 != *str2)
		{
			return (*str1 - *str2);
		}
		str1++;
		str2++;
	}
	if (*str1 == *str2)
	{
		return (0);
	}
	else
	{
		return (*str2 < *str1 ? 1 : -1);
	}
}
