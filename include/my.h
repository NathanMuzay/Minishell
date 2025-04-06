/*
** EPITECH PROJECT, 2024
** B-CPE-101-MAR-1-1-myprintf-nathan.muzay
** File description:
** my
*/

#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include "struct.h"
#include <sys/stat.h>

#ifndef MY_H_
    #define MY_H_
    #define BUFFER_SIZE 1024

char **cpy_env(char **envp);
void handle_pipe_process(var_t *f, int *prev_fd,
    char *cmd, char **env);
int my_cd(char **args, char **env);
void staaatus(pid_t pid, int status, var_t *f);
void child_2(int pipefd[2], char *right_cmd, char **args, char **env);
void child_1(int pipefd[2], char *left_cmd, char **args, char **env);
void handle_redirections(char **args);
void my_env(char **env);
int chevron(char **args, int i);
int param(char **args, int i);
int double_chevron(char **args, int i);
void my_setenv(char **env, var_t *f);
int my_unsetenv(char **env, var_t *f);
void parsing_env(char **env, var_t *f);
int verif_exist(char *name, var_t *f);
char *my_strchr(const char *str, int c);
int strlen_lign(char *buff);
int nb_lign(char *str);
int add(void *data, char **args);
int my_getnbr_n(char *const str, int n);
int my_getnbr(char *const str);
char *nb_to_str(int i);
char *concat_params(int argc, char **argv);
int my_is_prime(int nb);
int my_isalpha(char c);
int len_float(int f);
char *my_strcat(char *dest, const char *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
char *my_strlowcase(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strstr(char *str, char const *to_find);
char **str_to_array(char *buff);
int nb_char(char *str);
int nb_mot(char *str);
char *my_strupcase(char *str);
void my_swap(void *a, void *b);
int my_show_word_array(char *const *tab);
//my_printf
void my_printf(char const *format, ...);
int my_putchar(char);
int my_putstr(char const *);
int my_putnbr(int);
char *my_revstr(char *);
char *my_strcpy(char *, char const *);
int get_precision(const char *str, int *index);
int my_strlen(char const *);
int nb_len(int);
int my_putnbr_hexamaj(unsigned int nb);
int my_putnbr_hexamin(unsigned long int nb);
long unsigned int my_putnbr_octal(unsigned int n);
int my_put_unsigned(unsigned long int nb);
int my_put_float_f(double a, int precision);
//maths
int my_compute_power_it(int nb, int p);

#endif /* !MY_H_ */
