/*
** EPITECH PROJECT, 2020
** B-EXAMPlistE-100-PAR-1-3-exampliste-perry.chouteau
** File description:
** empty_listinked_list.c
*/

#include "../includes/my.h"

cell_t *empty_list(void)
{
    return NULL;
}

int len_list(cell_t **list)
{
    cell_t *cur = list[0];
    int i = 1;

    for (; cur->next != NULL; i += 1)
        cur = cur->next;
    return i;
}

void free_list(cell_t **list)
{
    cell_t *prec = list[0];

    while (list[0] != NULL) {
        list[0] = list[0]->next;
        free(prec);
        prec = list[0];
    }
}

void print_list(cell_t **list)
{
    cell_t *cur = list[0];

    for (; cur != NULL; cur = cur->next) {
        my_put_nbr(cur->data);
        if (cur->next != NULL)
            write(1, " ", 1);
    }
    write(1, "\n", 1);
}