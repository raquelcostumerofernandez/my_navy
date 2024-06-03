/*
** EPITECH PROJECT, 2023
** navy
** File description:
** main.c
*/
#include "../include/navy.h"

int main(int ac, char **av)
{
    char *input = malloc(sizeof(char) * 4);
    int reading = 0;
    char *str = NULL;

    if (error_handling(ac, av) != 0)
        return (84);
    str = my_strdup(av[1]);
    global = global_ctor();
    if (ac == 2) {
        reading = player_1(str);
        return reading;
    }
    if (ac == 3) {
        reading = player_2(av[2], my_get_nbr(av[1]));
        return reading;
    }
    return 0;
}
