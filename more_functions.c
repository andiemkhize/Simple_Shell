#include "shell.h"

/*
 * This file contains more functions needed for the Simple Shell to work
 */

/**
 * print_env - Function prints out each environment variable
 * @env: Environment
 */
void printenv_builtin(char **env)
{
	size_t len;
	ssize_t char_written;

	if (env == NULL)
	{
		perror("$ Invalid environment");
		exit(EXIT_FAILURE);
	}

	printf("%s\n", *env);

	while (*env != NULL)
	{
		len = _strlen(*env);
		char_written = write(STDOUT_FILENO, *env, len);
		write(STDOUT_FILENO, "\n", 1);

		if (char_written == -1)
		{
			perror("$ Env write error");
			exit(EXIT_FAILURE);
		}
		env++;
	}
}

/**
 * _strncmp - Function compares two strings
 * @s1: Pointer parameter for a string
 * @s2: Pointer parameter for a string
 * @n: Number of character/bytes to be read/compared
 *
 * Return: Difference of bytes/chars
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i, j;

	i = 0;
	j = 0;

	while (i < n)
	{
		if (s1[j] && s1[j] == s2[j])
		{
			j++;
		}
		i++;
	}

	return (i - j);
}

/**
 * getpath - Function returns the PATH variable
 * @env: Environment
 *
 * Return: env
 */
char *getpath(char **env)
{
	while (*env != NULL)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			return (*env + 5);
		}
		env++;
	}

	return (NULL);
}

/**
 * _strcat - Function concatenates two strings
 * @dest: Pointer parameter for string
 * @src: Pointer parameter for string
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int len1, len2;

	len1 = 0;
	len2 = 0;

	while (dest[len1] != '\0')
	{
		len1++;
	}

	while (src[len2] != '\0')
	{
		dest[len1] = src[len2];
		len1++;
		len2++;
	}

	dest[len1] = '\0';

	return (dest);
}

/**
 * _strcpy - Function copies a string
 * @dest: Pointer parameter for a string
 * @src: Pointer parameter for a string
 * Return: dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);
}
