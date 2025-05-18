/*
** EPITECH PROJECT, 2024
** my_strupcase
** File description:
** Day 6, task 8
*/

char *my_strupcase(char *str)
{
    int i = 0;

    while (str[i] != '\0'){
        i++;
    }
    for (int j = 0; j < i; j++){
        if (str[j] >= 97 && str[j] <= 122){
            str[j] = str[j] - 32;
        }
    }
    return str;
}
