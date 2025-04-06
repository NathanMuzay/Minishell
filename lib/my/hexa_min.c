/*
** EPITECH PROJECT, 2024
** B-CPE-100-MAR-1-1-cpoolday13-nathan.muzay
** File description:
** hexa
*/



#include "my.h"

int my_putnbr_hexamin(unsigned long int nb)
{
    int i = 0;
    int r = 0;
    char *result = malloc(sizeof(char) * nb_len(nb));

    while (nb != 0){
        r = nb % 16;
        nb = nb / 16;
        if (r <= 9 && r >= 0) {
            result[i] = (char)(r + 48);
        } else {
            result[i] = (char)(r + 87);
        }
        i++;
    }
    result[i] = '\0';
    my_putstr(my_revstr(result));
    return 0;
}
