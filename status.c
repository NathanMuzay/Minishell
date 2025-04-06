/*
** EPITECH PROJECT, 2025
** status
** File description:
** status
*/

#include "include/my.h"

void staaatus(pid_t pid, int status, var_t *f)
{
    int signal = 0;

    waitpid(pid, &status, 0);
    if (WIFEXITED(status))
        f->statut = WEXITSTATUS(status);
    else if (WIFSIGNALED(status)){
        signal = WTERMSIG(status);
        my_printf("%s\n", strsignal(signal));
        f->statut = signal + 128;
    }
}
