/*
** EPITECH PROJECT, 2024
** B-CPE-100-MAR-1-1-cpoolday13-nathan.muzay
** File description:
** hexa
*/
#include "my.h"

int len_float(int f)
{
    int r = 0;

    if (f < 0)
        f = -f;
    r += nb_len((int)f);
    return r;
}

int nb_len(int nb)
{
    int temp = 0;

    while (nb >= 10){
        nb = nb / 10;
        temp++;
    }
    temp++;
    return temp;
}
