/*
** EPITECH PROJECT, 2025
** cd
** File description:
** cd
*/

#include "include/my.h"

static char *expand_tilde(char *arg, char *home)
{
    char *result;

    if (!home) {
        write(2, "cd: HOME not set\n", 18);
        return NULL;
    }
    result = malloc(my_strlen(home) + my_strlen(arg));
    if (!result)
        return NULL;
    my_strcpy(result, home);
    my_strcat(result, arg + 1);
    return result;
}

static char *get_oldpwd(char *oldpwd)
{
    if (!oldpwd) {
        write(2, "cd: OLDPWD not set\n", 20);
        return NULL;
    }
    return oldpwd;
}

static char *get_home_dir(char *home)
{
    if (!home) {
        write(2, "cd: HOME not set\n", 18);
        return NULL;
    }
    return home;
}

char *get_target_dir(char **args, char **env, char *oldpwd)
{
    char *home = my_getenv("HOME", env);

    if (!args[1] || my_strcmp(args[1], "~") == 0)
        return get_home_dir(home);
    if (my_strcmp(args[1], "-") == 0)
        return get_oldpwd(oldpwd);
    if (args[1][0] == '~')
        return expand_tilde(args[1], home);
    return args[1];
}

int my_cd(char **args, char **env)
{
    static char *oldpwd = NULL;
    char *target = NULL;
    char *new_pwd = NULL;

    target = get_target_dir(args, env, oldpwd);
    if (!target)
        return 1;
    if (args[1] && my_strcmp(args[1], "-") == 0 && oldpwd)
        my_printf("%s\n", oldpwd);
    new_pwd = getcwd(NULL, 0);
    if (chdir(target) != 0) {
        perror("cd");
        free(new_pwd);
        return 1;
    }
    if (oldpwd)
        free(oldpwd);
    oldpwd = new_pwd;
    return 0;
}
