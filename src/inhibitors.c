/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** inhibitors
*/

#include "../include/mysh.h"

char **backslash(char **array, int i)
{
    char *tmp = strdup(array[i]);

    array[i] = malloc(sizeof(char) * (strlen(tmp) + strlen(array[i + 1]) + 1));
    array[i] = strcpy(array[i], tmp);
    array[i] = strcat(array[i], array[i + 1]);
    for (int j = 0; array[i][j] != '\0'; j++){
        if (array[i][j] == '\\')
            array[i][j] = ' ';
    }
    array = strdup_array(array, -1, array[i + 1]);
    free(tmp);
    return array;
}

char **inhibitors_process(char **array)
{
    for (int i = 0; array[i] != NULL; i++){
        if (strstr(array[i], "\\") != NULL && array[i + 1] != NULL){
            array = backslash(array, i);
        }
    }
    return array;
}
