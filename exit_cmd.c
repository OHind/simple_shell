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
	int n;
	n = _atoi(command[1]);
	if (n <= -1)
		n = 2;
	else
		n = 0;

	free(line);
	free_buffers(command);
	exit(n);
}
