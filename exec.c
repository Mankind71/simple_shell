#include "main.h"

/**
 * exec - super simple shell
 * @prog: name of exec file
 * @line: command
 */

void exec(char *prog, char *line)
{
	int i = 0;
	char *const custom_envp[] = {"MY_VAR=Hello", "ANOTHER_VAR=World", NULL};
	const char delimiters[] = " ";
	int wordCount;
	char **argv;

	wordCount = count_strings(line);
	argv = splitStringIntoWords(line, delimiters, wordCount);

	if (execve(argv[0], argv, custom_envp) == -1)
	{
		perror(prog);
		for (i = 0; i < wordCount; i++)
			free(argv[i]);

		free(argv);
		exit(EXIT_FAILURE);
	}
}
