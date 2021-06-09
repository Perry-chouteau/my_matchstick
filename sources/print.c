/*
** EPITECH PROJECT, 2020
** matchstick preshot
** File description:
** print.c
*/

#include "../includes/include.h"

int print(char **tab)
{
    int n = -1;
    for (int i = 0; tab[i] != NULL; i += 1) {
        for (int j = 0; tab[i][j]; j += 1)
            n += 1;
        for (; n >= 0; n -= 1)
            my_printf("%c", tab[i][n]);
        my_printf("\n");
    }
    return 0;
}
