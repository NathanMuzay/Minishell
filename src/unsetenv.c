/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** unsetenv
*/

#include "../include/mysh.h"

char **remove_var_condition(mysh_t *sh, char *var, char **new_env, int i)
{
    if (my_strncmp(var, sh->env[i], my_strlen(var)) == 0){
        new_env = strdup_array(sh->env, 0, sh->env[i]);
        sh->env = new_env;
    }
    return new_env;
}

void my_unsetenv(mysh_t *sh)
{
    char **args = space_to_array(sh->line);
    int nb_args = count_lines_array(args);
    char *var = NULL;
    char **new_env = NULL;

    if (nb_args == 1){
        my_printf("unsetenv: Too few arguments.\n");
        sh->status = BAD_COMMAND;
        return;
    }
    for (int j = 1; j < nb_args; j++){
        var = malloc(sizeof(char) * (my_strlen(args[j]) + 2));
        var = my_strcpy(var, args[j]);
        var = my_strcat(var, "=");
        for (int i = 0; sh->env[i] != NULL; i++){
            new_env = remove_var_condition(sh, var, new_env, i);
        }
    }
    sh->status = SUCCESS;
    return;
}
