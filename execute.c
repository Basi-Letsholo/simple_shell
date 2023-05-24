#include "main.h"
/**
 * exec_cmd - creates child process to execute command
 * @args: command arguments
 * @av: argv
 * Return: pid
 */

pid_t exec_cmd(char **args, char *cmd_arg, char **av)
{
	pid_t pid;
	int cmd;

	pid = fork();

	if (pid == 0)
	{
		cmd = execve(cmd_arg, args, NULL);
		if (cmd == -1)
		{
			perror(av[0]);
			exit(0);
		}
		exit(0);
	}
	else if (pid > 0)
	{
		wait(NULL);
	}
	else
	{
		perror(av[0]);
		exit(0);
	}

	return (pid);
}
