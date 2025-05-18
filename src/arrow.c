/*
** EPITECH PROJECT, 2025
** arrow
** File description:
** recode de arrow
*/

#include "../include/mysh.h"


size_t handle_arrow(char **lineptr, size_t *n, FILE *stream, mysh_t *sh)
{
    int c2 = fgetc(stream);
    int c3 = fgetc(stream);

    if (c2 == '[' && c3 == 'A') {
        *n = up_arrow(lineptr, n, sh);
        return *n;
    }
    if (c2 == '[' && c3 == 'B') {
        *n = down_arrow(lineptr, n, sh);
        return *n;
    }
    if (c2 == '[' && c3 == 'C') {
        right_arrow(sh);
        return *n;
    }
    if (c2 == '[' && c3 == 'D') {
        left_arrow(sh);
        return *n;
    }
    return 0;
}

size_t up_arrow(char **lineptr, size_t *n, mysh_t *sh)
{
    if (sh->current_history_index < 0) {
        return 0;
    }
    free(*lineptr);
    *lineptr = strdup(sh->history[sh->current_history_index].cmd);
    *n = strlen(sh->history[sh->current_history_index].cmd);
    *lineptr = realloc(*lineptr, (*n) + 1);
    sh->current_history_index--;
    write(1, "\33[2K\r", 5);
    shell_display_prompt(sh);
    write(1, *lineptr, *n);
    return *n;
}

size_t down_arrow(char **lineptr, size_t *n, mysh_t *sh)

{
    if (sh->current_history_index >= sh->id_command - 1) {
        return 0;
    }
    free(*lineptr);
    *lineptr = strdup(sh->history[sh->current_history_index].cmd);
    *n = strlen(sh->history[sh->current_history_index].cmd);
    *lineptr = realloc(*lineptr, (*n) + 1);
    sh->current_history_index++;
    write(1, "\33[2K\r", 5);
    shell_display_prompt(sh);
    write(1, *lineptr, *n);
    return *n;
}

void right_arrow(mysh_t *sh)
{
    if (sh->cursor < (int)sh->line_size) {
        write(1, "\033[C", 3);
        (sh->cursor)++;
    }
}

void left_arrow(mysh_t *sh)
{
    if (sh->cursor > 0) {
        write(1, "\033[D", 3);
        (sh->cursor)--;
    }
}
