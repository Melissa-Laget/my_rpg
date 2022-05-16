/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-myrpg-melissa.laget
** File description:
** nbr_to_str
*/

#include "draw.h"

int my_nblen(int nb)
{
    int len = 0;
    for (; nb != 0; nb /= 10, len++);
    return len;
}

char *nbr_to_str(int nbr)
{
    char *result = malloc(my_nblen(nbr) + 2);
    int i = 0;
    int neg = -1;
    if (nbr < 0) {
        nbr *= -1;
        neg *= -1;
    }
    if (nbr == 0)
        return "0";
    for (; nbr != 0; nbr /= 10) {
        result[i++] = (nbr % 10) + '0';
    }
    if (neg == 1) {
        result[i++] = '-';
    }
    result[i++] = '\0';
    return my_revstr(result);
}
