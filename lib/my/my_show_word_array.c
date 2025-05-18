/*
** EPITECH PROJECT, 2024
** my_show_word_array
** File description:
** Day 8, task 3
*/

#include "my.h"

int my_show_word_array(char *const *tab)
{
    for (int i = 0; tab[i] != 0; i++){
        my_putstr(tab[i]);
        my_putchar('\n');
    }
    return 0;
}
