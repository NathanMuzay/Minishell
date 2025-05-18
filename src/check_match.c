/*
** EPITECH PROJECT, 2025
** delivery
** File description:
** check_match
*/

#include "../include/mysh.h"

static int bad_carac_check(char c, char b)
{
    if (c != '&' && b != '&' &&
        c != '|' && b != '|' && c != '(' &&
        c != ')' && c != ' ') {
        return 1;
        }
    return 0;
}

int check_spe(char *line, int c, int *delim)
{
    int count = 1;

    (*delim)++;
    for (int i = 0; line[i] != '\0' && line[i] != ';'; i++) {
        if (line[i] == c)
            count++;
    }
    if ((count % 2) != 0) {
        printf("Unmatched '%c'.\n", c);
        return 1;
    }
    return 0;
}

int error_brackets(int count_left, int count_right, int leftovers)
{
    if (leftovers != 0 && count_left > 0 && count_right > 0) {
        printf("Badly placed ()'s.\n");
        return 1;
    }
    if (count_left > count_right) {
        printf("Too many ('s.\n");
        return 1;
    }
    if (count_right > count_left) {
        printf("Too many )'s.\n");
        return 1;
    }
    return 0;
}

static void check_conditions(char c, int *count_left,
    int *count_right, int *count_semi)
{
    if (c == '(')
            (*count_left)++;
    if (c == ')') {
        (*count_right)++;
    }
    if (c == ';') {
        (*count_semi)++;
        if (*count_left > 1 && *count_right > 1) {
            *count_left -= 1;
            *count_right -= 1;
        }
    }
}

int check_brackets(char *line, int *brackets, int leftovers)
{
    int count_left = 1;
    int count_right = 0;
    int count_semi = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (count_right > 0 && bad_carac_check(line[i], line[i + 1]) == 1) {
            leftovers++;
            }
        check_conditions(line[i], &count_left, &count_right, &count_semi);
    }
    if (count_left == count_right && count_semi > 0)
        leftovers = 0;
    *brackets = *brackets == 1 ? 0 : 1;
    return error_brackets(count_left, count_right, leftovers);
}

static void reset(int *num1, int *num2)
{
    *num1 = 0;
    *num2 = 0;
    return;
}

int real_check(char *line, int i, int *brackets, int leftovers)
{
    static int squote = 0;
    static int dquotes = 0;
    static int backticks = 0;

    if ((line[i] == '\'' && squote == 0 &&
    check_spe(line + i + 1, '\'', &squote) == 1) ||
    (line[i] == '\"' && dquotes == 0 &&
    check_spe(line + i + 1, '\"', &dquotes) == 1) ||
    (line[i] == '`' && backticks == 0 &&
        check_spe(line + i + 1, '`', &backticks) == 1) ||
    (line[i] == '(' && check_brackets(line + i + 1, brackets, leftovers) == 1))
        return 1;
    if (line[i] == ';') {
        reset(&squote, &dquotes);
        reset(&backticks, &leftovers);
    }
    return 0;
}

int check_matching(char *line)
{
    int brackets = 0;
    int leftovers = 0;
    int brackets_count = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        if (bad_carac_check(line[i], line[i + 1]) == 1)
            leftovers++;
        if (line[i] == '(' || line[i] == ')')
            brackets_count++;
        if (line[i] == ')' && brackets == 0 && brackets_count == 0) {
            printf("Too many )'s.\n");
            return 1;
        }
        if (line[i] == ';' && brackets_count == 2)
            reset(&leftovers, &brackets_count);
        if (real_check(line, i, &brackets, leftovers) == 1)
            return 1;
        brackets = 0;
    }
    return 0;
}
