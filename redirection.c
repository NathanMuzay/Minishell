/*
** EPITECH PROJECT, 2025
** redirection.c
** File description:
** redir
*/

#include "include/my.h"

int chevron(char **args, int i)
{
    int fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (fd == -1) {
        perror("open");
        exit(84);
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    args[i] = NULL;
    return 1;
}

int double_chevron(char **args, int i)
{
    int fd = open(args[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);

    if (fd == -1) {
        perror("open");
        exit(84);
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
    args[i] = NULL;
    return 1;
}

int param(char **args, int i)
{
    int fd = open(args[i + 1], O_RDONLY);

    if (fd == -1) {
        perror("open");
        exit(84);
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
    args[i] = NULL;
    return 1;
}
