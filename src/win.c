/*
** EPITECH PROJECT, 2021
** navy
** File description:
** win
*/

#include "../includes/navy.h"

int win_check(game_t game)
{
    if (usr[7] >= 14) {
        my_printf("I won\n");
        return 1;
    }
    if (usr[8] >= 14) {
        my_printf("Enemy won\n");
        return 1;
    }
    return 0;
}
