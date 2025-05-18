/*
** EPITECH PROJECT, 2025
** mysh
** File description:
** history
*/

/*#include "../include/mysh.h"

void enable_raw_mode(struct termios *oldt)
{
    struct termios newt;

    tcgetattr(STDIN_FILENO, oldt);
    newt = *oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void disable_raw_mode(struct termios *oldt)
{
    tcsetattr(STDIN_FILENO, TCSANOW, oldt);
}

static size_t getline_action(char **lineptr, FILE *stream,
    mysh_t *sh, int c, size_t *n)
{
    if (c == 27)
        *n = handle_arrow(lineptr, n, stream, sh);
    if (c == 8 || c == 127)
        *n = delete_char(n, lineptr, sh);
    if (c != 27 && c != 8 && c != 127)
        *n = write_char(c, n, lineptr, sh);
    return *n;
}

size_t my_getline(char **lineptr, size_t *n, FILE *stream, mysh_t *sh)
{
    struct termios oldt;
    int c;

    *lineptr = malloc(sizeof(char) * 2);
    *n = 0;
    sh->cursor = 0;
    enable_raw_mode(&oldt);
    c = fgetc(stream);
    while (c != EOF && c != '\n') {
        if (c == 4) {
            my_putchar('\n');
            disable_raw_mode(&oldt);
            exit(84);
        }
        (*n) = getline_action(lineptr, stream, sh, c, n);
        c = fgetc(stream);
    }
    disable_raw_mode(&oldt);
    (*lineptr)[*n] = '\0';
    return *n;
}

size_t delete_char(size_t *n, char **lineptr, mysh_t *sh)
{
    int move_left = 0;
    int i = 0;

    if (sh->cursor <= 0 || *n == 0)
        return *n;
    for (int j = sh->cursor - 1; j < (int)(*n) - 1; j++) {
        (*lineptr)[j] = (*lineptr)[j + 1];
    }
    (*n)--;
    *lineptr = realloc(*lineptr, *n + 1);
    (*lineptr)[*n] = '\0';
    sh->cursor--;
    if (isatty(STDIN_FILENO)) {
        write(1, "\33[2K\r", 5);
        shell_display_prompt(sh);
        write(1, *lineptr, *n);
    }
    move_left = *n - sh->cursor;
    i = move_left - 1;
    while (i > 0)
        write(1, "\033[D", 3);
    return *n;
}

size_t write_char(int c, size_t *n, char **lineptr, mysh_t *sh)
{
    int move_left = 0;
    int i = 0;

    (*n)++;
    *lineptr = realloc(*lineptr, *n + 1);
    for (int j = *n - 1; j > sh->cursor; j--) {
        (*lineptr)[j] = (*lineptr)[j - 1];
    }
    (*lineptr)[sh->cursor] = c;
    if (isatty(STDIN_FILENO)) {
        write(1, "\33[2K\r", 5);
        shell_display_prompt(sh);
        write(1, *lineptr, *n);
    }
    move_left = *n - sh->cursor - 1;
    i = move_left - 1;
    while (i > 0)
        write(1, "\033[D", 3);
    (*lineptr)[*n] = '\0';
    sh->cursor++;
    return *n;
}*/
