/*
** EPITECH PROJECT, 2022
** navy
** File description:
** game loop
*/

#include "../includes/navy.h"

int game_debut_1(game_t game)
{
    char *str = NULL;
    int attack[2] = {0, 0};

    while (win_check(game) != 1) {
        display(game);
        str = get_input();
        send_pos(str, game.enemy.pid);
        my_printf("%s : ", str);
        is_touch(game, str);
        if (win_check(game) == 1)
            return 1;
        my_printf("waiting for ennemy attack...\n");
        receive();
        attack[0] = usr[2];
        attack[1] = usr[3];
        my_printf("%c%c", attack[0] + 64, attack[1] + 48);
        check_attack(attack, game);
    }
}

int game_debut_2(game_t game)
{
    int attack[2] = {0, 0};
    char *str = NULL;

    while (win_check(game) != 1) {
        display(game);
        my_printf("waiting for ennemy attack...\n");
        receive();
        attack[0] = usr[2];
        attack[1] = usr[3];
        my_putchar(attack[0] + 64);
        my_putchar(attack[1] + 48);
        check_attack(attack, game);
        if (win_check(game) == 1)
            return 1;
        str = get_input();
        send_pos(str, game.enemy.pid);
        my_printf("%s : ", str);
        is_touch(game, str);
    }
}

int main_player1(game_t game, char **av)
{
    game.player = init_player(game.player);
    game.enemy = init_enemy(game.enemy);
    game.player.map = map_boat(game.player.map, av[1]);
    if (game.player.map == NULL)
        return ERROR;
    while (connection(game) != 1);
    my_putchar('\n');
    game.enemy.pid = usr[5];
    game_debut_1(game);
}

int main_player2(game_t game, char **av)
{
    game.player = init_player(game.player);
    game.enemy = init_enemy(game.enemy);
    game.player.map = map_boat(game.player.map, av[2]);
    game.enemy.pid = my_getnbr(av[1]);
    kill(game.enemy.pid, SIGUSR1);
    my_printf("my_pid : %i\nsuccessfully connected\n\n", game.player.pid);
    game_debut_2(game);
}
