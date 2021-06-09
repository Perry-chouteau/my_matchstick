/*
** EPITECH PROJECT, 2020
** B-EXAMPLE-100-PAR-1-3-example-perry.chouteau
** File description:
** my_term_line.c
*/

#include <stdio.h>
#include <stdlib.h>

char *my_termline(void)
{
    char *line = NULL;
    size_t len = 0;
    int n = 0;
    ssize_t err = getline(&line, &len, stdin);
    if (err == -1)
        return NULL;
    for (n = 0; line[n]; n += 1);
    line[n - 1] = '\0';
    return line;
}
