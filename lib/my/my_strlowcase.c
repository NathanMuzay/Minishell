/*
** EPITECH PROJECT, 2024
** my_strlowcase
** File description:
** Day 6, task 9
*/

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    for (int j = 0; j < i; j++){
        if (str[j] >= 65 && str[j] <= 90){
            str[j] = str[j] + 32;
        }
    }
    return str;
}
