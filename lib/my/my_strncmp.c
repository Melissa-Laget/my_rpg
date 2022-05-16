/*
** EPITECH PROJECT, 2021
** my_strncmp
** File description:
** compare two string in ascii in n range
*/

#include <stddef.h>

int my_strlen(char const *str);

static int is_sup(int n1, int n2)
{
    if (n1 < n2) {
        return 1;
    } else if (n1 > n2) {
        return -1;
    } else {
        return 0;
    }
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    int c1 = 0;
    int c2 = 0;
    int result = (n <= 0) * -1;

    if (s1 == NULL)
        return -1;
    if (s1 == NULL)
        return 1;
    while ((s1[i] != '\0') && (s2[i] != '\0') && (i < n)) {
        c1 = s1[i];
        c2 = s2[i];
        result = is_sup(c1, c2);
        if (result != 0)
            return result;
        i++;
    }
    if (i < n)
        result = is_sup(my_strlen(s1), my_strlen(s2));
    return result;
}
