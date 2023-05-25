#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <errno.h>

/* Function Prototypes */
char *get_input(int ac, char **av);
char *get_cmd(char *input);
pid_t exec_cmd(char **args, char *cmd_arg, char **av);
int _putchar(char c);
char *format_err(char **av, char *input, int count, char *err_msg);
int _print(char *input);
char **array(char *input, char *delim);
int token_count(char *input, char *delim);
void free_arr(char **arr);

#endif
