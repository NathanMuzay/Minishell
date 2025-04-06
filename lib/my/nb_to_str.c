/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** Day 6, task 6
*/
#include "my.h"

char *nb_to_str(int i)
{
    char *str = malloc(sizeof(char) * nb_len(i));
    int a = 0;

    if (i == 0){
        str[a] = '0';
        a++;
    }
    while (i > 0){
        str[a] = i % 10 + '0';
        i = i / 10;
        a++;
    }
    str[a] = '\0';
    return my_revstr(str);
}
