/*
** EPITECH PROJECT, 2024
** my_atoi
** File description:
** recode de atoi, s'arrete quand c'est pas un chiffre (à part + ou  -)
*/

#include "my.h"

int my_atoi(const char *str)
{
    int nb = 0;
    int sign = 1;

    if (str[0] == '-'){
        sign = -1;
        str++;
    } else if (str[0] == '+'){
        str++;
    }
    for (int i = 0; str[i] != '\0' && my_isdigit(str[i]) == 1; i++){
        nb *= 10;
        nb = nb + str[i] - 48;
    }
    return sign * nb;
}
