/*
** EPITECH PROJECT, 2020
** B-CPE-110-PAR-1-3-bspushswap-perry.chouteau
** File description:
** two_list.c
*/

#include "../includes/include.h"

int game_status(s_t *s)
{
    s->status = END;
    for (int i = 0; s->tab[i] != NULL; i += 1)
        for (int j = 0; s->tab[i][j] != '\0'; j += 1)
            if (s->tab[i][j] == '|')
                return CONTINUE;
    return END;
}

int del__stick(s_t *s)
{
    for (int i = 0, j = s->turn.max;
    s->tab[s->turn.line][i] != '\0' && j > 0; i += 1)
        if (s->tab[s->turn.line][i] == '|') {
            s->tab[s->turn.line][i] = ' ';
            j -= 1;
        }
    return 0;
}

int matchstick(s_t *s)
{
    s->status = END;
    print(s->tab);
    while (1) {
        if (matchstick_you(s) == -2)
            return 0;
        print(s->tab);
        if (game_status(s) == END) {
            my_printf("You lost, too bad...\n");
            return 2;
        }
        matchstick_ia(s);
        print(s->tab);
        if (game_status(s) == END) {
            my_printf("I lost... snif... but I'll get you next time!!\n");
            return 1;
        }
    }
}

int main(int ac, char **av)
{
    s_t *s = malloc(sizeof(s_t));
    if (my_error(ac, av) == 1)
        return 0;
    if (my_error(ac, av) == 84)
        return 84;
    init(s, av);
    return matchstick(s);
}