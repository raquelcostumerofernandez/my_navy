/*
** EPITECH PROJECT, 2023
** radar_mod
** File description:
** read.c
*/
#include "my.h"
#include <string.h>

int my_putchar_error(char c)
{
    write(2, &c, 1);
    return 0;
}

char **load_to_arr(char *buffer)
{
    char *tmp = my_strdup(buffer);
    int rows = how_many_rows_str(tmp);
    char **arr = malloc(sizeof(char *) * (rows + 1));
    int i = 0;
    int j = 0;
    int k = 0;

    for (; tmp[k] != '\0'; i++) {
        arr[i] = malloc(sizeof(char) * 30);
        for (j = 0; tmp[k] != '\n'; j++) {
            arr[i][j] = tmp[k];
            k++;
        }
        arr[i][j] = '\0';
        k++;
    }
    arr[i] = NULL;
    return arr;
}

char **read_file(int ac, char **av)
{
    int fd = 0;
    char *buffer = malloc(sizeof(char) * 30000);
    char **arr = malloc(sizeof(char) * 30000);
    int bytes_read = 0;

    if (ac < 2) {
        return NULL;
    }
    for (int i = 1; i < ac; i++) {
        fd = open(av[i], O_RDONLY);
        bytes_read = read(fd, buffer, 30000);
        arr = load_to_arr(buffer);
        close(fd);
    }
    return arr;
}

char **read_file_noarg(char *filepath)
{
    int fd = 0;
    char *buffer = malloc(sizeof(char) * 30000);
    char **arr = malloc(sizeof(char) * 30000);
    int bytes_read = 0;

    fd = open(filepath, O_RDONLY);
    bytes_read = read(fd, buffer, 30000);
    arr = load_to_arr(buffer);
    close(fd);
    return arr;
}
