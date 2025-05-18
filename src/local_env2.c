/*
** EPITECH PROJECT, 2025
** local_env.c
** File description:
** This is to create local variable.
*/

#include "../include/mysh.h"

void delete_current_node(mysh_t *sh, local_var_t *previous,
    local_var_t *current)
{
    if (previous == NULL) {
        sh->locals = current->next;
    } else {
        previous->next = current->next;
    }
    free(current->name);
    free(current->value);
    free(current);
}

void delete_node(mysh_t *sh, char *name_del)
{
    local_var_t *current = sh->locals;
    local_var_t *previous = NULL;

    while (current != NULL) {
        if (my_strcmp(current->name, name_del) == 0) {
            delete_current_node(sh, previous, current);
            return;
        }
        previous = current;
        current = current->next;
    }
}

void my_unset(mysh_t *sh)
{
    char *input = sh->line;

    for (char *tokens = strtok(input, " ");
        tokens != NULL; tokens = strtok(NULL, " ")) {
        delete_node(sh, tokens);
    }
    return;
}

char *local_var_token(char *token)
{
    if (token != NULL)
        return (my_strdup(token));
    else
        return (my_strdup(""));
}
