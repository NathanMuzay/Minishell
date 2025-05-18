/*
** EPITECH PROJECT, 2024
** my_compute_factorial_it
** File description:
** day 5, task 2
*/

#include "my.h"

int my_compute_factorial_rec(int nb)
{
    int result;

    if (nb == 0){
        return 1;
    }
    if (nb < 0 || nb > 12){
        return 0;
    }
    result = nb * my_compute_factorial_it(nb - 1);
    return result;
}
