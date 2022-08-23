/*
** EPITECH PROJECT, 2021
** navy
** File description:
** test.c
*/

#include "../includes/navy.h"

int test_attack(char *str)
{
    if (my_strlen(str) != 2) {
        my_printf("wrong position\n");
        return 84;
    }
    if (str[0] < 65 || str[0] > 72) {
        my_printf("wrong position\n");
        return 84;
    }
    if (str[1] < 49 || str[1] > 56) {
        my_printf("wrong position\n");
        return 84;
    }
    return 0;
}

test_boat_t change_test(test_boat_t test)
{
    char *test_alpha = "..A.B.C.D.E.F.G.H";
    char *test_num = "..12345678";

    for (int i = 0; test_alpha[i] != '\0'; i++) {
        if (test_alpha[i] == test.col)
            test.col = i;
        if (test_alpha[i] == test.end_col)
            test.end_col = i;
    }
    for (int i = 0; test_num[i] != '\0'; i++) {
        if (test_num[i] == test.line)
            test.line = i;
        if (test_num[i] == test.end_line)
            test.end_line = i;
    }
    return test;
}

int my_atoi(char *str)
{
    int nb = 0;

    for (int i = 0; i < my_strlen(str); i++) {
        nb *= 10 + str[i] - 48;
    }
    return nb;
}
