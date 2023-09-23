#include "main.h"

/**
 * exec - super simple shell
 * @prog: name of exec file
 * @line: command
 */

void exec(char *prog, char *line)
{
	int i = 0;
	const char delimiters[] = " ";
	int wordCount;
	char **argv;

	wordCount = count_words(line);
	argv = splitStringIntoWords(line, delimiters, wordCount);

	if (execve(argv[0], argv, NULL) == -1)
	{
		perror(prog);
		for (i = 0; i < wordCount; i++)
			free(argv[i]);

		free(argv);
		exit(EXIT_FAILURE);
	}
}
