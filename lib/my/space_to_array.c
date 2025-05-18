/*
** EPITECH PROJECT, 2024
** space_to_array
** File description:
** str to word array with spaces
*/

#include <stdlib.h>
#include "my.h"

int separation(char const *str, int i, int *words, int *inside_word)
{
    if (str[i] != ' '){
        if (!(*inside_word)){
            (*words)++;
            *inside_word = 1;
        }
    } else {
        *inside_word = 0;
    }
    return *words;
}

int word_counter(char const *str)
{
    int words = 0;
    int inside_word = 0;

    for (int i = 0; str[i] != '\0'; i++){
        separation(str, i, &words, &inside_word);
    }
    return words;
}

void array_builder(char const *str, int *j, char **split, int *i)
{
    int start = *j;
    int length = 0;

    while (str[*j] == ' ')
        (*j)++;
    start = *j;
    while (str[*j] != '\0' && str[*j] != ' ')
        (*j)++;
    length = *j - start;
    split[*i] = malloc(sizeof(char) * (length + 1));
    for (int k = 0; k < length; k++) {
        split[*i][k] = str[start + k];
    }
    split[*i][length] = '\0';
    (*i)++;
}

char **space_to_array(char const *str)
{
    int count = word_counter(str);
    char **split = malloc(sizeof(char *) * (count + 1));
    int i = 0;
    int j = 0;
    int spaces = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ')
            spaces++;
    if (spaces == my_strlen(str))
        return NULL;
    while (str[j] != '\0') {
        array_builder(str, &j, split, &i);
    }
    split[i] = NULL;
    return split;
}
