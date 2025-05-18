/*
** EPITECH PROJECT, 2024
** is_float
** File description:
** return 0 si pas un float, 1 si un float
*/

#include "my.h"

int is_float(const char *str)
{
    int i = 0;
    int count = 0;
    int signe = 0;

    if (str[i] == '+' || str[i] == '-'){
        i++;
        signe = 1;
    }
    while (str[i] != '\0'){
        if (isdigit(str[i]) == 0 && str[i] != '.')
            return 0;
        if (str[i] == '.')
            count++;
        i++;
    }
    if ((signe == 1 && i == 1) || count > 1 ||
        (count == 1 && str[i - 1] == '.'))
        return 0;
    return 1;
}
