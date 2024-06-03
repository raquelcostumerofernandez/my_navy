/*
** EPITECH PROJECT, 2023
** navy
** File description:
** binary.c
*/
#include "my.h"
#include <stdlib.h>

char *to_bin(int num)
{
    int i = 0;
    char *str = malloc(sizeof(char) * 30);

    for (; num != 0; i++) {
        if (num % 2 != 0)
            str[i] = '1';
        if (num % 2 == 0)
            str[i] = '0';
        num /= 2;
    }
    str[i] = '\0';
    str = my_revert(str);
}
