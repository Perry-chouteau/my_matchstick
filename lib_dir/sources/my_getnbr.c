/*
** EPITECH PROJECT, 2020
** get nbr
** File description:
** get number
*/

#include "../includes/my.h"
#include <stdio.h>

int my_getnbr(char const *str)
{
    int i = 0;
    int nb_signe = 1;
    int nb_str = 0;

    for (;str[i] == '-' || str[i] == '+'; i += 1)
        if (str[i] == '-')
            nb_signe *= -1;
    for (; str[i];  i += 1) {
        nb_str += str[i] - '0';
        if (str[i + 1])
            nb_str *= 10;
    }
    nb_str *= nb_signe;
    return nb_str;
}