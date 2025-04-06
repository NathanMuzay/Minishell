/*
** EPITECH PROJECT, 2024
** strlen_lign.c
** File description:
** number char on a lign
*/
#include "../../include/my.h"

int strlen_lign(char *buff)
{
    int count = 0;
    int temp = 0;
    int a = my_strlen(buff);
    int j = 0;
    int i = 0;

    while (j < a){
        i = 0;
        do {
            temp++;
            i++;
        } while (buff[i] != '\n');
        j++;
        if (temp > count)
            count = temp;
    }
    return count;
}
