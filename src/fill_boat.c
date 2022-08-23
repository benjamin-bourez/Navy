/*
** EPITECH PROJECT, 2021
** navy
** File description:
** put boat in map
*/

#include "../includes/navy.h"

char *change_line(char *line, int i, int change)
{
    char *new_line = malloc(my_strlen(line));

    for (int y = 0; y < i; y++)
        new_line[y] = line[y];
    if (line[i] != '.')
        return NULL;
    new_line[i] = change + 48;
    for (int y = i + 1; line[y] != '\0'; y++)
        new_line[y] = line[y];
    return new_line;
}

char *read_pos(char *content, char *boat)
{
    char *nbr = "2345";
    int count = 0;
    if (nbr[0] != content[0] || nbr[1] != content[8]\
    || nbr[2] != content[16] || nbr[3] != content[24])
        return NULL;
    for (int i = 1; content[i] != '\0'; i++) {
        if (content[i] == ':')
            i += 1;
        if (content[i] == '\n' && i < 30)
            i += 3;
        boat[count] = content[i];
        count += 1;
    }
    return boat;
}

char **check(test_boat_t test, char *boat, char **map, int i)
{
    test.col = boat[i];
    test.end_col = boat[i + 2];
    test.line = boat[i + 1];
    test.end_line = boat[i + 3];
    if (boat[i] - boat[i + 2] == 0)
        if (boat[i + 1] < boat[i + 3] && boat[i + 3] -\
        boat[i + 1] + 1 == i / 4 + 2) {
            test = change_test(test);
            map = change_map(test, map);
        }
    if (boat[i + 1] - boat[i + 3] == 0)
        if (boat[i] < boat[i + 2] && boat[i + 2] - boat[i] + 1 == i / 4 + 2) {
            test = change_test(test);
            map = change_map(test, map);
        }
    if (map == NULL)
        return NULL;
    return map;
}

int cheking_all(test_boat_t test, char *boat, int i)
{
    static int nb_boat[4] = {0, 0, 0, 0}; 
    test.col = boat[i];
    test.end_col = boat[i + 2];
    test.line = boat[i + 1];
    test.end_line = boat[i + 3];
    if (boat[i] - boat[i + 2] == 0)
        if (boat[i + 1] < boat[i + 3] && boat[i + 3] -\
        boat[i + 1] + 1 == i / 4 + 2) {
            nb_boat[i / 4] += 1;
        }
    if (boat[i + 1] - boat[i + 3] == 0)
        if (boat[i] < boat[i + 2] && boat[i + 2] - boat[i] + 1 == i / 4 + 2) {
            nb_boat[i / 4] += 1;
        }
    for (int y; y < 4; y++) {
        if (nb_boat[y] != 1 && i == 16) {
            return 84;
        }
    }
    return 0;
}

char **map_boat(char **map, char *filename)
{
    char *content = malloc(37);
    char *boat = malloc(17);
    int pos = open(filename, O_RDONLY);
    test_boat_t test;

    if (pos == -1)
        return NULL;
    read(pos, content, 36);
    close(pos);
    boat = read_pos(content, boat);
    if (boat == NULL)
        return NULL;
    for (int i = 0; boat[i] != '\0'; i += 4) {
        if (cheking_all(test, boat, i) == 84)
            return NULL;
        map = check(test, boat, map, i);
        if (map == NULL)
            return NULL;
    }
    return map;
}
