/*
** EPITECH PROJECT, 2022
** B-PSU-101-BDX-1-1-minishell1-maxime.senard
** File description:
** char_arr_utils
*/

/*
** EPITECH PROJECT, 2021
** B-PSU-100-BDX-1-1-myls-maxime.senard
** File description:
** utils
*/

#include <stddef.h>
#include <stdlib.h>
#include "my.h"

char **create_char_tabl(int size)
{
    char **res = malloc(sizeof(char *) * (size + 1));

    for (int i = 0; i <= size; i++)
        res[i] = NULL;
    return res;
}

int my_char_tabl_len(char **tabl)
{
    int i = 0;

    if (tabl == NULL)
        return 0;
    if (tabl[0] == NULL)
        return 0;
    for (i = 0; tabl[i] != NULL; i++);
    return i + 1;
}

char **add_str_to_tabl(char **tabl, char *str)
{
    int size = 0;
    char **res = NULL;

    if (str == NULL || str[0] == '\0')
        return tabl;
    if (tabl == NULL) {
        if ((tabl = create_char_tabl(1)) == NULL)
            return NULL;
        tabl[0] = str;
        return tabl;
    }
    size = my_char_tabl_len(tabl) - 1;
    if ((res = create_char_tabl(size + 1)) == NULL)
        return tabl;
    for (int i = 0; i < size; i++)
        res[i] = tabl[i];
    res[size] = str;
    free(tabl);
    return res;
}

char *add_to_str(char *str, char c)
{
    int length = 0;
    char *res = NULL;
    int i = 0;

    if (str == NULL)
        return NULL;
    length = my_strlen(str);
    res = malloc(sizeof(char) * (length + 2));
    if (res == NULL)
        return NULL;
    for (i = 0; i < length; i++)
        res[i] = str[i];
    res[i++] = c;
    res[i] = '\0';
    free(str);
    return res;
}

unsigned char *add_to_ustr(unsigned char *str, unsigned char c)
{
    int length = 0;
    unsigned char *res = NULL;
    int i = 0;

    if (str == NULL)
        return NULL;
    length = my_strlen((char*)str);
    res = malloc(sizeof(unsigned char) * (length + 2));
    if (res == NULL)
        return NULL;
    for (i = 0; i < length; i++)
        res[i] = str[i];
    res[i++] = c;
    res[i] = '\0';
    free(str);
    return res;
}
