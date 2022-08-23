/*
** EPITECH PROJECT, 2021
** Navy
** File description:
** Send position
*/

#include "../includes/navy.h"

int *send_pos(char *pos, pid_t pid)
{
    int pos_nb[2] = {pos[0] - 64, pos[1] - 48};

    for (int i = 0; i < pos_nb[0]; i++) {
        usleep(100);
        kill(pid, SIGUSR1);
    }
    for (int i = pos_nb[0]; i < 8; i++) {
        usleep(100);
        kill(pid, SIGUSR2);
    }
    for (int i = 0; i < pos_nb[1]; i++) {
        usleep(100);
        kill(pid, SIGUSR1);
    }
    for (int i = pos_nb[1]; i < 8; i++) {
        usleep(100);
        kill(pid, SIGUSR2);
    }
}
