/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-42sh-pierre-alexandre.mondoloni
** File description:
** array_to_str
*/

#include "../include/my.h"

static int len(char **array)
{
    int len = 0;

    for (int i = 0; array[i] != NULL; i++) {
        len += my_strlen(array[i]);
        if (array[i + 1] != NULL)
            len++;
    }
    return len;
}

char *array_to_str(char **array)
{
    char *str = NULL;
    int i = 0;
    int pos = 0;
    int word_len = 0;

    str = malloc(sizeof(char) * (len(array) + 1));
    pos = 0;
    for (i = 0; array[i] != NULL; i++) {
        word_len = my_strlen(array[i]);
        my_strncpy(str + pos, array[i], word_len);
        pos += word_len;
        if (array[i + 1] != NULL) {
            str[pos] = ' ';
            pos++;
        }
    }
    str[pos] = '\0';
    return str;
}
