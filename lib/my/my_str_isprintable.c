/*
** EPITECH PROJECT, 2024
** my_str_isprintable
** File description:
** Day 6, 16
*/

int my_str_isprintable(char const *str)
{
    if (str[0] == '\0'){
        return 1;
    }
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] < 33 || str[i] > 126){
            return 0;
        }
    }
    return 1;
}
