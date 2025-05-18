/*
** EPITECH PROJECT, 2024
** my.h
** File description:
** prototype de mes fonctions
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#include <dirent.h>
#include <sys/stat.h>
#include <sys/sysmacros.h>
#include <fcntl.h>

#include <utmp.h>
#include <sys/wait.h>
#include <signal.h>

#include <errno.h>

#include <glob.h>

#include <termios.h>

#ifndef MY_HEADERS
    #define MY_HEADERS
    #ifndef M_PI
        #define M_PI 3.14159265358979323846
    #endif
int is_digit(const char *str);
int my_getnbr(char *const str);
int my_printf(const char *restrict format, ...);
int flag_selector(const char, va_list, int, int *);
char *my_hexadecimal(unsigned long int, char);
char *my_octal(unsigned long int);
unsigned int my_decimal(int);
unsigned int my_put_unsigned(unsigned int);
char *my_putfloat(float, int);
char *my_scientific(double, int);
int my_numlen(unsigned int);
int my_intnumlen(int);
int non_signe(va_list, int, int *);
int caractere(va_list);
int prcentage(void);
char *concat_params(int, char **);
int my_compute_factorial_it(int);
int my_compute_factorial_rec(int);
int my_compute_power_it(int, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_find_prime_sup(int);
int my_isalpha(char);
int my_isalnum(char);
int my_isneg(int);
int my_is_prime(int);
int my_putchar(char);
int my_put_nbr(int);
int my_putstr(char const *);
char *my_revstr(char *);
int my_show_word_array(char *const *);
char *my_strcat(char *, char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_strdup(char const *);
int my_str_isalpha(char const *);
int my_str_islower(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_isupper(char const *);
int my_strlen(char const *);
char *my_strlowcase(char *);
char *my_strncat(char *, char const *, int);
int my_strncmp(char const *, char const *, int);
char *my_strstr(char *, char const *);
char *my_strupcase(char *);
void my_swap(int *, int *);
char **my_str_to_word_array(char const *);
char **my_str_to_word_array_delim(const char *str, char delim);
int is_integer(const char *);
int is_float(const char *str);
int my_isdigit(const char);
int my_atoi(const char *);
char *int_to_str(int nb);
char **space_to_array(char const *str);
char **strdup_array(char **array, int len_addition, char *ignore);
int count_lines_array(char *const *tab);
char *clean_str(char *str);
char *array_to_str(char **array);
#endif
