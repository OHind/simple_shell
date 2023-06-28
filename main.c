#include "main.h"
/**
 * main - the entry point of the system
 * @argc: The number of arguments
 * @argv: pointer to arguments
 * @env: pointer to envirement variables
 * Return: 0 or 1
 */
int exitcode = 0, errorcount = 0;
int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	size_t nbytes;
	char *input_user = NULL;
	char **c = NULL;
	char **p_ar = NULL;
	char *N = argv[0];
	ssize_t bytes_read = 0;
	int i;
	while (1)
	{
		errorcount++;
		bytes_read = getline(&input_user, &nbytes, stdin);
		if (bytes_read == -1)
		{
			free(input_user);
			exit(exitcode);
		}
		if (check_input_exit(input_user, N) == -1)
		{
			continue;
		}
		if (check_input_blank(input_user) == 1)
		{
			continue;
		}
		if (check_input_env(input_user) == 1)
		{
			print_env(env);
			continue;
		}
		p_ar = path_array(env);
		c = input_parse(input_user, p_ar, N);
		if (c != NULL)
		{
			fork_wait_exec(c, p_ar, env, N, input_user);
			for (i = 0; i < _strlen(*c); i++)
			{
				free(c[i]);
			}
			/*free_array(c);*/
			i = 0;
			for (i = 0; i < _strlen(*p_ar); i++)
			{
				free(p_ar[i]);
			}
			/*free_array(p_ar);*/
		}
	}
	return (0);
}
