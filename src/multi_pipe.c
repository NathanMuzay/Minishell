/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-minishell2-nathan.muzay
** File description:
** handle
*/

#include "../include/mysh.h"

void args_actu(char *input, char **args)
{
    int i = 0;
    char *token = strtok(input, " \t\n");

    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
}

static void fork_error(void)
{
    exit(84);
}

static void setup_child_io(mysh_t *sh, int *prev_fd)
{
    if (sh->i > 0) {
        dup2(*prev_fd, STDIN_FILENO);
        close(*prev_fd);
    }
    if (sh->i < sh->cmd_count - 1) {
        close(sh->pipefd[0]);
        dup2(sh->pipefd[1], STDOUT_FILENO);
        close(sh->pipefd[1]);
    }
}

static void handle_pipe_parent(mysh_t *sh, int *prev_fd)
{
    if (sh->i > 0)
        close(*prev_fd);
    if (sh->i < sh->cmd_count - 1) {
        close(sh->pipefd[1]);
        *prev_fd = sh->pipefd[0];
    }
}

void handle_pipe_process(mysh_t *sh, int *prev_fd,
    char *cmd)
{
    char *args[100];
    pid_t pid;

    args_actu(cmd, args);
    if (sh->i < sh->cmd_count - 1 && pipe(sh->pipefd) == -1) {
        exit(84);
    }
    pid = fork();
    if (pid == -1)
        fork_error();
    if (pid == 0) {
        setup_child_io(sh, prev_fd);
        shell_simple_command(sh, args);
        exit(0);
    }
    handle_pipe_parent(sh, prev_fd);
}

void execute_piped_commands(char *cmd_line, mysh_t *sh)
{
    char *commands[100];
    char *save = NULL;
    int prev_fd = -1;

    sh->cmd_count = 0;
    commands[sh->cmd_count] = strtok_r(cmd_line, "|", &save);
    while (commands[sh->cmd_count]) {
        sh->cmd_count++;
        commands[sh->cmd_count] = strtok_r(NULL, "|", &save);
    }
    for (sh->i = 0; sh->i < sh->cmd_count; sh->i++)
        handle_pipe_process(sh, &prev_fd, commands[sh->i]);
    for (int i = 0; i < sh->cmd_count; i++)
        wait(NULL);
}
