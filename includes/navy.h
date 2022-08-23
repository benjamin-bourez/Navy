/*
** EPITECH PROJECT, 2021
** navy
** File description:
** .h
*/

#ifndef NAVY
    #define NAVY
    #define ERROR 84

    #include <stdio.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <signal.h>
    #include <fcntl.h>
    #include <string.h>
    #include "my_printf.h"
    #include "my.h"

    typedef struct s_player
    {
    char **map;
    pid_t pid;
    int hit;
    } player_t;
    typedef struct game
    {
        player_t player;
        player_t enemy;
    } game_t;
    typedef struct test_boat
    {
        int col;
        int line;
        int end_col;
        int end_line;
        int fail;
    } test_boat_t;
    int test_attack(char *str);
    void display_map(char **map);
    void display(game_t game);
    char **map_boat(char **map, char *filename);
    test_boat_t change_test(test_boat_t test);
    char **change_map_col(test_boat_t test, char **map);
    char **change_map_line(test_boat_t test, char **map);
    char **change_map(test_boat_t test, char **map);
    char *change_line(char *line, int i, int change);
    int connection(game_t g);
    char *get_next_line(int fdesc);
    char *return_freed(char *ptr, char *ret);
    int get_character(int fdesc, char *str);
    char *my_realloc2(char *ptr, unsigned int size);
    char *my_strconfigure(unsigned int size);
    int check_attack(int *attack, game_t game);
    char *get_input(void);
    int win_check(game_t game);
    int game_debut_1(game_t game);
    int game_debut_2(game_t game);
    char *stdin_redirect(void);
    char *read_pos(char *content, char *boat);
    char **check(test_boat_t test, char *boat, char **map, int i);
    int *receive(void);
    int *send_pos(char *pos, pid_t pid);
    int my_atoi(char *str);
    char *is_touch(game_t game, char *str);
    char *modif_line(char *line, int i, char c);
    player_t init_player(player_t player);
    int main_player1(game_t game, char **av);
    int main_player2(game_t game, char **av);
    player_t init_enemy(player_t player);
    extern int usr[9];

#endif
