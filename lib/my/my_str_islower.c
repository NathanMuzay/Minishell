/*
** EPITECH PROJECT, 2024
** my_str_islower
** File description:
** Day 6, 14
*/

int my_str_islower(char const *str)
{
    if (str[0] == '\0'){
        return 1;
    }
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] < 97 || str[i] > 122){
            return 0;
        }
    }
    return 1;
}
