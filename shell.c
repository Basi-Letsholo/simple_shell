#include "main.h"
/**
 * main - entry point for shell
 * @ac: no. of cmd line arguments
 * @av: list of cmd line arguments
 * @env: env variables
 * Return: 0 on success
 */

int main(int ac, char **av, char **env)
{
	unsigned int i, j;
	char *input = NULL, **args, *format = NULL, *cmd_arg;
	int command_count = 0;
	/*extern char **environ;*/
	while (1)
	{
		input = get_input(ac, av);
		args = array(input, " \n");
		command_count++;
		if (strcmp(input, "env") == 0 || strcmp(input, "printenv") == 0)
		{
			for (i = 0; env[i] != NULL; i++)
			{
				for (j = 0; env[i][j] != '\0'; j++)
				{
					_putchar(env[i][j]);
				}
				_putchar('\n');
			}
		}
		if (strcmp(input, " ") == 0 || strcmp(input, "\n") == 0)
			continue;

		cmd_arg = get_cmd(input);
		if (cmd_arg == NULL) 
		{
			format = format_err(av, input, command_count, "not found");
			_print(format);
			continue;
		}
		exec_cmd(args, cmd_arg, av);
		free(cmd_arg);
		free_arr(args);
		free(input);
		free(format);
	}
	return (0);
}
