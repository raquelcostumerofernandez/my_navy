/*
** EPITECH PROJECT, 2023
** unit tests
** File description:
** ddff
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/navy.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test(get_num, test_get_num, .init = redirect_all_std)
{
    char *input = "B6";
    char *str = malloc(sizeof(char) * 11);

    str = my_strdup("010");
    str = my_strdup(get_num(input, str));
    cr_assert_str_eq(str, "01011111100");
}

Test(get_letter, test_get_letter, .init = redirect_all_std)
{
    char *input = "B6";

    cr_assert_str_eq(get_letter(input), "010");
}

// Test(obtain_num, test_obt_num, .init = redirect_all_std)
// {
//     global->str_code = "01011111100";
//     char *str = malloc(sizeof(char) * 11);

//     str = my_strdup(my_int_to_str(obtain_num()));
//     cr_assert_str_eq(str, "6");
// }

// Test(obtain_letter, test_obt_letter, .init = redirect_all_std)
// {
//     char *input = "B6";
//     char *str = malloc(sizeof(char) * 11);

//     str = my_strdup(obtain_letter(input));
//     cr_assert_str_eq(str, "010");
// }

Test(int_to_str, test_int_to_str, .init = redirect_all_std)
{
    int num = 010;
    char *str = malloc(sizeof(char) * 4);

    str = int_to_str(num);
    cr_assert_str_eq(str, "010");
}

Test(map_initialize, test_init_map, .init = redirect_all_std)
{
    char **map  = malloc(sizeof(char *) * 11);

    map = map_initialize();
    cr_assert_str_eq(map[0], " |A B C D E F G H\n");
    cr_assert_str_eq(map[1], "-+---------------\n");
    cr_assert_str_eq(map[2], "1|. . . . . . . .\n");
    cr_assert_str_eq(map[3], "2|. . . . . . . .\n");
    cr_assert_str_eq(map[4], "3|. . . . . . . .\n");
    cr_assert_str_eq(map[5], "4|. . . . . . . .\n");
    cr_assert_str_eq(map[6], "5|. . . . . . . .\n");
    cr_assert_str_eq(map[7], "6|. . . . . . . .\n");
    cr_assert_str_eq(map[8], "7|. . . . . . . .\n");
    cr_assert_str_eq(map[9], "8|. . . . . . . .\n");
}
