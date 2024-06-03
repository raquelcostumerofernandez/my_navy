/*
** EPITECH PROJECT, 2023
** navy
** File description:
** map.c
*/

#include "../include/navy.h"

char **map_initialize(void)
{
    char **map = malloc(sizeof(char *) * 11);
    char *tmp[] = {
        " |A B C D E F G H\n",
        "-+---------------\n",
        "1|. . . . . . . .\n",
        "2|. . . . . . . .\n",
        "3|. . . . . . . .\n",
        "4|. . . . . . . .\n",
        "5|. . . . . . . .\n",
        "6|. . . . . . . .\n",
        "7|. . . . . . . .\n",
        "8|. . . . . . . .\n",
        NULL
    };

    for (int i = 0; i < 10; i++)
        map[i] = my_strdup(tmp[i]);
    return map;
}

map_t *create_map(char **info)
{
    map_t *map = malloc(sizeof(map_t));

    map->map0 = map_initialize();
    map->map_me = map->map0;
    map->map_me = fill_pos(map->map0, info);
    map->map_you = map_initialize();
    map->won = 0;
    map->current = 0;
    map->before = 0;
    return map;
}
