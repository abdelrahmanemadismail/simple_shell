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
char **tokenize(char *buf, char *del);
int exe(char *command[], char *filename, int c);
char *which(char *token);
int print_env(char *command[]);
int exit_shell(char *command[], char *filename, int c, int s);
#endif
