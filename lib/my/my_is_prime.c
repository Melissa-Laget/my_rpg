/*
** EPITECH PROJECT, 2021
** my_is_prime
** File description:
** test if a number is prime
*/

int my_is_prime(int nb)
{
    int pos_div = 0;

    if (nb <= 1) {
        return 0;
    }
    for (int i = 1; i <= nb; i++) {
        if ((nb % i) == 0) {
            pos_div++;
        }
    }
    if (pos_div == 2) {
        return 1;
    } else {
        return 0;
    }
}

int my_is_prime_sup(int nb)
{
    int cand_nb = nb;

    if (my_is_prime(nb)) {
        return nb;
    } else {
        while (!my_is_prime(cand_nb)) {
            cand_nb++;
        }
        return cand_nb;
    }
}
