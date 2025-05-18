/*
** EPITECH PROJECT, 2024
** my_compute_factorial_it
** File description:
** day 5, task 1
*/

#include "my.h"

int my_compute_factorial_it(int nb)
{
    int result = 1;

    if (nb == 0 || nb == 1){
        result = 1;
        return result;
    }
    if (nb < 0 || nb > 12){
        result = 0;
        return result;
    }
    while (nb >= 1){
        result = nb * result;
        nb = nb - 1;
    }
    return result;
}
