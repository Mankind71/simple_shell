#include "main.h"

/**
 * splitStringIntoWords - split string to arr of words
 * @input: str to split
 * @delimiters: separators
 * @wordCount: num of chars in str
 * Return: array of words
 */
char **splitStringIntoWords(const char *input, const char *delimiters,
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

	copy = strdup(input);
	if (copy == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}

	token = strtok(copy, delimiters);

	while (token != NULL && count < wordCount)
	{
		words[count] = strdup(token);
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
 * count_strings - count chars in str
 * @str: str to count
 * Return: num of chars
 */

int count_strings(char *str)
{
	int i = 0, count = 0;

	while (str[i])
	{
		if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
		{
			count++;
		}
		i++;
	}
	return (count);
}
