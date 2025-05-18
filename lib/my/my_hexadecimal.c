/*
** EPITECH PROJECT, 2024
** my_hexadecimal
** File description:
** pour hexa printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int hexa_allocation(int nb)
{
    int j = 1;
    int nb2 = nb;
    int reste2 = nb2 % 16;

    while (reste2 != 0){
        reste2 = nb2 % 16;
        nb2 = nb2 / 16;
        j++;
    }
    return j;
}

char hexa_selector(int nb, char case_type)
{
    char *hexamaj = "0123456789ABCDEF";
    char *hexamin = "0123456789abcdef";

    if (case_type == 'x'){
        return hexamin[nb];
    }
    return hexamaj[nb];
}

char *my_hexadecimal(unsigned long int nb, char case_type)
{
    unsigned long int n = nb;
    int i = 0;
    int alloc = hexa_allocation(n);
    int reste = n % 16;
    char *str = malloc(sizeof(char) * alloc + 1);
    char *zerostr = malloc(2);

    if (n == 0){
        zerostr[0] = '0';
        zerostr[1] = '\0';
        return zerostr;
    }
    while (n > 0){
        reste = n % 16;
        str[i] = hexa_selector(reste, case_type);
        n = n / 16;
        i++;
    }
    str[i] = '\0';
    return my_revstr(str);
}
