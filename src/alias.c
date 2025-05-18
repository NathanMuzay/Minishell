/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** alias
*/

#include "../include/mysh.h"

int contains(const char *str)
{
    int count = 0;

    if (!str)
        return 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] == '"')
            count++;
    }
    return count;
}

static void free_curr(alias_t *curr)
{
    free(curr->new_name);
    free(curr->command_base);
    free(curr);
}

static void add_tolist(mysh_t *sh, alias_t *curr)
{
    alias_t *ind = sh->alias;

    if (sh->alias == NULL)
        sh->alias = curr;
    else {
        while (ind->next)
            ind = ind->next;
        ind->next = curr;
    }
}

static void init_alias(alias_t *curr, char *copy)
{
    strtok(copy, " ");
    curr->new_name = strtok(NULL, "=");
    curr->command_base = strtok(NULL, "\"");
    curr->next = NULL;
    curr->new_name = strdup(curr->new_name);
    curr->command_base = strdup(curr->command_base);
}

void set_alias(mysh_t *sh)
{
    alias_t *curr = malloc(sizeof(alias_t));
    char *copy = strdup(sh->line);

    if (my_strcmp(sh->line, "alias") == 0)
        return;
    init_alias(curr, copy);
    for (alias_t *ind = sh->alias; ind != NULL; ind = ind->next)
        if (strcmp(ind->new_name, curr->new_name) == 0){
            free(ind->command_base);
            ind->command_base = strdup(curr->command_base);
            free_curr(curr);
        }
    if (my_strlen(curr->new_name) == my_strlen(sh->line) - my_strlen("alias ")
    || contains(sh->line) != 2){
        free(curr);
        printf("Alias syntax error\n");
        return;
    }
    add_tolist(sh, curr);
    return;
}

int alias_process(mysh_t *sh)
{
    sh->separated_space = space_to_array(sh->line);
    sh->alias_count = 1;
    free_array(sh->cmd_args);
    sh->cmds = parse_commands(sh, sh->line);
    for (int i = 0; sh->cmds[i].cmd != NULL; i++){
        sh->line = strdup(sh->cmds[i].cmd);
        sh->line = clean_str(sh->line);
        sh->cmd_args = space_to_array(sh->line);
        shell_process_commands(sh);
    }
    return sh->status;
}

static void change(alias_t *al, mysh_t *sh, int test, int i)
{
    int ind = -1;

    if (my_strcmp(al->new_name, sh->separated_space[i]) == 0) {
        if (sh->tmp[i] != NULL)
            free(sh->tmp[i]);
        sh->tmp[i] = my_strdup(al->command_base);
        sh->lol = 1;
        ind = 1;
    }
    if (test == 1 && ind != 1) {
        if (sh->tmp[i] != NULL)
            free(sh->tmp[i]);
        sh->tmp[i] = my_strdup(sh->separated_space[i]);
    }
}

int change_tmp(mysh_t *sh, int test, alias_t *al)
{
    sh->lol = 0;
    for (int i = 0; sh->separated_space[i] != NULL; i++) {
        change(al, sh, test, i);
    }
    return sh->lol;
}

int is_alias(mysh_t *sh)
{
    int indicateur = 0;
    int lol = 0;

    if (init_tmp_alias_array(sh, &indicateur) == -1)
        return -1;
    lol = apply_aliases(sh);
    if (lol == 1)
        return handle_alias_execution(sh, indicateur);
    free_array(sh->tmp);
    sh->tmp = NULL;
    return -1;
}
