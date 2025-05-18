/*
** EPITECH PROJECT, 2024
** my_put_unsigned
** File description:
** pour printf unsigned %u
*/

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

unsigned int my_put_unsigned(unsigned int nb)
{
    unsigned int count = 0;

    if (nb <= 9){
        count += my_putchar(nb + 48);
    } else {
        count += my_put_unsigned(nb / 10);
        count += my_putchar((nb % 10) + '0');
    }
    return count;
}
