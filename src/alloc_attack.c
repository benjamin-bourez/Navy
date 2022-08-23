/*
** EPITECH PROJECT, 2021
** navy
** File description:
** ATTAQUE recive
*/

#include "../includes/navy.h"

char *my_strconfigure(unsigned int size)
{
    char *ptr;
    unsigned int i = 0;

    if (!size)
        return (NULL);
    ptr = malloc(sizeof(char) * (size + 1));
    if (ptr == NULL)
        return (NULL);
    while (i < size + 1)
        *(ptr + i++) = 0;
    return (ptr);
}

char *my_realloc2(char *ptr, unsigned int size)
{
    char *new_ptr = my_strconfigure(size);
    int ch = 0;

    if (ptr == NULL || size < 1 || !new_ptr)
        return (NULL);
    while (((ssize_t)ch) != size && ptr[ch] != '\0') {
        new_ptr[ch] = ptr[ch];
        ch++;
    }
    if (ptr[ch])
        while (((ssize_t)ch) < size)
            new_ptr[ch++] = 0;
    new_ptr[ch] = 0;
    free(ptr);
    return (new_ptr);
}

char *return_freed(char *ptr, char *ret)
{
    if (ptr != NULL)
        free(ptr);
    return (ret);
}
