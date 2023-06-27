#include "main.h"
/**
 * main - the entry point of the system
 * @argc: The number of arguments
 * @argv: pointer to arguments
 * @env: pointer to envirement variables
 * Return: 0 or 1
 */
int exitcode, errorcode;
int main(__attribute__((unused)) int argc, char **argv, char **env)
{
	size_t nbytes;
	char *input_user = NULL;
	char **c = NULL;
	char **p_ar = NULL;
	char *N = argv[0];
	ssize_t bytes_read = 0;
	while (1)
	{
		bytes_read = getline(&input_user, &nbytes, stdin);
		if (bytes_read == -1)
		{
			free(input_user);
			exit(0);
		}
		if (check_input_exit(input_user, N) == -1)
			continue;
		if (check_input_blank(input_user) == 1)
			continue;
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
			free_array(c);
			free_array(p_ar);
		}
	}
	return (0);
}
