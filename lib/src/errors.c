/*
** EPITECH PROJECT, 2023
** radar_mod
** File description:
** errors.c
*/
#include "../lib/my/my.h"
#include <string.h>

int is_legit(char **arr)
{
    int num = 2;

    for (int i = 0; i < 4; i++) {
        if (arr[i][0] != num + 48)
            return 84;
        num++;
    }
    return 0;
}

int error_2(char **argv)
{
    char **arr = NULL;

    if (open(argv[2], O_RDONLY) == -1) {
        write(2, "File not found\n", 16);
        return (-1);
    }
    arr = read_file_noarg(argv[2]);
    if (is_legit(arr) != 0)
        return (-1);
    return 0;
}

int error_handling(int argc, char **argv)
{
    int fd = 0;
    char **arr = NULL;
    int num = 0;

    if (argc < 2)
        return (-1);
    if (argc == 2) {
        if (open(argv[1], O_RDONLY) == -1) {
            write(2, "File not found\n", 16);
            return (-1);
        }
        arr = read_file_noarg(argv[1]);
        if (is_legit(arr) != 0)
            return (-1);
        return 0;
    }
    if (argc == 3) {
        num = error_2(argv);
        return num;
    }
}
