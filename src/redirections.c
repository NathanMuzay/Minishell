/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** redirections
*/

#include "../include/mysh.h"

void redirection_handler(mysh_t *sh)
{
    sh->std_output = dup(STDOUT_FILENO);
    for (int i = 0; sh->cmd_args[i] != NULL; i++){
        if (my_strcmp(sh->cmd_args[i], ">") == 0){
            redirect1(sh, i);
            sh->is_redirect = 1;
            break;
        }
        if (my_strcmp(sh->cmd_args[i], ">>") == 0){
            redirect2(sh, i);
            sh->is_redirect = 1;
            break;
        }
        if (my_strcmp(sh->cmd_args[i], "<") == 0){
            redirect3(sh, i);
            sh->is_redirect = 1;
            break;
        }
    }
}

int redirect1(mysh_t *sh, int i)
{
    sh->file = open(sh->cmd_args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (sh->file == -1 || sh->cmd_args[i + 1] == NULL){
        my_printf("Missing name for redirect.\n");
        close(sh->file);
        exit(BAD_COMMAND);
    }
    sh->fd2 = dup2(sh->file, STDOUT_FILENO);
    sh->cmd_args[i] = NULL;
    return 0;
}

int redirect2(mysh_t *sh, int i)
{
    sh->file = open(sh->cmd_args[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (sh->file == -1 || sh->cmd_args[i + 1] == NULL){
        my_printf("Missing name for redirect.\n");
        close(sh->file);
        exit(BAD_COMMAND);
    }
    sh->fd2 = dup2(sh->file, STDOUT_FILENO);
    sh->cmd_args[i] = NULL;
    return 0;
}

int redirect3(mysh_t *sh, int i)
{
    sh->file = open(sh->cmd_args[i + 1], O_RDONLY);
    if (sh->file == -1 || sh->cmd_args[i + 1] == NULL){
        my_printf("Missing name for redirect.\n");
        close(sh->file);
        exit(BAD_COMMAND);
    }
    sh->fd2 = dup2(sh->file, STDIN_FILENO);
    sh->cmd_args[i] = NULL;
    return 0;
}

void redirection_close(mysh_t *sh)
{
    if (sh->is_redirect == 1){
        sh->fd3 = dup2(sh->std_output, sh->fd2);
        close(sh->std_output);
    }
    sh->is_redirect = 0;
}
