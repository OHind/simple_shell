#include "main.h"
/**
 * handle_exit_error - print an error message when the user enters an invalid command
 * @N: name of the program
 * @input_user: the commad entered by the user
 * Return: void
 */
void handle_exit_error(char *N, char *input_user)
{
	char *token;

	token = strtok(input_user, "\n ");
	token = strtok(NULL, "\n ");

	write(STDERR_FILENO, N, _strlen(N));
	write(STDERR_FILENO, ": ", 2);
	print_number(errorcount);
	write(STDERR_FILENO, ": exit: Illegal number: ", 24);
	write(STDERR_FILENO, token, _strlen(token));
	write(STDERR_FILENO, "\n", 1);
}


/**
 * handle_command_error - prints error message when command is not found
 * @NAME: name of program
 * @command: command not found
 *
 */

void handle_command_error(char *NAME, char *command)
{
	write(STDERR_FILENO, NAME, _strlen(NAME));
	write(STDERR_FILENO, ": ", 2);
	print_number(errorcount);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 13);

	exitcode = 127;
}

/**
 * handle_exec_error - prints error message when command fails to execute
 * @NAME: name of program
 * @command: name of command
 */

void handle_exec_error(__attribute__((unused))char *NAME, char *command)
{
	perror(command);
	exitcode = 2;
}

/**
 * handle_access_error - prints error message if user does not have execute privileges
 * @NAME: name of program
 * @command: name of command
 */

void handle_access_error(char *NAME, char *command)
{
	write(STDERR_FILENO, NAME, _strlen(NAME));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": Permission denied\n", 20);
}

