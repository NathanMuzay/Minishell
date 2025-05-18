/*
** EPITECH PROJECT, 2024
** my_swap
** File description:
** day 4, task 1
*/

void my_swap(int *a, int *b)
{
    int temp = *a;

    *a = *b;
    *b = temp;
}
