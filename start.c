/*
** EPITECH PROJECT, 2025
** minishell
** File description:
** minishell start
*/

#include "include/my.h"

char *my_getenv(const char *name, char **env)
{
    int len = my_strlen(name);

    for (int i = 0; env[i]; i++) {
        if (my_strncmp(env[i], name, len) == 0 && env[i][len] == '=')
            return env[i] + len + 1;
    }
    return NULL;
}

static int contains(const char *str, char sep)
{
    while (*str) {
        if (*str == sep)
            return 1;
        str++;
    }
    return 0;
}

void args_actu(char *input, char **args)
{
    int i = 0;
    char *token = strtok(input, " \t\n");

    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
}

static char *get_cmd_path(char *cmd, char **env)
{
    char *path = my_getenv("PATH", env);
    char *token;
    char *full_path;

    if (contains(cmd, '/'))
        return my_strdup(cmd);
    if (!path)
        return NULL;
    token = strtok(path, ":");
    while (token) {
        full_path = malloc(my_strlen(token) + my_strlen(cmd) + 2);
        my_strcpy(full_path, token);
        my_strcat(full_path, "/");
        my_strcat(full_path, cmd);
        if (access(full_path, X_OK) == 0)
            return full_path;
        free(full_path);
        token = strtok(NULL, ":");
    }
    return NULL;
}

void execute_command(char **args, char **env, var_t *f)
{
    pid_t pid = fork();
    int status = 0;
    char *cmd_path;

    if (pid < 0) {
        write(2, "fork error\n", 11);
        return;
    }
    if (pid == 0) {
        handle_redirections(args);
        cmd_path = get_cmd_path(args[0], env);
        if (!cmd_path) {
            my_printf("%s: Command not found\n", args[0]);
            exit(1);
        }
        execve(cmd_path, args, env);
        write(2, "execve error\n", 13);
        exit(84);
    } else
        staaatus(pid, status, f);
}

static void execute_piped_commands(char *cmd_line, char **env, var_t *f)
{
    char *commands[100];
    char *save = NULL;
    int prev_fd = -1;

    f->cmd_count = 0;
    commands[f->cmd_count] = strtok_r(cmd_line, "|", &save);
    while (commands[f->cmd_count]) {
        f->cmd_count++;
        commands[f->cmd_count] = strtok_r(NULL, "|", &save);
    }
    for (f->i = 0; f->i < f->cmd_count; f->i++)
        handle_pipe_process(f, &prev_fd, commands[f->i], env);
    for (int i = 0; i < f->cmd_count; i++)
        wait(NULL);
}

static void handle_pipes_redirections(char *input, char **env, var_t *f)
{
    char *args[100];
    char *cmd_copy;

    for (char *cmd = strtok_r(input, ";", &f->save_ptr1); cmd;
        cmd = strtok_r(NULL, ";", &f->save_ptr1)) {
        cmd_copy = my_strdup(cmd);
        if (contains(cmd_copy, '|') == 1) {
            execute_piped_commands(cmd_copy, env, f);
            free(cmd_copy);
            continue;
        }
        args_actu(cmd_copy, args);
        if (args[0] && my_strcmp(args[0], "cd") == 0)
            my_cd(args, env);
        else
            execute_command(args, env, f);
        free(cmd_copy);
    }
}

static char *read_input(var_t *f)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    if (f->input != NULL)
        free(f->input);
    nread = getline(&line, &len, stdin);
    if (nread == -1) {
        write(2, "getline error\n", 14);
        free(line);
        return NULL;
    }
    return line;
}

int main(int argc, char **argv, char **envp)
{
    var_t *f = malloc(sizeof(var_t));

    if (!f) {
        write(2, "malloc error\n", 13);
        return 84;
    }
    while (1) {
        write(1, "$> ", 3);
        f->input = read_input(f);
        if (f->input == NULL) {
            free(f);
            return 84;
        }
        if (my_strcmp(f->input, "exit\n") == 0) {
            free(f->input);
            return f->statut;
        }
        handle_pipes_redirections(f->input, envp, f);
    }
}
