/*
** EPITECH PROJECT, 2021
** navy
** File description:
** ATTAQUE recive
*/

#include "../includes/navy.h"

int get_character(int fdesc, char *str)
{
    static int off = 0;
    static char buff[10];
    static int reader = 10;

    if (off >= reader || off == 0) {
        off = 0;
        reader = read(fdesc, buff, 10);
        if (reader == 0)
            return (0);
    }
    if (reader == 0) {
        *str = 0;
        off = -1;
    } else {
        if (buff[off] == '\n' || buff[off] == '\0')
            *str = 0, off++;
        else
            *str = buff[off++];
    }
    return (reader);
}

char *alloc_line(int i, char *line)
{
    if (i % 10 == 0) {
        line = my_realloc2(line, i + 10 + 1);
        if (line == NULL)
            return (return_freed(line, NULL));
    }
    return line;
}

char *get_next_line(int fdesc)
{
    char *line = my_strconfigure(10);
    int i = 0;
    int reader = get_character(fdesc, &line[i]);

    if (reader == 0 || line == NULL || fdesc < 0)
        return (return_freed(line, NULL));
    while (line[i]) {
        line = alloc_line(i, line);
        if (line == NULL)
            return NULL;
        reader = get_character(fdesc, &line[++ i]);
    }
    line[++ i] = 0;
    return (line);
}

char *stdin_redirect(void)
{
    char *str = get_next_line(0);
    int len;

    if (str == NULL)
        return (NULL);
    if (test_attack(str) == 84)
        return (NULL);
    return (str);
}

char *get_input(void)
{
    int a = 1;
    char *s;

    while (a == 1) {
        my_putstr("attack: ");
        s = stdin_redirect();
        if (s != NULL) {
            a = 2;
            return (s);
        }
        if (a == 1)
            free(s);
    }
    return (NULL);
}
