/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** cd builtin
*/

#include "../include/mysh.h"

char *get_home_path(mysh_t *sh)
{
    char *home_path = NULL;

    for (int i = 0; sh->env[i] != NULL; i++){
        if (my_strncmp("HOME=", sh->env[i], 5) == 0){
            home_path = my_strdup(sh->env[i]);
            home_path += 5;
            return home_path;
        }
    }
    return NULL;
}

char *truncate_path(char *path, size_t size)
{
    char *new_path = malloc(sizeof(char) * size);
    int last_slash_index = 0;

    new_path = my_strcpy(new_path, path);
    for (int i = 0; new_path[i] != '\0'; i++){
        if (new_path[i] == '/')
            last_slash_index = i;
    }
    new_path[last_slash_index + 1] = '\0';
    return new_path;
}

static void is_home_dir(mysh_t *sh, char *new_dir)
{
    if (my_strcmp(new_dir, sh->curr_dir) != 0) {
        sh->last_dir = my_strdup(sh->curr_dir);
        chdir(new_dir);
        getcwd(sh->curr_dir, sh->path_size);
    }
}

int not_a_dir_cd(mysh_t *sh, char **args)
{
    char *new_dir = NULL;

    if (my_strcmp(args[1], "-") == 0){
        chdir(sh->last_dir);
        sh->last_dir = my_strdup(sh->curr_dir);
        getcwd(sh->curr_dir, sh->path_size);
        return SUCCESS;
    } else if (my_strcmp(args[1], "..") == 0){
        new_dir = truncate_path(sh->curr_dir, sh->path_size);
        is_home_dir(sh, new_dir);
        free(new_dir);
        return SUCCESS;
    }
    return ERROR;
}

void two_args_cd(mysh_t *sh, char **args)
{
    struct stat sb;

    if (not_a_dir_cd(sh, args) == SUCCESS){
        sh->status = SUCCESS;
        return;
    }
    if (stat(args[1], &sb) == 0 && S_ISDIR(sb.st_mode) != 1){
        my_printf("%s%s\n", args[1], ": Not a directory.");
        sh->status = BAD_COMMAND;
    } else if (chdir(args[1]) == -1){
        my_printf("%s%s\n", args[1], ": No such file or directory.");
        sh->status = BAD_COMMAND;
    } else {
        sh->last_dir = my_strdup(sh->curr_dir);
        getcwd(sh->curr_dir, sh->path_size);
        sh->status = SUCCESS;
    }
}

void my_cd(mysh_t *sh)
{
    char **args = space_to_array(sh->line);
    int nb_args = count_lines_array(args);
    char *home_path = get_home_path(sh);

    if (nb_args > 2){
        my_printf("cd: Too many arguments.\n");
        free_array(args);
        sh->status = BAD_COMMAND;
        return;
    }
    if (nb_args == 1 || my_strcmp(args[1], "~") == 0){
        chdir(home_path);
        sh->last_dir = my_strdup(sh->curr_dir);
        getcwd(sh->curr_dir, sh->path_size);
        sh->status = SUCCESS;
    } else if (nb_args == 2){
        two_args_cd(sh, args);
    }
    free_array(args);
}
