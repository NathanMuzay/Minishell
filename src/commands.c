/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** commands management
*/

#include "../include/mysh.h"

int is_separator(const char *str)
{
    for (int i = 0; str[i] != '\0'; i++){
        if ((str[i] == '|' && str[i + 1] == '|')
        || (str[i] == '&' && str[i + 1] == '&')
        || (str[i] == '(' && strchr(str + i + 1, ')') != NULL)
        || (str[i] == '\'' && strchr(str + i + 1, '\'') != NULL)
        || (str[i] == '"' && strchr(str + i + 1, '"') != NULL &&
        strchr(str, '=') == NULL)
        || (str[i] == '`' && strchr(str + i + 1, '`') != NULL))
            return 1;
    }
    return 0;
}

int is_end_separator(const char *str)
{
    int len = 0;

    if (str == NULL || str[0] == '\0')
        return 1;
    len = strlen(str);
    if (str[len - 1] == '|' || str[len - 1] == '&'
    || (str[len - 2] == '|' || str[len - 2] == '&')
    || str[len - 1] == ';')
        return 1;
    return 0;
}

static int count_nb_separators(const char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] == ';' || (str[i] == '&' && str[i + 1] == '&')
        || (str[i] == '|' && str[i + 1] == '|')
        || (str[i] == '(' && strchr(str + i + 1, ')') != NULL)
        || (str[i] == '\'' && strchr(str + i + 1, '\'') != NULL)
        || (str[i] == '"' && strchr(str + i + 1, '"') != NULL &&
        strchr(str, '=') == NULL)
        || (str[i] == '`' && strchr(str + i + 1, '`') != NULL)){
            count++;
        }
    }
    return count;
}

static void get_last_command(commands_t *cmds, mysh_t *sh, char *str)
{
    char *tmp = my_revstr(str);
    char *token = my_revstr(strtok(tmp, "()\"\'`&&||;"));

    cmds[sh->cmd_index].cmd = strdup(token);
    cmds[sh->cmd_index].separator = NONE;
    cmds[sh->cmd_index].mother = sh->mere;
    cmds[sh->cmd_index].next = NONE;
    cmds[sh->cmd_index + 1].cmd = NULL;
}

static commands_t *simple_separator(commands_t *cmds, mysh_t *sh, char *str)
{
    int index = 0;
    char *token = strtok(str, ";");

    while (token != NULL){
        cmds[index].cmd = strdup(token);
        cmds[index].separator = SEMICOLON;
        cmds[index].mother = sh->mere;
        cmds[index].next = NONE;
        token = strtok(NULL, ";");
        index++;
    }
    cmds[index].cmd = NULL;
    return cmds;
}

static int parse_alot(parse_ctx_t *ctx, int i)
{
    if (ctx->str[i] == '(' && strchr(ctx->str + i + 1, ')') != NULL) {
        parse_brackets(ctx->cmds, ctx->sh, ctx->str, ctx->index);
        return 1;
    }
    if (ctx->str[i] == '\'' && strchr(ctx->str + i + 1, '\'') != NULL
    && ctx->sh->in->squotes == 0) {
        parse_logic(ctx, '\'', SINGLE_QUOTES, 1);
        ctx->sh->in->squotes = 1;
    }
    if (ctx->str[i] == '\"' && strchr(ctx->str + i + 1, '\"') != NULL
    && ctx->sh->in->dquotes == 0 && strchr(ctx->str, '=') == NULL) {
        parse_logic(ctx, '"', DOUBLE_QUOTES, 1);
        ctx->sh->in->dquotes = 1;
    }
    if (ctx->str[i] == '`' && strchr(ctx->str + i + 1, '`') != NULL
    && ctx->sh->in->backticks == 0) {
        parse_backtick(ctx->cmds, ctx->sh, ctx->str, ctx->index);
        ctx->sh->in->backticks = 1;
    }
    return 0;
}

static void reset_inside(parse_ctx_t *ctx, int i)
{
    if (i > 0 && ctx->str[i - 1] == '\'')
        ctx->sh->in->squotes = 0;
    if (i > 0 && ctx->str[i - 1] == '\"')
        ctx->sh->in->dquotes = 0;
    if (i > 0 && ctx->str[i - 1] == '`')
        ctx->sh->in->backticks = 0;
}

void parse_loop(parse_ctx_t *ctx)
{
    reset_parse(ctx->sh);
    for (int i = 0; ctx->str[i] != '\0'; i++){
        reset_inside(ctx, i);
        if (parse_alot(ctx, i) == 1)
            break;
        if (ctx->str[i] == '&' && ctx->str[i + 1] == '&')
            parse_logic(ctx, '&', AND, 2);
        if (ctx->str[i] == '|' && ctx->str[i + 1] == '|')
            parse_logic(ctx, '|', OR, 2);
        if (ctx->str[i] == ';' && ctx->sh->in->brackets == 0 &&
            ctx->sh->in->squotes == 0 && ctx->sh->in->dquotes == 0 &&
            ctx->sh->in->backticks == 0 && ctx->sh->nb_brackets == 0)
            parse_logic(ctx, ';', SEMICOLON, 1);
        if (ctx->str[i] == ')')
            ctx->sh->in->brackets = 0;
    }
}

static int count_brackets(char *str)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == '(') {
            count++;
        }
    }
    return count;
}

commands_t *parse_commands(mysh_t *sh, char *str)
{
    int count = count_nb_separators(str);
    commands_t *cmds = malloc(sizeof(commands_t) * (count + 2));
    int index = 0;
    parse_ctx_t ctx = {cmds, sh, str, &index};

    ctx.sh->nb_brackets = count_brackets(str);
    memset(ctx.cmds, 0, sizeof(commands_t) * (count + 2));
    if (is_separator(ctx.str) == 0 && ctx.sh->mere != BRACKETS){
        return simple_separator(ctx.cmds, ctx.sh, ctx.str);
    }
    ctx.sh->cmd_index = 0;
    ctx.sh->cmd_pos = 0;
    parse_loop(&ctx);
    if ((ctx.sh->cmd_index == 0 ||
        (ctx.cmds[ctx.sh->cmd_index - 1].separator == OR ||
        ctx.cmds[ctx.sh->cmd_index - 1].separator == AND ||
        ctx.cmds[ctx.sh->cmd_index - 1].separator == SEMICOLON)))
        get_last_command(ctx.cmds, ctx.sh, ctx.str);
    return ctx.cmds;
}
