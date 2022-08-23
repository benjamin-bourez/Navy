/*
** EPITECH PROJECT, 2021
** navy
** File description:
** ATTAQUE recive
*/

#include "../includes/navy.h"

int check_attack(int *attack, game_t game)
{
    if (game.player.map[attack[1] + 1][attack[0] * 2] != '.'\
    && game.player.map[attack[1] + 1][attack[0] * 2] != 'o'
    && game.player.map[attack[1] + 1][attack[0] * 2] != 'x') {
        usleep(100);
        kill(game.enemy.pid, SIGUSR1);
        usr[8]++;
        game.player.map[attack[1] + 1] = \
        modif_line(game.player.map[attack[1] + 1], attack[0] * 2, 'x');
        my_printf(": hit\n\n");
        return 0;
    } else {
        if (game.player.map[attack[1] + 1][attack[0] * 2] == '.')
            game.player.map[attack[1] + 1] = \
            modif_line(game.player.map[attack[1] + 1], attack[0] * 2, 'o');
        usleep(100);
        kill(game.enemy.pid, SIGUSR2);
        my_printf(": missed\n\n");
        return 1;
    }
}

void touch_or_not(int sig, siginfo_t *info, void *ucontext)
{
    if (sig == 10 && usr[6] == 0) {
        my_printf("hit\n\n");
        usr[6] = 1;
    }
    if (sig == 12 && usr[6] == 0) {
        my_printf("missed\n\n");
        usr[6] = 2;
    }
}

char *is_touch(game_t game, char *str)
{
    struct sigaction act;

    usr[6] = 0;
    sigemptyset(&act.sa_mask);
    act.sa_sigaction = touch_or_not;
    act.sa_flags = SA_SIGINFO;
    int retval1 = sigaction(10, &act, NULL);
    int retval2 = sigaction(12, &act, NULL);
    pause();
    if (usr[6] == 1) {
        game.enemy.map[str[1] - 47] = modif_line(game.enemy.map[str[1] - 47], \
        (str[0] - 64) * 2, 'x');
        usr[7]++;
    } else {
        if (game.enemy.map[str[1] - 47][(str[0] - 64) * 2] == '.')
            game.enemy.map[str[1] - 47] = modif_line(\
            game.enemy.map[str[1] - 47], (str[0] - 64) * 2, 'o');
    }
}

char *modif_line(char *line, int i, char c)
{
    char *new_line = malloc(20);

    for (int x = 0; line[x] != '\0'; x++) {
        if (x == i)
            new_line[x] = c;
        else
            new_line[x] = line[x];
    }
    return new_line;
}
