/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** all function in libm.a
*/
#ifndef MY_H

    #define MY_H

    void my_put_unsigned_nbr(unsigned int nbr);

    void my_put_binary_nbr(int nbr);

    void my_put_hexa_nbr(int nbr);

    void my_put_octal_nbr(int nbr);

    char **my_str_to_word_array(char const *str);

    int my_compute_power_rec(int nb, int p);

    int my_putchar(char c);

    int my_compute_square_root(int nb);

    int my_find_prime_sup(int nb);

    int is_prime(int nb);

    int my_getnbr(char const *str);

    int my_isneg(int n);

    int my_is_prime(int nb);

    int my_put_nbr(int nb);

    int my_putstr(char const *str);

    char *my_revstr(char *str);

    int my_showmem(char const *str, int size);

    int my_showstr(char const *str);

    void my_sort_int_array(int *tab, int size);

    char *my_strcapitalize(char *str);

    char *my_strcat(char *dest , char const *src);

    int my_strcmp(char const *s1 , char const *s2);

    char *my_strcpy(char *dest , char const *src);

    int my_str_isalpha(char const *str);

    int my_str_islower(char const *str);

    int my_str_isnum(char const *str);

    int my_str_isprintable(char const *str);

    int my_str_isupper(char const *str);

    int my_strlen(char const *str);

    char *my_strlowcase(char *str);

    char *my_strncat(char *dest , char const *src, int nb);

    int my_strncmp(char const *s1 , char const *s2, int n);

    char *my_strncpy(char *dest, char const *src, int n);

    char *my_strstr(char *str, char *to_find);

    char *my_strupcase(char *str);

    void my_swap(int *a, int *b);

    char *my_strdup(char const *str);

    int my_put_long_nbr(long int nbr);

    int my_put_short_nbr(int nbr);

    int my_putstr_none(char *str);

    char **my_str_to_word_array(char const *str);
#endif
