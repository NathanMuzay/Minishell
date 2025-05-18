/*
** EPITECH PROJECT, 2024
** my_revstr
** File description:
** Day 6, task 3
*/

char *my_revstr(char *str)
{
    int i = 0;
    int r = 0;
    char temp;

    while (str[i] != '\0'){
        i++;
    }
    i--;
    while (i > r){
        temp = str[i];
        str[i] = str[r];
        str[r] = temp;
        r++;
        i--;
    }
    return str;
}
