/*
** EPITECH PROJECT, 2022
** str_to_array
** File description:
** str_to_array
*/

#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include "my.h"

static char **add_separators(char **sep, char *dict, int *i, char delim)
{
    int len = *i + 2;
    char *newsep = NULL;

    if (dict == NULL || my_strlen(dict) < *i + 2)
        return sep;
    for (; dict[len] != '\0' && dict[len] != delim && dict[len + 1] != delim;
        len++);
    if (dict[len] == '\0' || dict[len + 1] == '\0')
        return sep;
    if ((newsep = my_strndup(&dict[*i + 2], len - *i - 1)) == NULL) {
        *i = len + 2;
        return sep;
    }
    *i = len + 2;
    return add_str_to_tabl(sep, newsep);
}

int skip_delimiter(char *dict, int i, char delim)
{
    for (i += 2; dict[i] != '\0' && dict[i] != delim &&
        dict[i + 1] != delim; i++);
    i += (dict[i] == '\0' || dict[i + 1] == '\0') ? 1 : 2;
    i += (dict[i] == '\0' || dict[i + 1] == '\0') ? 1 : 2;
    return i;
}

char **get_separators(char *dict)
{
    char **separators = NULL;

    if (dict == NULL)
        return NULL;
    for (int i = 0; dict[i] != '\0'; i++) {
        if (dict[i] == '!' && dict[i + 1] == '!' && dict[i + 2] != '\0') {
            i += skip_delimiter(dict, i, '!');
            continue;
        }
        if (dict[i] == '`' && dict[i + 1] == '`' && dict[i + 2] != '\0')
            separators = add_separators(separators, dict, &i, '`');
        else
            separators = add_str_to_tabl(separators, my_strndup(&dict[i], 1));
        if (separators == NULL)
            return NULL;
    }
    return separators;
}

char **get_delimiters(char *dict)
{
    char **delimiter = NULL;

    if (dict == NULL)
        return NULL;
    for (int i = 0; dict[i] != '\0'; i++) {
        if (dict[i] == '`' && dict[i + 1] == '`' && dict[i + 2] != '\0') {
            i = skip_delimiter(dict, i, '`');
            continue;
        }
        if (dict[i] == '!' && dict[i + 1] == '!' && dict[i + 2] != '\0')
            delimiter = add_separators(delimiter, dict, &i, '!');
        else
            continue;
        if (delimiter == NULL)
            return NULL;
    }
    return delimiter;
}

int is_in_array(char **str, char **array, bool move_ptr)
{
    int len = 0;
    int tmp = 0;

    if (str == NULL || array == NULL)
        return 0;
    for (int i = 0; array[i] != NULL; i++) {
        len = my_strlen(array[i]);
        tmp = my_strlen(*str);
        if (my_strncmp(*str, array[i], (tmp < len) ? tmp : len) == 0) {
            (*str) += (move_ptr == true) ? (len - 1) : 0;
            return 1;
        }
    }
    return 0;
}
