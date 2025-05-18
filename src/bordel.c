/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-42sh-pierre-alexandre.mondoloni
** File description:
** bordel
*/

#include "../include/mysh.h"

int init_tmp_alias_array(mysh_t *sh, int *indicateur)
{
    *indicateur = my_arrlen(sh->separated_space) + 1;
    sh->tmp = malloc(sizeof(char *) * (*indicateur + 1));
    if (!sh->tmp)
        return -1;
    for (int i = 0; i <= *indicateur; i++)
        sh->tmp[i] = NULL;
    sh->alias_count = 1;
    return 0;
}

int apply_aliases(mysh_t *sh)
{
    alias_t *al = NULL;
    int test = 1;
    int lol = 0;

    for (al = sh->alias; al != NULL; al = al->next) {
        if (change_tmp(sh, test, al) == 1)
            lol = 1;
        test = -1;
    }
    return lol;
}

int handle_alias_execution(mysh_t *sh, int indicateur)
{
    sh->tmp[indicateur] = NULL;
    sh->line = array_to_str(sh->tmp);
    free_array(sh->tmp);
    sh->tmp = NULL;
    if (sh->line)
        alias_process(sh);
    return 1;
}
