/*
** EPITECH PROJECT, 2025
** handle redirection
** File description:
** handle redirection
*/

#include "include/my.h"

void child_2(int pipefd[2], char *right_cmd, char **args, char **env)
{
    dup2(pipefd[0], STDIN_FILENO);
    close(pipefd[1]);
    close(pipefd[0]);
    args_actu(right_cmd, args);
    execute_command(args, env);
    exit(0);
}

void child_1(int pipefd[2], char *left_cmd, char **args, char **env)
{
    dup2(pipefd[1], STDOUT_FILENO);
    close(pipefd[0]);
    close(pipefd[1]);
    args_actu(left_cmd, args);
    execute_command(args, env);
    exit(0);
}

void handle_redirections(char **args)
{
    for (int i = 0; args[i] != NULL; i++) {
        if (my_strcmp(args[i], ">") == 0 && chevron(args, i) == 1)
            break;
        if (my_strcmp(args[i], ">>") == 0 && double_chevron(args, i) == 1)
            break;
        if (my_strcmp(args[i], "<") == 0 && param(args, i) == 1)
            break;
    }
}
