#include "main.h"

/**
 * _fork - create fork process
 *
 * @cmd: command
 * @line: line
 */
void _fork(char *cmd, char *line)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		exec(cmd, line);
	}
	else
	{
		wait(&status);
	}
}

/**
 * get_first_word - get the first word from cmd line
 *
 * @str: str to extract word
 * @token: return cmd
 * Return: the first word
 */
char *get_first_word(char *str, char *token)
{
	int i = 0, count = 0;

	count = _strlen(str);

	count = 0;

	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			continue;
		}
		if (str[i] != ' ')
		{
			token[count] = str[i];
			count++;
			if (str[i + 1] == ' ' || str[i + 1] == '\0')
			{
				break;
			}
			i++;
		}
	}

	token[count] = '\0';
	return (token);
}

/**
 * main - super simple shell
 *
 * @argc: arg count
 * @argv: arg vector
 * @envp: env var
 * Return: Always 0.
 */
int main(__attribute__((unused)) int argc, char **argv, char *envp[])
{
	char *line = NULL, *cmd = argv[0], *path, *filepath;
	char **env_var = envp;
	size_t len = 0, i;
	ssize_t nread = 0;
	int num_of_words;
	bool interactive = isatty(STDIN_FILENO); /* Check if input is interactive */
	struct stat st;

	path = get_environment_variable("PATH", env_var);
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

			num_of_words = count_words(line);
			if (num_of_words == 0)
				continue;

			line = trim_str(line);
			if (_strcmp(line, "exit", 4) == 0)
			{
				break;
			}

			if (_strcmp(line, "env", 3) == 0)
			{
				i = 0;
				while (envp[i] != NULL)
				{
					printf("%s\n", envp[i]);
					i++;
				}
				continue;
			}


			if (stat(line, &st) == 0)
			{
				_fork(cmd, line);
			}
			else
			{
				filepath = _which(line, path);
				if (filepath)
				{
					_fork(cmd, add_path(filepath, line));
				}
				else
				{
					printf("%s: Command not found\n", line);
				}
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
