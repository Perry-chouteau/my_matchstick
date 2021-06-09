/*
** EPITECH PROJECT, 2020
** matchstick preshot
** File description:
** getline_lm.c
*/

#include "../includes/include.h"

int get__line2(s_t *s, char *str)
{
    s->turn.line = my_getnbr(str);
    if (s->turn.line <= 0 || s->turn.line > s->stick.line) {
        my_printf("Error: this line is out of range\n");
        return -1;
    }
    return 0;
}

int get__line(s_t *s)
{
    for (char *str; 1; ) {
        int n = 0;
        my_printf("Line: ");
        str = my_termline();
        if (str == NULL)
            return -2;
        if (my_str_isnum(str) == 0) {
            my_printf("Error: invalid input (positive number expected)\n");
            return -1;
        } else if (get__line2(s, str) == -1)
            return -1;
        for (int i = 0; s->tab[s->turn.line][i] != '\0'; i += 1)
            n += (s->tab[s->turn.line][i] == '|') ? 1: 0;
        if (n <= 0) {
            my_printf("Error: you cannot remove more than");
            my_printf(" %i matches per turn\n", s->stick.max);
            return -1;
        }
        return 0;
    }
}

int get__stick2(s_t *s, char *str)
{
    s->turn.max = my_getnbr(str);
    if (s->turn.max <= 0) {
        my_printf("Error: you have to remove at least one match\n");
        return -1;
    } else if (s->turn.max > s->stick.max) {
        my_printf("Error: you cannot remove more than");
        my_printf(" %i matches per turn\n", s->stick.max);
        return -1;
    }
    return 0;
}

int get__stick(s_t *s)
{
    for (int n = 0; 1; n = 0) {
        my_printf("Matches: ");
        char *str = my_termline();
        if (str == NULL)
            return -2;
        if (my_str_isnum(str) == 0) {
            my_printf("Error: invalid input (positive number expected)\n");
            return -1;
        } else if (get__stick2(s, str) == -1)
            return -1;
        for (int i = 0; s->tab[s->turn.line][i] != '\0'; i += 1)
            n += (s->tab[s->turn.line][i] == '|') ? 1: 0;
        if (n == 0 || n < s->turn.max) {
            my_printf("Error: not enough matches on this line\n");
            return -1;
        }
        return 0;
    }
}

int matchstick_you(s_t *s)
{
    my_printf("\nYour turn:\n");
    for (int i; 1;) {
        i = get__line(s);
        if (i == -1)
            continue;
        else if (i == -2)
            return -2;
        i = get__stick(s);
        if (i  == -1)
            continue;
        else if (i == -2)
            return -2;
        break;
    }
    my_printf("Player removed %i match(es) from line %i\n", \
    s->turn.max, s->turn.line);
    del__stick(s);
    return 0;
}