/*
** EPITECH PROJECT, 2024
** my_find_prime_sup
** File description:
** Day 5, task 7
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    while (my_is_prime(nb) != 1){
        nb++;
    }
    return nb;
}
