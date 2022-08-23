/*
** EPITECH PROJECT, 2021
** my_strdup.c
** File description:
** Duplicate string
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest , char const *src);

char *my_strdup(char const *str)
{
    char *dup;

    dup = malloc(my_strlen(str) + 1);
    dup = my_strcpy(dup, str);
    return (dup);
}
