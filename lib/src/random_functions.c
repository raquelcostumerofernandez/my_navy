/*
** EPITECH PROJECT, 2023
** navy
** File description:
** random_functions.c
*/
#include "../include/navy.h"

char *int_to_str(int num)
{
    char *str = malloc(sizeof(char) * 20);

    if (num == 001)
        str = my_strdup("001");
    if (num == 010)
        str = my_strdup("010");
    if (num == 011)
        str = my_strdup("011");
    if (num == 100)
        str = my_strdup("100");
    if (num == 101)
        str = my_strdup("101");
    if (num == 110)
        str = my_strdup("110");
    if (num == 111)
        str = my_strdup("111");
    if (num == 000)
        str = my_strdup("000");
    return str;
}
