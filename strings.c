#include "main.h"

/**
 * trim_str - remove starting space
 *
 * @str: string1
 * Return: trimmed str
 */
char *trim_str(char *str)
{
	char *str1;
	int count = 0, i = 0;

	while (str[count] == ' ')
		count++;
	str1 = malloc(sizeof(char) * (_strlen(str) - count + 1));
	if (str1 == NULL)
	{
		printf("Memory allocation failed.\n");
		exit(1);
	}
	while (str[count])
	{
		str1[i] = str[count];
		count++;
		i++;
	}
	str1[i] = '\0';

	return (str1);
}

/**
 * count_words - count chars in str
 * @str: str to count
 * Return: num of chars
 */
int count_words(char *str)
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

/**
 * _strlen - count chars in str
 * @str: str to count
 * Return: num of chars
 */
int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;

	return (i);
}

/**
 * _strdup - dup 2 strings
 *
 * @str1: string1
 * Return: 0 if equal, 1 otherwise
 */
char *_strdup(char *str1)
{
	char *str;
	int count = _strlen(str1) + 1, i;

	str = malloc(sizeof(char) * count);
	if (str == NULL)
	{
		free(str);
		return (NULL);
	}
	for (i = 0; i < (count - 1); i++)
	{
		str[i] = str1[i];
	}
	str[i] = '\0';
	return (str);
}

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

	if (str1 == NULL || str2 == NULL)
		return (1);

	for (i = 0; i < 4; i++)
	{
		if (str1[i] == '\0' || str2[i] == '\0')
			return (1);
		if (str1[i] != str2[i])
			return (1);
	}

	return (0);
}
