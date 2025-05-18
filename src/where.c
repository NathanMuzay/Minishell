/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** handle where command (tcsh style)
*/

#include "../include/mysh.h"

static void display_paths(char *command, char **paths)
{
    char *full_path = NULL;
    struct stat sb;

    for (int i = 0; paths[i] != NULL; i++) {
        full_path = malloc(sizeof(char) * (my_strlen(paths[i]) +
            my_strlen(command) + 2));
        if (full_path == NULL)
            return;
        my_strcpy(full_path, paths[i]);
        my_strcat(full_path, "/");
        my_strcat(full_path, command);
        if (stat(full_path, &sb) == 0 && (sb.st_mode & S_IXUSR))
            my_printf("%s\n", full_path);
        free(full_path);
    }
}

void handle_where_command(mysh_t *sh)
{
    char **paths = NULL;

    if (!sh->cmd_args || !sh->cmd_args[1]) {
        my_printf("Usage: where <command>\n");
        sh->status = BAD_COMMAND;
        return;
    }
    paths = my_str_to_word_array_delim(getenv("PATH"), ':');
    if (paths == NULL)
        return;
    display_paths(sh->cmd_args[1], paths);
    free_array(paths);
}
