#include "main.h"

/**
 * splitStringIntoWords - split string to arr of words
 * @input: str to split
 * @delimiters: separators
 * @wordCount: num of chars in str
 * Return: array of words
 */
char **splitStringIntoWords(char *input, const char *delimiters,
							int wordCount)
{
	char **words = (char **)malloc((wordCount + 1) * sizeof(char *));
	char *copy;
	char *token;
	int count = 0;

	if (words == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	copy = _strdup(input);
	if (copy == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(copy, delimiters);

	while (token != NULL && count < wordCount)
	{
		words[count] = _strdup(token);
		if (words[count] == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		count++;
		token = strtok(NULL, delimiters);
	}

	words[count] = NULL;
	free(copy);
	return (words);
}

/**
 * get_environment_variable - gets env var
 *
 * @var_name: name of env var
 * @environ: env var
 * Return: value of env var
 */
char *get_environment_variable(char *var_name, char *environ[])
{
	char **env;

	/* Iterate through the environ array */
	for (env = environ; *env != NULL; env++)
	{
		char *variable = *env;
		/* Check if the variable name matches the one we're looking for */
		if (strncmp(variable, var_name, strlen(var_name)) == 0 &&
			variable[strlen(var_name)] == '=')
		{
			/* Return the value part of the variable */
			return (variable + strlen(var_name) + 1);
		}
	}
	return (NULL);
}

/**
 * add_path - compare 2 strings
 *
 * @str1: string1
 * @str2: string2
 * Return: 0 if equal, 1 otherwise
 */
char *add_path(char *str1, char *str2)
{
	int count, commandCount;
	int i, j;
	char *filepath;

	count = _strlen(str1);
	commandCount = _strlen(str2);
	filepath = malloc(sizeof(char) * (count + commandCount + 2));
	for (i = 0; i < count; i++)
	{
		filepath[i] = str1[i];
	}
	filepath[i] = '/';
	i++;
	for (j = 0; j < commandCount; j++)
	{
		filepath[i + j] = str2[j];
	}
	filepath[i + j] = '\0';
	return (filepath);
}

/**
 * _which - Function to look for files in path
 * @command: arg vector
 * @copy: environ
 * Return: NULL if the variable is not found
 */
char *_which(char *command, char *copy)
{
	char *token;
	char *path;
	char *filepath;

	path = _strdup(copy);

	if (path == NULL)
		return (NULL);

	token = strtok(path, ":");

	while (token != NULL)
	{
		filepath = add_path(token, command);

		if (access(filepath, F_OK) != -1)
		{
			return (token);
		}

		/* Get the next directory in the PATH */
		token = strtok(NULL, ":");
	}

	return (NULL);
}
