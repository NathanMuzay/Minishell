/*
** EPITECH PROJECT, 2025
** local_env.c
** File description:
** This is to create local variable.
*/

#include "../include/mysh.h"

void add_local_var(mysh_t *sh, char *name, char *value)
{
    local_var_t *current = sh->locals;
    local_var_t *new_var = malloc(sizeof(local_var_t));

    while (current != NULL) {
        if (my_strcmp(current->name, name) == 0) {
            current->value = my_strdup(value);
            return;
        }
        current = current->next;
    }
    new_var->name = my_strdup(name);
    new_var->value = my_strdup(value);
    new_var->next = sh->locals;
    sh->locals = new_var;
}

void display_local_vars(local_var_t *head)
{
    local_var_t *current = head;

    while (current != NULL) {
        my_printf("%s\t%s\n", current->name, current->value);
        current = current->next;
    }
}

int verif_space_str(char *str)
{
    for (int i = 0; str[i]; i++){
        if (str[i] == ' ')
            return 1;
    }
    return 0;
}

char **parse_set_line(char *line)
{
    char *token = NULL;
    char **args = malloc(sizeof(char *) * 3);

    token = strtok(line, " ");
    token = strtok(NULL, "=");
    if (token == NULL) {
        args[0] = NULL;
        return args;
    }
    if (verif_space_str(token) == 1){
        printf("set: Variable name must begin with a letter.\n");
        args[0] = NULL;
        return args;
    }
    if (token != NULL)
        args[0] = my_strdup(token);
    token = strtok(NULL, "\"");
    args[1] = local_var_token(token);
    args[2] = NULL;
    return args;
}

void my_set(mysh_t *sh)
{
    char **args = parse_set_line(sh->line);

    if (args[0] == NULL) {
        display_local_vars(sh->locals);
        free_array(args);
        return;
    }
    add_local_var(sh, args[0], args[1]);
    free_array(args);
}
