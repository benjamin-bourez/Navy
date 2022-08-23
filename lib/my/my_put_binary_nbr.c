/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** put a nbr
*/

void my_putchar(char c);

void my_put_binary_nbr(int nbr)
{
    unsigned int nbr2;

    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * (-1);
    }
    if (nbr >= 2) {
        nbr2 = nbr % 2;
        nbr = nbr / 2;
        my_put_binary_nbr(nbr);
        my_putchar(nbr2 + 48);
    } else {
        my_putchar(nbr + 48);
    }
}
