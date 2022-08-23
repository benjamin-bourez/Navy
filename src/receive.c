/*
** EPITECH PROJECT, 2021
** navy
** File description:
** signal_me
*/

#include "../includes/navy.h"

int usr[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

void handler(int sig, siginfo_t *info, void *ucontext)
{
    if (sig == 10) {
        usr[0]++;
        if (usr[0] + usr[1] <= 8)
            usr[2]++;
        else if (usr[0] + usr[1] > 8)
            usr[3]++;
    }
    if (sig == 12) {
        usr[1]++;
    }
}

int *receive(void)
{
    struct sigaction act;

    usr[0] = 0;
    usr[1] = 0;
    usr[2] = 0;
    usr[3] = 0;
    sigemptyset(&act.sa_mask);
    act.sa_sigaction = handler;
    act.sa_flags = SA_SIGINFO;
    int retval1 = sigaction(10, &act, NULL);
    int retval2 = sigaction(12, &act, NULL);
    while (usr[0] + usr[1] != 16);
}
