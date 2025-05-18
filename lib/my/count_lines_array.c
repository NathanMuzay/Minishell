/*
** EPITECH PROJECT, 2025
** count lines array
** File description:
** self explanatory
*/

#include "my.h"

int count_lines_array(char *const *tab)
{
    int nb_lines = 0;

    for (int i = 0; tab[i] != NULL; i++){
        nb_lines++;
    }
    return nb_lines;
}
