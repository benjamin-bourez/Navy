/*
** EPITECH PROJECT, 2021
** my_strcmp
** File description:
** copis strcmp fonction
*/

int my_strcmp(char const *s1 , char const *s2)
{
    while (*s1 != '\0' && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    if (*s1 == *s2) {
        return 0;
    } else {
        return (*(unsigned char *)s1 - *(unsigned char *)s2);
    }
}
