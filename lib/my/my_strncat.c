/*
** EPITECH PROJECT, 2024
** my_strncat
** File description:
** Day 7, task 3
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0'){
        i++;
    }
    while (j < nb){
        dest[i] = src[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}
