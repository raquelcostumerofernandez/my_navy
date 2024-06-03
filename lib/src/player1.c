/*
** EPITECH PROJECT, 2023
** navy
** File description:
** player1.c
*/
// global->won = 0 : base
// global->won = 1 : missed
// global->won = 2 : touched
// global->won = 3 : won
#include "../include/navy.h"
#include <signal.h>

glob_t *global;

void connected_1(map_t *info_up)
{
    my_printf("my navy:\n");
    for (int i = 0; global->map->map_me[i] != NULL; i++)
        my_printf("%s", global->map->map_me[i]);
    my_printf("\nenemy navy:\n");
    for (int i = 0; global->map->map_you[i] != NULL; i++)
        my_printf("%s", global->map->map_you[i]);
    my_printf("\n");
}

void receive_1(int num)
{
    global->str_code[global->i] = '1';
    global->i++;
}

void receive_2(int num)
{
    global->str_code[global->i] = '0';
    global->i++;
}

static void handler1(int signo, siginfo_t *info, void *context)
{
    my_printf("\nenemy connected\n");
    global->signal_received = 1;
    global->pidyou = info->si_pid;
    global->pidme = getpid();
    my_printf("\n");
}

int game1(void)
{
    while (global->won == 0) {
        if (attack() == 84)
            return 84;
        if (global->won == 1)
            return 0;
        my_printf("waiting for enemy's attack...\n\n");
        receive();
        my_printf("\n");
        connected_1(global->map);
        if (global->won == 3)
            return 1;
        if (global->won == 1)
            return 1;
        usleep(1000000);
    }
}

int player_1(char *map)
{
    char *str = malloc(sizeof(char) * 20);
    char **info = read_file_noarg(map);
    map_t *info_up = create_map(info);
    struct sigaction sa;

    global->map = info_up;
    memset(&sa, 0, sizeof(sa));
    sa.sa_sigaction = handler1;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sa, NULL);
    my_printf("my_pid: %d\n", getpid());
    my_printf("\nwaiting for enemy...\n");
    while (global->signal_received != 1)
        usleep(1);
    connected_1(info_up);
    if (game1() == 84)
        return 84;
    while (global->won == 0)
        usleep(1);
    return 0;
}
