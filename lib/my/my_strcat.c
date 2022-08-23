/*
** EPITECH PROJECT, 2021
** my_strcat
** File description:
** concatenates tow string
*/

char *my_strcat(char *dest , char const *src)
{
    int i = 0;
    int w = 0;
    while (dest[w] != '\0') {
        w += 1;
    }
    while (src[i] != '\0') {
        dest[w + i] = src[i];
        i += 1;
    }
    return (dest);
}
