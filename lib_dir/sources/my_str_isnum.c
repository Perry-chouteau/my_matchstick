/*
** EPITECH PROJECT, 2020
** my str is num
** File description:
** say if the string is a number
*/

#include "../includes/my.h"

int my_str_isnum(char const *str)
{
    int	i = 0;

    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            i = i + 1;
        else
            return (0);
    }
    if (str[0] == '\0')
        return 0;
    return (1);
}