/*
** EPITECH PROJECT, 2024
** my_compute_power_it
** File description:
** day 5, task 3
*/

int my_compute_power_it(int nb, int p)
{
    int result = nb;

    if (p == 0){
        return 1;
    }
    if (p < 0){
    return 0;
    }
    while (p > 1){
        nb = nb * result;
        p--;
    }
    return nb;
}
