/*
** EPITECH PROJECT, 2021
** my_put_nbr
** File description:
** put a nbr
*/

void my_putchar(char c);

void my_put_hexa_nbr(int nbr)
{
    unsigned int nbr2;

    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * (-1);
    }
    if (nbr >= 16) {
        nbr2 = nbr % 16;
        nbr = nbr / 16;
        if (nbr2 > 9)
            nbr2 += 7;
        my_put_hexa_nbr(nbr);
        my_putchar(nbr2 + 48);
    } else {
        if (nbr > 9)
            nbr += 7;
        my_putchar(nbr + 48);
    }
}
