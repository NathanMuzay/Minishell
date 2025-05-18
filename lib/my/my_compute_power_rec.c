/*
** EPITECH PROJECT, 2024
** my_compute_power_rec
** File description:
** day 5, task 4
*/

int my_compute_power_rec(int nb, int p)
{
    int result;

    if (p == 0){
        return 1;
    }
    if (p < 0){
        return 0;
    }
    result = nb * my_compute_power_rec(nb, p - 1);
    return result;
}
