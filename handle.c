/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell2-nathan.muzay
** File description:
** handle
*/

#include "include/my.h"

static void fork_error(void)
{
    perror("fork");
    exit(84);
}

static void setup_child_io(var_t *f, int *prev_fd)
{
    if (f->i > 0) {
        dup2(*prev_fd, STDIN_FILENO);
        close(*prev_fd);
    }
    if (f->i < f->cmd_count - 1) {
        close(f->pipefd[0]);
        dup2(f->pipefd[1], STDOUT_FILENO);
        close(f->pipefd[1]);
    }
}

static void handle_pipe_parent(var_t *f, int *prev_fd)
{
    if (f->i > 0)
        close(*prev_fd);
    if (f->i < f->cmd_count - 1) {
        close(f->pipefd[1]);
        *prev_fd = f->pipefd[0];
    }
}

void handle_pipe_process(var_t *f, int *prev_fd,
    char *cmd, char **env)
{
    char *args[100];
    pid_t pid;

    args_actu(cmd, args);
    if (f->i < f->cmd_count - 1 && pipe(f->pipefd) == -1) {
        perror("pipe");
        exit(84);
    }
    pid = fork();
    if (pid == -1)
        fork_error();
    if (pid == 0) {
        setup_child_io(f, prev_fd);
        execute_command(args, env, f);
        exit(0);
    }
    handle_pipe_parent(f, prev_fd);
}
