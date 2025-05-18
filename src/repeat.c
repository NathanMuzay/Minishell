/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-42sh-pierre-alexandre.mondoloni
** File description:
** repeat
*/

#include "../include/mysh.h"

void do_repeat(int nb_repeat, mysh_t *sh)
{
    int previous = sh->interactive_input;

    while (nb_repeat != 0) {
        sh->interactive_input = 0;
        shell_process_commands(sh);
        sh->interactive_input = previous;
        nb_repeat--;
    }
}

void repeat(mysh_t *sh)
{
    int nb_repeat = 0;

    if (is_digit(sh->cmd_args[1]) == -1) {
        printf("repeat: Numéro mal formé.\n");
        return;
    }
    nb_repeat = my_atoi(sh->cmd_args[1]);
    sh->line = my_strdup(sh->cmd_args[2]);
    for (int i = 3; sh->cmd_args[i]; i++) {
        sh->line = my_strcat(sh->line, " ");
        sh->line = my_strcat(sh->line, sh->cmd_args[i]);
    }
    sh->cmds = parse_commands(sh, sh->line);
    do_repeat(nb_repeat, sh);
    return;
}
