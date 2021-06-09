/*
** EPITECH PROJECT, 2020
** my_strncmp
** File description:
** Cette fonction permet de comparer deux chaînes de caractères
** et de savoir si la première est inférieure, égale ou supérieure à la seconde.
*/

#include "../includes/my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    for (; s1[i] != '\0' || s1[i] != n; i += 1)
        if (s1[i] != s2[i])
            return (s2[i] - s1[i]);
    return 0;
}