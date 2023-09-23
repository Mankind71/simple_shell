#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdbool.h>

char **splitStringIntoWords(char *input,
const char *delimiters, int wordCount);
int count_words(char *str);
char *get_first_word(char *str, char *token);
void exec(char *prog, char *line);
char *get_environment_variable(char *var_name,
char *environ[]);
char *add_path(char *str1, char *str2);
char *_which(char *command, char *path);
int _strcmp(char *str1, char *str2, size_t count);
char *_strdup(char *str1);
int _strlen(char *str);
char *trim_str(char *str1);

#endif
