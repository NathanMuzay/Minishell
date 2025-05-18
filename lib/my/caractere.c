/*
** EPITECH PROJECT, 2024
** caractere
** File description:
** flag %c pour my_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int caractere(va_list liste)
{
    int count = 0;
    int character = va_arg(liste, int);

    count += write(1, &character, 1);
    return count;
}
