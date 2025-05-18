/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** builtins
*/

#include "../include/mysh.h"

void my_env(mysh_t *sh)
{
    char **args = space_to_array(sh->line);
    int nb_args = count_lines_array(args);

    if (nb_args > 1){
        my_printf("env: '%s%s\n", args[1],
            "': No such file or directory");
        free_array(args);
        sh->status = ENV_BAD_ARGS;
        return;
    }
    my_show_word_array(sh->env);
    free_array(args);
    sh->status = SUCCESS;
}

void my_exit(mysh_t *sh)
{
    char **args = space_to_array(sh->line);
    int nb_args = count_lines_array(args);
    int status = SUCCESS;

    if (nb_args == 2 && is_integer(args[1]) == 1){
        sh->status = my_atoi(args[1]);
    } else if (nb_args != 1){
        my_printf("exit: Expression Syntax.\n");
        free_array(args);
        sh->status = BAD_COMMAND;
        return;
    }
    my_printf("exit\n");
    status = sh->status;
    free_array(args);
    free_shell(sh);
    exit(status);
}
