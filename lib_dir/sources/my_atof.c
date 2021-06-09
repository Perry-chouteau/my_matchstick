/*
** EPITECH PROJECT, 2020
** B-MUL-100-PAR-1-3-myrunner-perry.chouteau
** File description:
** my_atof.c
*/

#include "../includes/my.h"

double my_atof(char *str)
{
    double resa = 0;
    double resb = 0;
    int neg = 1;
    int i;

    for (i = 0; str[i] == '-' || str[i] == '+'; i += 1)
        if (str[i] == '-')
            neg *= -1;
    for (; str[i] && str[i] != '.'; i += 1, resa *= 10)
        resa += str[i] - '0';
    resa *= 0.1;
    if (str[i] == '\0')
        return (neg * resa);
    for (i = 0; str [i]; i += 1);
    for (i -= 1; str[i] != '.'; i -= 1, resb *= 0.1)
        resb += str[i] - '0';
    return (neg * (resa + resb));
}