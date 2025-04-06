/*
** EPITECH PROJECT, 2024
** mini_printf
** File description:
** mini_printf
*/




#include "my.h"

static int test4(char const *format, int a, va_list ap)
{
    switch (format[a]) {
        case 'i':
            return my_putnbr(va_arg(ap, unsigned int));
        default:
            write(2, "84", 2);
            return 84;
    }
}

static int test3(char const *format, int a, int pre, va_list ap)
{
    switch (format[a]) {
        case 'f':
            return my_put_float_f(va_arg(ap, double), pre);
        case 'F':
            return my_put_float_f(va_arg(ap, double), pre);
        case 'd':
            return my_putnbr(va_arg(ap, long int));
        default:
            return test4(format, a, ap);
    }
}

static long unsigned int test2(char const *format, int a, int pre, va_list ap)
{
    switch (format[a]) {
        case 'o':
            return my_putnbr_octal(va_arg(ap, unsigned int));
        case 'u':
            return my_put_unsigned(va_arg(ap, unsigned long int));
        default:
            return test3(format, a, pre, ap);
    }
}

static int test1(char const *format, int a, int pre, va_list ap)
{
    switch (format[a]) {
        case 'c':
            return my_putchar(va_arg(ap, int));
        case 's':
            return my_putstr(va_arg(ap, char *));
        case 'x':
            return my_putnbr_hexamin(va_arg(ap, unsigned int));
        case 'X':
            return my_putnbr_hexamaj(va_arg(ap, unsigned int));
        case 'p':
            my_putstr("0x");
            return my_putnbr_hexamin(va_arg(ap, unsigned long int));
        case '%':
            return my_putchar('%');
        default:
            return test2(format, a, pre, ap);
    }
}

int get_precision(const char *str, int *index)
{
    int precision = 0;
    int i = *index;

    if (str[i] == '.') {
        precision = 0;
        i++;
        if (str[i] <= '0' && str[i] >= '9')
            precision = - 1;
        while (str[i] >= '0' && str[i] <= '9') {
            precision = precision * 10 + (str[i] - '0');
            i++;
        }
    } else if (precision == 0)
        precision = 6;
    *index = i;
    return precision;
}

void my_printf(char const *format, ...)
{
    va_list ap;
    int i = 0;
    int pre = 0;

    va_start(ap, format);
    if (format[0] == '\0')
        return;
    for (i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%'){
            i++;
            pre = get_precision(format, &i);
            test1(format, i, pre, ap);
        } else {
            write(1, format + i, 1);
        }
    }
}
