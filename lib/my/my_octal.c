/*
** EPITECH PROJECT, 2024
** my_octal
** File description:
** pour octal printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int octal_allocation(int nb)
{
    int j = 1;
    int nb2 = nb;
    int reste2 = nb2 % 8;

    while (reste2 != 0){
        reste2 = nb2 % 8;
        nb2 = nb2 / 8;
        j++;
    }
    return j;
}

char octal_selector(int nb)
{
    char *octal = "01234567";

    return octal[nb];
}

char *my_octal(unsigned long int nb)
{
    unsigned long int n = nb;
    int i = 0;
    int alloc = octal_allocation(n);
    int reste = n % 8;
    char *str = malloc(sizeof(char) * alloc + 1);
    char *zerostr = malloc(2);

    if (n == 0){
        zerostr[0] = '0';
        zerostr[1] = '\0';
        return zerostr;
    }
    while (n > 0){
        reste = n % 8;
        str[i] = octal_selector(reste);
        n = n / 8;
        i++;
    }
    str[i] = '\0';
    return my_revstr(str);
}
