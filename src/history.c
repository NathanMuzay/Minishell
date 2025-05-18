/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** history
*/

#include "../include/mysh.h"

void history_update(mysh_t *sh)
{
    time_t t = time(NULL);
    struct tm *tmp = localtime(&t);

    sh->history = realloc(sh->history, sizeof(history_t) *
    (sh->id_command + 2));
    if (sh->line[sh->line_size - 1] != '\0')
        sh->line[sh->line_size - 1] = '\0';
    sh->history[sh->id_command].cmd = strdup(sh->line);
    sh->history[sh->id_command].hour = tmp->tm_hour;
    sh->history[sh->id_command].min = tmp->tm_min;
    sh->history[sh->id_command].id = sh->id_command;
    sh->current_history_index = sh->id_command;
    if (sh->line[0] != '!')
        sh->id_command++;
}

void simple_history(mysh_t *sh)
{
    int nb_command = atoi(sh->line + 1);

    sh->cmd_args = space_to_array(sh->line);
    if (nb_command > sh->id_command || nb_command == 0) {
        my_printf("%d: Event not found.\n", nb_command);
        return;
    }
    if (sh->cmd_args[0])
        free(sh->cmd_args[0]);
    sh->cmd_args[0] = strdup(sh->history[nb_command - 1].cmd);
    for (int i = 0; sh->cmd_args[i] != NULL; i++)
        write(1, sh->cmd_args[i], strlen(sh->cmd_args[i]));
    write(1, "\n", 1);
    sh->line = sh->cmd_args[0];
    history_update(sh);
    shell_handle_builtins(sh);
}

void flag_history(mysh_t *sh)
{
    if (my_isdigit(sh->cmd_args[0][1]) == 1) {
        simple_history(sh);
        return;
    }
    if (sh->cmd_args[0][1] == '!') {
        double_history(sh);
        return;
    }
    return;
}

void double_history(mysh_t *sh)
{
    sh->cmd_args = space_to_array(sh->line);
    if (sh->id_command == 0) {
        my_printf("%d: Event not found.\n", 0);
        return;
    }
    if (sh->cmd_args[0])
        free(sh->cmd_args[0]);
    sh->cmd_args[0] = strdup(sh->history[sh->id_command - 1].cmd);
    for (int i = 0; sh->cmd_args[i] != NULL; i++)
        write(1, sh->cmd_args[i], strlen(sh->cmd_args[i]));
    write(1, "\n", 1);
    shell_handle_builtins(sh);
}

void history_display(mysh_t *sh)
{
    char **args = space_to_array(sh->line);

    if (!args[1] || args[0][1] == 0) {
        for (int i = 0; i < sh->id_command; i++)
        printf("\t%d  %d:%d   %s\n", sh->history[i].id + 1,
            sh->history[i].hour, sh->history[i].min, sh->history[i].cmd);
        return;
    }
    if (args[1][1] == 'h') {
        for (int i = 0; i < sh->id_command; i++)
            printf("%s\n", sh->history[i].cmd);
    }
    if (args[1][1] == 'r') {
        for (int r = sh->id_command - 1; r >= 0; r--) {
        printf("\t%d  %d:%d   %s\n", sh->history[r].id + 1,
            sh->history[r].hour, sh->history[r].min, sh->history[r].cmd);
        }
    }
    free_args(args);
}
