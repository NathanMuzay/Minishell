/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** setenv
*/

#include "../include/mysh.h"

void two_args(mysh_t *sh, char **args)
{
    char *var = malloc(sizeof(char) * (my_strlen(args[1]) + 2));
    char **new_env = NULL;
    int i = 0;

    var = my_strcpy(var, args[1]);
    var = my_strcat(var, "=");
    while (sh->env[i] != NULL) {
        if (my_strncmp(sh->env[i], var, my_strlen(var)) == 0) {
            sh->env[i] = my_strdup(var);
            return;
        }
        i++;
    }
    new_env = strdup_array(sh->env, 1, NULL);
    new_env[i] = my_strdup(var);
    new_env[i + 1] = NULL;
    sh->env = new_env;
    free(var);
}

static char *build_var_value(char *var, char *value)
{
    char *var_value = malloc((my_strlen(var) + my_strlen(value) + 1));

    var_value = my_strcpy(var_value, var);
    var_value = my_strcat(var_value, value);
    return var_value;
}

void three_args(mysh_t *sh, char **args)
{
    char *var = malloc(sizeof(char) * (my_strlen(args[1]) + 2));
    char *value = my_strdup(args[2]);
    char *var_value = NULL;
    char **new_env = NULL;
    int i = 0;

    var = my_strcpy(var, args[1]);
    var = my_strcat(var, "=");
    var_value = build_var_value(var, value);
    while (sh->env[i] != NULL) {
        if (my_strncmp(sh->env[i], var, my_strlen(var)) == 0) {
            sh->env[i] = my_strdup(var_value);
            return;
        }
        i++;
    }
    new_env = strdup_array(sh->env, 1, NULL);
    new_env[i] = my_strdup(var_value);
    new_env[i + 1] = NULL;
    sh->env = new_env;
}

int error_handling(mysh_t *sh, char **args, int nb_args, int i)
{
    if (my_isalpha_underscore(args[i][0]) != 1){
        sh->status = BAD_COMMAND;
        my_printf("setenv: Variable name must begin with a letter.\n");
        return ERROR;
    }
    for (int j = 0; args[i][j] != '\0'; j++){
        if (!my_isalnum_underscore(args[i][j])){
            sh->status = BAD_COMMAND;
            my_printf("setenv: Variable name must ");
            my_printf("contain alphanumeric characters.\n");
            return ERROR;
        }
    }
    if (nb_args > 3){
        my_printf("setenv: Too many arguments.\n");
        sh->status = BAD_COMMAND;
        return ERROR;
    }
    return SUCCESS;
}

void my_setenv(mysh_t *sh)
{
    char **args = space_to_array(sh->line);
    int nb_args = count_lines_array(args);

    if (nb_args == 1){
        my_show_word_array(sh->env);
        free_array(args);
        sh->status = SUCCESS;
        return;
    }
    for (int i = 1; i < 2; i++)
        if (error_handling(sh, args, nb_args, i) == ERROR)
            return;
    if (nb_args == 2){
        two_args(sh, args);
    } else if (nb_args == 3){
        three_args(sh, args);
    }
    free_array(args);
    sh->status = SUCCESS;
    return;
}
