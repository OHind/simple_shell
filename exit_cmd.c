#include "shell.h"

/**
* exit_cmd - handles the exit command
* @command: tokenized command
* @line: input read from stdin
*
* Return: no return
*/
void exit_cmd(char **command, char *line)
{

	int i, n = 0;

	if (command[1])
	{
		n = _atoi(command[1]);
		if (n <= -1)
			n = 2;
		free_buffers(command);
		printf("HInd %d", n);
		exit(n);
	}
	for (i = 0;command[i]; i++)
		free(command[i]);
	free(command);
	free(line);
	exit(n);
}
