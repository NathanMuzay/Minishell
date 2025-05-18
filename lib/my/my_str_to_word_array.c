/*
** EPITECH PROJECT, 2024
** my_str_to_word_array
** File description:
** Day 8, task 4
*/

#include <stdlib.h>
#include "my.h"

static int separation(char const *str, int i, int *words, int *inside_word)
{
    if (my_isalnum(str[i])){
        if (!(*inside_word)){
            (*words)++;
            *inside_word = 1;
        }
    } else {
        *inside_word = 0;
    }
    return *words;
}

static int word_counter(char const *str)
{
    int words = 0;
    int inside_word = 0;

    for (int i = 0; str[i] != '\0'; i++){
        separation(str, i, &words, &inside_word);
    }
    return words;
}

static int array_builder(char const *str, int *i, int *j, char **split)
{
    static int inside_word = 0;
    static int array_char = 0;

    if (my_isalnum(str[*j])) {
        if (!inside_word){
            array_char = 0;
            inside_word = 1;
        }
        split[*i][array_char] = str[*j];
        array_char++;
    } else if (inside_word == 1) {
        split[*i][array_char] = '\0';
        (*i)++;
        inside_word = 0;
    }
    (*j)++;
    return array_char;
}

char **my_str_to_word_array(char const *str)
{
    int count = word_counter(str);
    char **split = malloc(sizeof(char *) * (count + 1));
    int i = 0;
    int j = 0;
    int array_char = 0;

    for (int i = 0; i < count; i++){
        split[i] = malloc(sizeof(char) * (my_strlen(str) + 1));
    }
    while (str[j] != '\0'){
        array_char = array_builder(str, &i, &j, split);
    }
    if (my_isalnum(str[j - 1])) {
        split[i][array_char] = '\0';
        i++;
    }
    split[i] = 0;
    return split;
}
