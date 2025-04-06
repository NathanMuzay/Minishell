/*
** EPITECH PROJECT, 2024
** B-CPE-101-MAR-1-1-myprintf-nathan.muzay
** File description:
** my
*/

#ifndef MY_STRUCT
    #define MY_STRUCT

typedef struct var_s {
    char *input;
    char **args;
    int indi;
    int existe;
    char **envir;
    char *save_ptr1;
    char *save_ptr2;
    char *left_cmd;
    char *right_cmd;
    int statut;
    int i;
    int pipefd[2];
    int cmd_count;
} var_t;

#endif
