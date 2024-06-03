/*
** EPITECH PROJECT, 2023
** navy
** File description:
** navy.h
*/
#pragma once
#include "../lib/my/my.h"
#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef struct pos_s {
    int len;
    char Fletter;
    int Fnum;
    char Lletter;
    int Lnum;
}pos_t;

typedef struct ship_s {
    pos_t *s1;
    pos_t *s2;
    pos_t *s3;
    pos_t *s4;
}ship_t;

typedef struct code_s {
    char letter;
    int code;
    int j;
}code_t;

typedef struct map_s {
    char **map0;
    char **map_me;
    char **map_you;
    int won;
    int current;
    int before;
    ship_t *ships;
}map_t;

typedef struct my_global {
    int signal_received;
    char *str_code;
    char *str_trans;
    int i;
    int pidme;
    int pidyou;
    int turn;
    code_t code[8];
    int won;
    map_t *map;
    char *touch;
    int count;
}glob_t;

typedef struct var_s {
    int i;
    int j;
    int k;
    int m;
    int v;
}var_t;

typedef struct my_s {
    char c;
    int i;
}my_t;

extern glob_t *global;

// General
int error_handling(int argc, char **argv);
glob_t *global_ctor(void);
char *int_to_str(int num);

// Map
char **map_initialize(void);
char **my_map_initialize(char **info);
map_t *create_map(char **info);
void connected_1(map_t *info_up);
char **fill_pos(char **map, char **info);

// Players
int player_2(char *map, pid_t pid);
int player_1(char *map);

// Receiving the attack -> num into position
char obtain_letter(void);
int obtain_num(void);
char *translate_attack(void);
int is_touched(void);

// Sending the attack -> position into num
int attack(void);
char *get_letter(char *input);
char *get_num(char *input, char *str);
void send_attack(char *str);
int was_touched(char *input);

// Receive attack
void receive1(int num);
void receive2(int num);
void receive(void);
