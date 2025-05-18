/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-42sh-pierre-alexandre.mondoloni
** File description:
** backticks
*/

#include "../include/mysh.h"

char *clear_str(char *str)
{
    char *result = malloc(sizeof(char) * strlen(str) + 1);
    int j = 0;

    if (strchr(str, '\n') == NULL) {
        result = strdup(str);
        return result;
    }
    for (int i = 0; str[i]; i++) {
        if (str[i] != '\n') {
            result[j] = str[i];
            j++;
        }
        if (str[i] == '\n') {
            result[j] = ' ';
            j++;
        }
    }
    free(str);
    result[j] = '\0';
    return result;
}

int exequing(int *fd, char *str)
{
    char **stock = NULL;

    close(fd[0]);
    stock = space_to_array(clean_str(str));
    dup2(fd[1], STDOUT_FILENO);
    dup2(fd[1], STDERR_FILENO);
    close(fd[1]);
    if (execvp(stock[0], stock) == -1) {
        free_args(stock);
        return 1;
    }
    free_args(stock);
    return 0;
}

int getting_output(int *fd, char *result)
{
    ssize_t size = 0;

    close(fd[1]);
    size = read(fd[0], result, BUFSIZ - 1);
    if (size < 1)
        return 1;
    result[size] = '\0';
    close(fd[0]);
    return 0;
}

char *backtick_management(char *str)
{
    pid_t pid;
    int fd[2];
    char *result = malloc(sizeof(char) * BUFSIZ);
    char *output = NULL;
    int status = 0;

    if (pipe(fd) == -1) {
        exit(84);
    }
    pid = fork();
    if (pid == 0) {
        status = exequing(fd, str);
    } else {
        if (getting_output(fd, result) == 1)
            return NULL;
    }
    if (status == 1)
        return result;
    output = clear_str(result);
    return output;
}
