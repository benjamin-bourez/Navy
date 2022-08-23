/*
** EPITECH PROJECT, 2021
** Navy
** File description:
** Connection
*/

#include "../includes/navy.h"

void action(int sig, siginfo_t *info, void *ucontext)
{
    if (usr[4] == 0) {
        my_printf("\nennemy connected\n");
        usr[4]++;
        usr[5] = info->si_pid;
    }
}

int connection(game_t g)
{
    struct sigaction act;
    int nb = 0;

    sigemptyset(&act.sa_mask);
    act.sa_sigaction = action;
    act.sa_flags = SA_SIGINFO;
    int retval = sigaction(10, &act, NULL);
    my_printf("my_pid: %i\nwaiting for enemy connection...\n\n", g.player.pid);
    while (usr[4] != 1);
    return 1;
}
