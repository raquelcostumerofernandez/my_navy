/*
** EPITECH PROJECT, 2023
** navy
** File description:
** transform_attack.c
*/

#include "../include/navy.h"

static code_t code[] = {
    {'A', 001, 2},
    {'B', 010, 4},
    {'C', 011, 6},
    {'D', 100, 8},
    {'E', 101, 10},
    {'F', 110, 12},
    {'G', 111, 14},
    {'H', 000, 16}
};

glob_t *global_ctor(void)
{
    glob_t *glob = malloc(sizeof(glob_t));

    glob->i = 0;
    glob->won = 0;
    glob->count = 0;
    glob->pidme = 0;
    glob->pidyou = 0;
    glob->signal_received = 0;
    glob->touch = malloc(sizeof(char) * 2);
    glob->str_code = malloc(sizeof(char) * 12);
    glob->str_trans = malloc(sizeof(char) * 12);
    for (int i = 0; i < 8; i++)
        glob->code[i] = code[i];
    return glob;
}

char *get_letter(char *input)
{
    char *str = malloc(sizeof(char) * 12);

    for (int i = 0; i < 8; i++)
        if (input[0] == code[i].letter)
            str = my_strdup(int_to_str(code[i].code));
    return str;
}

char *get_num(char *input, char *str)
{
    if (input[1] == '1')
        str = my_strdup(my_strcat(str, "10000000"));
    if (input[1] == '2')
        str = my_strdup(my_strcat(str, "11000000"));
    if (input[1] == '3')
        str = my_strdup(my_strcat(str, "11100000"));
    if (input[1] == '4')
        str = my_strdup(my_strcat(str, "11110000"));
    if (input[1] == '5')
        str = my_strdup(my_strcat(str, "11111000"));
    if (input[1] == '6')
        str = my_strdup(my_strcat(str, "11111100"));
    if (input[1] == '7')
        str = my_strdup(my_strcat(str, "11111110"));
    if (input[1] == '8')
        str = my_strdup(my_strcat(str, "11111111"));
    return str;
}

void send_attack(char *str)
{
    for (int i = 0; i < 11; i++) {
        if (str[i] == '0') {
            kill(global->pidyou, SIGUSR2);
            usleep(10000);
        }
        if (str[i] == '1') {
            kill(global->pidyou, SIGUSR1);
            usleep(10000);
        }
    }
}

static void handling1(int num)
{
    global->count += 1;
    global->turn++;
}

static void handling2(int num)
{
    global->count += 2;
    global->turn++;
}

static void receive_result(char *input)
{
    int i = 0;

    global->count = 0;
    global->turn = 0;
    signal(SIGUSR1, handling1);
    signal(SIGUSR2, handling2);
    while (global->turn < 2)
        usleep(1);
    if (global->count == 2 && global->won == 0)
        my_printf("\nresult: %c%c:hit\n\n", input[0], input[1]);
    if (global->count == 4 && global->won == 0)
        my_printf("\nresult: %c%c:missed\n\n", input[0], input[1]);
    if (global->count == 3) {
        my_printf("\nI won\n");
        global->won = 1;
    }
    was_touched(input);
}

static void attack_continue(char *input, int *ok)
{
    if (input[0] > 72 || input[0] < 65 && (input[0] > 16 || input[0] < 20)
    || input[1] <= 48) {
        (*ok) = 0;
        my_printf("\nwrong position\n\n");
    }
}

int attack(void)
{
    char *input = malloc(sizeof(char) * 4);
    int reading = 0;
    char *str = NULL;
    int ok = 0;

    while (ok == 0) {
        ok++;
        write(1, "attack:  ", 10);
        reading = read(0, input, 4 - 1);
        if (reading == 0)
            return 84;
        attack_continue(input, &ok);
    }
    str = my_strdup(get_letter(input));
    str = my_strdup(get_num(input, str));
    send_attack(str);
    receive_result(input);
    usleep(1000000);
}
