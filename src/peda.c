/*
** EPITECH PROJECT, 2025
** B-PSU-200-MAR-2-1-42sh-pierre-alexandre.mondoloni
** File description:
** peda
*/

#include "../include/mysh.h"

void peda(mysh_t *sh)
{
    int fd = open("peda.txt", O_RDONLY);
    struct stat st;
    char *buf;

    sh = sh;
    if (fd < 0 || fstat(fd, &st) < 0)
        return;
    buf = malloc(st.st_size + 1);
    if (!buf)
        return (void)close(fd);
    if (read(fd, buf, st.st_size) != st.st_size)
        return (void)(free(buf), close(fd));
    buf[st.st_size] = '\0';
    printf("%s\n", buf);
    free(buf);
    close(fd);
    return;
}
