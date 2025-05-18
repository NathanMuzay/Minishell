/*
** EPITECH PROJECT, 2024
** my_strcat
** File description:
** Day 7, task 2
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0'){
        i++;
    }
    while (src[j] != '\0'){
        dest[i] = src[j];
        j++;
        i++;
    }
    dest[i] = '\0';
    return dest;
}
