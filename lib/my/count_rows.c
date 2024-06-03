/*
** EPITECH PROJECT, 2023
** radar_mod
** File description:
** count_rows.c
*/
#include "my.h"

int how_many_rows_str(char *buffer)
{
    int count = 0;

    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n')
            count += 1;
    return count;
}
