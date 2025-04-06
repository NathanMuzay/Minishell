/*
** EPITECH PROJECT, 2024
** B-CPE-100-MAR-1-1-cpoolday13-nathan.muzay
** File description:
** my_revstr
*/
#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int r = 0;
    char temp;

    while (str[i] != '\0'){
        i++;
    }
    i--;
    while (i > r){
        temp = str[i];
        str[i] = str[r];
        str[r] = temp;
        r++;
        i--;
    }
    return str;
}
