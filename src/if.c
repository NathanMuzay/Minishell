/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** handle if command (tcsh style)
*/

#include "../include/mysh.h"

static int eval_condition(char *expr)
{
    return (my_strcmp(expr, "1") == 0);
}

static char **extract_cmd(char **args, int start, int end)
{
    char **new_cmd = NULL;
    int len = 0;
    int j = 0;

    len = end - start;
    new_cmd = malloc(sizeof(char *) * (len + 1));
    if (new_cmd == NULL)
        return NULL;
    for (int i = start; i < end; i++) {
        new_cmd[j] = my_strdup(args[i]);
        j++;
    }
    new_cmd[j] = NULL;
    return new_cmd;
}

static void execute_condition(mysh_t *sh, int start, int end)
{
    char **cmd = NULL;

    if (start < end) {
        cmd = extract_cmd(sh->cmd_args, start, end);
        if (cmd != NULL) {
            shell_simple_command(sh, cmd);
            free_array(cmd);
        }
    }
}

static void condition(mysh_t *sh, int then_index, int else_index,
    int condition_result)
{
    if (condition_result)
        return execute_condition(sh, then_index + 1,
            (else_index == -1 ? my_arrlen(sh->cmd_args) : else_index));
    else if (else_index != -1)
        return execute_condition(sh, else_index + 1, my_arrlen(sh->cmd_args));
}

void handle_if_command(mysh_t *sh)
{
    int then_index = -1;
    int else_index = -1;
    int condition_result = 0;

    if (!sh->cmd_args || !sh->cmd_args[1]) {
        sh->status = BAD_COMMAND;
        return;
    }
    condition_result = eval_condition(sh->cmd_args[1]);
    for (int i = 2; sh->cmd_args[i]; i++) {
        if (my_strcmp(sh->cmd_args[i], "then") == 0)
            then_index = i;
        if (my_strcmp(sh->cmd_args[i], "else") == 0)
            else_index = i;
    }
    if (then_index == -1) {
        sh->status = BAD_COMMAND;
        return;
    }
    return condition(sh, then_index, else_index, condition_result);
}

int my_arrlen(char **array)
{
    int i = 0;

    if (!array)
        return 0;
    while (array[i])
        i++;
    return i;
}

int valid_wi(mysh_t *sh)
{
    if (my_strcmp(sh->cmd_args[0], "if") == 0) {
        handle_if_command(sh);
        return 1;
    }
    if (my_strcmp(sh->cmd_args[0], "where") == 0) {
        handle_where_command(sh);
        return 1;
    }
    return 0;
}
