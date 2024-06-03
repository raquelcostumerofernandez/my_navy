/*
** EPITECH PROJECT, 2023
** navy
** File description:
** my_map.c
*/
#include "../include/navy.h"

static pos_t *ship_ctor(int i, char **info)
{
    pos_t *ship = malloc(sizeof(pos_t));

    ship->len = info[i][0] - 48;
    ship->Fletter = info[i][2];
    ship->Fnum = info[i][3] - 48;
    ship->Lletter = info[i][5];
    ship->Lnum = info[i][6] - 48;
    return ship;
}

static ship_t *fill_ships(char **info)
{
    ship_t *ship = malloc(sizeof(ship_t));

    ship->s1 = ship_ctor(0, info);
    ship->s2 = ship_ctor(1, info);
    ship->s3 = ship_ctor(2, info);
    ship->s4 = ship_ctor(3, info);
    return ship;
}

static var_t *var_ctor(void)
{
    var_t *var = malloc(sizeof(var_t));

    var->i = 0;
    var->j = 0;
    var->k = 0;
    var->m = 0;
    var->v = 0;
    return var;
}

static pos_t *what_ship(ship_t *ship, var_t *var)
{
    pos_t *my_ship = NULL;

    if (var->i == 0)
        my_ship = ship->s1;
    if (var->i == 1)
        my_ship = ship->s2;
    if (var->i == 2)
        my_ship = ship->s3;
    if (var->i == 3)
        my_ship = ship->s4;
    return my_ship;
}

void my_loop(var_t *var, pos_t *my_ship, char **map)
{
    for (; var->j < 8; var->j++)
        if (my_ship->Fletter == global->code[var->j].letter)
            var->v = global->code[var->j].j;
    if (my_ship->Fletter == my_ship->Lletter) {
        map[my_ship->Fnum + 1 + var->k][var->v] = my_ship->len + 48;
        var->k++;
    }
    if (my_ship->Fletter != my_ship->Lletter) {
        map[my_ship->Fnum + 1][var->v] = my_ship->len + 48;
        var->v += 2;
    }
    var->m++;
}

char **fill_pos(char **map, char **info)
{
    ship_t *ship = fill_ships(info);
    var_t *var = var_ctor();
    pos_t *my_ship = NULL;

    for (; var->i < 4; var->i++) {
        var->k = 0;
        var->v = 0;
        var->j = 0;
        var->m = 0;
        my_ship = what_ship(ship, var);
        while (var->m < my_ship->len)
            my_loop(var, my_ship, map);
    }
    return map;
}
