/*
** EPITECH PROJECT, 2025
** 42sh
** File description:
** shell
*/

#include "../include/mysh.h"

const builtins_t builtins[] = {
    {"cd", my_cd},
    {"setenv", my_setenv},
    {"unsetenv", my_unsetenv},
    {"env", my_env},
    {"exit", my_exit},
    {"alias", set_alias},
    {"history", history_display},
    {"repeat", repeat},
    {"fortune", fortune},
    {"chaos", chaos},
    {"peda", peda},
    {"set", my_set},
    {"unset", my_unset},
    {NULL, NULL}
};

static void core_dump_management(mysh_t *sh, int signal)
{
    char *msg = NULL;

    if (signal != SIGPIPE){
        msg = strdup(strsignal(signal));
        switch (signal){
            case SIGFPE:
            my_printf("Floating exception");
            break;
            case SIGSEGV:
            my_printf("Segmentation fault");
            break;
            default:
            my_printf("%s", msg);
            break;
        }
        if (WCOREDUMP(sh->status))
            my_putstr(" (core dumped)");
        my_putchar('\n');
        free(msg);
    }
}

void shell_catch_status(mysh_t *sh, pid_t pid)
{
    int signal = 0;

    waitpid(pid, &sh->status, 0);
    if (WIFEXITED(sh->status))
        sh->status = WEXITSTATUS(sh->status);
    else if (WIFSIGNALED(sh->status)){
        signal = WTERMSIG(sh->status);
        core_dump_management(sh, signal);
        sh->status = signal + 128;
    }
}

void shell_execute_command(mysh_t *sh, char **cmd)
{
    if (my_strncmp(cmd[0], "./", 2) != 0)
        sh->cmd_path = strdup(cmd[0]);
    else
        sh->cmd_path = my_strdup(cmd[0]);
    if (execvp(sh->cmd_path, cmd) == -1){
        switch (errno){
            case EACCES:
            my_printf("%s%s\n", cmd[0], ": Permission denied.");
            break;
            case ENOEXEC:
            my_printf("%s%s\n", cmd[0],
                ": Exec format error. Binary file not executable.");
            break;
            default:
            my_printf("%s%s\n", cmd[0], ": Command not found.");
            break;
        }
        exit(BAD_COMMAND);
    }
}

void shell_simple_command(mysh_t *sh, char **cmd)
{
    pid_t pid = fork();

    if (pid == 0){
        redirection_handler(sh);
        shell_execute_command(sh, cmd);
    } else {
        shell_catch_status(sh, pid);
    }
}

static void shell_execute(mysh_t *sh)
{
    int is_pipe = 0;

    for (int i = 0; sh->cmd_args[i] != NULL; i++)
        if (my_strcmp(sh->cmd_args[i], "|") == 0){
            is_pipe = 1;
            break;
        }
    if (is_pipe != 1)
        shell_simple_command(sh, sh->cmd_args);
    else {
        for (int a = 0; sh->commands[a]; a++) {
            execute_piped_commands(sh->commands[a], sh);
        }
        shell_catch_status(sh, sh->pipefd[0]);
        shell_catch_status(sh, sh->pipefd[1]);
    }
}

void shell_handle_builtins(mysh_t *sh)
{
    if (is_arg_empty(sh->line) == 1)
        return;
    if (sh->cmd_args && sh->cmd_args[0][0] == '!'){
        flag_history(sh);
        return;
    }
    if (valid_wi(sh) == 1 || is_alias(sh) == 1)
        return;
    for (int i = 0; builtins[i].cmd != NULL; i++){
        if (my_strcmp(sh->cmd_args[0], builtins[i].cmd) == 0){
            builtins[i].function(sh);
            return;
        }
    }
    shell_execute(sh);
    redirection_close(sh);
}

void shell_process_commands(mysh_t *sh)
{
    char **expanded = NULL;

    for (int i = 0; sh->cmds[i].cmd != NULL; i++){
        sh->line = strdup(sh->cmds[i].cmd);
        sh->line = clean_str(sh->line);
        sh->cmd_args = quotes(sh->cmds, sh->line, i);
        if (sh->cmd_args && sh->cmd_args[0]) {
            expanded = globbings(sh->cmd_args);
            free_array(sh->cmd_args);
            sh->cmd_args = strdup_array(expanded, 1, NULL);
            free_args(expanded);
        }
        if (sh->cmds[i].separator == BRACKETS)
            brackets(sh);
        else
            shell_handle_builtins(sh);
        if ((sh->cmds[i].separator == AND && sh->status != SUCCESS) ||
            (sh->cmds[i].separator == OR && sh->status == SUCCESS))
            break;
    }
}

/*
long seconds;
long useconds;

gettimeofday(&sh->start, NULL);

gettimeofday(&sh->end, NULL);
seconds = sh->end.tv_sec - sh->start.tv_sec;
useconds = sh->end.tv_usec - sh->start.tv_usec;
printf("Command took %.5f seconds\n", seconds + useconds / 1000000.0);*/
