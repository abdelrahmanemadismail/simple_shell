#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>

extern char **environ;

char **tokenize(char *buf);
int exe(char *command[]);
char which(char *token);

#endif
