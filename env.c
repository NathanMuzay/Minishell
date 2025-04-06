/*
** EPITECH PROJECT, 2025
** env
** File description:
** env
*/

#include "include/my.h"

void my_env(char **env)
{
    if (env == NULL)
        exit(84);
    for (int i = 0; env[i] != NULL; i++){
        write(1, env[i], my_strlen(env[i]));
        write(1, "\n", 1);
    }
}

void parsing_env(char **env, var_t *f)
{
    f->envir = malloc(sizeof(char *) * 1000);
    for (int i = 0; env[i] != NULL; i++){
        f->envir[i] = malloc(sizeof(char) * my_strlen(env[i]));
        for (int k = 0; env[i][k] != '='; k++){
            f->envir[i][k] = env[i][k];
        }
    }
}

int verif_exist(char *name, var_t *f)
{
    f->existe = 0;
    for (int i = 0; f->envir[i] != NULL; i++){
        if (my_strcmp(f->envir[i], name) == 0)
            return i;
    }
    my_printf("the argument : %s, isn't in the environnement\n");
    return -1;
}

void my_setenv(char **env, var_t *f)
{
    env = env;
    f = f;
    return;
}

int my_unsetenv(char **env, var_t *f)
{
    int index = 0;

    if (!f->args[1]){
        perror("Invalid arguments to unsetenv");
        return -1;
    }
    parsing_env(env, f);
    index = verif_exist(f->args[1], f);
    if (index == -1)
        return 0;
    for (int i = index; env[i] != NULL; i++)
        env[i] = env[i + 1];
    return 0;
}
