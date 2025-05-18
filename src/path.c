/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** path
*/

#include "../include/mysh.h"

char *path_building(char *PATH, char *full_path, char *cmd)
{
    while (PATH != NULL){
        full_path = malloc((my_strlen(PATH) + my_strlen(cmd) + 2));
        full_path = my_strcpy(full_path, PATH);
        full_path = my_strcat(full_path, "/");
        full_path = my_strcat(full_path, cmd);
        if (access(full_path, X_OK) == 0)
            return full_path;
        PATH = strtok(NULL, ":");
    }
    return cmd;
}

char *path_from_file(mysh_t *sh, char *PATH, int fd)
{
    PATH = malloc(sizeof(char) * (sh->sb.st_size + 1));
    read(fd, PATH, sh->sb.st_size);
    close(fd);
    PATH[sh->sb.st_size] = '\0';
    PATH += 6;
    PATH = my_revstr(PATH);
    PATH += 2;
    PATH = my_revstr(PATH);
    PATH = strtok(PATH, ":");
    return PATH;
}

char *path_get_full_cmd(mysh_t *sh, char *cmd, char **env)
{
    char *PATH = NULL;
    char *full_path = NULL;
    int path_found = 0;
    int fd = open("/etc/environment", O_RDONLY);

    if (fd == -1 || stat("/etc/environment", &sh->sb) == -1)
        return cmd;
    for (int i = 0; env[i] != NULL; i++){
        if (my_strncmp(env[i], "PATH=", 5) == 0){
            PATH = my_strdup(env[i]);
            path_found = 1;
        }
    }
    if (path_found == 1){
        PATH += 5;
        PATH = strtok(PATH, ":");
    } else {
        PATH = path_from_file(sh, PATH, fd);
    }
    return path_building(PATH, full_path, cmd);
}
