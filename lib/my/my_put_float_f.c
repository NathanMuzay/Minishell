/*
** EPITECH PROJECT, 2024
** put_float
** File description:
** put_float
*/



#include "my.h"

static int my_power(int precision)
{
    unsigned long long int i = 1;

    for (precision; precision > 0; precision--) {
        i *= 10;
    }
    return i;
}

static int arrondissement(double a, int precision)
{
    int decimal = (a * my_power(precision));
    double maxime = (a * my_power(precision)) - decimal;

    if (maxime > 0.4) {
        decimal += 1;
    }
    return decimal;
}

int my_put_float_f(double a, int precision)
{
    int temp = a;
    double tmp = a - temp;
    int decimal = 0;

    if (precision == 0)
        precision = 6;
    if (a < 0)
        decimal = arrondissement(- tmp, precision);
    else
        decimal = arrondissement(tmp, precision);
    my_putnbr(temp);
    if (precision != - 1) {
        write(1, ".", 1);
        my_putnbr(decimal);
    }
    return 0;
}
