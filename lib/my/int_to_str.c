/*
** EPITECH PROJECT, 2024
** int to str
** File description:
** convertis char* en string
*/

#include "my.h"

char *int_to_str(int nb)
{
    char *str = malloc(sizeof(char) * (my_intnumlen(nb) + 1));
    int nb_len = my_intnumlen(nb);
    int is_neg = 0;

    if (nb < 0){
        nb = -nb;
        is_neg = 1;
    }
    for (int i = 0; i < nb_len; i++){
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    if (is_neg == 1){
        str[nb_len - 1] = '-';
    }
    str[nb_len] = '\0';
    my_revstr(str);
    return str;
}
