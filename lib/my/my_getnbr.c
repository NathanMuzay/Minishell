/*
** EPITECH PROJECT, 2024
** my_radar
** File description:
** radar's window
*/
#include "my.h"

int my_getnbr(char *const str)
{
    int res = 0;
    int i = 0;

    while (str[i] != '\0') {
        res *= 10;
        res += str[i] - 48;
        i += 1;
    }
    return (res);
}

int my_getnbr_n(char *const str, int n)
{
    int res = 0;

    if (n > my_strlen(str))
        return -1;
    while (str[n] != '\n' && str[n] != ' ' && str[n] != '\0') {
        res *= 10;
        res += str[n] - 48;
        n++;
    }
    return (res);
}
