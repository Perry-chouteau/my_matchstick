/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-pushswap-perry.chouteau
** File description:
** init.c
*/

#include "../includes/include.h"

int init_tab(s_t *s)
{
    s->tab = malloc(sizeof(char *) * (s->stick.line + 3));
    s->tab[s->stick.line + 2] = NULL;
    for (int i = 0; i < s->stick.line + 2; i += 1) {
        s->tab[i] = malloc(sizeof(char) * (s->stick.line * 2 + 2));
        s->tab[i][s->stick.line * 2 + 1] = '\0';
    }
    return 0;
}

int init_square(s_t *s)
{
    for (int i = 0; s->tab[i] != NULL; i += 1) {
        for (int j = 0; j < (s->stick.line * 2 + 1); j += 1) {
            if (j == 0 || j == s->stick.line * 2)
                s->tab[i][j] = '*';
            else if (i == 0 || i == s->stick.line + 1)
                s->tab[i][j] = '*';
            else
                s->tab[i][j] = ' ';
        }
    }
    return 0;
}

int init_stick(s_t *s)
{
    for (int i = 0; s->tab[i + 1] != NULL; i += 1) {
        for (int j = 0; s->tab[i][j] != '\0'; j += 1) {
            if (j > s->stick.line - i && j < s->stick.line + i)
                s->tab[i][j] = '|';
        }
    }
    return 0;
}

int init(s_t *s, char **av)
{
    s->stick.line = my_getnbr(av[1]);
    s->stick.max = my_getnbr(av[2]);
    init_tab(s);
    init_square(s);
    init_stick(s);
    return 0;
}