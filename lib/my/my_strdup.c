/*
** EPITECH PROJECT, 2024
** my_strdup
** File description:
** Day 8, task 1
*/
#include "my.h"

char *my_strdup(char const *src)
{
    char *oe;
    int i = 0;

    while (src[i] != '\0'){
        i++;
    }
    oe = malloc(sizeof(char) * (i + 1));
    i = 0;
    while (src[i] != '\0'){
        oe[i] = src[i];
        i++;
    }
    oe[i] = '\0';
    return oe;
}
