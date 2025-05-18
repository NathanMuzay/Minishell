/*
** EPITECH PROJECT, 2024
** non_signe
** File description:
** flag %u pour my_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int non_signe(va_list liste, int precision, int *attributs)
{
    int count = 0;
    unsigned int n = va_arg(liste, int);
    int pindex = precision - my_numlen(n);
    int p2 = 0;

    if (attributs[0] != 1){
        precision = 0;
        pindex = precision - my_numlen(n);
    }
    if ((attributs[2] == 1 || attributs[0] == 1) && n > 0){
        while (p2 < pindex){
            count += my_putstr("0");
            p2++;
        }
    }
    count += my_put_unsigned(my_decimal(n));
    return count;
}
