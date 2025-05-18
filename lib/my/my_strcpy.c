/*
** EPITECH PROJECT, 2024
** my_strcpy
** File description:
** Day 6, task 1
*/

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
