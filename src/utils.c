/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** utils
*/

#include "../include/mysh.h"

char *delete_newline(char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == '\n')
            str[i] = '\0';
    }
    return str;
}

int is_arg_empty(const char *str)
{
    int spaces = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ' ')
            spaces++;
    if (spaces == my_strlen(str))
        return 1;
    return 0;
}

int my_isalnum_underscore(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
    || (c >= '0' && c <= '9') || (c == '_'));
}

int my_isalpha_underscore(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c == '_');
}

char **split_by_semicolon(char *str)
{
    char **split = NULL;
    int count = 1;
    char *token = NULL;
    int k = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == ';'){
            count++;
        }
    }
    split = malloc(sizeof(char *) * (count + 1));
    token = strtok(str, ";");
    while (token != NULL){
        split[k] = my_strdup(token);
        token = strtok(NULL, ";");
        k++;
    }
    split[k] = NULL;
    return split;
}

/*void shell_first_run(void)
{
    char *texte[] = {
    "--------------------------------------------------------------------",
    " ██╗     ██╗███╗   ██╗ ██████╗  █████╗ ███╗   ██╗ ██████╗ ██╗   ██╗",
    " ██║     ██║████╗  ██║██╔════╝ ██╔══██╗████╗  ██║██╔════╝ ██║   ██║",
    " ██║     ██║██╔██╗ ██║██║  ███╗███████║██╔██╗ ██║██║  ███╗██║   ██║",
    " ██║     ██║██║╚██╗██║██║   ██║██╔══██║██║╚██╗██║██║   ██║██║   ██║",
    " ███████╗██║██║ ╚████║╚██████╔╝██║  ██║██║ ╚████║╚██████╔╝╚██████╔╝",
    " ╚══════╝╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝  ╚═════╝",
    "--------------------------------------------------------------------",
    NULL};

    my_putchar('\n');
    for (int i = 0; texte[i] != NULL; i++){
        my_printf(BOLD COLOR_RED "%s\n", texte[i]);
    }
    my_putchar('\n');
}*/
