/*
** EPITECH PROJECT, 2024
** my_isalpha.c
** File description:
** pour my_str_to_word_array
*/

int my_isalpha(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
