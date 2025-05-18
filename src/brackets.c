/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-42sh-pierre-alexandre.mondoloni
** File description:
** brackets
*/

#include "../include/mysh.h"

void parse_brackets(commands_t *cmds, mysh_t *sh, char *str, int *index)
{
    sh->nb_brackets--;
    sh->in->brackets = 1;
    cmds[sh->cmd_index].cmd = malloc(sizeof(char) * strlen(str) + 1);
    sh->cmd_pos = 0;
    if (str[*index] == '(')
        (*index)++;
    for (; str[*index] != '\0' && str[*index] != ')'; (*index)++){
        cmds[sh->cmd_index].cmd[sh->cmd_pos] = str[*index];
        sh->cmd_pos++;
    }
    cmds[sh->cmd_index].cmd[sh->cmd_pos] = '\0';
    cmds[sh->cmd_index].separator = BRACKETS;
    cmds[sh->cmd_index].mother = BRACKETS;
    cmds[sh->cmd_index].next = NONE;
    sh->cmd_index++;
    if (str[*index] == ')') {
        (*index) += 1;
    }
}

char **quotes(commands_t *cmds, char *str, int i)
{
    char **args = NULL;

    if (cmds[i].separator != SINGLE_QUOTES &&
        cmds[i].separator != DOUBLE_QUOTES)
        args = space_to_array(str);
    else
        args = quotes_to_array(str);
    return args;
}

void brackets_process_cmd(mysh_t *sh)
{
    char **expanded = NULL;
    static int k = 0;

    for (int i = 0; sh->brackets_cmds[k][i].cmd != NULL; i++){
        sh->line = clean_str(strdup(sh->brackets_cmds[k][i].cmd));
        sh->cmd_args = quotes(sh->brackets_cmds[k], sh->line, i);
        if (sh->cmd_args && sh->cmd_args[0]) {
            expanded = globbings(sh->cmd_args);
            free_array(sh->cmd_args);
            sh->cmd_args = strdup_array(expanded, 1, NULL);
            free_array(expanded);
        }
        shell_handle_builtins(sh);
        if ((sh->brackets_cmds[k][i].separator == AND && sh->status != SUCCESS)
        || (sh->brackets_cmds[k][i].separator == OR && sh->status == SUCCESS))
            break;
    }
    k++;
}

void brackets(mysh_t *sh)
{
    pid_t pid = fork();

    if (pid == 0) {
        brackets_process_cmd(sh);
        exit(0);
    } else
        shell_catch_status(sh, pid);
}
