/*
** EPITECH PROJECT, 2023
** navy
** File description:
** common_functions.c
*/

#include "../include/navy.h"

char obtain_letter(void)
{
    char *letters = malloc(sizeof(char) * 3);
    char letter;

    for (int i = 0; i < 3; i++)
        letters[i] = global->str_code[i];
    for (int j = 0; j < 8; j++)
        if (my_strcmp(letters, int_to_str(global->code[j].code)) == 1)
            letter = global->code[j].letter;
    return letter;
}

int obtain_num(void)
{
    int count = 0;

    for (int i = 3; i < 11; i++)
        if (global->str_code[i] == '1')
            count++;
    return count;
}

char *translate_attack(void)
{
    char letter = obtain_letter();
    int num = obtain_num();

    global->str_trans[0] = letter;
    global->str_trans = my_strcat(global->str_trans, my_int_to_str(num));
}
