#ifndef SHELL_H
#define SHELL_H

/* header files to be used in the project */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>



/* prototype to be used in the project */

void prompt(void);
void execmd(char **argv);
int letprint(char *format);
int putchars(char c);
extern char **environ;
void getpath(char *cmd, char path[]);






#endif
