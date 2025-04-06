/*
** EPITECH PROJECT, 2024
** my_strncat
** File description:
** Day 7, task 3
*/
#include "my.h"


char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;

    if (!dest || !src)
        return NULL;
    while (dest[i] != '\0')
        i++;
    while (src[j] != '\0') {
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
