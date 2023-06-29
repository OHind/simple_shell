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
	int n = 0;

	free(line);
	if (command[1])
	{
		n = atoi(command[1]);
		if (n <= -1)
			n = 2;
		free_buffers(command);
		exit(n);
	}
	free(command);
	exit(n);
}
