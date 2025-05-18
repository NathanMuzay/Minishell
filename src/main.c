/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** main
*/

#include "../include/mysh.h"

static void shell_init2(mysh_t *sh)
{
    sh->cmds = NULL;
    sh->brackets_cmds = NULL;
    sh->in = calloc(sizeof(i_t), sizeof(int));
    sh->nb_brackets = 0;
    sh->cmd_index = 0;
    sh->locals = NULL;
    sh->tmp = NULL;
    sh->interactive_input = isatty(STDIN_FILENO);
}

static void shell_init(mysh_t *sh, char **env)
{
    sh->env = strdup_array(env, 0, NULL);
    sh->local_env = malloc(sizeof(char *) * 1);
    sh->local_env[0] = NULL;
    sh->line = NULL;
    sh->line_size = 0;
    sh->cmd_path = NULL;
    sh->cmd_args = NULL;
    sh->status = SUCCESS;
    sh->path_size = 4095;
    sh->curr_dir = malloc(sizeof(char) * sh->path_size);
    getcwd(sh->curr_dir, sh->path_size);
    sh->last_dir = my_strdup(sh->curr_dir);
    sh->is_redirect = 0;
    sh->history = malloc(sizeof(history_t));
    sh->id_command = 0;
    sh->alias = NULL;
    sh->current_history_index = 0;
    sh->brackets = 0;
    sh->index_pid = 0;
    shell_init2(sh);
}

void shell_display_prompt(mysh_t *sh)
{
    my_printf(BOLD COLOR_MAGENTA "[" COLOR_RESET);
    my_printf(BOLD COLOR_BLUE "suicide" COLOR_RESET);
    my_printf(BOLD "@");
    my_printf(BOLD COLOR_RED "squad" COLOR_RESET);
    my_printf(BOLD COLOR_MAGENTA"]" COLOR_RESET);
    my_printf(BOLD ":" "%s", sh->curr_dir);
    my_printf(BOLD COLOR_YELLOW "$> " COLOR_RESET);
}

static int shell_process_input(mysh_t *sh)
{
    char *temp = NULL;

    sh->line_size = my_getline(&sh->line, &sh->line_size, stdin, sh);
    if (sh->line_size == (size_t)-1) {
        if (isatty(STDIN_FILENO))
            my_putchar('\n');
        return ERROR;
    }
    sh->line = strdup(delete_newline(sh->line));
    if (is_end_separator(sh->line) == 1 || check_matching(sh->line) == 1)
        return BAD_COMMAND;
    if (check_matching(sh->line) == 1)
        return BAD_COMMAND;
    sh->separated_space = space_to_array(sh->line);
    parsing(sh);
    sh->commands = split_by_semicolon(sh->line);
    history_update(sh);
    shell_process_commands(sh);
    return sh->status;
}

void ctrlc(int sig)
{
    (void)sig;
}

int minishell(char **env)
{
    mysh_t sh;
    int status = SUCCESS;

    shell_init(&sh, env);
    signal(SIGINT, ctrlc);
    while (42) {
        sh.mere = NONE;
        if (isatty(STDIN_FILENO))
            shell_display_prompt(&sh);
        if (shell_process_input(&sh) == ERROR){
            status = sh.status;
            free_shell(&sh);
            break;
        }
    }
    status = sh.status;
    return status;
}

int main(int ac, char **av, char **env)
{
    (void)ac;
    (void)av;
    return minishell(env);
}
