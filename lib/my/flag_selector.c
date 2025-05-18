/*
** EPITECH PROJECT, 2024
** flag_selector
** File description:
** flag selecotr pour my_printf
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

static int entier(va_list liste, int precision, int *attributs)
{
    int count = 0;
    int nb = va_arg(liste, int);
    int pindex = precision - my_intnumlen(nb);
    int p2 = 0;

    if (attributs[4] == 1 && nb >= 0)
        count += my_putstr(" ");
    if (attributs[5] == 1){
        if (nb >= 0){
            count += my_putstr("+");
        }
    }
    if (attributs[2] == 1 || (attributs[1] == 1 && attributs[0] == 1)){
        while (p2 < pindex){
            count += my_putstr("0");
            p2++;
        }
    }
    count += my_put_nbr(nb);
    return count;
}

static int flottant(va_list liste, int precision, int *attributs)
{
    int count = 0;
    float nbf = va_arg(liste, double);
    int pindex = precision - my_strlen(my_putfloat(nbf, precision));
    int p2 = 0;

    if (attributs[4] == 1 && nbf >= 0)
        count += my_putstr(" ");
    if (attributs[5] == 1)
        if (nbf >= 0)
            count += my_putstr("+");
    if (attributs[1] == 1 && precision == 0)
        count += my_putstr("0.");
    if (attributs[2] == 2){
        while (p2 < pindex){
            count += my_putstr("0");
            p2++;
        }
    }
    count += my_putstr(my_putfloat(nbf, precision));
    return count;
}

static int hexa(char format, va_list liste, int precision, int *attributs)
{
    int count = 0;
    unsigned int nb = va_arg(liste, int);
    char *hexadeci = my_hexadecimal(nb, format);
    int pindex = precision - my_strlen(hexadeci);
    int p2 = 0;

    if (attributs[1] == 1 && format == 'x'){
        count += my_putstr("0x");
    } else if (attributs[1] == 1 && format == 'X'){
        count += my_putstr("0X");
    }
    if (attributs[0] == 1){
        while (p2 < pindex){
            count += my_putstr("0");
            p2++;
        }
    }
    count += my_putstr(my_hexadecimal(nb, format));
    return count;
}

static int octal(va_list liste, int precision, int *attributs)
{
    int count = 0;
    unsigned int nb = va_arg(liste, int);
    char *octalised = my_octal(nb);
    int pindex = precision - my_strlen(octalised);
    int p2 = 0;

    if (attributs[1] == 1 && (attributs[2] != 1 || attributs[0] != 1)){
        count += my_putstr("0");
    }
    if (attributs[0] == 1){
        while (p2 < pindex){
            count += my_putstr("0");
            p2++;
        }
    }
    count += my_putstr(my_octal(nb));
    return count;
}

static int scientifique(va_list liste, int precision,
    int *attributs)
{
    int count = 0;
    float nbf = va_arg(liste, double);
    int pindex = precision - my_strlen(my_putfloat(nbf, precision));
    int p2 = 0;

    if (attributs[1] == 1 && precision == 0){
        count += my_putstr("0.");
    }
    if (attributs[2] == 2){
        while (p2 < pindex){
            count += my_putstr("0");
            p2++;
        }
    }
    count += my_putstr(my_scientific(nbf, precision));
    return count;
}

static int adr_pointeur(va_list liste)
{
    int count = 0;
    unsigned long int adr = 0;

    adr = va_arg(liste, unsigned long int);
    count += my_putstr("0x");
    count += my_putstr(my_hexadecimal(adr, 'x'));
    return count;
}

static int string(va_list liste)
{
    int count = 0;

    count += my_putstr(va_arg(liste, char *));
    return count;
}

int flag_num(const char format, va_list liste, int precision, int *attributs)
{
    switch (format) {
        case 'd':
        case 'i':
            return entier(liste, precision, attributs);
        case 'f':
        case 'F':
            return flottant(liste, precision, attributs);
        case 'x':
        case 'X':
            return hexa(format, liste, precision, attributs);
        case 'o':
            return octal(liste, precision, attributs);
        case 'e':
        case 'E':
            return scientifique(liste, precision, attributs);
        default:
            return 0;
    }
}

int flag_alpha(const char format, va_list liste, int precision, int *attributs)
{
    switch (format) {
        case 's':
            return string(liste);
        case 'c':
            return caractere(liste);
        case '%':
            return prcentage();
        case 'p':
            return adr_pointeur(liste);
        case 'u':
            return non_signe(liste, precision, attributs);
        default:
            return 0;
    }
}

int flag_selector(const char format, va_list liste, int precision,
    int *attributs)
{
    if (format == 'd' || format == 'i' || format == 'x'
        || format == 'X' || format == 'o'
        || format == 'f' || format == 'F' || format == 'e'
        || format == 'E') {
        return flag_num(format, liste, precision, attributs);
    } else if (format == 's' || format == 'c' || format == '%'
        || format == 'p' || format == 'u') {
        return flag_alpha(format, liste, precision, attributs);
    }
    return 0;
}
