/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** pipes
*/

#include "../include/mysh.h"

pid_t pipe_write_execute(mysh_t *sh, int *fd, pid_t pid1)
{
    if (pipe(fd) == -1){
        exit(BAD_COMMAND);
    }
    pid1 = fork();
    if (pid1 == 0){
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        redirection_handler(sh);
        shell_execute_command(sh, sh->cmd_args);
    }
    return pid1;
}

pid_t pipe_read_execute(mysh_t *sh, int *fd, pid_t pid2, int pipe_index)
{
    char **cmd = &sh->cmd_args[pipe_index + 1];

    pid2 = fork();
    if (pid2 == 0){
        if (sh->cmd_args[pipe_index + 1] == NULL){
            exit(BAD_COMMAND);
        }
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
        redirection_handler(sh);
        shell_execute_command(sh, cmd);
        free_array(cmd);
    }
    return pid2;
}
