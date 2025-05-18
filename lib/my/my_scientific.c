/*
** EPITECH PROJECT, 2024
** my_scientific
** File description:
** flag %e/%E pour my_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void exponent(char *result, int exp, int j)
{
    if (exp >= 0) {
        result[j + 1] = '+';
    } else {
        result[j + 1] = '-';
    }
    result[j + 2] = '0' + abs(exp) / 10;
    result[j + 3] = '0' + abs(exp) % 10;
    result[j + 4] = '\0';
}

void digits(char *science, char *result, int *j, int precision)
{
    int p = 0;
    int a;

    if (science[0] == '0') {
        a = 0;
    } else {
        a = 1;
    }
    for (int idx = a; science[idx] != '\0' && p < precision; idx++) {
        if (science[idx] != '.') {
            result[*j] = science[idx];
            (*j)++;
            p++;
        }
    }
}

void scientific_format(char *science, char *result, int precision)
{
    int i = 0;
    int j = 2;
    int exp = -1;

    while (science[i] == '0' || science[i] == '.') {
        i++;
    }
    result[0] = science[i];
    result[1] = '.';
    digits(science, result, &j, precision);
    result[j] = 'e';
    while (science[i] != '.') {
        exp++;
        i++;
    }
    exponent(result, exp, j);
}

void zero_case(int precision, char *result)
{
    result[0] = '0';
    result[1] = '.';
    for (int b = 2; b < precision + 2; b++) {
        result[b] = '0';
    }
    result[precision + 2] = 'e';
    result[precision + 3] = '+';
    result[precision + 4] = '0';
    result[precision + 5] = '0';
    result[precision + 6] = '\0';
}

char *my_scientific(double f, int precision)
{
    char *result = malloc(sizeof(char) * 999);
    char *science;
    int isneg = (f < 0) ? 1 : 0;
    char *negscience = malloc(sizeof(char) * 1000);

    if (isneg == 1) {
        f = -f;
    }
    science = my_putfloat(f, precision);
    if (f == 0.0) {
        zero_case(precision, result);
        return result;
    }
    scientific_format(science, result, precision);
    if (isneg == 1) {
        negscience[0] = '-';
        my_strcpy(negscience + 1, result);
        return negscience;
    }
    return result;
}
