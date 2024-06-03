/*
** EPITECH PROJECT, 2023
** navy
** File description:
** touch_miss.c
*/

#include "../include/navy.h"

static void touch1(int num)
{
    global->touch = my_strcat(global->touch, "1");
    global->count++;
}

static void touch2(int num)
{
    global->touch = my_strcat(global->touch, "0");
    global->count++;
}

int change_char(char c)
{
    int num = 0;

    if (c == '1')
        num = 1;
    if (c == '2')
        num = 2;
    if (c == '3')
        num = 3;
    if (c == '4')
        num = 4;
    if (c == '5')
        num = 5;
    if (c == '6')
        num = 6;
    if (c == '7')
        num = 7;
    if (c == '8')
        num = 8;
    return num;
}

int my_getnum(char c)
{
    int num = change_char(c);

    return num;
}

int is_touched(void)
{
    int v = 0;
    int c = my_getnum(global->str_trans[1]);

    global->count = 0;
    memset(global->touch, 0, 2);
    for (int j = 0; j < 8; j++)
        if (global->str_trans[0] == global->code[j].letter)
            v = global->code[j].j;
    if (global->map->map_me[c + 1][v] != '.' &&
    global->map->map_me[c + 1][v] != ' ') {
        global->map->map_me[c + 1][v] = 'x';
        return 2;
    } else if (global->map->map_me[c + 1][v] == '.' ||
    global->map->map_me[c + 1][v] == ' ') {
        global->map->map_me[c + 1][v] = 'o';
        return 1;
    }
    return 84;
}

int was_touched(char *input)
{
    int v = 0;
    int c = my_getnum(input[1]);

    global->count = 0;
    memset(global->touch, 0, 2);
    for (int j = 0; j < 8; j++)
        if (input[0] == global->code[j].letter)
            v = global->code[j].j;
    if (global->map->map_you[c + 1][v] != '.' &&
    global->map->map_you[c + 1][v] != ' ') {
        global->map->map_you[c + 1][v] = 'o';
        return 2;
    } else if (global->map->map_you[c + 1][v] == '.' ||
    global->map->map_you[c + 1][v] == ' ') {
        global->map->map_you[c + 1][v] = 'x';
        return 1;
    }
    return 84;
}
