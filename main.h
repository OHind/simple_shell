#ifndef _MAIN_H_
#define _MAIN_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
extern int exitcode;
extern int errorcount;
int _strlen(char *c);
int _atoi(char *c);
int check_input_path(char *input_user);
int check_input_blank(char *input_user);
int check_input_exit(char *input_user, char *N);
int check_input_env(char *input_user);
void handle_exit_error(char *N, char *input_user);
int _putchar(char c);
char *_strdup(char *s);
int _strcmp(char *s1, char *s2);
int path_count(char *path);
char **path_array(char **env);
char *find_path(char **path_array, char *command);
void print_env(char **env);
void handle_command_error(char *NAME, char *command);
void handle_exec_error(__attribute__((unused))char *NAME, char *command);
void handle_access_error(char *NAME, char *command);
void fork_wait_exec(char **commands, char **path_array, char **env,
                    char *NAME, char *user_input);
int count_arg(char *input_user);
char **input_parse(char *input_user, char **array, char *N);
void print_number(int n);
void free_array(char **array);
#endif
