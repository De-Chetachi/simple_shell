#ifndef MY_SHELL_H
#define MY_SHELL_H

#define BUFF_SIZE 1024

#include "sh_utils.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

extern char **environ;
extern char *cmd_str;
extern char **cmds;
extern char **envi;
extern int path_len;
extern char *path;
extern char **path_arr;
extern int exit_status;
extern char **av;
extern int determinant;

/*main*/
void sh_interactive(void);
void sh_uninteractive(void);
void c_handler(int signal);
void z_handler(int signal);


/*sh_interactive*/
char *read_line(void);
char **tok_str(char *str, char *delim, int *tok_size);
int exe_cute(char **argv);
void signal_free(void);

/*sh_uninteractive*/

/*exe_cute*/
int handle_bt_ins(char **argv);
int handle_executable(char **argv);

/*handle_executable*/
char *handle_path(char *cmd);
char **path_append(char *cmd);
char *cmd_status(char **cmd_arr);
pid_t fork_exec(char **argv);


/*builtin functions*/
void my_exit(char **argv);
void my_env(char **argv);
void my_cd(char **argv);
void my_setenv(char **argv);
void my_unsetenv(char **argv);

/*util functions*/
void free_double(char **vector);
int arr_len(char **vector);
char *strchr_str(char *fruit, char *seeds);
char *_getenv(char *env_name, char **ev);
char *tok_once(char *str, char *delim);
char **env_var();
void error_stat(int stream, char *program, char *cmd);
void error_exit(int stream, char *program, char **cmd);
void error_cd(int stream, char *program, char **cmd);

/*setenv and unsetenv*/
int _unsetenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
void _puts(char *str);
int _putchar(char c);
#endif
