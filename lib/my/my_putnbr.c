/*
** EPITECH PROJECT, 2024
** my_isneg
** File description:
** my_isneg.c
*/
#include "my.h"




int my_putnbr(int n)
{
    if (n < 0){
        n = - n;
        my_putchar('-');
    }
    if (n < 10){
        my_putchar(n + 48);
    } else {
        my_putnbr(n / 10);
        my_putchar((n % 10) + 48);
    }
    return 0;
}
