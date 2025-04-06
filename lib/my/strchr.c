/*
** EPITECH PROJECT, 2025
** strchr.
** File description:
** pointer vers premiere occurence
*/
#include "my.h"

char *my_strchr(const char *str, int c)
{
    while (*str) {
        if (*str == (char)c)
            return (char *)str;
        str++;
    }
    return NULL;
}
