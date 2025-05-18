/*
** EPITECH PROJECT, 2024
** my_isalnum
** File description:
** recode de isalnum
*/

int my_isalnum(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
    || (c >= '0' && c <= '9'));
}
