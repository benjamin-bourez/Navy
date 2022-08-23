/*
** EPITECH PROJECT, 2021
** navy
** File description:
** main
*/

#include "../includes/navy.h"

void help(void)
{
    my_printf("USAGE\n     ./navy [first_player_pid] navy_positions\n");
    my_printf("DESCRIPTION\n     first_player_pid: only for the 2nd player. p\
id of the first player.\n     navy_positions: file representing the positions\
of the ships.\n");
}

char **init_map(char **map)
{
    map = malloc(sizeof(char *) * 10);
    for (int i = 0; i < 10; i++)
        map[i] = malloc(sizeof(char) * 20);
    map[0] = " |A B C D E F G H\n";
    map[1] = "-+---------------\n";
    map[2] = "1|. . . . . . . .\n";
    map[3] = "2|. . . . . . . .\n";
    map[4] = "3|. . . . . . . .\n";
    map[5] = "4|. . . . . . . .\n";
    map[6] = "5|. . . . . . . .\n";
    map[7] = "6|. . . . . . . .\n";
    map[8] = "7|. . . . . . . .\n";
    map[9] = "8|. . . . . . . .\n";
    return map;
}

player_t init_player(player_t player)
{
    player.map = init_map(player.map);
    player.hit = 0;
    player.pid = getpid();
    return player;
}

player_t init_enemy(player_t player)
{
    player.map = init_map(player.map);
    player.hit = 0;
    player.pid = 0;
    return player;
}

int main(int ac, char **av)
{
    game_t game;
    int test = 0;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        help();
        return 0;
    }
    if (ac == 2) {
        test = main_player1(game, av);
        if (test == ERROR)
            return ERROR;
    }
    if (ac == 3) {
        test = main_player2(game, av);
        if (test == ERROR)
            return ERROR;
    }
}
