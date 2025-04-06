/*
** EPITECH PROJECT, 2024
** my_str_isalpha
** File description:
** Day 6, task 12
*/
#include "my.h"




int my_str_isalpha(char const *str)
{
    if (str[0] == '\0'){
        return 1;
    }
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122){
            return 0;
        }
    }
    return 1;
}
