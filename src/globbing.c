/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-42sh-pierre-alexandre.mondoloni
** File description:
** globbing
*/

#include "../include/mysh.h"

char *remove_quotes(const char *str)
{
    int len = strlen(str);
    char *new = malloc(len - 1);

    if (len >= 2 && ((str[0] == '"' && str[len - 1] == '"') ||
        (str[0] == '\'' && str[len - 1] == '\''))) {
        new = malloc(len - 1);
        if (!new)
            return NULL;
        strncpy(new, str + 1, len - 2);
        new[len - 2] = '\0';
        return new;
    }
    return strdup(str);
}

static int is_glob_pattern(const char *str)
{
    return (strchr(str, '*') || strchr(str, '?') || strchr(str, '['));
}

static char **append_glob_result(char **dest, glob_t *globbuf, int *index)
{
    for (size_t i = 0; i < globbuf->gl_pathc; i++) {
        dest[*index] = strdup(globbuf->gl_pathv[i]);
        if (!dest[*index])
            return NULL;
        (*index)++;
    }
    return dest;
}

char **globbings(char **args)
{
    char **new_args = malloc(sizeof(char *) * 1024);
    int index = 0;
    glob_t globbuf;
    char *clean;

    if (!new_args)
        return NULL;
    for (int i = 0; args[i]; i++) {
        clean = remove_quotes(args[i]);
        if (is_glob_pattern(clean) && glob(clean, 0, NULL, &globbuf) == 0) {
            new_args = append_glob_result(new_args, &globbuf, &index);
            globfree(&globbuf);
            free(clean);
        } else {
            new_args[index] = my_strdup(clean);
            index++;
        }
    }
    new_args[index] = NULL;
    return new_args;
}

void free_args(char **args)
{
    if (!args)
        return;
    for (int i = 0; args[i]; i++)
        free(args[i]);
    free(args);
}
