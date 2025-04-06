/*
** EPITECH PROJECT, 2024
** concat_params
** File description:
** Day 8, task 2
*/
#include "my.h"




char *concat_params(int argc, char **argv)
{
    char *concat;
    int j = 0;
    int c = 0;

    for (int i = 0; i < argc; i++){
        while (argv[i][j] != '\0'){
            j++;
        }
    }
    concat = malloc(sizeof(char) * (j + 1));
    for (int a = 0; a < argc; a++){
        for (int b = 0; argv[a][b] != '\0'; b++){
            concat[c] = argv[a][b];
            c++;
        }
        concat[c] = '\n';
        c++;
    }
    concat[c - 1] = '\0';
    return concat;
}
