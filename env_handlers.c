#include "main.h"

/**
 * path_count - counts number of directories in PATH
 * @path: PATH string
 * Return: number of directories
 */

int path_count(char *path)
{
	int i, n;

	i = 0;
	n = 0;
	while (path[i] != '\0')
	{
		if (path[i] == '=' || path[i] == ':')
			n++;
		i++;
	}

	return (n);
}

/**
 * path_array - creates an array of PATH directories
 * @env: user environment
 * Return: array of strings
 */

char **path_array(char **env)
{
	unsigned int i;
	int path_number;
	int compare = 0, j;
	char *token, *token2, *mypath;
	char **path_array;

	i = 0;
	j = 0;
	while (env[i] != NULL)
	{
		compare = _strcmp(env[i], "PATH");
		if (compare == 0)
		{
			mypath = _strdup(env[i]);
			path_number = path_count(mypath);
			token = strtok(mypath, "=");
			token = strtok(NULL, "=");
			path_array = malloc(sizeof(char *) * (path_number + 1));
			if (path_array == NULL)
				return (NULL);
			if (token[0] == ':')
			{
				path_array[j] = _strdup("./");
				j++;
				token2 = strtok(token, ":");
				token2 = strtok(NULL, ":");
			}
			else
				token2 = strtok(token, ":");
			while (j < path_number)
			{
				path_array[j] = _strdup(token2);
				j++;
				token2 = strtok(NULL, ":");
			}
		}
		i++;
	}
	path_array[path_number] = NULL;
	free(mypath);
	return (path_array);
}

/**
 * find_path - find the PATH of a command
 * @path_array: array of directories in PATH
 * @command: command to find path for
 *
 * Return: path of command, NULL if it fails
 */

char *find_path(char **path_array, char *command)
{
	int i, j, ok_f = 0, ok_x = 0, dir_len, k = 0, com_len, total_len;
	char *path;

	for (i = 0; path_array[i] != NULL; i++)
	{
		dir_len = _strlen(path_array[i]);
		com_len = _strlen(command);
		total_len = dir_len + com_len;
		path = malloc(sizeof(char) * (total_len + 2));
		if (path == NULL)
		{
			for (k = 0; k < _strlen(*path_array); k++)
			{
				free(path_array[k]);
			}
			/*free_array(path_array);*/
			return (NULL);
		}
		j = 0;
		while (j < dir_len)
		{
			path[j] = path_array[i][j];
			j++;
		}
		path[j] = '/';
		j = 0;
		while (j < com_len)
		{
			path[dir_len + j + 1] = command[j];
			j++;
		}
		path[total_len + 1] = '\0';
		ok_f = access(path, F_OK);
		ok_x = access(path, X_OK);
		if (ok_f == 0)
		{
			if (ok_x == 0)
				return (path);
			free(path);
			return ("no_access");
		}
		free(path);
	}
	return (NULL);
}

/**
 * print_env - print environment variables
 * @env: array of environment variables
 */

void print_env(char **env)
{
	int i;

	i = 0;
	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], _strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
