#include "main.h"
/**
 * check_input_path - verify if the user input starts with a slash
 * @input_user: The user input
 * Return: 0 if a path detected, -1 otherwise
 */
int check_input_path(char *input_user)
{
	if (input_user[0] == '/')
		return (0);
	return (-1);
}
/**
 * check_input_blank - check if the user input starts with a null caracter
 * @input_user: the user input
 * Return: 0 if a null caracter detected, -1 otherwise
 */
int check_input_blank(char *input_user)
{
	if (input_user[0] == '\0')
		return (1);
	return (0);
}
/**
 * check_input_exit - check if the user input contains exit
 * @input_user: the user input
 * @N: Name to display
 * Return: 0 if not exit
 */
int check_input_exit(char *input_user, char *N)
{
	int i = 0, j = 0, length, stat = 0, length2;
	char *e = "exit";
	char *n;

	length = _strlen(input_user);
	length2 = length - 5;
	for (i = 0; i < 4; i++)
	{
		if (*(e + i) != *(input_user + i))
			return (0);
	}
	if (*(input_user + 4) != '\n' && *(input_user + 4) != ' ')
		return (0);
	if (length > 5)
	{
		n = malloc(sizeof(char) * length2);
		for (i = 5; i < length - 1; i++)
		{
			if (*(input_user + i) >= '0' && *(input_user + i) >= '9')
			{
				*(n + j) = *(input_user + i);
				j++;
			}
			else
			{
				handle_exit_error(N, input_user);
				free(n);
				exitcode = 2;
				return (-1);
			}
		}
		*(n + j) = '\0';
		stat = _atoi(n);
		free(n);
	}
	free(input_user);
	exit(stat);
}

/**
 * check_input_env - check if the user input is env
 * @input_user: the input of the user
 * Return: 1 if the input equals env, 0 otherwise
 */
int check_input_env(char *input_user)
{
	int i = 0;
	char *e = "env";

	if (_strlen(input_user) != 4)
		return (0);
	while (*(e + i) != '\0')
	{
		if (*(e + i) != *(input_user + i))
			return (0);
		i++;
	}
	return (1);
}
