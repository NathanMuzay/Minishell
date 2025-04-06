/*
** EPITECH PROJECT, 2024
** my_is_prime
** File description:
** Day 5, task 6
*/
#include "my.h"




int my_is_prime(int nb)
{
    if (nb <= 1){
        return 0;
    }
    for (int i = 2; i < nb; i++){
        if (nb % i == 0){
            return 0;
        }
    }
    return 1;
}
