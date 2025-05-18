/*
** EPITECH PROJECT, 2024
** my_numlen
** File description:
** compteur de nombres NORMAUX
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int my_intnumlen(int nb)
{
    int i = 0;

    if (nb < 0) {
        nb = -nb;
        i++;
    }
    if (nb == 0){
        return 1;
    }
    while (nb > 0){
        nb = nb / 10;
        i++;
    }
    return i;
}
