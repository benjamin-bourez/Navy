/*
** EPITECH PROJECT, 2021
** navy
** File description:
** change map
*/

#include "../includes/navy.h"

char **change_map_col(test_boat_t test, char **map)
{
    for (int i = 0; i <= test.end_line - test.line; i++) {
        map[test.line + i] = change_line(map[test.line + i], test.col, \
        test.end_line - test.line + 1);
        if (map[test.line] == NULL)
            return NULL;
    }
    return map;
}

char **change_map_line(test_boat_t test, char **map)
{
    int index_col = test.col;
    int nb = (test.end_col - test.col + 1) / 2 ;

    nb += (test.end_col - test.col + 1) % 2;
    for (int i = 0; i <= test.end_col - test.col; i += 2) {
        map[test.line] = change_line(map[test.line], index_col, nb);
        index_col += 2;
        if (map[test.line] == NULL)
            return NULL;
    }
    return map;
}

char **change_map(test_boat_t test, char **map)
{
    if (test.col == test.end_col)
        map = change_map_col(test, map);
    if (test.line == test.end_line)
        map = change_map_line(test, map);
    return map;
}
