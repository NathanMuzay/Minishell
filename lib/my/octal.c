/*
** EPITECH PROJECT, 2024
** octal
** File description:
** octal
*/
#include "my.h"




long unsigned int my_putnbr_octal(unsigned int n)
{
    unsigned long int octal = 0;
    unsigned long long int i = 1;

    while (n != 0) {
        octal += (n % 8) * i;
        n /= 8;
        i *= 10;
    }
    my_put_unsigned(octal);
    return 0;
}
