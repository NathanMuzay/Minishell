/*
** EPITECH PROJECT, 2025
** strdup_array
** File description:
** duplicate array to copy array
*/

#include "my.h"

char **strdup_array(char **array, int len_addition, char *ignore)
{
    int i = 0;
    int j = 0;
    int len = count_lines_array(array);
    char **copy = malloc(sizeof(char *) * (len + len_addition + 1));

    if (ignore == NULL){
        while (array[i] != NULL) {
            copy[i] = my_strdup(array[i]);
            i++;
        }
        copy[i] = NULL;
        return copy;
    }
    for (int k = 0; array[k] != NULL; k++)
        if (my_strcmp(array[k], ignore) != 0){
            copy[j] = my_strdup(array[k]);
            j++;
        }
    copy[j] = NULL;
    return copy;
}
