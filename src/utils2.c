/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-42sh-pierre-alexandre.mondoloni
** File description:
** utils2
*/

#include "../include/mysh.h"

void reset_parse(mysh_t *sh)
{
    sh->in->brackets = 0;
    sh->in->backticks = 0;
    sh->in->dquotes = 0;
    sh->in->squotes = 0;
}

char **quotes_to_array(char *str)
{
    char **args = malloc(sizeof(char *) * 2);

    args[0] = strdup(str);
    args[1] = NULL;
    return args;
}

int tab_count(commands_t *cmd)
{
    int count = 0;

    while (cmd[count].cmd != NULL) {
        count++;
    }
    return count;
}

char *type_to_string(separator_t sep)
{
    if (sep == LAST)
        return "LAST";
    if (sep == SEMICOLON)
        return "SEMICOLON";
    if (sep == AND)
        return "AND";
    if (sep == OR)
        return "OR";
    if (sep == SINGLE_QUOTES)
        return "SINGLE_QUOTES";
    if (sep == DOUBLE_QUOTES)
        return "DOUBLE_QUOTES";
    if (sep == BACKTICKS)
        return "BACKTICKS";
    if (sep == BRACKETS)
        return "BRACKETS";
    if (sep == NONE)
        return "NONE";
    return NULL;
}
