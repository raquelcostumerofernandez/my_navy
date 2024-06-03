/*
** EPITECH PROJECT, 2023
** navy
** File description:
** receive_attack.c
*/
#include "../include/navy.h"

void receive1(int num)
{
    global->str_code = my_strcat(global->str_code, "1");
    global->turn++;
}

static int is_ok2(int i)
{
    char c;

    for (int j = 2; j < 18; j++) {
        c = global->map->map_me[i][j];
        if (c > 48 && c < 57) {
            global->won = 0;
            return 1;
        }
    }
    return 0;
}

static void is_ok(void)
{
    for (int i = 2; i < 9; i++)
        if (is_ok2(i) == 1)
            return;
    global->won = 1;
}

void receive2(int num)
{
    global->str_code = my_strcat(global->str_code, "0");
    global->turn++;
}

static void receive_2(void)
{
    my_printf("Enemy won\n");
    usleep(100000);
    kill(global->pidyou, SIGUSR1);
    usleep(100000);
    kill(global->pidyou, SIGUSR2);
}

void receive_coninue(int c)
{
    if (c == 1 && global->won == 0) {
        my_printf("result: %c%c:missed\n", global->str_trans[0],
        global->str_trans[1]);
        usleep(100000);
        kill(global->pidyou, SIGUSR2);
        usleep(100000);
        kill(global->pidyou, SIGUSR2);
    }
    if (c == 2 && global->won == 0) {
        my_printf("result: %c%c:hit\n", global->str_trans[0],
        global->str_trans[1]);
        usleep(100000);
        kill(global->pidyou, SIGUSR1);
        usleep(100000);
        kill(global->pidyou, SIGUSR1);
    }
    if (global->won == 1)
        receive_2();
}

void receive(void)
{
    int c = 0;

    global->won = 0;
    memset(global->str_trans, 0, 11);
    memset(global->str_code, 0, 11);
    global->turn = 0;
    while (global->turn < 11) {
        signal(SIGUSR1, receive1);
        signal(SIGUSR2, receive2);
    }
    global->turn = 0;
    translate_attack();
    c = is_touched();
    is_ok();
    receive_coninue(c);
}
