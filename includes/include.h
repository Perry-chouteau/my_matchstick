/*
** EPITECH PROJECT, 2020
** Psu2
** File description:
** navy.h
*/

#ifndef ITSC_H
#define ITSC_H

//lib - lib_c
#include "../lib_dir/includes/my.h"
#include <stdlib.h>
#include <string.h>

//write
#include "../printf_dir/includes/my_printf.h"
#include <unistd.h>
#include <stdio.h>

//math
#include <math.h>

//signal
#include <signal.h>
#include <stddef.h>

// sys & bits
#include <sys/types.h>
#include<sys/stat.h>
#include <fcntl.h>

//criterion
#include <criterion/criterion.h>

typedef enum
{
    END, CONTINUE, ERR_LINE, ERR_STICK
}status;

// struct
typedef struct
{
    int line;
    int max;
}vector2i_t;

typedef struct
{
    int status;

    vector2i_t stick;
    char **tab;
    vector2i_t turn;
}s_t;

// error / -h / init
int my_error(int ac, char **av);
int init(s_t *s, char **av);

int print(char **tab);

//your move
int matchstick_you(s_t *s);
int matchstick_ia(s_t *s);
int del__stick(s_t *s);

#endif
