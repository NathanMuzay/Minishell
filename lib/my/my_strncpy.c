/*
** EPITECH PROJECT, 2024
** my_strncpy
** File description:
** Day 6, task 2
*/
#include "my.h"




char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (n > i){
        dest[i] = src[i];
        i++;
    }
    if (n > i){
        dest[i] = '\0';
    } else if (n < i){
        return dest;
    }
    return dest;
}
