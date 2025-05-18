/*
** EPITECH PROJECT, 2024
** prcentage
** File description:
** flag %% pour my_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int prcentage(void)
{
    int count = 0;
    int character = '%';

    count += write(1, &character, 1);
    return count;
}
