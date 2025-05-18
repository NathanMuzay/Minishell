/*
** EPITECH PROJECT, 2024
** my_put_nbr
** File description:
** day 3, task 7
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int count = 0;

    if (nb == - 2147483648){
        count += my_putchar('-');
        count += my_putchar('2');
        count += my_put_nbr(147483648);
    }
    if (nb < 0){
        count += my_putchar('-');
        nb = -nb;
    }
    if (nb >= 0 && nb <= 9){
        count += my_putchar(nb + 48);
    } else {
        count += my_put_nbr(nb / 10);
        count += my_putchar((nb % 10) + '0');
    }
    return count;
}
