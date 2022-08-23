/*
** EPITECH PROJECT, 2021
** my_str_to_word_array.c
** File description:
** split string into words
*/

#include <stdio.h>
#include <stdlib.h>

void my_putchar(char c);

void my_putstr(char *str);

char *my_strcpy(char *dest, char const *str);

char *my_strncpy(char *dest, char const *str, int n);

int my_strlen(char const *str);

int is_alphanum(char c)
{
    if ((47 < c && c < 58) || (64 < c && c < 91) ||
        (96 < c && c < 123)) {
        return 1;
    } else {
        return 0;
    }
}

int count_non_alphanum(char const *str)
{
    int compt = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alphanum(str[i]) == 0) {
            compt++;
        }
    }
    return compt;
}

char **my_str_to_word_array(char const *str)
{
    int j = 0;
    int nonalpha = count_non_alphanum(str);
    char **tab = malloc(sizeof(char *) * (nonalpha + 2));
    int i;
    for (i = 0; i < nonalpha; i++) {
        while (is_alphanum(str[j]) == 1) {
            j++;
        }
        tab[i] = malloc(sizeof(char) * j + 1);
        my_strncpy(tab[i], str, j);
        j++;
        str = str + j;
    }
    i++;
    tab[i] = 0;
    return tab;
}
