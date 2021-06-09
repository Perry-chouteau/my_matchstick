/*
** EPITECH PROJECT, 2020
** matchstick preshot
** File description:
** getline_lm.c
*/

#include "../includes/include.h"

int get_ia_line(s_t *s)
{
    for (int n = 0; 1; n = 0) {
        s->turn.line = (rand() % s->stick.line + 1);
        if (s->turn.line <= 0 || s->turn.line > s->stick.line)
            continue;
        for (int i = 0; s->tab[s->turn.line][i] != '\0'; i += 1)
            n += (s->tab[s->turn.line][i] == '|') ? 1: 0;
        if (n <= 0)
            continue;
        return 0;
    }
}

int get_ia_stick(s_t *s)
{
    for (int n = 0; 1; n = 0) {
        s->turn.max = (rand() % s->stick.max + 1);
        if (s->turn.max <= 0 || s->turn.max > s->stick.max)
            continue;
        for (int i = 0; s->tab[s->turn.line][i] != '\0'; i += 1)
            n += (s->tab[s->turn.line][i] == '|') ? 1: 0;
        if (n == 0 || n < s->turn.max)
            continue;
        return s->turn.max;
    }
}

int matchstick_ia(s_t *s)
{
    my_printf("\nAI's turn...\n");
    get_ia_line(s);
    get_ia_stick(s);
    my_printf("AI removed %i match(es) from line %i\n", \
    s->turn.max, s->turn.line);
    del__stick(s);
    return 0;
}