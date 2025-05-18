/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** my_str_to_word_array with custom delim
*/

#include "../include/mysh.h"

static int count_words(const char *str, char delim)
{
    int count = 0;
    int in_word = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] != delim && !in_word) {
            in_word = 1;
            count++;
        }
        if (str[i] == delim) {
            in_word = 0;
        }
    }
    return count;
}

static char *copy_word(const char *str, int start, int end)
{
    char *word = malloc(sizeof(char) * (end - start + 1));
    int i = 0;

    if (word == NULL)
        return NULL;
    for (int j = start; j < end; j++) {
        word[i] = str[j];
        i++;
    }
    word[i] = '\0';
    return word;
}

char **my_str_to_word_array_delim(const char *str, char delim)
{
    char **array = NULL;
    int words = 0;
    int start = 0;
    int idx = 0;

    if (!str)
        return NULL;
    words = count_words(str, delim);
    array = malloc(sizeof(char *) * (words + 1));
    for (int i = 0; str[i]; i++) {
        if (str[i] != delim && (i == 0 || str[i - 1] == delim))
            start = i;
        if (str[i] != delim && (str[i + 1] == '\0' || str[i + 1] == delim)) {
            array[idx] = copy_word(str, start, i + 1);
            idx++;
        }
    }
    array[idx] = NULL;
    return array;
}
