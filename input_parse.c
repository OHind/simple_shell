#include "main.h"
/**
 * count_arg - count the number of arguments
 * @input_user: input of the user
 * Return: retunrs the number of arguments
 */
int count_arg(char *input_user)
{
	int i = 0, arg = 1, s = 0;

	while (*(input_user + i) != '\0' && *(input_user + i) != '\n')
	{
		if (*(input_user + i) != ' ')
			s = 1;
		if (*(input_user + i) == ' ' &&  *(input_user + i + 1) != ' ' && *(input_user + i + 1) != '\n' && s == 1)
		      arg++;
		i++;
	}
	return (arg);
}
/**
 * input_parse - parse input
 * @input_user: user input
 * @array: Directories of path
 * @N: name of the program
 * Return: Array of arguments
 */
char **input_parse(char *input_user, char **array, char *N)
{
	char **c, *token, *path_dir = NULL;
	int arg = 1, i = 0, k = 0;

	arg = count_arg(input_user);
	c = malloc(sizeof(char *) * (arg + 1));
	if (c == NULL)
	{
		free_array(array);
		return (NULL);
	}
	token = strtok(input_user, "\n ");
	if (check_input_path(token) == -1)
	{
		path_dir = find_path(array, token);
		if (path_dir == NULL)
		{
			free(c);
			for (k = 0; k < _strlen(*array); k++)
			{
				free(array[k]);
			}
			/*free_array(array);*/
			handle_command_error(N, token);
			exitcode = 127;
			return (NULL);
		}
		else if (_strcmp("no_access", path_dir) == 0)
		{
			free(c);
			for (k = 0; k < _strlen(*array); k++)
			{
				free(array[k]);
			}
			/*free_array(array);*/
			handle_access_error(N, token);
			exitcode = 126;
			return (NULL);
		}
		*(c) = _strdup(path_dir);
		free (path_dir);
	}
	else
	{
		*(c) = _strdup(token);
	}
	for (i = 1; i < arg; i++)
	{
		token = strtok(0, "\n ");
		*(c + i) = _strdup(token);
	}
	*(c + i) = NULL;
	return (c);
}
