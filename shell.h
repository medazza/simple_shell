#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdbool.h>
#include <ctype.h>

extern char **environ;

#define READ_SIZE 1024
#define BUFSIZE 1024


void free_array(char **array);
int check_cmd(char *cmnd);
char *get_path(char *cmd);
char **tokenize(char *buf);
char *_getenv(const char *key);
int run_cmd(char **args, char **env, char **argv);
void execute(char *cmnd, char **env, char **argv);

/* path_handle.c */
char *make_path(char *path, char *cmnd);
char *get_path(char *cmnd);

/* my_cd.c */
void my_cd(char **args);
void change_directory(char **dirs, char *cmnd_name);

/* input_handle.c */
char **tokenizez(char *str_input, char *del);
int handle_input(char *buffer, char **env, char **argv);
void sigint_handler(int signal);

/* echo_handle.c */
void handle_echo_args(char *args, int *status);
int handle_echo(char **args, int *status)
;

/* builtin_handle.c */
void print_env(char **env);
int builtins(char **args, char **env);
int handle_builtins1(char **args, char **env);
int handle_builtins2(char **args);
int handle_builtins3(char **args);

/* funcs1.c */
size_t _strlen(const char *s);
char *_strcpy(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strcat(char *dest, const char *src);
int _strncmp(const char *str1, const char *str2, int n);

/* funcs2.c */
char *_strdup(const char *str);
char *_strchr(const char *s, char c);
char *_strcatpath(const char *dest, const char *src);
int _atoi(const char *s);
void print_err(const char *av, int count, const char *cmnd, const char *msg);

/* funcs3.c */
char *_strtok(char *str, const char *delim);
char *_itoa(int num);
size_t _constcharlen(const char *str);
void *_realloc(void *ptr, size_t old_size, size_t new_size);
int _putchar(char c);

/* funcs4.c */
char *_strncat(char *dest, const char *src, int n);
char *_strncpy(char *dest, const char *src, int n);
void _puts(char *str);
ssize_t _getline(char **buffer, size_t *bufsize, int fd);
int empty_line(const char *l);

#endif
