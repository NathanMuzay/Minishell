/*
** EPITECH PROJECT, 2024
** my_strcmp
** File description:
** Day 6, task 6
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0'){
        if (s1[i] != s2[i]){
            return s1[i] - s2[i];
        }
        i++;
    }
    return s1[i] - s2[i];
}
