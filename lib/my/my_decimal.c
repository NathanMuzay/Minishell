/*
** EPITECH PROJECT, 2024
** my_decimal
** File description:
** pour %u printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

unsigned int my_decimal(int nb)
{
    unsigned int n = (int)nb;

    if (nb > 0){
        return nb;
    }
    return n;
}
