/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-42sh-pierre-alexandre.mondoloni
** File description:
** parsing
*/

#include "../include/mysh.h"

static char *management(commands_t *cmds, mysh_t *sh, char *before,
    bool backticks)
{
    char *temp = NULL;
    char *concat = NULL;

    temp = strdup(cmds[sh->cmd_index].cmd);
    free(cmds[sh->cmd_index].cmd);
    if (backticks)
        cmds[sh->cmd_index].cmd = strdup(backtick_management(temp));
    else
        cmds[sh->cmd_index].cmd = strdup(temp);
    free(temp);
    concat = malloc(sizeof(char) * (strlen(cmds[sh->cmd_index].cmd) +
    strlen(before) + 1));
    concat[0] = '\0';
    strcat(concat, before);
    free(before);
    if (cmds[sh->cmd_index].cmd != NULL)
        strcat(concat, cmds[sh->cmd_index].cmd);
    free(cmds[sh->cmd_index].cmd);
    return concat;
}

static void before_management(char **before, int *index, char *str)
{
    int i = *index;
    int j = 0;

    while (str[i] != '`' && str[i] != '\0') {
        i++;
        j++;
    }
    *before = malloc(sizeof(char) * (j + 1));
    i = *index;
    for (int k = 0; str[i] != '`' && str[i] != '\0'; k++) {
        (*before)[k] = str[i];
        i++;
    }
    (*before)[j] = '\0';
}

void parse_dquotes(commands_t *cmds, mysh_t *sh, char *str, int *index)
{
    char *before = NULL;

    before_management(&before, index, str);
    if (str[*index] == '"')
        (*index)++;
    cmds[sh->cmd_index].cmd = malloc(sizeof(char) * strlen(str) + 1);
    sh->cmd_pos = 0;
    for (; str[*index] != '\0' && str[*index] != '"'; (*index)++){
        cmds[sh->cmd_index].cmd[sh->cmd_pos] = str[*index];
        sh->cmd_pos++;
    }
    cmds[sh->cmd_index].cmd[sh->cmd_pos] = '\0';
    cmds[sh->cmd_index].cmd = strdup(management(cmds, sh, before, 0));
    cmds[sh->cmd_index].separator = DOUBLE_QUOTES;
    cmds[sh->cmd_index].mother = sh->mere;
    cmds[sh->cmd_index].next = NONE;
    sh->cmd_index++;
    if (str[*index] == '"')
        (*index) += 1;
}

void parse_backtick(commands_t *cmds, mysh_t *sh, char *str, int *index)
{
    char *before = NULL;

    before_management(&before, index, str);
    if (str[*index] == '`')
        (*index)++;
    cmds[sh->cmd_index].cmd = malloc(sizeof(char) * strlen(str) + 1);
    sh->cmd_pos = 0;
    for (; str[*index] != '\0' && str[*index] != '`'; (*index)++){
        cmds[sh->cmd_index].cmd[sh->cmd_pos] = str[*index];
        sh->cmd_pos++;
    }
    cmds[sh->cmd_index].cmd[sh->cmd_pos] = '\0';
    cmds[sh->cmd_index].cmd = strdup(management(cmds, sh, before, 1));
    cmds[sh->cmd_index].separator = BACKTICKS;
    cmds[sh->cmd_index].mother = sh->mere;
    cmds[sh->cmd_index].next = NONE;
    sh->cmd_index++;
    if (str[*index] == '`')
        (*index) += 1;
}

void parse_logic(parse_ctx_t *ctx, char delim, separator_t sep, int advance)
{
    if (ctx->str[*ctx->index] == delim)
        (*ctx->index)++;
    ctx->cmds[ctx->sh->cmd_index].cmd = malloc(sizeof(char) * (
    strlen(ctx->str) + 1));
    ctx->sh->cmd_pos = 0;
    for (; ctx->str[*ctx->index] && ctx->str[*ctx->index] != delim;
        (*ctx->index)++) {
        ctx->cmds[ctx->sh->cmd_index].cmd[ctx->sh->cmd_pos] =
        ctx->str[*ctx->index];
        ctx->sh->cmd_pos++;
    }
    ctx->cmds[ctx->sh->cmd_index].cmd[ctx->sh->cmd_pos] = '\0';
    ctx->cmds[ctx->sh->cmd_index].separator = sep;
    ctx->cmds[ctx->sh->cmd_index].mother = ctx->sh->mere;
    ctx->cmds[ctx->sh->cmd_index].next = NONE;
    ctx->sh->cmd_index++;
    if (ctx->str[*ctx->index] == delim && ctx->str[*ctx->index + 1] == delim)
        (*ctx->index) += advance;
    else if (ctx->str[*ctx->index] == delim)
        (*ctx->index) += advance;
}

static int bracket_counters(commands_t *cmds)
{
    int count = 0;
    int brackets = 0;

    for (int i = 0; cmds[i].cmd != NULL; i++) {
        if (cmds[i].separator == BRACKETS)
            brackets++;
        count++;
    }
    if (brackets == 0)
        return 0;
    return count;
}

void parsing(mysh_t *sh)
{
    int count = 0;
    int k = 0;

    sh->cmds = parse_commands(sh, sh->line);
    count = bracket_counters(sh->cmds);
    if (count > 0)
        sh->brackets_cmds = malloc(sizeof(commands_t *) * (count + 1));
    for (int i = 0; sh->cmds[i].cmd; i++) {
        if (sh->cmds[i].separator == BRACKETS) {
            sh->mere = BRACKETS;
            sh->brackets_cmds[k] = parse_commands(sh, sh->cmds[i].cmd);
            sh->brackets_cmds[k]
            [tab_count(sh->brackets_cmds[k]) - 1].next = LAST;
            k++;
        }
    }
    if (sh->brackets_cmds != NULL) {
        sh->brackets_cmds[k] = NULL;
    }
}
