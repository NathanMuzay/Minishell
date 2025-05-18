/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** free
*/

#include "../include/mysh.h"

void free_array(char **array)
{
    int i = 0;

    if (array == NULL)
        return;
    for (i = 0; array[i] != NULL; i++) {
        free(array[i]);
        array[i] = NULL;
    }
    free(array);
}

static void free_alias_list(alias_t *alias)
{
    alias_t *tmp;

    while (alias) {
        tmp = alias->next;
        free(alias->command_base);
        free(alias->new_name);
        free(alias);
        alias = tmp;
    }
}

static void free_history(history_t *history, int size)
{
    for (int i = 0; i < size; i++)
        free(history[i].cmd);
    free(history);
}

static void free_commands(commands_t *cmds, int count)
{
    if (!cmds)
        return;
    for (int i = 0; i < count; i++)
        free(cmds[i].cmd);
    free(cmds);
}

static void free_brackets_cmds(commands_t **brackets_cmds)
{
    if (!brackets_cmds)
        return;
    for (int i = 0; brackets_cmds[i]; i++) {
        for (int j = 0; brackets_cmds[i][j].cmd; j++)
            free(brackets_cmds[i][j].cmd);
        free(brackets_cmds[i]);
    }
    free(brackets_cmds);
}

void free_shell(mysh_t *shell)
{
    free_array(shell->env);
    free_array(shell->local_env);
    free_array(shell->cmd_args);
    free_array(shell->separated_space);
    free_array(shell->commands);
    free(shell->line);
    free(shell->cmd_path);
    free(shell->curr_dir);
    free(shell->last_dir);
    free(shell->in);
    free_commands(shell->cmds, shell->cmd_index);
    free_brackets_cmds(shell->brackets_cmds);
    free_alias_list(shell->alias);
    free_history(shell->history, shell->id_command);
}
