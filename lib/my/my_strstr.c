/*
** EPITECH PROJECT, 2024
** my_strstr
** File description:
** Day 6, Task 5
*/

#include <stddef.h>

char *my_strstr(char *str, char const *to_find)
{
    int j = 0;

    if (*to_find == '\0') {
        return str;
    }
    for (int i = 0; str[i] != '\0'; i++){
        j = 0;
        while (to_find[j] != '\0' && str[i + j] == to_find[j]){
            j++;
        }
        if (to_find[j] == '\0'){
            return &str[i];
        }
    }
    return NULL;
}
