#include "shell.h"

/*
 * This file contains even more functions needed for the Simple Shell to work
 */

/**
 * _strlen - Function returns the length of *s
 * @str: Pointer Value with string inside
 * Return: count
 */
int _strlen(char *str)
{
	int i;

	i = 0;

	while (str[i] != '\0')
	{
		i++;
	}

	return (i);
}

/**
 * _strcmp - Function compares two strings
 * @s1: Pointer parameter for a string
 * @s2: Pointer parameter for a string
 * Return: result
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;

	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

/**
 * print_prompt - Function prints the symbol indicating the prompt
 */
void print_prompt(void)
{
		write(STDOUT_FILENO, ANSI_COLOR_GREEN "$ " ANSI_COLOR_RESET, 12);
}
