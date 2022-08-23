/*
** EPITECH PROJECT, 2021
** navy
** File description:
** display.c
*/

#include "../includes/navy.h"

void display_map(char **map)
{
    for (int i = 0; i < 10; i++)
        my_printf(map[i]);
    my_printf("\n");
}

void display(game_t game)
{
    my_printf("my positions:\n");
    display_map(game.player.map);
    my_printf("enemy's positions:\n");
    display_map(game.enemy.map);
}
