/*
** EPITECH PROJECT, 2025
** clean_str
** File description:
** recode stumper clean_str: supprime espaces/tabs inutiles
*/

#include "my.h"

void clean_condition(char *str, char *clean, int i, int *j)
{
    if (str[i] != ' ' && str[i] != '\t'){
        clean[*j] = str[i];
        (*j)++;
    } else if (str[i + 1] != ' ' && str[i + 1] != '\t'){
        clean[*j] = ' ';
        (*j)++;
    }
}

char *clean_str(char *str)
{
    char *clean = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;
    int j = 0;

    while (str[i] == ' ' || str[i] == '\t')
        i++;
    while (str[i] != '\0'){
        clean_condition(str, clean, i, &j);
        i++;
    }
    if (j > 0 && clean[j - 1] == ' ')
        j--;
    clean[j] = '\0';
    return clean;
}
