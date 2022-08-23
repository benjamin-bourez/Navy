/*
** EPITECH PROJECT, 2021
** my_revstr
** File description:
** revesres a string
*/

int my_counting(char const *str)
{
    int i = 0;
    while (*str != '\0') {
        i += 1;
        str += 1;
    }
    return (i);
}

void my_reverse(char *str, char *str2)
{
    char temp = *str;
    *str = *str2;
    *str2 = temp;
}

char *my_revstr(char *str)
{
    int n = (my_counting(str));

    for (int i = 0; i < n / 2; i++) {
        my_reverse(str + i, str + n - 1 - i);
    }
    return str;
}
