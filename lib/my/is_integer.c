/*
** EPITECH PROJECT, 2024
** is_integer
** File description:
** return 1 si entier
*/

#include "my.h"

int is_integer(const char *str)
{
    int i = 0;
    int signe = 0;

    if (str[i] == '+' || str[i] == '-'){
        i++;
        signe = 1;
    }
    while (str[i] != '\0'){
        if (my_isdigit(str[i]) == 0){
            return 0;
        }
        i++;
    }
    if (signe == 1 && i == 1){
        return 0;
    }
    return 1;
}
