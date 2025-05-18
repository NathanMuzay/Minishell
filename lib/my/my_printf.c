/*
** EPITECH PROJECT, 2024
** my_printf
** File description:
** projet printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../include/my.h"

int calcul_precision(const char *format, int *a, int *attributs)
{
    int precision = 6;

    if (format[*a] == '.') {
        attributs[0] = 1;
        (*a)++;
        precision = 0;
        while (format[*a] >= '0' && format[*a] <= '9') {
            precision = precision * 10 + (format[*a] - '0');
            (*a)++;
        }
    }
    return precision;
}

void attribute_selector(const char *format, int *a, int *attributs)
{
    while (format[*a] == '#' || format[*a] == '0'
    || format[*a] == '+' || format[*a] == '-' || format[*a] == ' ') {
        if (format[*a] == '#')
            attributs[1] = 1;
        if (format[*a] == '0'){
            attributs[2] = 1;
        }
        if (format[*a] == '-'){
            attributs[3] = 1;
            attributs[2] = 0;
        }
        if (format[*a] == ' '){
            attributs[4] = 1;
        }
        if (format[*a] == '+'){
            attributs[5] = 1;
            attributs[4] = 0;
        }
        (*a)++;
    }
}

int format_selector(const char *format, int *a, va_list liste, int *count)
{
    int precision = 6;
    int attributs[6] = {0, 0, 0, 0, 0, 0};

    if (format[*a] == '%'){
        (*a)++;
        attribute_selector(format, a, attributs);
        precision = calcul_precision(format, a, attributs);
        *count += flag_selector(format[*a], liste, precision, attributs);
    } else {
        my_putchar(format[*a]);
        (*count)++;
    }
    return *count;
}

int my_printf(const char *restrict format, ...)
{
    int count = 0;
    va_list liste;

    va_start(liste, format);
    if (format == NULL || (format[0] == ' ' && format[1] == '\0')) {
        return -1;
    }
    for (int a = 0; format[a] != '\0'; a++){
        count = format_selector(format, &a, liste, &count);
    }
    va_end(liste);
    return count;
}
