/*
** EPITECH PROJECT, 2024
** my_putfloat
** File description:
** afficher float
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

int neg_float(float *nb, int *entier, float *decimale, int *intdecimale)
{
    *nb = - *nb;
    *entier = (int)*nb;
    *decimale = *nb - *entier;
    *intdecimale = (int)*decimale;
    return 1;
}

void decimal_part(char *nbstr, int *i, float decimale, int precision)
{
    int intdecimale = (int)decimale;

    if (precision > 0){
        nbstr[*i] = '.';
        (*i)++;
    }
    for (int p = 0; p < precision; p++){
        decimale = decimale * 10;
        nbstr[*i] = decimale + '0';
        (*i)++;
        intdecimale = decimale;
        decimale = decimale - intdecimale;
    }
    nbstr[*i] = '\0';
}

char *negafloat(char *nbstr)
{
    char *negfloat = malloc(sizeof(char) * 999);
    int i = 0;
    int j = 0;

    negfloat[j] = '-';
    j++;
    while (nbstr[i] != '\0'){
        negfloat[j] = nbstr[i];
        i++;
        j++;
    }
    negfloat[j] = '\0';
    return negfloat;
}

char *float_to_str(float nb, int precision, char *str, int i)
{
    int entier = (int)nb;
    float decimale = nb - entier;
    int intdecimale = (int)decimale;
    int isneg = 0;
    char *nbstr;

    if (entier == 0){
        str[i] = '0';
        i++;
    } else if (nb < 0)
        isneg = neg_float(&nb, &entier, &decimale, &intdecimale);
    while (entier > 0){
        str[i] = (entier % 10) + '0';
        entier = entier / 10;
        i++;
    }
    nbstr = my_revstr(str);
    decimal_part(nbstr, &i, decimale, precision);
    return (isneg == 1) ? negafloat(nbstr) : nbstr;
}

char *my_putfloat(float nb, int precision)
{
    char *str = malloc(sizeof(char) * 999);
    int i = 0;

    return float_to_str(nb, precision, str, i);
}
