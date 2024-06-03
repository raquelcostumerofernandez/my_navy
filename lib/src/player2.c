/*
** EPITECH PROJECT, 2023
** navy
** File description:
** player2.c
*/
#include "../include/navy.h"

void connected_2(map_t *info)
{
    my_printf("\nsuccessfully connected to enemy\n\n");
    my_printf("my navy:\n");
    for (int i = 0; info->map_me[i] != NULL; i++)
        my_printf("%s", info->map_me[i]);
    my_printf("\nenemy navy:\n");
    for (int i = 0; info->map_you[i] != NULL; i++)
        my_printf("%s", info->map_you[i]);
    my_printf("\nwaiting for enemy's attack...\n\n");
    global->signal_received = 1;
}

int game2(void)
{
    while (global->won == 0) {
        receive();
        if (global->won == 1)
            return 0;
        if (global->won == 3)
            return 1;
        my_printf("\n");
        usleep(1000000);
        if (attack() == 84)
            return 84;
        if (global->won == 1)
            return 0;
        connected_1(global->map);
        my_printf("waiting for enemy's attack...\n\n");
    }
}

int player_2(char *map, pid_t pid)
{
    char **info = read_file_noarg(map);
    map_t *info_up = create_map(info);

    global->map = info_up;
    global->pidme = getpid();
    global->pidyou = pid;
    my_printf("my_pid: %d\n", getpid());
    kill(pid, SIGUSR2);
    connected_2(info_up);
    while (global->signal_received == 0)
        usleep(1);
    if (game2() == 84)
        return 84;
    while (global->won == 0)
        usleep(1);
    return 0;
}
