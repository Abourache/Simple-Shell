#include "shell.h"
/**
 * _strlen - strlen
 * @str: str
 * Return: int
*/
int _strlen(char *str)
{
	int i = 0;

	if (str == NULL)
	{
		return (0);
	}
	while (*str++)
	{
		i++;
	}
	return (i);
}
/**
 * _strcpy - strcpy
 * @d: d
 * @s: s
 * Return: char
*/
char *_strcpy(char *d, char *s)
{
	int j = 0;

	if (d == s || s == 0)
	{
		return (d);
	}
	while (s[j])
	{
		d[j] = s[j];
		j++;
	}
	d[j] = '\0';
	return (d);
}
/**
 * _strdup - strdup
 * @str: str
 * Return: pointer to char
*/
char *_strdup(const char *str)
{
	int i = 0;
	char *dup;

	if (str == NULL)
		return (NULL);
	while (*str++)
	{
		i++;
	}
	dup = malloc(sizeof(char) * (i + 1));
	if (dup == NULL)
	{
		return (NULL);
	}
	while (i >= 0)
	{
		dup[i] = *--str;
		i--;
	}
	return (dup);
}
