#include "main.h"

/**
 * _strcmp - compare 2 strings
 *
 * @str1: string1
 * @str2: string2
 * Return: 0 if equal, 1 otherwise
 */

int _strcmp(char *str1, char *str2)
{
	size_t i;

	for (i = 0; i < 4; i++)
	{
		if (str1[i] != str2[i])
			return (1);
	}

	return (0);
}

/**
 * main - super simple shell
 *
 * @argc: arg count
 * @argv: arg vector
 * Return: Always 0.
 */
int main(__attribute__((unused)) int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	pid_t child_pid;
	int status;
	bool interactive = isatty(STDIN_FILENO); /* Check if input is interactive */
	char *cmd = argv[0];
	struct stat st;

	while (1)
	{
		if (interactive)
		{
			printf("$ ");
			fflush(stdout);
		}

		nread = getline(&line, &len, stdin);
		if (nread != -1)
		{
			if (line[nread - 1] == '\n')
				line[nread - 1] = '\0';

			if (_strcmp(line, "exit") == 0)
				break;

			if (stat(cmd, &st) == 0)
			{
				child_pid = fork();
				if (child_pid == 0)
					exec(cmd, line);
				else
					wait(&status);
			}
			else
			{
				printf("%s: Command not found\n", line);
			}
		}
		else
		{
			if (interactive)
				printf("\n");
			break;
		}
	}

	free(line);
	return (0);
}
