#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

char **splitStringIntoWords(const char *input, const char *delimiters,
int wordCount);
int count_strings(char *str);
void exec(char *prog, char *line);

#endif
