/*
** EPITECH PROJECT, 2024
** my_isdigit
** File description:
** return 1 si un chiffre
*/

#include "my.h"

int my_isdigit(const char c)
{
    if (c < '0' || c > '9'){
        return 0;
    }
    return 1;
}
